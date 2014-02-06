#pragma once

#include "MembershipFunction.h"

namespace functions {

    class TrapezoidalMembershipFunction: public MembershipFunction {
        private:
            double a;
            double b;
            double c;
            double d;
            double positiveInfinity;
            double negativeInfinity;

        public:
            TrapezoidalMembershipFunction(double a, double b, double c, double d);
            TrapezoidalMembershipFunction(double a, double b, double c, bool right);
            virtual double getValue(double input);
            virtual double getClippedValue(double input, double clip);
            virtual double getMax();
            virtual double getMin();
        private:
            void InitializeInstanceFields();
    };
}
