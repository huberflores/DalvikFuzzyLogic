#include "BasicFuzzyController.h"
#include "../deffuzifyer/CentroidMethod.h"
#include <iostream>

using namespace std;

namespace controller {
    using deffuzifyer::CentroidMethod;
    using deffuzifyer::DefuzzyerMethod;
    using rules::FuzzyTerm;
    using rules::Rule;
    using variables::FuzzySet;
    using variables::LinguisticVariable;
    using std::cout;

    BasicFuzzyController::BasicFuzzyController() {
        variablesList = std::vector<LinguisticVariable*>();
        rulesList = std::vector<Rule*>();
        defMethod = new CentroidMethod();
    }

    void BasicFuzzyController::addVariable(LinguisticVariable *lv) {
        variablesList.push_back(lv);
    }

    void BasicFuzzyController::setDefuzzifyerMethod(DefuzzyerMethod *defMethod) {
        this->defMethod = defMethod;
    }

    void BasicFuzzyController::addRule(FuzzyTerm *ant, FuzzyTerm *con) {
        rulesList.push_back(new Rule(ant, con));
    }

    void BasicFuzzyController::fuzzify(const std::wstring &label, double val) {
        //cout << "FUZZIFYING...";
        for (std::vector<LinguisticVariable*>::const_iterator lv = variablesList.begin(); lv != variablesList.end(); ++lv) {
            if (BasicFuzzyController::caseInsensitiveStringCompare(label, (*lv)->getLabel())) {
                (*lv)->fuzziffy(val);
            }
        }
    }

    bool BasicFuzzyController::caseInsensitiveStringCompare(const std::wstring& str1, const std::wstring& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        for (std::wstring::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
            if (tolower(*c1) != tolower(*c2)) {
                return false;
            }
        }
        return true;
    }

    std::map<std::wstring, double> BasicFuzzyController::defuzzify(const std::wstring &label) {
        //cout << "DEFUZZIFYING...";
        setConfidencesOfConsequentsToZero();
        LinguisticVariable *lv = 0;

        for (std::vector<LinguisticVariable*>::const_iterator l = variablesList.begin(); l != variablesList.end(); ++l) {
            //wcout<<"iteration-"<<(*l)->getLabel()<<" value-"<<(*l)->getBestLabel() <<"\n";
            if (BasicFuzzyController::caseInsensitiveStringCompare((*l)->getLabel(), label)) {
                lv = *l;
            }
        }

        if (lv == 0) {
            //throw UnsupportedOperationException;
            cout << "UnsupportedOperationException";
        } else {
            this->setConfidencesOfConsequentsToZero();
            for (std::vector<Rule*>::const_iterator r = rulesList.begin(); r != rulesList.end(); ++r) {
                (*r)->calculate();
            }
            //cout<<lv.getBestLabel();
            std::map<std::wstring, double> values = std::map<std::wstring, double>();
            values[lv->getBestLabel()] = defMethod->getDefuzziedValue(lv);

            //return defMethod.getDefuzziedValue(lv);
            return values;
        }
    }

    void BasicFuzzyController::setConfidencesOfConsequentsToZero() {
        for (std::vector<Rule*>::const_iterator r = rulesList.begin(); r != rulesList.end(); ++r) {
            (*r)->getConsequent()->clearDOM();
        }
    }
}
