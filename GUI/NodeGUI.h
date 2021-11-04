//
// Created by maxgm on 27/10/21.
//

#ifndef RENTACAR_NODEGUI_H
#define RENTACAR_NODEGUI_H
/**
 * @file NodeGUI.h
 * @author Max Garro Mora
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
     *
     * @return
     */
    const string &getAdyacentes() const;

    /**
     *
     * @return
     */
    const string &getId() const;

    /**
     *
     * @param id
     */
    void setId(const string &id);

    /**
     *
     * @return
     */
    string getNodeNumber() const;

    /**
     *
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
