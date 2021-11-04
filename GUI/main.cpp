#include <iostream>
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

    RCWindow rcWindow(1200, 580, "RentACar");
    rcWindow.run();

    return 0;
}
