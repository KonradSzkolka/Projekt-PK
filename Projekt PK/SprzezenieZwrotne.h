#pragma once
#include "ModelARX.h"
//#include "ModelWejscia.h"
#include "RegulatorPID.h"

class SprzezenieZwrotne {
private:
    ModelARX& modelARX;        // Referencja do modelu ARX
    ModelWejscia& modelWejscia; // Referencja do modelu wejściowego
    RegulatorPID& regulatorPID; // Referencja do regulatora PID

public:
    SprzezenieZwrotne(ModelARX& arx, ModelWejscia& wejscie, RegulatorPID& pid)
        : modelARX(arx), modelWejscia(wejscie), regulatorPID(pid) {}

    ~SprzezenieZwrotne() {}

    double symuluj(double wartoscZadana, size_t liczbaIteracji);
};
