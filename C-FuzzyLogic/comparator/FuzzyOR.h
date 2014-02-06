#pragma once

#include "../rules/FuzzyTerm.h"
#include <vector>

namespace comparator {

    using rules::FuzzyTerm;
    class FuzzyOR: public FuzzyTerm {
        public:
            std::vector<FuzzyTerm*> terms;
            FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB);
            FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC);
            FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC, FuzzyTerm *termD);
            virtual double getDOM();
            virtual void clearDOM();
            virtual void orWithDOM(double val);
    };
}
