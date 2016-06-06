#pragma once
#pragma once
#ifndef MEGA_RATIONAL
#define MEGA_RATIONAL

#include "MegaInteger.h"


class MegaRational
{
public:
	MegaRational();
	MegaRational(const MegaInteger &a);
	MegaRational(const MegaInteger &a, const MegaNatural &b);
	MegaRational(const MegaRational &a);
	MegaRational(string);
	~MegaRational();

	void reduction();
	bool isInteger();
	MegaInteger toMegaInteger();

	MegaRational& operator =(const MegaRational &ob);

	friend bool operator ==(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator !=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >=(const MegaRational &ob1, const MegaRational &ob2);

	friend MegaRational operator +(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator -(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator *(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator /(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator -(const MegaRational &ob);

	friend void toCommonDenominator(MegaRational &ob1, MegaRational &ob2);

	MegaNatural getDenominator();
	MegaInteger getNumerator();

	string toString();
private:
	MegaInteger numerator;
	MegaNatural denominator;
};

#endif