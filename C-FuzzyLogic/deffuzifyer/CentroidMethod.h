#pragma once

#include "DefuzzyerMethod.h"
#include "../variables/FuzzySet.h"
#include "../variables/LinguisticVariable.h"
#include <vector>

namespace deffuzifyer {

    using variables::FuzzySet;
    using variables::LinguisticVariable;

    class CentroidMethod: public DefuzzyerMethod {
        public:
            std::vector<FuzzySet*> setList;
            double min;
            double max;
            int s;
            CentroidMethod();
            virtual double getDefuzziedValue(LinguisticVariable *lv);
            virtual void setSamplesPoints(int s);

        private:
            void InitializeInstanceFields();
    };

}
