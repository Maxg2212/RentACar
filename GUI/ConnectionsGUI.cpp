//
// Created by maxgm on 27/10/21.
//

#include "ConnectionsGUI.h"
#include <math.h>
#define PI 3.14159265
using namespace sf;


ConnectionsGUI::ConnectionsGUI(float x, float y, float ady_x, float ady_y, const string &gas, const string &id) : x(x), y(y), ady_x(ady_x), ady_y(ady_y), gas(gas), ID(id) {

    connection = Line(x,y,ady_x,ady_y);

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

RectangleShape ConnectionsGUI::Line(float x1, float y1, float x2, float y2) {

    RectangleShape line;
    float len, angle;
    line.setPosition(x1,y1);
    len = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    angle = atan((y2-y1)/(x2-x1)) * 180/PI;

    if(x2-x1 < 0 ){
        angle += 180;
    }

    line.setSize(Vector2f(len,1));
    line.setFillColor(Color(100,100,100));
    line.setOutlineThickness(0.5);
    line.setOutlineColor(Color(100,100,100));
    line.setRotation(angle);

    return line;
}

const RectangleShape &ConnectionsGUI::getConnection() const {
    return connection;
}

float ConnectionsGUI::getAdyX() const {
    return ady_x;
}

float ConnectionsGUI::getAdyY() const {
    return ady_y;
}


