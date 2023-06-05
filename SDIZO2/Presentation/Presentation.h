//
// Created by Jakub on 05.06.2023.
//

#ifndef SDIZO2_PRESENTATION_H
#define SDIZO2_PRESENTATION_H


#include "../Kruskal/kruskal_implementation.h"
#include "../Prim/prim_implementation.h"
#include "../Dijkstra/Dijkstra_implementation.h"
#include "../Bellman-Ford/BelmanFord_implementation.h"
#include "../File_handling/Reader.h"


class Presentation {
public:
    void kruskal();
    void prim();
    void dijkstra();
    void bellman_ford();
    Matrix *matrix;
    Reader *reader = new Reader();
};


#endif //SDIZO2_PRESENTATION_H
