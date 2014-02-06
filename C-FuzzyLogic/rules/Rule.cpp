#include "Rule.h"

namespace rules
{

	Rule::Rule(FuzzyTerm *antecedent, FuzzyTerm *consequent)
	{
		this->antecedent = antecedent;
		this->consequent = consequent;
	}

	void Rule::calculate()
	{
		//System.out.println("RULE "+antecedent.getDOM());
		consequent->orWithDOM(getAntecedent()->getDOM());
	}

	FuzzyTerm *Rule::getAntecedent()
	{
		return antecedent;
	}

	void Rule::setAntecedent(FuzzyTerm *antecedent)
	{
		this->antecedent = antecedent;
	}

	FuzzyTerm *Rule::getConsequent()
	{
		return consequent;
	}

	void Rule::setConsequent(FuzzyTerm *consequent)
	{
		this->consequent = consequent;
	}
}
