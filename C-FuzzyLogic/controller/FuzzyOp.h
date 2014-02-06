#pragma once

#include "../rules/FuzzyTerm.h"
#include "../comparator/FuzzyAND.h"
#include "../comparator/FuzzyNOT.h"
#include "../comparator/FuzzyOR.h"
#include <cmath>

namespace controller {

    using rules::FuzzyTerm;

    class FuzzyOp {
        public:
            static double doubleAnd(double a, double b);
            static FuzzyTerm *fuzzyAnd(FuzzyTerm *a, FuzzyTerm *b);
            static FuzzyTerm *fuzzyOr(FuzzyTerm *a, FuzzyTerm *b);
            static FuzzyTerm *fuzzyNot(FuzzyTerm *a);
            static double doubleOr(double a, double b);
            static double doubleNot(double a);
    };
}
