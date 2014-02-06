#include "TrapezoidalMembershipFunction.h"
#include <limits>
#include <iostream>

namespace functions {

    TrapezoidalMembershipFunction::TrapezoidalMembershipFunction(double a, double b, double c, double d) {
        InitializeInstanceFields();
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    TrapezoidalMembershipFunction::TrapezoidalMembershipFunction(double a, double b, double c, bool right) {
        InitializeInstanceFields();
        if (!right) {
            // <summary>
            //  ------
            // 		   \
			// 			\
			// 			 \
			// 			  \
			// </summary>

            this->a = a;
            this->b = a;
            this->c = b;
            this->d = c;
        } else {
            //     ------
            // 	   /
            // 	  /
            // 	 /
            // 	/
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = c;
        }
    }

    double TrapezoidalMembershipFunction::getValue(double input) {
        double result = 0;
        if (input >= a && input <= b) {
            result = (input - a) / (b - a);
            return result;
        }
        if (input >= b && input <= c) {
            result = 1;
            return result;
        }
        if (input >= c && input <= d) {
            result = (input - d) / (c - d);
        }
        return result;
    }

    double TrapezoidalMembershipFunction::getClippedValue(double input, double clip) {
        double result = 0;
        double flag = 0;
        if (input >= a && input <= b) {
            flag = (input - a) / (b - a);
            if (result < clip) {
                result = flag;
            } else {
                result = clip;
            }
        }
        if (input >= b && input <= c) {
            flag = 1;
            if (flag < clip) {
                result = flag;
            } else {
                result = clip;
            }
        }
        if (input >= c && input <= d) {
            flag = (input - d) / (c - d);
        }
        if (flag < clip) {
            result = flag;
        } else {
            result = clip;
        }
        //std::cout<<"input: "<<input<<"--"<<clip<<"--"<<result<<"\n";
        return result;
    }

    double TrapezoidalMembershipFunction::getMax() {
        if (d == positiveInfinity || d == negativeInfinity) {
            if (c == positiveInfinity || c == negativeInfinity) {
                if (b == positiveInfinity || b == negativeInfinity) {
                    return a;
                }
                return b;
            }
            return c;
        }
        return d;
    }

    double TrapezoidalMembershipFunction::getMin() {
        if (a == positiveInfinity || a == negativeInfinity) {
            if (b == positiveInfinity || b == negativeInfinity) {
                if (c == positiveInfinity || c == negativeInfinity) {
                    return d;
                }
                return c;
            }
            return b;
        }
        return a;
    }

    void TrapezoidalMembershipFunction::InitializeInstanceFields() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        positiveInfinity = std::numeric_limits<double>::infinity();
        negativeInfinity = -std::numeric_limits<double>::infinity();
    }
}
