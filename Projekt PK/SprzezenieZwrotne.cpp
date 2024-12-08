#include "SprzezenieZwrotne.h"

double SprzezenieZwrotne::symuluj(size_t liczbaIteracji) {
    double aktualnaWartosc = 0.0;
    double sterowanie = 0.0;
    double wartoscZadana = *(modelWejscia.getChceWynik());

    for (size_t i = 0; i < liczbaIteracji; ++i) {
        // Pobierz wartoœæ zadan¹ z modelu wejœciowego

        // Oblicz sygna³ steruj¹cy za pomoc¹ regulatora PID
        sterowanie = regulatorPID.symuluj(wartoscZadana, aktualnaWartosc);

        // Symuluj model ARX z wygenerowanym sterowaniem
        aktualnaWartosc = modelARX.symuluj(sterowanie);

        // Debug: wypisz aktualny stan
        std::cerr << "Iteracja: " << i+1
            << ", Wartosc zadana: " << wartoscZadana
            << ", Aktualna wartosc: " << aktualnaWartosc
            << ", Sygnal sterujacy: " << sterowanie << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return aktualnaWartosc; // Zwróæ koñcow¹ wartoœæ wyjœciow¹
}
