//
// Created by maxgm on 14/10/21.
//

#include "RCWindow.h"
#include "ConnectionsGUI.h"
#include <vector>
#include "Backtracking/Graph.h"
#include <fstream>
#include <random>
#include <sstream>

using namespace std;
using namespace sf;

vector<NodeGUI> nodeList;


RCWindow::RCWindow(int w, int h, string title) {

    window = new RenderWindow(VideoMode(w,h),title,Style::Close);
    Graph graph1(6);


    for(int i = 0; i < graph1.Nodes.size(); i++){
        NodeGUI node;
        //cout << to_string(i) << " - " + graph1.getname(i) << endl;
        node.setId(graph1.getname(i));
        node.setNodeNumber(to_string(i));
        nodeList.push_back(node);
    }

    font1.loadFromFile("../font.ttf");
    text1.setFont(font1);
    text1.setOutlineColor(Color::Black);
    text1.setOutlineThickness(1.0f);
    text1.setCharacterSize(14);


    //cout << "Getting ids" << endl;
    //for(int i = 0; i < nodeList.size(); i++){
        //cout << i << " " +  nodeList.at(i).getId() << endl;
    //}


    c1 = new ConnectionsGUI(10,10,10,10,"G","id");

    readFile();

    //To traverse through the list
    for(string & line : textList){
        cout << "Checking for first node in string" << endl;
        char nodeID = line[0];
        cout << line[0]  << endl;
        cout << line << endl;
        unsigned first = line.find("(");
        unsigned last = line.find(")");
        string neighborString = line.substr(first,last-first);
        cout << "neighbor string" << endl;
        neighborString = neighborString.erase(0,1);
        cout << neighborString << endl;

        std::replace(neighborString.begin(),neighborString.end(),',',' ');
        vector<string> array;
        stringstream ss(neighborString);
        basic_string<char> temp;
        while(ss >> temp){
            array.push_back(temp);
        }

        for(int i = 0; i < array.size(); i++){
            cout << line[0] << " Array content at " + to_string(i) + " " << array.at(i) << endl;
        }

    }


}

RCWindow::~RCWindow() {
    delete window;

}

void RCWindow::update() {

    //for(int i = 0; i < nodeList.size(); i++){
      //  nodeList.at(i).nodeID.setString("hi");
    //}



}

void RCWindow::render() {

    for(int i = 0; i < nodeList.size(); i++){
        window->draw(nodeList.at(i).getNode());
    }



    for(int i = 0; i < nodeList.size(); i++) {
        text1.setPosition(nodeList.at(i).getX(), nodeList.at(i).getY());
        text1.setString(to_string(i) + " - " +nodeList.at(i).getId());
        window->draw(text1);
    }

    window->draw(c1->getConnection());

}


void RCWindow::run() {

    while(window->isOpen()){
        while(window->pollEvent(e)){
            event();
        }
        update();
        window->clear(Color::White);
        render();
        window->display();
    }
}

void RCWindow::event() {
    if(e.type == Event::Closed){
        window->close();
    }else if(e.type == Event::MouseMoved){
        //cout <<  "X: " + to_string(Mouse::getPosition(*window).x) + " " << "Y: " + to_string(Mouse::getPosition(*window).y) + " " << endl;

    }
}


void RCWindow::readFile() {

    cout << "Reading from file" << endl;
    string textFromFile;
    string filename = "Graph.txt";

    ifstream in(filename.c_str());
    if(!in){
        cout << "Error opening the file" << endl;
    }
    while (getline(in,textFromFile)){
        if(textFromFile.size() > 0){
            textList.push_back(textFromFile);
        }
    }
    in.close();

}
