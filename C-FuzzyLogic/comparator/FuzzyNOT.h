#pragma once

#include "../rules/FuzzyTerm.h"

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
namespace comparator
{

	using rules::FuzzyTerm;



	/// 
	/// <summary>
	/// @author Root
	/// </summary>
	class FuzzyNOT : public FuzzyTerm
	{

	public:
		FuzzyTerm *term;

		FuzzyNOT(FuzzyTerm *term);

		virtual double getDOM();

		virtual void clearDOM();

		virtual void orWithDOM(double val);
	};

}
