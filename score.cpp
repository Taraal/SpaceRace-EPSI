#include "score.h"
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>


using namespace std;
using namespace sf;

score::score()
{
ScoreFond.loadFromFile("images/score.jpg");
SpriteScore.setTexture(ScoreFond);
SpriteScore.setPosition(540,460);

Cash.loadFromFile("images/piece.png");
SpriteCash.setTexture(Cash);
SpriteCash.setPosition(560, 445);

font.loadFromFile("arial.ttf");

text1.setFont(font);
text1.setStyle(sf::Text::Regular);
text1.setPosition(590,463);

pieces.setFont(font);
pieces.setStyle(sf::Text::Regular);
pieces.setPosition(570, 440);

}


//petite méthode au-dessus du main
string score::convertTo(float sec){
 sec = floor(sec);
    stringstream stream;
    stream << (sec);

    return stream.str();
}





void score::scoredraw(sf::RenderWindow *renderWindow) {

hauteur = acceleration();
str = convertTo(hauteur);
view = str + "km";
text1.setString(view);
text1.setCharacterSize(12);
renderWindow->draw(SpriteScore);
renderWindow->draw(text1);

}

float score::acceleration(){

chrono = clock.getElapsedTime();
hauteur = chrono.asSeconds() * vitesse;
if (vitesse < 30) {
  vitesse = vitesse +0.0001;
}
return hauteur;

}

void score::piecesdraw(sf::RenderWindow * renderWindow){
   pcs = convertTo(compteur);
   cash = pcs + "$";
   pieces.setString(cash);
   pieces.setCharacterSize(12);
   renderWindow->draw(SpriteCash);
   renderWindow->draw(pieces);

}

