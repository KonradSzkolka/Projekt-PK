#include "Sprzezenie_Zwrotne.h"

double SprzezenieZwrotne::symuluj(size_t liczbaIteracji) {
    double aktualnaWartosc = 0.0;
    double sterowanie = 0.0;
    double wartoscZadana = *(modelWejscia.getChceWynik());

    for (size_t i = 0; i < liczbaIteracji; ++i) {
        // Oblicz sygna³ steruj¹cy za pomoc¹ regulatora PID
        sterowanie = regulatorPID.symuluj(wartoscZadana, aktualnaWartosc);

        // Symuluj model ARX z wygenerowanym sterowaniem
        aktualnaWartosc = modelARX.symuluj(sterowanie);

        cerr << "Iteracja: " << i+1
            << ", Wartosc zadana: " << wartoscZadana
            << ", Aktualna wartosc: " << aktualnaWartosc
            << ", Sygnal sterujacy: " << sterowanie << endl;

        //zegar opuŸnieñ
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return aktualnaWartosc; // Zwróæ koñcow¹ wartoœæ wyjœciow¹
}
