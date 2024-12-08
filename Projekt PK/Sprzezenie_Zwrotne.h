#pragma once

#include "Model_ARX.h"
#include "Regulator_PID.h"

class SprzezenieZwrotne {
private:
    ModelARX& modelARX;        
    ModelWejscia& modelWejscia; 
    RegulatorPID& regulatorPID; 

public:
    SprzezenieZwrotne(ModelARX& arx, ModelWejscia& wejscie, RegulatorPID& pid)
        : modelARX(arx), modelWejscia(wejscie), regulatorPID(pid) {}

    ~SprzezenieZwrotne() {}

    double symuluj(size_t liczbaIteracji);
};
