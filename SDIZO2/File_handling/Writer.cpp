//
// Created by Jakub on 05.06.2023.
//

#include <string>
#include "Writer.h"
void Writer::save(std::basic_string<char> wynik) {
    std::ofstream file("wyniki.txt", std::ios::app);

    if (file.is_open()) {

        file << wynik << std::endl;

        file.close(); // Zamknij plik
    }
}