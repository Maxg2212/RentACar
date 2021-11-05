#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "RCWindow.h"
#include "Backtracking/Graph.h"


int main() {

    string cantidadNodos;
    string nodoInicial;
    string nodoFinal;

    cout << "Ingrese cantidad de nodos que desea generar: " << endl;
    getline(cin, cantidadNodos);

    cout << "Ingrese el nodo inicial: " << endl;
    getline(cin, nodoInicial);

    cout << "Ingrese el nodo final: " << endl;
    getline(cin, nodoFinal);

    RCWindow rcWindow(1200, 580, "RentACar", stoi(cantidadNodos), stoi(nodoInicial), stoi(nodoFinal));
    rcWindow.run();

    return 0;
}
