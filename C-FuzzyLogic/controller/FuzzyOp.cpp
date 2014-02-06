#include "FuzzyOp.h"
#include "../comparator/FuzzyAND.h"
#include "../comparator/FuzzyOR.h"
#include "../comparator/FuzzyNOT.h"

using namespace comparator;
namespace controller {

    double FuzzyOp::doubleAnd(double a, double b) {
        if (a < b) {
            return a;
        } else
            return b;
    }

    rules::FuzzyTerm *FuzzyOp::fuzzyAnd(FuzzyTerm *a, FuzzyTerm *b) {
        return new FuzzyAND(a, b);
    }

    rules::FuzzyTerm *FuzzyOp::fuzzyOr(FuzzyTerm *a, FuzzyTerm *b) {
        return new FuzzyOR(a, b);
    }

    rules::FuzzyTerm *FuzzyOp::fuzzyNot(FuzzyTerm *a) {
        return new FuzzyNOT(a);
    }

    double FuzzyOp::doubleOr(double a, double b) {
        if (a > b) {
            return a;
        } else
            return b;
    }

    double FuzzyOp::doubleNot(double a) {
        return 1 - a;
    }
}
