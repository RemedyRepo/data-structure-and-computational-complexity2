//
// Created by Jakub on 14.05.2023.
//

#ifndef SDIZO2_READER_H
#define SDIZO2_READER_H


#include "../Graph_tools/Matrix.h"

class Reader {

public:
    void Read_from_file(Matrix *matrix,bool directed);
    void Read_from_file_for_testing(Matrix *matrix, bool directed, std::string filename);
};


#endif //SDIZO2_READER_H
