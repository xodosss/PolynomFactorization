#pragma once
#pragma once
#ifndef POLYNOM
#define POLYNOM

#include "MegaRational.h"

class Polynom
{
public:
	Polynom();
	Polynom(const Polynom &ob);
	Polynom::Polynom(const MegaRational *coeffs, long degree);
	Polynom::Polynom(const long *coeffs, long degree);
	Polynom(const string str);
	~Polynom();

	friend bool operator ==(const Polynom &p1, const Polynom &p2);
	friend bool operator !=(const Polynom &p1, const Polynom &p2);

	Polynom &operator =(const Polynom &p);

	friend Polynom operator +(const Polynom &p1, const Polynom &p2);
	friend Polynom operator -(const Polynom &p1, const Polynom &p2);
	friend Polynom operator *(const Polynom &p, const MegaRational &a);
	friend Polynom operator /(const Polynom &p, const MegaRational &a);
	friend Polynom operator *(const Polynom &p1, const Polynom &p2);
	friend Polynom operator /(const Polynom &p1, const Polynom &p2);
	friend Polynom operator %(const Polynom &p1, const Polynom &p2);
	friend Polynom operator -(const Polynom &p);

	Polynom fluxion();
	Polynom reduce();
	MegaRational reduceCoef();

	long long getDegree();
	MegaRational Polynom::getCoef(const long &n);

	MegaRational setX(MegaRational x);

	string toString();
	friend ostream& operator<<(std::ostream &os, Polynom &ob);
protected:
	deque<MegaRational> coefficients;
	Polynom mulByXPowK(long long k);
};

#endif