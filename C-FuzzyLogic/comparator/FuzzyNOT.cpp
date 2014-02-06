#include "FuzzyNOT.h"

namespace comparator
{
	using rules::FuzzyTerm;

	FuzzyNOT::FuzzyNOT(FuzzyTerm *term)
	{
		this->term = term;
	}

	double FuzzyNOT::getDOM()
	{
		return 1 - term->getDOM();
	}

	void FuzzyNOT::clearDOM()
	{
		term->clearDOM();
	}

	void FuzzyNOT::orWithDOM(double val)
	{
		term->orWithDOM(val);
	}
}
