//
// Created by Jakub on 14.05.2023.
//

#include "List.h"
List::List(int value, int weight, int parent){
    this->parent = parent;
    this->value = value;
    this->weight = weight;
    this->next = nullptr;
    this->visited = false;
}

List::List(){


}

List::List(int value, int weight, int parent, bool duplicate){
    this->parent = parent;
    this->value = value;
    this->weight = weight;
    this->next = nullptr;
    this->visited = false;
    this->duplicate = duplicate;
}