#pragma once

#include "FuzzySet.h"
#include "../functions/MembershipFunction.h"
#include "../modifier/FzSet.h"
//#include "IllegalSetException.cpp"
#include <string>
#include <vector>
#include <iostream>

namespace variables {

    using functions::MembershipFunction;
    using modifier::FzSet;

    class LinguisticVariable {
        private:
            std::wstring label;
            std::vector<FuzzySet*> possibleValues;
        public:
            LinguisticVariable(const std::wstring &label);
            virtual std::vector<FuzzySet*> getSetList();
            virtual std::wstring getLabel();
            virtual void fuzziffy(double input);
            virtual FzSet *addSet(const std::wstring &setLabel, MembershipFunction *functions);
            virtual double getMax();
            virtual double getMin();
            virtual std::wstring getBestLabel();
    };
}
