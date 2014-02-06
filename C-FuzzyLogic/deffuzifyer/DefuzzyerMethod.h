#pragma once

#include "../variables/LinguisticVariable.h"

namespace deffuzifyer {

    using variables::LinguisticVariable;

    class DefuzzyerMethod {

        public:
            virtual double getDefuzziedValue(variables::LinguisticVariable *lv) = 0;
    };

}
