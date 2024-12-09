#include "Projekt_PK.h"
#include "Model_ARX.h"
#include "Regulator_PID.h"
#include "Sprzezenie_Zwrotne.h"

#ifdef TESTUKLADU

void testDLaMalychWspolczynnikow()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.8, 0.5, 0.2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik -wartzad) < 0.0001)
		cerr << "\nMale wspolczynniki OK!!!\n";
	else
		cerr << "\nMale wspolczynniki FAIL!!!\n";
}

void testDLaduzychWartPID()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 10;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 2, 2, 2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nInnych wart PID OK!!!\n";
	else
		cerr << "\nInnych wart PID FAIL!!!\n";
}

void testDlaMalychWartPID()
{
	vector<double> a = { 0.3, -0.1 };
	vector<double> b = { 0.7, 0.4 };
	size_t opuzn = 2;
	double wartzad = 10.0;

	ModelWejscia MW(a, b, opuzn, 0.02, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.1, 0.05, 0.01);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nRozne PID OK!!!\n";
	else
		cerr << "\nRozne PID FAIL!!!\n";
}

void testDLaWiecejA()
{
	vector<double> a = { 0.4,-0.4,0.1,-0.1 };
	vector<double> b = { 0.6 };
	size_t opuzn = 1;
	double wartzad = 4.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.8, 0.5, 0.2);
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
	double wartzad = 50.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.8, 0.5, 0.2);
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
	double wartzad = 9.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.8, 0.5, 0.2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nTyle samo AiB OK!!!\n";
	else
		cerr << "\nTyle samo AiB FAIL!!!\n";
}
void testDlaDuzegoOpoznienia()
{
	vector<double> a = { 0.4 };
	vector<double> b = { 0.6 };
	size_t opuzn = 10; // Du¿e opóŸnienie
	double wartzad = 5.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.5, 0.2, 0.1);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nDuze opoznienie OK!!!\n";
	else
		cerr << "\nDuze opoznienie FAIL!!!\n";
}

void testDlaZerowegoOpoznienia()
{
	vector<double> a = { 0.3, -0.2 };
	vector<double> b = { 0.5, 0.4 };
	size_t opuzn = 0;
	double wartzad = 1.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 0.6, 0.3, 0.2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nMale opoznienie OK!!!\n";
	else
		cerr << "\nMale opoznienie FAIL!!!\n";
}

void testDlaBrakuSzumow()
{
	vector<double> a = { 0.4, -0.2 };
	vector<double> b = { 0.5, 0.3 };
	size_t opuzn = 1;
	double wartzad = 2.0;

	ModelWejscia MW(a, b, opuzn, 0.0, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1.0, 0.5, 0.2);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(100);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nBrak szumow OK!!!\n";
	else
		cerr << "\nBrak szumow FAIL!!!\n";
}

void testDlaDuzejLiczbyIteracji()
{
	vector<double> a = { 0.4, -0.3 };
	vector<double> b = { 0.6, 0.2 };
	size_t opuzn = 1;
	double wartzad = 10.0;

	ModelWejscia MW(a, b, opuzn, 0.01, &wartzad);
	RegulatorPID RPID(MW.getModel(), 1.0, 0.8, 0.4);
	SprzezenieZwrotne SPRZ(*MW.getModel(), MW, RPID);
	double wynik = SPRZ.symuluj(1000);
	cerr << wynik;
	if (abs(wynik - wartzad) < 0.0001)
		cerr << "\nDuza liczba iteracji OK!!!\n";
	else
		cerr << "\nDuza liczba iteracji FAIL!!!\n";
}

int main()
{
	testDLaMalychWspolczynnikow();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDLaduzychWartPID();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDlaMalychWartPID();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDLaWiecejA();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDLaWiecejB();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDLaTyleSamoAiB();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDlaDuzegoOpoznienia();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDlaZerowegoOpoznienia();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDlaBrakuSzumow();
	this_thread::sleep_for(chrono::milliseconds(2000));

	testDlaDuzejLiczbyIteracji();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

#endif // TESTUKLADU
