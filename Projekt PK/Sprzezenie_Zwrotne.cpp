#include "Sprzezenie_Zwrotne.h"

double SprzezenieZwrotne::symuluj(size_t liczbaIteracji) {
    double aktualnaWartosc = 0.0;
    double sterowanie = 0.0;
    double wartoscZadana = *(modelWejscia.getChceWynik());

    for (size_t i = 0; i < liczbaIteracji; ++i) {
        // Oblicz sygna� steruj�cy za pomoc� regulatora PID
        sterowanie = regulatorPID.symuluj(wartoscZadana, aktualnaWartosc);

        // Symuluj model ARX z wygenerowanym sterowaniem
        aktualnaWartosc = modelARX.symuluj(sterowanie);

        cerr << "Iteracja: " << i+1
            << ", Wartosc zadana: " << wartoscZadana
            << ", Aktualna wartosc: " << aktualnaWartosc
            << ", Sygnal sterujacy: " << sterowanie << endl;

        //zegar opu�nie�
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return aktualnaWartosc; // Zwr�� ko�cow� warto�� wyj�ciow�
}
