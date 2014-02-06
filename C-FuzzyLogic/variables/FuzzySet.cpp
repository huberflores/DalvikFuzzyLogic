#include <string>

#include "FuzzySet.h"
#include "../controller/FuzzyOp.h"

namespace variables {
    using controller::FuzzyOp;
    using functions::MembershipFunction;

    FuzzySet::FuzzySet(const std::wstring &label, MembershipFunction *function) {
        InitializeInstanceFields();
        this->label = label;
        this->function = function;
        this->degree = 0;
    }

    double FuzzySet::getNormalValue(double input) {
        return function->getValue(input);
    }

    double FuzzySet::getFairlyValue(double input) {
        return sqrt(function->getValue(input));
    }

    double FuzzySet::getVeryValue(double input) {
        return pow(function->getValue(input), 2);
    }

    bool caseInsensitiveStringCompare(const std::wstring& str1, const std::wstring& str2) {
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

    bool FuzzySet::equals(FuzzySet *obj) {
        return caseInsensitiveStringCompare(getLabel(), obj->getLabel()) ? true : false;
    }

    std::wstring FuzzySet::toString() {
        return getLabel();
    }

    double FuzzySet::getDOM() {
        return degree;
    }

    void FuzzySet::clearDOM() {
        degree = 0;
    }

    void FuzzySet::orWithDOM(double val) {
        degree = FuzzyOp::doubleOr(degree, val);
    }

    double FuzzySet::calculateDOM(double input) {
        degree = function->getValue(input);
        return function->getValue(input);
    }

    double FuzzySet::getClippedValue(double input) {
        return function->getClippedValue(input, degree);
    }

    std::wstring FuzzySet::getLabel() {
        return label;
    }

    void FuzzySet::setLabel(const std::wstring &label) {
        this->label = label;
    }

    functions::MembershipFunction *FuzzySet::getMembershipFunction() {
        return function;
    }

    void FuzzySet::setMembershipFunction(MembershipFunction *function) {
        this->function = function;
    }

    void FuzzySet::InitializeInstanceFields() {
        degree = 0;
    }
}
