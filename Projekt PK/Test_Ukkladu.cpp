#include "Test_Ukkladu.h"

#ifdef TESTUKLADU

void testDLaMalychWspolczynnikow()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1, 1, 1);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(wartzad, 200);
	cerr << wynik;
	if (abs(wartzad - wynik) < 0.0001)
		cerr << "\nMale wspolczynniki OK!!!\n";
	else
		cerr << "\nMale wspolczynniki FAIL!!!\n";
}

int main()
{
	testDLaMalychWspolczynnikow();
}

#endif // TESTUKLADU
