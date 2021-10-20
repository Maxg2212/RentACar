//
// Created by marcelo on 20/10/21.
//

#ifndef RENTACAR_GRAPH_H
#define RENTACAR_GRAPH_H


#include "vector"
#include "NodeLogistic.h"
#include "random"
#include "string"

using namespace std;

class Graph {
private:
    vector<NodeLogistic> Nodes;

    void makeconnection(int Node1, int Node2, int peso);

    NodeLogistic searchnode(int ID);

    void Adminconections(int index);
public:
    Graph(int size);
};




#endif //RENTACAR_GRAPH_H
