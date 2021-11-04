//
// Created by maxgm on 27/10/21.
//

#include "NodeGUI.h"
#include <random>


NodeGUI::NodeGUI() {

    x = 0.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(1100.0-0-0)));
    y = 0.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(540.0-0-0)));

    node.setRadius(15.f);
    node.setFillColor(Color::Blue);
    node.setPosition(Vector2f(x, y));
    node.setOutlineThickness(0.1f);

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

const string &NodeGUI::getId() const {
    return ID;
}

void NodeGUI::setId(const string &id) {
    ID = id;
}

string NodeGUI::getNodeNumber() const {
    return nodeNumber;
}

void NodeGUI::setNodeNumber(string nodeNumber) {
    NodeGUI::nodeNumber = nodeNumber;
}


