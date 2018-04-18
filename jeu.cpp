#include "jeu.h"
#include "score.h"
#include <vector>

jeux::jeux(sf::RenderWindow *renderWindow)
{
rocket = new fusee;
fond = new background;
scoreboard = new score;
gain = new piece;
for(i = 0; i < 50;i++)
{
tab.push_back(new obstacle);
}

for (i = 0; i < 10; i++){
    pieces.push_back(new piece);
}
}

bool jeux::decollage(sf::RenderWindow *renderWindow) {
fond->dessiner(renderWindow);
rocket->deplacement();
rocket->dessiner(renderWindow);
rocket->decollage(fond,&etatdecollage);
if(etatdecollage == true) {return true;}
}


bool jeux::controle(sf::RenderWindow *renderWindow) {

fond->defilement();
fond->dessiner(renderWindow);
rocket->deplacement();
rocket->dessiner(renderWindow);
fond->changement(scoreboard);
scoreboard->scoredraw(renderWindow);
scoreboard->piecesdraw(renderWindow);
//gain->dessiner(renderWindow);
//gain->chute();
///gain->checkColli(rocket, renderWindow, scoreboard);


for (i=0; i < 10; i++){
    pieces[i]->checkColli(rocket, renderWindow, scoreboard);
}

for (i=0; i < 10;i++ ) {
tab[i]->checkColli(rocket,renderWindow);
}
if (game_over == true) {return true;}

}
