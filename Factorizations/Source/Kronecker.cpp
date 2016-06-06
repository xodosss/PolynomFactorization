#include "PolynomZ.h"

bool KroneckerGeneration(int pos, vector <MegaInteger> x, vector <vector <MegaInteger>> divs, Polynom *p, vector <pair <Polynom, long long>> *multipliers)
{
	if (pos == divs.size())
	{
		Polynom L;
		for (int i = 0; i < x.size(); i++)
		{
			MegaRational xt(1, 1), xm[] = { xt };
			Polynom tmp(xm, 1);
			for (int j = 0; j < x.size(); j++)
			{
				if (i != j)
				{
					MegaRational mr2(1, 1), mr1(-j), amr[] = { mr1, mr2 };
					Polynom l(amr, 2);
					tmp = tmp * l / MegaRational(i - j);
				}
			}
			L = L + tmp * x[i];
		}

		if (L.getDegree() >= 1 && (*p % L).toString() == "0")
		{
			L = L.reduce();
			*p = *p / L;
			if ((*multipliers).size() > 0)
				for (int k = (*multipliers).size() - 1; k >= 0; k--)
				{
					if ((*multipliers)[k].first == L)
					{
						(*multipliers)[k].second++;
						break;
					}
					else if (k == 0)
						(*multipliers).push_back({ L, 1 });
				}
			else
				(*multipliers).push_back({ L, 1 });
			return 1;
		}
	}
	else
	{
		for (int i = 0; i < divs[pos].size(); i++)
		{
			x[pos] = divs[pos][i];
			if (KroneckerGeneration(pos + 1, x, divs, p, multipliers))
				return 1;
		}
	}
	return 0;
}

vector <pair <Polynom, long long>> PolynomZ::kroneckerFact()
{
	PolynomZ p = *this;
	vector <pair <Polynom, long long>> multipliers;
	long m = floor(p.getDegree() / 2);
	vector <vector <MegaInteger>> divs;
	vector<MegaInteger> x;
	bool found;

	if (p.reduceCoef() != MegaRational(1))
	{
		MegaRational t[] = { p.reduceCoef() };
		multipliers.push_back({ Polynom(t, 1), 1 });
		p = p.reduce();
	}

	do
	{
		found = 0;
		m = floor(p.getDegree() / 2);
		for (int i = 2; i <= m + 1 && !found; i++)
		{
			divs.resize(i);
			x.resize(i);
			for (int j = 0; j < i; j++)
				divs[j] = p.setX(MegaInteger(j)).toMegaInteger().dividers();
			found = KroneckerGeneration(0, x, divs, &p, &multipliers);
		}
	} while (found);

	if (p.toString() != "1")
		if (multipliers.size() > 0)
			for (int k = multipliers.size() - 1; k >= 0; k--)
			{
				if (multipliers[k].first == p)
				{
					multipliers[k].second++;
					break;
				}
				else if (k == 0)
					multipliers.push_back({ p, 1 });
			}
		else
			multipliers.push_back({ p, 1 });

	return multipliers;
}