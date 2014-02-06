#pragma once

#include "FuzzyController.h"
#include "../deffuzifyer/DefuzzyerMethod.h"
#include "../variables/LinguisticVariable.h"
#include "../rules/Rule.h"
#include "../rules/FuzzyTerm.h"
#include "../deffuzifyer/CentroidMethod.h"
#include <string>
#include <map>
#include <vector>
//#include "UnsupportedOperationException.cpp"

namespace controller {

    using deffuzifyer::DefuzzyerMethod;
    using rules::FuzzyTerm;
    using rules::Rule;
    using variables::FuzzySet;
    using variables::LinguisticVariable;

    class BasicFuzzyController: public FuzzyController {
        public:
            DefuzzyerMethod *defMethod;
            std::vector<LinguisticVariable*> variablesList;
            std::vector<Rule*> rulesList;
            BasicFuzzyController();
            virtual void addVariable(LinguisticVariable *lv);
            virtual void setDefuzzifyerMethod(DefuzzyerMethod *defMethod);
            virtual void addRule(FuzzyTerm *ant, FuzzyTerm *con);
            virtual void fuzzify(const std::wstring &label, double val);
            virtual std::map<std::wstring, double> defuzzify(const std::wstring &label);
        private:
            void setConfidencesOfConsequentsToZero();
            bool caseInsensitiveStringCompare(const std::wstring& str1, const std::wstring& str2);
    };
}
