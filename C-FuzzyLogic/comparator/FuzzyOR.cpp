#include "FuzzyOR.h"
#include <limits>

namespace comparator {
    using rules::FuzzyTerm;

    FuzzyOR::FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
    }

    FuzzyOR::FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
        terms.push_back(termC);
    }

    FuzzyOR::FuzzyOR(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC, FuzzyTerm *termD) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
        terms.push_back(termC);
        terms.push_back(termD);
    }

    double FuzzyOR::getDOM() {
        double minDOM = -std::numeric_limits<double>::infinity();
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            if ((*t)->getDOM() > minDOM) {
                minDOM = (*t)->getDOM();
            }
        }
        return minDOM;
    }

    void FuzzyOR::clearDOM() {
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            (*t)->clearDOM();
        }
    }

    void FuzzyOR::orWithDOM(double val) {
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            (*t)->orWithDOM(val);
        }
    }
}
