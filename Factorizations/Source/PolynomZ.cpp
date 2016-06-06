#include "PolynomZ.h"

PolynomZ::PolynomZ()
{
	coefficients.push_front(MegaRational());
}

PolynomZ::PolynomZ(const Polynom &ob)
{
	Polynom _ob = ob;
	coefficients.pop_back();
	for (int i = _ob.getDegree(); i >= 0; i--)
		coefficients.push_front(_ob.getCoef(i));
}

PolynomZ::~PolynomZ()
{

}
