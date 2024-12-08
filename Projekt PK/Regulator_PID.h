#pragma once

#include "Projekt_PK.h"
#include "Model_ARX.h"

class RegulatorPID {
private:
    double m_kP;  // Wzmocnienie proporcjonalne
    double m_kI;  // Sta³a ca³kowania
    double m_kD;  // Sta³a ró¿niczkowania
    double m_sumuchyb;
    double m_poprzedniuchyb; 

    ModelARX* m_model; 

public:
    RegulatorPID(ModelARX* model, double kP, double kI = 0.0, double kD = 0.0)
        : m_model(model), m_kP(kP), m_kI(kI), m_kD(kD), m_sumuchyb(0.0), m_poprzedniuchyb(0.0) {
    }

    ~RegulatorPID() {}

    double symuluj(double wartosczadana, double aktualnawartosc);
};