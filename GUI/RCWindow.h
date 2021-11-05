//
// Created by maxgm on 14/10/21.
//

#ifndef RENTACAR_RCWINDOW_H
#define RENTACAR_RCWINDOW_H
/**
 * @file RCWindow.h
 * @author Max Garro Mora y Michael Valverde Navarro.
 * @brief Clase que se encarga de mostrar el grafo y las rutas en pantalla.
 * @version 1.0
 * @date 14/10/2021
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Graph.h"
#include "NodeGUI.h"
#include <vector>

using namespace sf;
using namespace std;

class RCWindow {
public:
    /**
     *
     * @param w , el ancho de la ventana.
     * @param h , la altura de la ventana.
     * @param title , el titulo del juego.
     * @brief el constructor de la clase de la ventana.
     */
    RCWindow(int w, int h, string title, int cantidadN, int nI, int nF);

    virtual ~RCWindow();

    /**
     * @brief metodo para pruebas.
     */
    void update();

    /**
     * @brief metodo encargado de mostrar los objetos y texto en pantalla.
     */
    void render();

    /**
     * @brief metodo encargado de correr el programa.
     */
    void run();

    /**
     * @brief metodo encargado de manejar los eventos mediante clicks del mouse.
     */
    void event();

private:

    /**
     * @brief metodo encargado de leer el archivo Graph.txt para convertirlo a string.
     */
    void readFile();

    /**
     *
     * @param nodeID, la direccion del nodo
     * @param adjacents, los vecinos del nodo
     * @brief metodo encargado de crear los enlaces entre cada nodo.
     */
    void createEdge(char nodeID, vector<string> adjacents);

    /**
     * @brief metodo encargado de cambiar el color de cada nodo, verde si es visitado, rojo si no corresponde a la ruta final.
     * @param step, es el paso que se va dando cada vez que se visite un nodo.
     */
    void changeEdgeColor(string step);





private:
    RenderWindow* window = NULL;
    int w;
    int h;
    string title;
    Event e;
    int width;
    int height;
    Font font;
    Text nombre_nodo;
    //NodeGUI nodeGUI;
    ConnectionsGUI *c1;
    vector<string> textList;
    vector<NodeGUI> nodesList;
    NodeGUI nodeGui;
    Font font1;
    Text text1;
    Text seriePasos;
    Graph * graph1;
    Text text2;
    Text gas;








};


#endif //RENTACAR_RCWINDOW_H
