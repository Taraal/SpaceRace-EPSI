#include "obstacle.h"
using namespace std;
using namespace sf;

obstacle::obstacle()
{

    randpos = rand()%640; //Apparition random sur l'axe des x (de 0 à 640)
    TextObs.loadFromFile("images/ob1.png");
    std::cout << randpos << std::endl;
    SpriteObs.setTexture(TextObs); //Set de la texture ob1.png

    SpriteObs.setOrigin(sf::Vector2f(SpriteObs.getTexture()->getSize().x/2,SpriteObs.getTexture()->getSize().y/2 ));
    SpriteObs.setPosition(sf::Vector2f(randpos, 0));
}

void obstacle::dessiner(sf::RenderWindow *renderWindow) {
    renderWindow->draw(SpriteObs);// dessin de l'asteroide
}


void obstacle::chute() {
    hauteur = hauteur + 0.05;
    SpriteObs.setPosition(randpos,hauteur); //baisse de la hauteur
}

float obstacle::getx() {
     return SpriteObs.getPosition().x;
 }

float obstacle::gety() {

    return SpriteObs.getPosition().y;
}


float obstacle::getlargeur() {

    return SpriteObs.getPosition().x;

}

float obstacle::gettaille() {

    return SpriteObs.getPosition().y;

}


FloatRect obstacle::getGlobalBounds() {

    return SpriteObs.getGlobalBounds();

}

void obstacle::checkColli(fusee *r1, sf::RenderWindow *renderWindow){

    if(r1->getGlobalBounds().intersects(this->getGlobalBounds()) && this->collision != true) {
        this->collision = true;
        std::cout << "COLLISION" << endl;

    }

    else if(this->collision == false){

        this->chute();
        this->dessiner(renderWindow);
    }



}

