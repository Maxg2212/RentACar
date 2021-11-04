//
// Created by maxgm on 27/10/21.
//

#ifndef RENTACAR_CONNECTIONSGUI_H
#define RENTACAR_CONNECTIONSGUI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class ConnectionsGUI {
public:
    ConnectionsGUI(float x, float y, float ady_x, float ady_y, const string &gas, const string &id);

    float getX() const;

    float getY() const;

    const string &getGas() const;

    const string &getId() const;

    const RectangleShape &getConnection() const;

    RectangleShape Line(float x1, float y1, float x2, float y2);

    float getAdyX() const;

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
