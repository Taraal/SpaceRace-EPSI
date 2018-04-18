#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "score.h"
#include <stdlib.h>

class background
{
public:

background();
    sf::Sprite SpriteBack;
    sf::Sprite SpriteSpace;
    sf::Texture Textfond;
    sf::Texture Textfond2;
    sf::Texture Textfond3;
    void dessiner(sf::RenderWindow *renderWindow);
     void changement(score *scoreboard);
    void defilement();
    float opacite = 255;
   sf::Clock clock;
   sf::Time time1;
   bool valid = false;
    private:

};

