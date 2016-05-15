#pragma once
#ifndef MEGA_INTEGER
#define MEGA_INTEGER

#include "MegaNatural.h"

class MegaInteger
{
public:
	MegaInteger();
	MegaInteger(const MegaNatural &ob);
	MegaInteger(const MegaInteger &ob);
	MegaInteger(long long a);
	MegaInteger(string);
	~MegaInteger();

	MegaInteger abs() const;
	MegaNatural toMegaNatural();

	MegaInteger& operator =(const MegaInteger &ob);

	friend bool operator ==(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator!=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >=(const MegaInteger &ob1, const MegaInteger &ob2);

	friend MegaInteger operator %(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator *(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator /(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator +(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator -(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator -(const MegaInteger &ob);

	vector <MegaInteger> dividers();

	string toString();
	friend ostream& operator<<(ostream &os, MegaInteger &ob);
private:
	MegaNatural num;
	bool isNegative;
};

#endif