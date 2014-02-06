#pragma once

#include "../rules/FuzzyTerm.h"
#include "../variables/FuzzySet.h"
#include "Modifier.h"
#include <cmath>

namespace modifier {

using rules::FuzzyTerm;
using variables::FuzzySet;

class FzSet: public FuzzyTerm {

public:
	FuzzySet *set;
	Modifier mod;
	FzSet(FuzzySet *set);
	FzSet(FuzzySet *set, Modifier mod);
	virtual FzSet *fairly();
	virtual FzSet *very();
	virtual double getDOM();
	virtual void clearDOM();
	virtual void orWithDOM(double val);
	//
	//    public static void main(String arg[]) throws FunctionException {
	//        FuzzySet fs = new FuzzySet("LOL", new TriangularMembershipFunction(10, 50));
	//        fs.orWithDOM(30);
	//        System.out.println(fs.getDOM());
	//        FzSet fz = new FzSet(fs);
	//        System.out.println(fz.getDOM());
	//    }


};

}
