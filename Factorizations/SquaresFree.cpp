#include "PolynomZ.h"
#include "Functions.h"

vector <pair <Polynom, long long>> PolynomZ::squaresFreeFact()
{
	PolynomZ p = *this;
	vector <pair <Polynom, long long>> multipliers;
	if (p.reduceCoef() != MegaRational(1))
	{
		MegaRational mr[] = { p.reduceCoef() };
		multipliers.push_back({ Polynom(mr, 1), 1 });
		p = p.reduce();
	}

	Polynom
		r = func::gcdP(p, p.fluxion()).reduce(),
		t = p / r;
	long long i = 1;

	while (r.getDegree() != 0)
	{
		Polynom v = func::gcdP(r, t);
		if ((t / v).getDegree() != 0)
			multipliers.push_back({ (t / v).reduce(), i });
		r = r / v;
		t = v;
		i++;
	}
	
	multipliers.push_back({ t.reduce(), i });
	
	return multipliers;
}