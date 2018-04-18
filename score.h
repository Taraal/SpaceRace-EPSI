#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
using std::string;

class score
{
public:

score();
    sf::Sprite SpriteScore;
    
    sf::Texture Cash;
    sf::Sprite SpriteCash;

    sf::Texture ScoreFond;

    void scoredraw(sf::RenderWindow *renderWindow);
    void piecesdraw(sf::RenderWindow *renderWindow);
    float acceleration();
    string convertTo(float sec);
   sf::Clock clock;
   sf::Time chrono;
   sf::Font font;
   sf::Text text1;
   sf::Text pieces;
    int compteur = 0;
    string pcs;
    string cash;
    string str;
    string view;
    float vitesse = 0.1;
    int hauteur;
    private:

};

