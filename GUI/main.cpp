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

int main() {

    RCWindow rcWindow(800, 600, "RentACar");
    rcWindow.run();

    return 0;
}
