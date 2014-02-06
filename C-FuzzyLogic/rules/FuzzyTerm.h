#pragma once

namespace rules {
    class FuzzyTerm {
        public:
            virtual double getDOM() = 0;
            virtual void clearDOM() = 0;
            virtual void orWithDOM(double val) = 0;
    };
}
