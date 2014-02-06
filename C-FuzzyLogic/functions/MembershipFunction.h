#pragma once

namespace functions
{
	class MembershipFunction
	{
	public:
		virtual double getValue(double input) = 0;
		virtual double getClippedValue(double input, double clip) = 0;
		virtual double getMax() = 0;
		virtual double getMin() = 0;
	};
}
