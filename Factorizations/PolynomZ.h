#pragma once
#pragma once
#ifndef POLYNOM_Z
#define POLYNOM_Z

#include "Polynom.h"

class PolynomZ : public Polynom
{
public:
	PolynomZ(const Polynom &ob);
	~PolynomZ();

	vector <pair <Polynom, long long>> algebraicFact();
	vector <pair <Polynom, long long>> kroneckerFact();
	vector <pair <Polynom, long long>> squaresFreeFact();
};

#endif