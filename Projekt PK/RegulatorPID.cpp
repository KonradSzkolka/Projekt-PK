#include "RegulatorPID.h"

double RegulatorPID::symuluj(double wartosczadana, double aktualnawartosc) {
    // Obliczenie uchybu
    double uchyb = wartosczadana - aktualnawartosc;

    // Sk³adowa proporcjonalna
    double uP = m_kP * uchyb;

    // Sk³adowa ca³kuj¹ca
    m_sumuchyb += uchyb;
    double uI = m_kI * m_sumuchyb;

    // Sk³adowa ró¿niczkuj¹ca
    double uD = m_kD * (uchyb - m_poprzedniuchyb);

    // Aktualizacja poprzedniego uchybu
    m_poprzedniuchyb = uchyb;

    // Sygna³ steruj¹cy
    double sygnal = uP + uI + uD;

    // Wywo³anie modelu ARX, aby przetworzy³ sygna³ steruj¹cy
    return m_model->symuluj(sygnal);
}
