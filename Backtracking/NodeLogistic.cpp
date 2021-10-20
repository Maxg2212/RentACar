//
// Created by marcelo on 20/10/21.
//

#include "NodeLogistic.h"
NodeLogistic::NodeLogistic(int ID) {
    this->id=ID;
    this->gas=100;
}

void NodeLogistic::makeconnection(int ConectingNodeID, int peso) {
    this->connections.insert(pair<int,int>(ConectingNodeID,peso));
}

int NodeLogistic::getid(){
    return this->id;
}

void NodeLogistic::setgas(int Gas) {
    this->gas=Gas;
}

int NodeLogistic::getgas() {
    return this->gas;
}