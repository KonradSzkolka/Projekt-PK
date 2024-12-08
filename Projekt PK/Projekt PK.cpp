#include "Projekt PK.h"
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"
#include <thread>
#include <chrono>

#ifdef MAINPROJEKTU

//constexpr size_t ITERATIONS = 100;

int main() 
{
    bool nadane = true;
    std::vector<double> A;
    std::vector<double> B;
    double pomocnicza = 0;
    int czykoniecDanych = 1;
    double wartoscZadana = 0;

    size_t delay = 1;
    double noiseStdDev = 0.01;
    double kP = 0.5;
    double kI = 0.1;
    double kD = 0.05;
    size_t liczbaIteracji = 100;

    while (true)
    {
        if (nadane)
        {
            cout << "Jaki chcesz wynik? \t";
            cin >> wartoscZadana;
        }
        while (nadane)
        {
            cout << "Jaka wartosc A:\t";
            cin >> pomocnicza;
            A.push_back(pomocnicza);
            cout << "Jaka wartosc B:\t";
            cin >> pomocnicza;
            B.push_back(pomocnicza);
            cout << "Wszystkie wartosci? ( 1 - tak, 0 - nie)\t";
            cin >> czykoniecDanych;
            if (czykoniecDanych == 1)
            {
                nadane = false;
            }

        }
        // Konfiguracja modelu wejściowego
        ModelWejscia modelWejscia(A, B, delay, noiseStdDev, &wartoscZadana);

        // Konfiguracja regulatora PID

        RegulatorPID regulatorPID(modelWejscia.getModel(), kP, kI, kD);

        // Konfiguracja sprzężenia zwrotnego
        SprzezenieZwrotne sprzezenieZwrotne(*modelWejscia.getModel(), modelWejscia, regulatorPID);

        // Symulacja
        double wynik = sprzezenieZwrotne.symuluj(liczbaIteracji);

        cout << "Koncowa wartosc wyjsciowa: " << wynik << endl;
        nadane = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    /*
    // Konfiguracja modelu ARX
    std::vector<double> A = { -0.4 };
    std::vector<double> B = { 0.6 };
    size_t delay = 1;
    double noiseStdDev = 0.01;

    ModelARX modelARX(A, B, delay, noiseStdDev);

    // Konfiguracja modelu wejściowego
    double wartoscZadana = 50;
    ModelWejscia modelWejscia(A, B, delay, noiseStdDev, &wartoscZadana);

    // Konfiguracja regulatora PID
    double kP = 0.5;
    double kI = 0.1;
    double kD = 0.05;
    RegulatorPID regulatorPID(modelARX, kP, kI, kD);

    // Konfiguracja sprzężenia zwrotnego
    SprzezenieZwrotne sprzezenieZwrotne(modelARX, modelWejscia, regulatorPID);

    // Symulacja
    size_t liczbaIteracji = 100;
    double wynik = sprzezenieZwrotne.symuluj(wartoscZadana, liczbaIteracji);

    std::cout << "Koncowa wartosc wyjsciowa: " << wynik << std::endl;
    */

    /*vector<double> A = { -0.4,0.3,0.2,0.1 };
    vector<double> B = { 0.6,0.7,0.8,0.9 };
    size_t opuznienie = 1;
    double odchyl = 0.01;
    ModelWejscia wejscie(A, B, opuznienie, odchyl, nullptr);
    for (size_t i = 0; i < 100; i++)
    {
        cout << "symulacja: " << i + 1 << ". wynik: " << wejscie.oblicz(B[i % B.size()]) << "\n";
    }*/

    /*
    // Konfiguracja modelu ARX
    std::vector<double> A = { -0.4 };
    std::vector<double> B = { 0.6 };
    size_t delay = 1;
    double noiseStdDev = 0.01;

    ModelARX model(A, B, delay, noiseStdDev);

    // Konfiguracja regulatora PID
    double kP = 0.5;
    double kI = 0.1;
    double kD = 0.05;
    RegulatorPID pid(model, kP, kI, kD);

    // Symulacja
    constexpr size_t ITERATIONS = 100;
    double setpoint = 1.0;  // Wartość zadana
    double measuredValue = 0.0; // Początkowa wartość regulowana

    for (size_t i = 0; i < ITERATIONS; ++i) {
        measuredValue = pid.symuluj(setpoint, measuredValue);
        std::cout << "Iteracja: " << i << ", Wartość regulowana: " << measuredValue << std::endl;
    }
    */
}

#endif // MAINPROJEKTU