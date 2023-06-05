// Początek pliku KopiecBinarny.cpp
// Created by Jakub on 01.03.2023.
//

#include <iostream>
#include "KopiecBinarny.h"

// Konstruktor klasy KopiecBinarny
KopiecBinarny::KopiecBinarny() {
    // Inicjalizacja zmiennej kopiecBinarny jako nowej pustej TablicyDynamicznej
    this->kopiecBinarny = new TablicaDynamiczna();
    // Inicjalizacja zmiennych cr, cl i cp jako pustych ciągów znaków reprezentujących kolejno prawe dziecko, lewe dziecko i ojca
    cr = "  ";
    cl = "  ";
    cp = "  ";
    // Ustawienie odpowiednich znaków ASCII dla ciągów cr, cl i cp, aby utworzyć strukturę drzewa binarnego
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
}

// Metoda dodająca nowy element do kopca binarnego
void KopiecBinarny::dodaj_element(int dane) {
    // Dodanie nowego elementu do końca tablicy przechowującej kopiec binarny
    kopiecBinarny->dodaj_dane(kopiecBinarny->dostanRozmiar(), dane);
    // Ustawienie indeksu pomocnika jako ostatniego elementu
    int pomocnik = kopiecBinarny->dostanRozmiar() - 1;
    // Ustawienie indeksu ojca pomocnika
    int indexOjca = (pomocnik - 1) / 2;
    // Pętla przesuwająca element na odpowiednie miejsce w kopcu binarnym, aż do momentu gdy nie będzie spełniony warunek kopca
    while (pomocnik > 0 && kopiecBinarny->dostanElement(indexOjca) > kopiecBinarny->dostanElement(pomocnik)) {
        // Zamiana miejscami wartości elementów na pozycjach pomocnika i jego ojca w kopcu binarnym
        kopiecBinarny->zamien_wartosci(indexOjca, kopiecBinarny->dostanElement(indexOjca), pomocnik, kopiecBinarny->dostanElement(pomocnik));
        // Przesunięcie indeksu pomocnika na pozycję ojca
        pomocnik = indexOjca;
        // Obliczenie nowego indeksu ojca dla aktualnej pozycji pomocnika
        indexOjca = (pomocnik - 1) / 2;
    }
}

// Funkcja usuwająca wierzchołek (najmniejszy element) z kopca binarnego
void KopiecBinarny::usun_szczyt() {
    int i, j, v;
    if (this->dostanRozmiar() > 0) {
        kopiecBinarny->zamien_wartosci(0, kopiecBinarny->dostanElement(1), kopiecBinarny->dostanRozmiar() - 1, kopiecBinarny->dostanElement(kopiecBinarny->dostanRozmiar() - 1));

        kopiecBinarny->usun_dane(kopiecBinarny->dostanRozmiar() - 1);
    }

    // Pobranie aktualnej liczby elementów kopca
    int n = kopiecBinarny->dostanRozmiar();
    // Sprawdzenie, czy kopiec nie jest pusty
    if (n > 0) {
        // Przypisanie wartości wierzchołka do zmiennej v
        v = kopiecBinarny->dostanElement(0);
        i = 0;
        j = 1;
        // Przeglądanie elementów kopca w celu ustalenia nowego wierzchołka
        while (j < n) {
            // Wybór mniejszego z dwóch synów wierzchołka
            if (j + 1 < n && kopiecBinarny->dostanElement(j + 1) < kopiecBinarny->dostanElement(j))
                j++;
            // Sprawdzenie, czy nowy wierzchołek jest większy niż v
            if (v <= kopiecBinarny->dostanElement(j))
                break;
            // Zamiana miejscami wierzchołków
            kopiecBinarny->zamien_wartosci(i, kopiecBinarny->dostanElement(i), j, kopiecBinarny->dostanElement(j));
            i = j;
            j = 2 * j + 1;
        }
        // Dodanie wartości v do nowego wierzchołka
        kopiecBinarny->wsk[i] = v;
    }
}

// Metoda zwracająca element kopca o indeksie "dane"
int KopiecBinarny::dostanElement(int dane) {
    for(int i = 0; i < this->kopiecBinarny->dostanRozmiar()-1; i++){
        if(dane == kopiecBinarny->wsk[i]){
            std::cout << "Szukany element ma index: " << i << std::endl;
            return i;
        }
    }
    return NULL;
}

// Metoda zwracająca rozmiar kopca
int KopiecBinarny::dostanRozmiar() {
    return this->kopiecBinarny->dostanRozmiar();
}


//Metod wyświeltająca kopiec
void KopiecBinarny::printBT(std::string sp, std::string sn, int v) {
    std::string s;

    if (v < kopiecBinarny->dostanRozmiar()) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << kopiecBinarny->dostanElement(v) << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, 2 * v + 1);
    }
}
