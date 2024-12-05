#include "RegulatorPID.h"

double RegulatorPID::symuluj(double setpoint, double measuredValue) {
    // Obliczenie uchybu
    double error = setpoint - measuredValue;

    // Sk�adowa proporcjonalna
    double uP = m_kP * error;

    // Sk�adowa ca�kuj�ca
    m_sumError += error;
    double uI = m_kI * m_sumError;

    // Sk�adowa r�niczkuj�ca
    double uD = m_kD * (error - m_prevError);

    // Aktualizacja poprzedniego uchybu
    m_prevError = error;

    // Sygna� steruj�cy
    double controlSignal = uP + uI + uD;

    // Wywo�anie modelu ARX, aby przetworzy� sygna� steruj�cy
    return m_model.symuluj(controlSignal);
}
