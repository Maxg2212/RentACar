//
// Created by maxgm on 27/10/21.
//

#include "ConnectionsGUI.h"

ConnectionsGUI::ConnectionsGUI(float x, float y, float ady_x, float ady_y, const string &gas, const string &id) : x(x), y(y), ady_x(ady_x), ady_y(ady_y), gas(gas), ID(id) {
}

float ConnectionsGUI::getX() const {
    return x;
}

float ConnectionsGUI::getY() const {
    return y;
}

const string &ConnectionsGUI::getGas() const {
    return gas;
}

const string &ConnectionsGUI::getId() const {
    return ID;
}
