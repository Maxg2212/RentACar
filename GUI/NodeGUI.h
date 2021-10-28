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

using namespace sf;
using namespace std;

class NodeGUI {
public:
    NodeGUI(float x, float y, const string &adyacentes, string ID);

    const CircleShape &getNode() const;

    float getX() const;

    float getY() const;

    const string &getAdyacentes() const;



public:
    float x;
    float y;
    string adyacentes;
    string ID;
    CircleShape node;






};


#endif //RENTACAR_NODEGUI_H
