//
// Created by maxgm on 27/10/21.
//

#ifndef RENTACAR_NODEGUI_H
#define RENTACAR_NODEGUI_H
/**
 * @file NodeGUI.h
 * @author Max Garro Mora y Michael Valverde Navarro.
 * @brief Clase encargada de utilizar la logica del Nodo de Backtracking para asi mostrarlo en la interfaz.
 * @version 1.0
 * @date 27/10/2021
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "ConnectionsGUI.h"

using namespace sf;
using namespace std;

class NodeGUI {
public:
    /**
     * @brief constructor de la clase NodeGUI, que contiene las caracteristicas de cada nodo.
     */
    NodeGUI();

    /**
     * @brief un getter encargado de retornar el node.
     * @return node
     */
    const CircleShape &getNode() const;

    /**
     * @brief un getter encargado de retornar la x.
     * @return x
     */
    float getX() const;

    /**
     * @brief un getter encargado de retornar la y.
     * @return y
     */
    float getY() const;

    /**
     * @brief un getter encargado de retornar los nodos adyacentes.
     * @return adyacentes
     */
    const string &getAdyacentes() const;

    /**
     * @brief un getter encargado de retornar la identificacion del nodo.
     * @return ID
     */
    const string &getId() const;

    /**
     * @brief un setter encargado de configurar la identificacion del nodo.
     * @param id
     */
    void setId(const string &id);

    /**
     * @brief getter encargado de retornar el numero del nodo.
     * @return nodeNumber
     */
    string getNodeNumber() const;

    /**
     * @brief metodo encargado de setear el numero del nodo.
     * @param nodeNumber
     */
    void setNodeNumber(string nodeNumber);


public:
    float x;
    float y;
    string adyacentes;
    string ID;
    CircleShape node;
    string nodeNumber;

};


#endif //RENTACAR_NODEGUI_H
