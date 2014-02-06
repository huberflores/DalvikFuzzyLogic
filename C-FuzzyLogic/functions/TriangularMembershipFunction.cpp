#include "TriangularMembershipFunction.h"
#include <iostream>

using namespace functions;
using namespace std;

namespace functions {
    TriangularMembershipFunction::TriangularMembershipFunction(double a, double b, double c) {
        InitializeInstanceFields();
        if (!(a == positiveInfinity || a == negativeInfinity) || !(b == positiveInfinity || b == negativeInfinity) || !(c == positiveInfinity || c == negativeInfinity)) {
            this->a = a;
            this->b = b;
            this->c = c;
        } else {
            cout << "FunctionException";
            //throw FunctionException;
        }
    }

    TriangularMembershipFunction::TriangularMembershipFunction(double a, double b) {
        InitializeInstanceFields();
        if (!(a == positiveInfinity || a == negativeInfinity) || !(b == positiveInfinity || b == negativeInfinity) || !(c == positiveInfinity || c == negativeInfinity)) {
            this->a = a;
            this->b = b;
            this->c = (a + b) / 2;
        } else {
            cout << "FunctionException";
            //throw FunctionException;
        }
    }

    double TriangularMembershipFunction::getValue(double input) {
        double result = 0;
        if (input >= a && input <= c) {
            result = (input - a) / (c - a);
            return result;
        } else if (input >= c && input <= b) {
            result = (input - b) / (c - b);
            return result;
        }
        return result;
    }

    double TriangularMembershipFunction::getClippedValue(double input, double clip) {
        double result = 0;
        if (input >= a && input <= c) {
            result = (input - a) / (c - a);
            if (result < clip) {
                return result;
            } else {
                return clip;
            }
        } else if (input >= c && input <= b) {
            result = (input - b) / (c - b);
            if (result < clip) {
                return result;
            } else {
                return clip;
            }
        }

        //std::cout<<"input: "<<input<<"--"<<clip<<"--"<<result<<"\n";
        return result;
    }

    double TriangularMembershipFunction::getMax() {
        return b;
    }

    double TriangularMembershipFunction::getMin() {
        return a;
    }

    void TriangularMembershipFunction::InitializeInstanceFields() {
        a = 0;
        b = 0;
        c = 0;
    }
}
