#include "fusee.h"

using namespace std;
using namespace sf;


fusee::fusee()
{

textureliste[0] = "images/flamme.png";
textureliste[1] = "images/flamme2.png";
textureliste[2] = "images/flamme3.png";
i=0;
    rocket.loadFromFile("images/rocket.png");
    textflame.loadFromFile("images/flamme.png");
    flamme.setTexture(textflame);
    sprite.setTexture(rocket); //chargement de la texture de la rocket
    flamme.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2));
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2,sprite.getTexture()->getSize().y/2 ));
    sprite.setPosition(sf::Vector2f(320,360));//on place le centre de la fusee au milieu de l'écran au début du jeu
    //std::cout  << sprite.getPosition().x << " " << sprite.getPosition().y << "INIT_POST" << -(sprite.getTexture()->getSize().y) << "\n";

}



void fusee::dessiner(sf::RenderWindow *renderWindow)
{


    renderWindow->draw(sprite); //on dessine la fusée
    flamme.setPosition(sprite.getPosition().x,sprite.getPosition().y );
    flamme.setRotation(sprite.getRotation());
 //std::cout  << flamme.getPosition().x << " " << flamme.getPosition().y << "INIT_POST" << "\n";
Time time1 = clock.getElapsedTime();
std::cout << time1.asMilliseconds() << std::endl;
if (time1.asMilliseconds() > 100)
{

textflame.loadFromFile(textureliste[i]);
flamme.setTexture(textflame);
i++;
clock.restart();
if (i == 2) {i=0;}

}

    renderWindow->draw(flamme);
}


void fusee::decollage(background *fond,bool *etatdecollage) {



    if ( sprite.getPosition().y > -90) {

        hauteur =- 0.1;
std::cout << "deco" << std::endl;
        sprite.move(0,hauteur); //on fait décoller la fusée dès le début

    }

    if ( sprite.getPosition().y < -80) {


        sprite.setPosition(sf::Vector2f(320,360));
        *etatdecollage = true;
        std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
       // fond->defilement(); //après que le décollage ait été fait (y< -80) on fait défiler le fond

    }
}

void fusee::deplacement() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {

        sprite.move(0,-0.5); // On déplace le sprite sur l'axe des y
        sprite.setRotation(0); // On annule la rotation du sprite si la touche est préssé
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 480) {

        sprite.move(0,0.5); // On déplace le sprite sur l'axe des y
        sprite.setRotation(0); // On annule la rotation du sprite si la touche est préssé
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0)  {

        sprite.move(-0.5,0); // On déplace le sprite sur l'axe des x
        sprite.setRotation(-10); // On fait une animation de rotation de 10°
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 640 ) {

        sprite.move(0.5,0); // On déplace le sprite sur l'axe des x aussi
        sprite.setRotation(10); // meme procédé pour éviter l'effet "Handspinner"

    }

    else { // Si aucune touche n'est préssé alors :

        sprite.setRotation(0);
 }
}

 float fusee::getx() {

     return sprite.getPosition().x; // On calque le sprite sur le centre de la fusee

 }

float fusee::gety() {

    return sprite.getPosition().y; // ^ pareil mais sur l'axe des y

}

float fusee::getlargeur() {

    return sprite.getTexture()->getSize().x; // Taille du sprite sur l'axe des x
}

float fusee::gettaille(){
    return sprite.getTexture()->getSize().y;// Taille du sprite sur l'axe des y
}

FloatRect fusee::getGlobalBounds() {

    return sprite.getGlobalBounds(); // Hitbox de la fusée


}



