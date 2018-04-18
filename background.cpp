#include "background.h"

using namespace std;
using namespace sf;

//Chargement des textures du background
background::background()
{
    Textfond.loadFromFile("images/fond1.png");
    Textfond3.loadFromFile("images/fond3.jpg");
    Textfond2.loadFromFile("images/fond2.jpg");
    SpriteBack.setTexture(Textfond);
    SpriteSpace.setTexture(Textfond3);

}

//Dessin des sprites
void background::dessiner(sf::RenderWindow *renderWindow) {
    renderWindow->draw(SpriteSpace);
    renderWindow->draw(SpriteBack);
}

//Defilement des background
void background::defilement() {
    this->SpriteBack.setTexture(Textfond2);
}

//Transition ciel -> espace au fil du temps / opacité
void background::changement(score *scoreboard) {
    Time time1 = clock.getElapsedTime(); //prise en compte du temps passé depuis le début


    if (opacite > 0 && scoreboard->acceleration() > 27) {
        SpriteBack.setColor(sf::Color(255, 255, 255, opacite)); //changement de l'opacité à chaque boucle
        opacite = opacite - 0.02;
    }
}

