//
// Created by maxgm on 27/10/21.
//

#include "NodeGUI.h"


NodeGUI::NodeGUI(float x, float y, const string &adyacentes, string ID) : x(x), y(y), adyacentes(adyacentes), ID(ID) {
    this->x = x;
    this->y = y;
    this->adyacentes = adyacentes;
    this->ID = ID;
    node.setRadius(10.f);
    node.setFillColor(Color::Blue);
    node.setPosition(Vector2f(this->x, this->y));
    node.setOutlineThickness(2.f);
}

const CircleShape &NodeGUI::getNode() const {
    return node;
}

float NodeGUI::getX() const {
    return x;
}

float NodeGUI::getY() const {
    return y;
}

const string &NodeGUI::getAdyacentes() const {
    return adyacentes;
}

