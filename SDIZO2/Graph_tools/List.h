//
// Created by Jakub on 14.05.2023.
//

#ifndef SDIZO2_LIST_H
#define SDIZO2_LIST_H


class List {
public:
    List(int value, int weight, int parent);
    List(int value, int weight, int parent,bool duplicate);
    List();
    List *next;
    bool visited;
    int value;
    int weight;
    int parent;
    bool duplicate;
};


#endif //SDIZO2_LIST_H
