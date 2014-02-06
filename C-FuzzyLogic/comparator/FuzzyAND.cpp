#include "FuzzyAND.h"

namespace comparator {
    using rules::FuzzyTerm;

    FuzzyAND::FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
    }

    FuzzyAND::FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
        terms.push_back(termC);
    }

    FuzzyAND::FuzzyAND(FuzzyTerm *termA, FuzzyTerm *termB, FuzzyTerm *termC, FuzzyTerm *termD) {
        terms = std::vector<FuzzyTerm*>();
        terms.push_back(termA);
        terms.push_back(termB);
        terms.push_back(termC);
        terms.push_back(termD);
    }

    double FuzzyAND::getDOM() {
        double minDOM = std::numeric_limits<double>::infinity();
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            //cout<<"AND: "+t.getDOM();
            if ((*t)->getDOM() < minDOM) {
                minDOM = (*t)->getDOM();
            }
        }
        //cout<<"ANDRESULT: "+minDOM;
        return minDOM;
    }

    void FuzzyAND::clearDOM() {
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            (*t)->clearDOM();
        }
    }

    void FuzzyAND::orWithDOM(double val) {
        for (std::vector<FuzzyTerm*>::const_iterator t = terms.begin(); t != terms.end(); ++t) {
            (*t)->orWithDOM(val);
        }
    }
}
