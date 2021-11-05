//
// Created by marcelo on 20/10/21.
//

#ifndef RENTACAR_NODELOGISTIC_H
#define RENTACAR_NODELOGISTIC_H
/**
 * @file Graph.h
 * @author Marcelo Truque Montero.
 * @brief Clase encargada de crear la logica de los nodos del grafo.
 * @version 1.0
 * @date 20/10/2021
 */
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
    /**
     * @brief constructor encargado de generar el id del nodo y establecer que el gas es 100.
     * @param ID
     */
    NodeLogistic(int ID);

    /**
     * @brief metodo encargado de crear las conexiones entre cada nodo.
     * @param ConectingNodeID
     * @param peso
     */
    void makeconnection(int ConectingNodeID,int peso);

    /**
     * @brief getter encargado de retornar el id
     * @return id
     */
    int getid();

    /**
     * @brief metodo encargado de setear el gas
     * @param Gas
     */
    void setgas(int Gas);

    /**
     * @brief getter encargado de retornar el gas
     * @return gas
     */
    int getgas();
};




#endif //RENTACAR_NODELOGISTIC_H
