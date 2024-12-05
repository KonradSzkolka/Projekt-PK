#include "Projekt PK.h"
#include <iostream>
#include "ModelARX.h"
#include "RegulatorPID.h"
#ifdef MAINPROJEKTU

int main() {
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

    return 0;
}

#endif // MAINPROJEKTU