#include "Projekt PK.h"
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"

#ifdef MAINPROJEKTU

constexpr size_t ITERATIONS = 100;

int main() 
{

    // Konfiguracja modelu ARX
    std::vector<double> A = { -0.4 };
    std::vector<double> B = { 0.6 };
    size_t delay = 1;
    double noiseStdDev = 0.01;

    ModelARX modelARX(A, B, delay, noiseStdDev);

    // Konfiguracja modelu wejściowego
    double wartoscZadana = 1;
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