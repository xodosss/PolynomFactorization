#pragma once
#ifndef FACTORIZATION
#define FACTORIZATION

#include "PolynomZ.h"

using namespace std;

class Factorization
{
public:
	Factorization();
	Factorization(vector <pair <Polynom, long long>> ob);
	~Factorization();

	string toString();
private:
	vector <pair <Polynom, long long>> fact;
};

#endif