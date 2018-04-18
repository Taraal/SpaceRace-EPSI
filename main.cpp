#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "fusee.h"
#include "background.h"
#include "obstacle.h"
#include "score.h"
#include "piece.h"
#include "start.h"
#include <sys/time.h>


int main()
{
    //Mise en place du timer
    struct timeval time;
    gettimeofday(&time, NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); //Timer en millisecondes et non en secondes

    //Affichage de la fenetre 640*480
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Space RACE");

    //Lancement de la musique <3
    sf::Music music;
    sf::Event event;
    music.openFromFile("images/mars.ogg");



    //Creation de la fusee et du premier asteroide

    //MUSIQUE


    start menu;
    jeux game(&renderWindow);
while (menu.lancement(&renderWindow) != true)
{
renderWindow.display();
}


while(game.decollage(&renderWindow) != true)
{
renderWindow.display();
}
 music.play();



    //Boucle de lancement du jeu
    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

        }

game.controle(&renderWindow);
renderWindow.display();


    }
    return 0;
};










