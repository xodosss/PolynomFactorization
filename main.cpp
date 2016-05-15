#include "PolynomZ.h"
#include "Functions.h"
#include "GUI.h"
using namespace func;
using namespace std;

int main()
{
	const long cfs[] = { 5, 10, 15, 20, -1, 1, 1, 10, 1, 0, 0, 0, 25 };
	Polynom p(cfs, 4);
	PolynomZ pz(p);

	cout << pz << " = ";
	outputFactorization(pz.squaresFreeFact());

	cout << endl;
	system("pause");
	return 0;
}
