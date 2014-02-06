#pragma once

#include "FuzzyTerm.h"

namespace rules {

    class Rule {

        private:
            FuzzyTerm *antecedent;
            FuzzyTerm *consequent;
        public:
            Rule(FuzzyTerm *antecedent, FuzzyTerm *consequent);
            virtual void calculate();
            virtual FuzzyTerm *getAntecedent();
            virtual void setAntecedent(FuzzyTerm *antecedent);
            virtual FuzzyTerm *getConsequent();
            virtual void setConsequent(FuzzyTerm *consequent);
    };
}
