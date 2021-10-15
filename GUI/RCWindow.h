//
// Created by maxgm on 14/10/21.
//

#ifndef RENTACAR_RCWINDOW_H
#define RENTACAR_RCWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;
class RCWindow {
public:
    RCWindow(int w, int h, string title);

    virtual ~RCWindow();

    void update();

    void render();

    void run();

private:

    RenderWindow* window = NULL;
    int width;
    int height;





};


#endif //RENTACAR_RCWINDOW_H
