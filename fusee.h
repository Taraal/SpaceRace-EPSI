#pragma once
#define DEF_FUSEE
#include "background.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class fusee
{
public:

     float angle;
     sf::Sprite sprite;
     sf::Sprite flamme;
     sf::Texture rocket;
     sf::Texture textflame;
     string textureliste[3];
     fusee();
     void init();
     void dessiner(sf::RenderWindow *renderWindow);
     void commandes();
     void decollage(background *fond,bool *etatdecollage);
     bool  deco = false;
     float hauteur = 360;
     void deplacement();
     float getx();
     float gety();
     float getlargeur();
     float gettaille();
     sf::FloatRect getGlobalBounds();
     sf::Clock clock;
     sf::Time time1;
     int i = 0;
     private:
     sf::Vector2f position;
};
