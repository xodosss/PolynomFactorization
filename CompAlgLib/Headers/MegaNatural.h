#pragma once
#pragma once
#ifndef MEGA_NATURAL
#define MEGA_NATURAL

#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;
typedef unsigned char uchar;

class MegaNatural
{
public:
	MegaNatural();
	MegaNatural(const MegaNatural &ob);
	MegaNatural(string str);
	MegaNatural(unsigned long long l);
	~MegaNatural();

	friend bool operator ==(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator !=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >(const MegaNatural &ob1, const MegaNatural &ob2);

	MegaNatural& operator =(const MegaNatural &ob);
	friend MegaNatural operator +(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator -(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator /(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator %(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator *(const MegaNatural &ob1, const MegaNatural &ob2);

	string toString();
	friend ostream& operator<<(ostream &os, MegaNatural &ob);
private:
	deque<uchar> nums;

	MegaNatural mulByK(uchar k);
	void mulByTenPowK(long long k);
};

#endif