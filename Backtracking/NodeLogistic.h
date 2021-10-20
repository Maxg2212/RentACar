//
// Created by marcelo on 20/10/21.
//

#ifndef RENTACAR_NODELOGISTIC_H
#define RENTACAR_NODELOGISTIC_H

#include "vector"
#include "map"

using namespace std;


class NodeLogistic {
private:
    int gas;
    int id;
public:
    vector<int> path;//Camino que permite el tanque más pequeño
    map<int,int> connections;//Mapa sabe el peso de conexión entre nodos

    //--Funciones para el grupo
    NodeLogistic(int ID);

    void makeconnection(int ConectingNodeID,int peso);

    int getid();

    void setgas(int Gas);

    int getgas();
};




#endif //RENTACAR_NODELOGISTIC_H
