#include "RegulatorPID.h"

double RegulatorPID::symuluj(double setpoint, double measuredValue) {
    // Obliczenie uchybu
    double error = setpoint - measuredValue;

    // Sk³adowa proporcjonalna
    double uP = m_kP * error;

    // Sk³adowa ca³kuj¹ca
    m_sumError += error;
    double uI = m_kI * m_sumError;

    // Sk³adowa ró¿niczkuj¹ca
    double uD = m_kD * (error - m_prevError);

    // Aktualizacja poprzedniego uchybu
    m_prevError = error;

    // Sygna³ steruj¹cy
    double controlSignal = uP + uI + uD;

    // Wywo³anie modelu ARX, aby przetworzy³ sygna³ steruj¹cy
    return m_model.symuluj(controlSignal);
}
