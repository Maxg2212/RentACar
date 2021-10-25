//
// Created by marcelo on 20/10/21.
//

#ifndef RENTACAR_GRAPH_H
#define RENTACAR_GRAPH_H


#include "vector"
#include "NodeLogistic.h"
#include "random"
#include "string"
#include "algorithm"

using namespace std;

class Graph {
private:
    vector<NodeLogistic> Nodes;//Contiene todos los nodos

    string Decitions;//Guarda todas las desiciones hechas por el algoritmo

    int number;//Guarda el paso por el que va debuggeando las desiciones
    /**
 * Hace las conexiones pertinentes entre los nodos
 * @param Node1 Uno de lnodos a conectar
 * @param Node2 El otro nodo a conectar
 * @param peso El valor de la conexion entre nodos
 */
    void makeconnection(int Node1, int Node2, int peso);


    /**
     * Genera automaticamente la conexion de uno nodo con todo el grafo
     * Asegura que todo nodo va a estar conectado minimo una vez
     * La probabilidad de conectar con otro nodo es de 25%
     * Un nodo tiene un maximo de conexiones de n-1
     * No puede conectar consigo mismo
     * @param index
     */
    void Adminconections(int index);

    /**
     * Modifica el parametro de gasolina del ultimo nodo para que
     * sea maximo y siempre que se encuentre un camino viable se intercambie
     * Ademas reinicia el path de el nodo
     * @param Final
     */
    void resetbacktracking(int Final);

    /**
     * Funcion recursiva que evalua todos los nodos a profundidad
     * Hace el return solo si ya recorrio todas las posibildades o
     * si esta evaluando el nodo final, hace la revision en dado caso
     * de que el camino envcontrado sea el de menor capacidad
     * @param Init Nodo que se está evaluando
     * @param End Nodo al que se desea llegar
     * @param UnvisitedNodes Path para llegar a este nodo
     * @return
     */
    int backtracking(int Init, int End,vector<int> UnvisitedNodes);

    /**
     * Convierte un path en un string
     * @param Path
     * @return Path hecho string
     */
    string StringifyAnswer(vector<int> Path);

public:
    Graph(int size);

    /**
     * Dados un nodo de inicio y un nodo final devuelve un
     * string con el camino de menor acidad para llegar a ese nodo
     * @param Init Nodo de inicio
     * @param Fin Nodo final
     * @return Caminio recorrido
     */
    string Short(int Init, int Fin);

    /**
     * Busca un nodo en el grafo
     * @param ID
     * @return Nodo con el ID correspondiente
     */
    NodeLogistic searchnode(int ID);
};




#endif //RENTACAR_GRAPH_H
