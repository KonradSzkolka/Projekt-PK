#pragma once

#include "Projekt PK.h"

#include "ModelARX.h"

class RegulatorPID {
private:
    double m_kP;  // Wzmocnienie proporcjonalne
    double m_kI;  // Sta�a ca�kowania
    double m_kD;  // Sta�a r�niczkowania
    double m_sumuchyb;  // Suma uchybu (cz�� ca�kuj�ca)
    double m_poprzedniuchyb; // Poprzedni uchyb (cz�� r�niczkuj�ca)
    ModelARX* m_model;  // Referencja do modelu ARX, sterowany przez regulator

public:
    RegulatorPID(ModelARX* model, double kP, double kI = 0.0, double kD = 0.0)
        : m_model(model), m_kP(kP), m_kI(kI), m_kD(kD), m_sumuchyb(0.0), m_poprzedniuchyb(0.0) {
    }

    ~RegulatorPID() {}

    double symuluj(double wartosczadana, double aktualnawartosc);
};