//
// Created by maxgm on 14/10/21.
//

#include "RCWindow.h"
#include <vector>
using namespace std;
using namespace sf;

vector<NodeGUI> nodeList;


RCWindow::RCWindow(int w, int h, string title) {
    //sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    window = new RenderWindow(VideoMode(w,h),title,Style::Close); //sd
    NodeGUI *nodeGUI = new NodeGUI(100,100,"",""); //sd
    nodeList.push_back(*nodeGUI);


}

RCWindow::~RCWindow() {
    delete window;

}

void RCWindow::update() {

}

void RCWindow::render() {
    for(int i = 0; i < nodeList.size(); i++){
        window->draw(nodeList.at(i).getNode());
    }


}


void RCWindow::run() {

    while(window->isOpen()){
        update();
        window->clear(Color::White);
        render();
        window->display();
    }
}
