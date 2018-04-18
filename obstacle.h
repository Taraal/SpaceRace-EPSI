#pragma once
#define DEF_OBSTACLE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fusee.h"
class obstacle
{
public:

    obstacle();
    sf::Sprite SpriteObs;
    sf::Texture TextObs;
    void dessiner(sf::RenderWindow *renderWindow);
    float getx();
    float gety();
    float getlargeur();
    float gettaille();
    sf::FloatRect getGlobalBounds();
    void chute();
    float hauteur = 0;
    int randpos;
    void checkColli(fusee *r1, sf::RenderWindow *renderWindow);
    bool collision = false;
    private:

};
