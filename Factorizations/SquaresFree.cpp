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
	long long
		i = 1;

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

	Polynom tmp = multipliers[0].first / multipliers[0].first;
	
	for (int i = 0; i < multipliers.size(); i++)
	{
		for (int j = 0; j < multipliers[i].second; j++)
			tmp = tmp * multipliers[i].first;
	}

	if (tmp != p)
	{
		multipliers.clear();
		multipliers.push_back({ p, 1 });
	}

	return multipliers;
}