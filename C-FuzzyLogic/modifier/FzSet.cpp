#include "FzSet.h"

namespace modifier
{
	using rules::FuzzyTerm;
	using variables::FuzzySet;

	FzSet::FzSet(FuzzySet *set)
	{
		this->set = set;
		this->mod = NORMAL;
	}

	FzSet::FzSet(FuzzySet *set, Modifier mod)
	{
		this->set = set;
		this->mod = mod;
	}

	FzSet *FzSet::fairly()
	{
		return new FzSet(set, FAIRLY);
	}

	FzSet *FzSet::very()
	{
		return new FzSet(set, VERY);
	}

	double FzSet::getDOM()
	{
		switch (mod)
		{
			case NORMAL:
				return set->getDOM();
			case VERY:
				return sqrt(set->getDOM());
			case FAIRLY:
				return pow(set->getDOM(), 2);
		}
		return -1;
	}

	void FzSet::clearDOM()
	{
		set->clearDOM();
	}

	void FzSet::orWithDOM(double val)
	{
		set->orWithDOM(val);
	}

}
