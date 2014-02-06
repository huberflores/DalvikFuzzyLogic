#include "LinguisticVariable.h"

using namespace std;

namespace variables {
    using modifier::FzSet;

    LinguisticVariable::LinguisticVariable(const std::wstring &label) {
        this->label = label;
        //possibleValues = std::vector<FuzzySet*>();
    }

    std::vector<FuzzySet*> LinguisticVariable::getSetList() {
        return possibleValues;
    }

    std::wstring LinguisticVariable::getLabel() {
        return label;
    }

    void LinguisticVariable::fuzziffy(double input) {
        for (std::vector<FuzzySet*>::const_iterator fs = possibleValues.begin(); fs != possibleValues.end(); ++fs) {
            (*fs)->calculateDOM(input);
        }
    }

    modifier::FzSet *LinguisticVariable::addSet(const std::wstring &setLabel, MembershipFunction *functions) {
        FuzzySet *set = new FuzzySet(setLabel, functions);
        for (std::vector<FuzzySet*>::const_iterator fs = possibleValues.begin(); fs != possibleValues.end(); ++fs) {
            if (set->equals(*fs)) {
                cout << "IllegalSetException";
                //throw IllegalSetException();
            }
        }
        possibleValues.push_back(set);
        return new FzSet(set);

    }

    double LinguisticVariable::getMax() {
        double flag = 0;
        double max = 0;
        for (std::vector<FuzzySet*>::const_iterator fs = possibleValues.begin(); fs != possibleValues.end(); ++fs) {
            max = (*fs)->getMembershipFunction()->getMax();
            if (flag < max) {
                flag = max;
            }
        }
        return flag;
    }

    double LinguisticVariable::getMin() {
        double flag = 0;
        double min = 0;
        for (std::vector<FuzzySet*>::const_iterator fs = possibleValues.begin(); fs != possibleValues.end(); ++fs) {
            min = (*fs)->getMembershipFunction()->getMin();
            if (flag > min) {
                flag = min;
            }
        }
        return flag;
    }

    std::wstring LinguisticVariable::getBestLabel() {
        double flag = 0;
        std::wstring labelFlag = L"";
        for (std::vector<FuzzySet*>::const_iterator fs = possibleValues.begin(); fs != possibleValues.end(); ++fs) {
            double value = (*fs)->getDOM();
            if (value > flag) {
                labelFlag = (*fs)->getLabel();
            }
        }
        return labelFlag;
    }
}
