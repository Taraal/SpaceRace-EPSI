#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "fusee.h"
#include "score.h"
class piece
{
public:

     float angle;
     sf::Sprite star;
     sf::Texture pieceFond;
     piece();
     float getx();
     float gety();
     float getlargeur();
     float gettaille();
     void chute();
     void dessiner(sf::RenderWindow *renderWindow);
     sf::FloatRect getGlobalBounds();
    
    void checkColli(fusee *r1, sf::RenderWindow *renderWindow, score *scoreboard);
    bool collision = false;
     int hauteur = 0;
     int randpos;
     int banque = 0;
     private:

};

