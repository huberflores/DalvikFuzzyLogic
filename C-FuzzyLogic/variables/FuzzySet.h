#pragma once

#include "../functions/MembershipFunction.h"
#include "../controller/FuzzyOp.h"
#include <string>
#include <cmath>

namespace variables {
    using functions::MembershipFunction;
    class FuzzySet {
        private:
            std::wstring label;
            MembershipFunction *function;
            double degree;
        public:
            FuzzySet(const std::wstring &label, MembershipFunction *function);
            virtual double getNormalValue(double input);
            virtual double getFairlyValue(double input);
            virtual double getVeryValue(double input);
            virtual bool equals(FuzzySet *obj);
            virtual std::wstring toString();
            virtual double getDOM();
            virtual void clearDOM();
            virtual void orWithDOM(double val);
            virtual double calculateDOM(double input);
            virtual double getClippedValue(double input);
            virtual std::wstring getLabel();
            virtual void setLabel(const std::wstring &label);
            virtual MembershipFunction *getMembershipFunction();
            virtual void setMembershipFunction(MembershipFunction *function);
        private:
            void InitializeInstanceFields();
    };
}
