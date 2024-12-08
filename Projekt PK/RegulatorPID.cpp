#include "RegulatorPID.h"

double RegulatorPID::symuluj(double wartosczadana, double aktualnawartosc) {
    // Obliczenie uchybu
    double uchyb = wartosczadana - aktualnawartosc;

    // Sk�adowa proporcjonalna
    double uP = m_kP * uchyb;

    // Sk�adowa ca�kuj�ca
    m_sumuchyb += uchyb;
    double uI = m_kI * m_sumuchyb;

    // Sk�adowa r�niczkuj�ca
    double uD = m_kD * (uchyb - m_poprzedniuchyb);

    // Aktualizacja poprzedniego uchybu
    m_poprzedniuchyb = uchyb;

    // Sygna� steruj�cy
    double sygnal = uP + uI + uD;

    // Wywo�anie modelu ARX, aby przetworzy� sygna� steruj�cy
    return m_model->symuluj(sygnal);
}
