#include "SprzezenieZwrotne.h"

double SprzezenieZwrotne::symuluj(double wartoscZadana, size_t liczbaIteracji) {
    double aktualnaWartosc = 0.0; // Aktualna warto�� wyj�ciowa modelu ARX
    double sterowanie = 0.0;      // Sygna� steruj�cy wygenerowany przez regulator PID

    // Przypisanie warto�ci zadanej w modelu wej�ciowym
    modelWejscia.setChceWynik(&wartoscZadana);

    // Symulacja w p�tli
    for (size_t i = 0; i < liczbaIteracji; ++i) {
        // Pobierz warto�� zadan� z modelu wej�ciowego
        double warto��Zadana = *(modelWejscia.getChceWynik());

        // Oblicz sygna� steruj�cy za pomoc� regulatora PID
        sterowanie = regulatorPID.symuluj(warto��Zadana, aktualnaWartosc);

        // Symuluj model ARX z wygenerowanym sterowaniem
        aktualnaWartosc = modelARX.symuluj(sterowanie);

        // Debug: wypisz aktualny stan
        std::cerr << "Iteracja: " << i
            << ", Wartosc zadana: " << warto��Zadana
            << ", Aktualna wartosc: " << aktualnaWartosc
            << ", Sygnal sterujacy: " << sterowanie << std::endl;
    }

    return aktualnaWartosc; // Zwr�� ko�cow� warto�� wyj�ciow�
}
