//
// Created by maxgm on 14/10/21.
//

#ifndef RENTACAR_NODE_H
#define RENTACAR_NODE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;


class Node {
public:
    Node();
    Node(float x, float y, std::string name = "");
    Node(Node* node);
    float x();
    float y();
    std::string name();
    void setX(float x);
    void setY(float y);
    void setName(std::string name);
    void addNeighbor(Node* node);
    std::vector<Node*> neighbors();
    float distance(Node* neighbor);
private:
    float _x;
    float _y;
    std::string _name;
    std::vector<Node*> _neighbors;

};


#endif //RENTACAR_NODE_H
