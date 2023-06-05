// Plik nagłówkowy TablicaDynamiczna.h zawiera deklaracje klasy TablicaDynamiczna, która umożliwia tworzenie tablicy dynamicznej o rozmiarze określonym przez użytkownika.

#include <string>
#include "TablicaDynamiczna.h" // włączenie pliku nagłówkowego TablicaDynamiczna.h
#include <iostream>

TablicaDynamiczna::TablicaDynamiczna() {
    this->rozmiar_tablic = 0; // ustawienie początkowego rozmiaru tablicy na 0
    this->wsk = nullptr; // ustawienie wskaźnika na nullptr, gdyż tablica jeszcze nie istnieje
}

// Metoda dodająca nowy element do tablicy w wybranym przez użytkownika miejscu
void TablicaDynamiczna::dodaj_dane(int wybor_elementu, int nowy_element) {
    this->rozmiar_tablic = rozmiar_tablic + 1;
    if (wybor_elementu <= 0) {
        wybor_elementu = 0;
    } else if (wybor_elementu >= this->rozmiar_tablic - 1) {
        wybor_elementu = rozmiar_tablic - 1;
    }
    int helper = 0; // zmienna pomocnicza do przechodzenia po tablicy
    // zwiększenie rozmiaru tablicy o 1
    int *temp = new int[this->rozmiar_tablic]; // alokacja pamięci dla nowej, większej tablicy
    for (int i = 0; i < this->rozmiar_tablic; i++) {
        if (i == wybor_elementu) {
            temp[i] = nowy_element; // jeśli i równe jest wybor_elementu, to wstawiamy nowy_element do tablicy
            helper--; // zmniejszenie zmiennej pomocniczej, aby nadal odwoływać się do odpowiedniego miejsca w tablicy wsk
        } else {
            temp[i] = wsk[helper]; // w przeciwnym razie przepisujemy wartości z wsk do temp
        }
        helper++; // inkrementacja zmiennej pomocniczej
    }
    delete[] wsk; // zwolnienie pamięci zajmowanej przez poprzednią tablicę
    wsk = temp; // przypisanie wskaźnikowi wsk adresu nowej tablicy
}

// Metoda usuwająca wybrany przez użytkownika element z tablicy
void TablicaDynamiczna::usun_dane(int wybor_elementu) {
    int helper = 0; // zmienna pomocnicza do przechodzenia po tablicy
    this->rozmiar_tablic = rozmiar_tablic - 1; // zmniejszenie rozmiaru tablicy o 1
    if (wybor_elementu <= 0) {
        wybor_elementu = 0;
    } else if (wybor_elementu >= this->rozmiar_tablic - 1) {
        wybor_elementu = rozmiar_tablic - 1;
    }
    int *temp = new int[this->rozmiar_tablic]; // alokacja pamięci dla nowej, mniejszej tablicy
    for (int i = 0; i < this->rozmiar_tablic; i++) {
        if (i == wybor_elementu) {
            helper++; // jeśli i równe jest wybor_elementu, to pomijamy wartość wsk[helper] i inkrementujemy zmienną pomocniczą
        }
        temp[i] = wsk[helper]; // przepisanie wartości z wsk do temp
        helper++; // inkrementacja zmiennej pomocniczej
    }
    delete[] wsk; // zwolnienie pamięci zajmowanej
    wsk = temp;
}

// Metoda zwracająca rozmiar tablicy
int TablicaDynamiczna::dostanRozmiar() {
    return this->rozmiar_tablic;
}

// Metoda wyświetlająca elementy tablicy
int TablicaDynamiczna::dostanTablice() {
    std::cout << "Twoja tablica: " << std::endl;
    for (int i = 0; i < this->rozmiar_tablic; i++) {
        std::cout << wsk[i] << " ";
    }
}

// Metoda zwracająca element o podanym indeksie
int TablicaDynamiczna::dostanElement(int dane) {
//        for(int i = 0; i < this->dostanRozmiar()-1; i++){
//            if(dane == wsk[i]){
//                std::cout << "Twoj szukany element ma index: " << i << std::endl;
//                return i;
//            }
//        }
//        return NULL;
    return wsk[dane];
}

int TablicaDynamiczna::dostanElement2(int dane) {
    for (int i = 0; i < this->dostanRozmiar() - 1; i++) {
        if (dane == wsk[i]) {
            std::cout << "Twoj szukany element ma index: " << i << std::endl;
            return i;
        }
    }
    return NULL;

}


// Metoda zamieniająca wartości dwóch elementów w tablicy
void TablicaDynamiczna::zamien_wartosci(int miejsca_pierwszego, int wartosc, int miejsce_drugiego, int druga_wartosc) {
    wsk[miejsca_pierwszego] = druga_wartosc;
    wsk[miejsce_drugiego] = wartosc;
}
