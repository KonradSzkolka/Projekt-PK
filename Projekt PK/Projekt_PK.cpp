#include "Projekt_PK.h"
#include "Model_ARX.h"
#include "Regulator_PID.h"
#include "Sprzezenie_Zwrotne.h"


#ifdef MAINPROJEKTU

constexpr size_t liczbaIteracji = 100;
constexpr size_t opuznienie = 1;

int main() 
{
    std::vector<double> A;
    std::vector<double> B;

    bool nadane = true;
    int czykoniecDanych = 1;

    double pomocnicza = 0;
    double wartoscZadana = 0;
    double szum = 0.01;
    double kP = 0.5;
    double kI = 0.1;
    double kD = 0.05;

    while (true)
    {
        if (nadane)
        {
            cout << "\nJaki chcesz wynik? \t";
            cin >> wartoscZadana;
        }
        while (nadane)
        {
            cout << "Jaka wartosc A przedzial(-1,1):\t";
            cin >> pomocnicza;

            if(pomocnicza>-1 && pomocnicza<1)
                A.push_back(pomocnicza);
            else
            {
                A.push_back(0.4);
                cerr << "\npodales za duza wartosc ustawiam 0.4\n";
            }
            cout << "Jaka wartosc B przedzial(-1,1):\t";
            cin >> pomocnicza;

            if (pomocnicza > -1 && pomocnicza < 1)
                B.push_back(pomocnicza);
            else
            {
                B.push_back(0.6);
                cerr << "\npodales za duza wartosc ustawiam 0.6\n";
            }

            cout << "Wszystkie wartosci? ( 1 - tak, 0 - nie)\t";
            cin >> czykoniecDanych;
            if (czykoniecDanych == 1)
            {
                nadane = false;
            }

        }
        ModelWejscia modelWejscia(A, B, opuznienie, szum, &wartoscZadana);

        RegulatorPID regulatorPID(modelWejscia.getModel(), kP, kI, kD);

        SprzezenieZwrotne sprzezenieZwrotne(*modelWejscia.getModel(), modelWejscia, regulatorPID);

        // Symulacja
        double wynik = sprzezenieZwrotne.symuluj(liczbaIteracji);

        cout << "Koncowa wartosc wyjsciowa: " << wynik << endl;
        nadane = true;
    }
}

#endif // MAINPROJEKTU