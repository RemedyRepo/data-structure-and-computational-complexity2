//
// Created by Jakub on 01.03.2023.
//
#include "../Tablica Dynamiczna/TablicaDynamiczna.h"
#ifndef MENU_KOPIECBINARNY_H
#define MENU_KOPIECBINARNY_H
#include "string"

class KopiecBinarny {
public:
    KopiecBinarny();
    TablicaDynamiczna *kopiecBinarny;
    void usun_szczyt();
    void dodaj_element(int dane);
    int dostanElement(int dane);
    int dostanRozmiar();
    void printBT(std::string sp, std::string sn, int v);

private:
    std::string cr, cl, cp;

};


#endif //MENU_KOPIECBINARNY_H
