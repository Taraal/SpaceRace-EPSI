#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "fusee.h"
#include "background.h"
#include "obstacle.h"
#include "score.h"
#include "piece.h"
#include "start.h"


class jeux
{
public:

jeux(sf::RenderWindow *renderWindow);
fusee* rocket;
std::vector<obstacle*> tab;
std::vector<piece*> pieces;
//obstacle* asteroide;
piece* gain;
score* scoreboard;
background* fond;
bool decollage(sf::RenderWindow *renderWindow);
bool controle(sf::RenderWindow *renderWindow);
bool etatdecollage = false;
bool game_over = false;
int i = 0;
private:
};
