#ifndef FUNCTIONS
#define FUNCTIONS

#include "MegaNatural.h"
#include "Polynom.h"

namespace func
{
	MegaNatural gcd(const MegaNatural &a, const MegaNatural &b);
	MegaNatural lcm(const MegaNatural &a, const MegaNatural &b);
	Polynom gcdP(const Polynom &a, const Polynom &b);
}

#endif