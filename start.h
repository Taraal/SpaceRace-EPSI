#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "jeu.h"

class start
{
public:

start();

    sf::Texture TextStart;
    sf::Texture bouton;
    sf::Sprite SpriteFond;
    sf::Sprite SpriteBouton;

   bool lancement(sf::RenderWindow *renderWindow);
   sf::Vector2i position_mouse;





    private:

};

