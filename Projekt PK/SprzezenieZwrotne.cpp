#include "SprzezenieZwrotne.h"

double SprzezenieZwrotne::symuluj(double wartoscZadana, size_t liczbaIteracji) {
    double aktualnaWartosc = 0.0; // Aktualna wartoœæ wyjœciowa modelu ARX
    double sterowanie = 0.0;      // Sygna³ steruj¹cy wygenerowany przez regulator PID

    // Przypisanie wartoœci zadanej w modelu wejœciowym
    modelWejscia.setChceWynik(&wartoscZadana);

    // Symulacja w pêtli
    for (size_t i = 0; i < liczbaIteracji; ++i) {
        // Pobierz wartoœæ zadan¹ z modelu wejœciowego
        double wartoœæZadana = *(modelWejscia.getChceWynik());

        // Oblicz sygna³ steruj¹cy za pomoc¹ regulatora PID
        sterowanie = regulatorPID.symuluj(wartoœæZadana, aktualnaWartosc);

        // Symuluj model ARX z wygenerowanym sterowaniem
        aktualnaWartosc = modelARX.symuluj(sterowanie);

        // Debug: wypisz aktualny stan
        std::cerr << "Iteracja: " << i
            << ", Wartosc zadana: " << wartoœæZadana
            << ", Aktualna wartosc: " << aktualnaWartosc
            << ", Sygnal sterujacy: " << sterowanie << std::endl;
    }

    return aktualnaWartosc; // Zwróæ koñcow¹ wartoœæ wyjœciow¹
}
