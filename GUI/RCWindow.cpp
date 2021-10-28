//
// Created by maxgm on 14/10/21.
//

#include "RCWindow.h"
using namespace std;
using namespace sf;


RCWindow::RCWindow(int w, int h, string title) {
    //sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    window = new RenderWindow(VideoMode(w,h),title,Style::Close); //sd
    nodeGUI = new NodeGUI(100,100,"",""); //sd


}

RCWindow::~RCWindow() {
    delete window;

}

void RCWindow::update() {

}

void RCWindow::render() {
    window->draw(nodeGUI->getNode());

}


void RCWindow::run() {

    while(window->isOpen()){
        update();
        window->clear(Color::White);
        render();
        window->display();
    }
}
