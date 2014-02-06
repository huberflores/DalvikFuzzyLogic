#pragma once

#include "../rules/FuzzyTerm.h"
#include <vector>
#include <iostream>
#include <limits>

namespace comparator {
    using rules::FuzzyTerm;
    class FuzzyAND: public FuzzyTerm {
        public:
            std::vector<FuzzyTerm*> terms;
            FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB);
            FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC);
            FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC, FuzzyTerm *termD);
            virtual double getDOM();
            virtual void clearDOM();
            virtual void orWithDOM(double val);
    };
}
