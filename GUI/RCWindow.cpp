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
vector<ConnectionsGUI> connections;


RCWindow::RCWindow(int w, int h, string title) {

    window = new RenderWindow(VideoMode(w,h),title,Style::Close);
    graph1 = new Graph(9);
    string shortestPath = graph1->Short(2,5);
    cout << graph1->step() << endl;



    for(int i = 0; i < graph1->Nodes.size(); i++){
        NodeGUI node;
        //cout << to_string(i) << " - " + graph1.getname(i) << endl;
        node.setId(graph1->getname(i));
        node.setNodeNumber(to_string(i+1));
        nodeList.push_back(node);
    }

    //text to draw citynames in nodes
    font1.loadFromFile("../font.ttf");
    text1.setFont(font1);
    text1.setOutlineColor(Color::Black);
    text1.setOutlineThickness(1.0f);
    text1.setCharacterSize(14);

    seriePasos.setFont(font1);
    seriePasos.setOutlineColor(Color::Black);
    seriePasos.setOutlineThickness(1.0f);
    seriePasos.setCharacterSize(14);
    seriePasos.setPosition(1100,50);

    text2.setFont(font1);
    text2.setOutlineThickness(1.0f);
    text2.setOutlineColor(Color::Black);
    text2.setCharacterSize(14);
    text2.setPosition(1000,150);
    text2.setString(shortestPath);


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
        //cout << line[0]  << endl;
        //cout << line << endl;
        unsigned first = line.find("(");
        unsigned last = line.find(")");
        string neighborString = line.substr(first,last-first);
        //cout << "neighbor string" << endl;
        neighborString = neighborString.erase(0,1);
        //cout << neighborString << endl;

        std::replace(neighborString.begin(),neighborString.end(),',',' ');
        vector<string> array;
        stringstream ss(neighborString);
        basic_string<char> temp;
        while(ss >> temp){
            array.push_back(temp);
        }

        createEdge(line[0],array);


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

    for(int i = 0; i < connections.size(); i++){
        window->draw(connections.at(i).getConnection());
    }

    for(int i = 0; i < nodeList.size(); i++){
        window->draw(nodeList.at(i).getNode());
    }

    for(int i = 0; i < nodeList.size(); i++) {
        text1.setPosition(nodeList.at(i).getX(), nodeList.at(i).getY());
        text1.setString(to_string(i+1) + " - " +nodeList.at(i).getId());
        window->draw(text1);
    }

    window->draw(c1->getConnection());
    window->draw(seriePasos);
    window->draw(text2);

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

    }else if(e.type == Event::MouseButtonPressed){
        if(e.mouseButton.button == sf::Mouse::Right){
            string stepString =  graph1->step();
            cout << stepString << endl;
            seriePasos.setString("Paso: " + stepString);
            if(stepString != "Fin"){
                changeEdgeColor(stepString);
            }

        }
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

void RCWindow::createEdge(char nodeID, vector<string> adjacents) {
    cout << "CreateEdge " << endl;
    cout << nodeID << endl;

    for(int i = 0; i < adjacents.size(); i++){
        cout << adjacents.at(i) << endl;
        std::replace(adjacents.at(i).begin(),adjacents.at(i).end(),':',' ');
        vector<string> array_edges;
        stringstream ss(adjacents.at(i));
        basic_string<char> temp;
        while(ss >> temp){
            array_edges.push_back(temp);
        }

        float posx;
        float posy;

        float adj_x;
        float adj_y;

        string startingNode;
        string arrivingNode;

        //cout << nodeID <<  " Conectado con " <<  array_edges[0] << endl;
        for(int i = 0; i < nodeList.size(); i++){
            if(nodeID == nodeList.at(i).getNodeNumber()){
                startingNode = nodeList.at(i).getNodeNumber();
                posx = nodeList.at(i).getX();
                posy = nodeList.at(i).getY();

                //cout << "x: " << posx << "y: " << posy <<endl;
            }
        }

        for(int i = 0; i < nodeList.size(); i++){
            if(array_edges[0] == nodeList.at(i).getNodeNumber()){
                arrivingNode = nodeList.at(i).getNodeNumber();
                adj_x = nodeList.at(i).getX();
                adj_y = nodeList.at(i).getY();

                //cout << "x: " << adj_x << "y: " << adj_y <<endl;
            }
        }

        //cout << "Verifying coords " << endl;
        //cout << posx << " " << posy << endl;
        string connectionID = startingNode + "-" + arrivingNode;
        cout << "Connection ID "<< connectionID << endl;
        ConnectionsGUI conn(posx,posy,adj_x,adj_y,array_edges[1],connectionID);
        connections.push_back(conn);

    }

}

void RCWindow::changeEdgeColor(string step){

    string stepString;
    char startingNode = step[0];
    char arrivalNode = step[2];
    char backtrackingDecision = step[3];

    stepString.push_back(startingNode);
    stepString.push_back('-');
    stepString.push_back(arrivalNode);

    cout << "StepString: " << stepString << endl;
    //cout << "Starting Node : " << step[0] << endl;
    //cout << "Arriving Node : " << step[2] << endl;
    cout << "Decision " << backtrackingDecision << endl;
    for(int i = 0; i < connections.size(); i++){
        if(stepString == connections.at(i).getId()){
            if(backtrackingDecision == 'T'){
                connections.at(i).connection.setFillColor(Color::Green);
                connections.at(i).connection.setOutlineColor(Color::Green);

                connections.at(i).connection.setOutlineThickness(2.0f);

            }else{
                connections.at(i).connection.setFillColor(Color::Red);
                connections.at(i).connection.setOutlineColor(Color::Red);

                connections.at(i).connection.setOutlineThickness(2.0f);
            }
        }
    }





}
