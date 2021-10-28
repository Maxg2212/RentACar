//
// Created by maxgm on 14/10/21.
//

#ifndef RENTACAR_RCWINDOW_H
#define RENTACAR_RCWINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Node.h"
#include "NodeGUI.h"

using namespace sf;
using namespace std;

class RCWindow {
public:
    RCWindow(int w, int h, string title);

    virtual ~RCWindow();

    void update();

    void render();

    void run();


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
    NodeGUI* nodeGUI;






};


#endif //RENTACAR_RCWINDOW_H
