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
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik -wartzad) < 0.0001)
		cerr << "\nMale wspolczynniki OK!!!\n";
	else
		cerr << "\nMale wspolczynniki FAIL!!!\n";
}

void testDLaInnychWartPID()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 10;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.8, 0.5, 0.2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nInnych wart PID OK!!!\n";
	else
		cerr << "\nInnych wart PID FAIL!!!\n";
}

void testDLaWiecejA()
{
	vector<double> a = { 0.4,-0.4,0.1,-0.1 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1, 1, 1);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nWiecej A OK!!!\n";
	else
		cerr << "\nWiecej A FAIL!!!\n";
}
void testDLaWiecejB()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6,0.5,0.4,0.3 };
	size_t opuzn = 1;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1, 1, 1);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nWiecej B OK!!!\n";
	else
		cerr << "\nWiecej B FAIL!!!\n";
}
void testDLaTyleSamoAiB()
{
	vector<double> a = { 0.4,-0.4,0.1,-0.1 };
	vector<double> b = { 0.6,0.5,0.4,0.3 };
	size_t opuzn = 1;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1, 1, 1);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nTyle samo AiB OK!!!\n";
	else
		cerr << "\nTyle samo AiB FAIL!!!\n";
}
int main()
{
	testDLaMalychWspolczynnikow();
	testDLaInnychWartPID();
	testDLaWiecejA();
	testDLaWiecejB();
	testDLaTyleSamoAiB();
}

#endif // TESTUKLADU
