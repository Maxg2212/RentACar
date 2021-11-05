//
// Created by maxgm on 27/10/21.
//

#ifndef RENTACAR_CONNECTIONSGUI_H
#define RENTACAR_CONNECTIONSGUI_H
/**
 * @file ConnectionsGUI.h
 * @author Max Garro Mora y Michael Valverde Navarro.
 * @brief Clase encargada de crear las conexiones entre cada nodo.
 * @version 1.0
 * @date 27/10/2021
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class ConnectionsGUI {
public:
    /**
     * @brief constructor de la clase ConnectionsGUI y es basicamente crear la linea que une cada nodo.
     * @param x
     * @param y
     * @param ady_x
     * @param ady_y
     * @param gas
     * @param id
     */
    ConnectionsGUI(float x, float y, float ady_x, float ady_y, const string &gas, const string &id);

    /**
     * @brief getter encargado de retornar la x del nodo
     * @return x
     */
    float getX() const;

    /**
     * @brief getter encargado de retornar la y del nodo
     * @return y
     */
    float getY() const;

    /**
     * @brief getter encargado de retornar el gas del nodo
     * @return gas
     */
    const string &getGas() const;

    /**
     * @brief getter encargado de retornar el ID del nodo
     * @return ID
     */
    const string &getId() const;

    /**
     * @brief getter encargado de retornar la coneccion entre cada nodo.
     * @return coneccion
     */
    const RectangleShape &getConnection() const;

    /**
     * @brief metodo encargado de crear la linea entre cada nodo.
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return line
     */
    RectangleShape Line(float x1, float y1, float x2, float y2);

    /**
     * @brief getter encargado de retornar la x del adyacente del nodo actual
     * @return ady_x
     */
    float getAdyX() const;

    /**
     * @brief getter encargado de retornar la y del adyacente del nodo actual
     * @return ady_y
     */
    float getAdyY() const;

public:
    float x;
    float y;
    float ady_x;
    float ady_y;
    string gas;
    string ID;
    RectangleShape connection;




};


#endif //RENTACAR_CONNECTIONSGUI_H
