//
// Created by maxgm on 27/10/21.
//

#ifndef RENTACAR_NODEGUI_H
#define RENTACAR_NODEGUI_H

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
    NodeGUI();

    const CircleShape &getNode() const;

    float getX() const;

    float getY() const;

    const string &getAdyacentes() const;

    const string &getId() const;


    void setId(const string &id);

    string getNodeNumber() const;

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
