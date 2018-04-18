#include "start.h"


start::start()
{
TextStart.loadFromFile("images/StartFond.png");
    bouton.loadFromFile("images/StartIcon.png");
    SpriteFond.setTexture(TextStart);
    SpriteBouton.setTexture(bouton);
    SpriteBouton.setPosition(260,190);
}



bool start::lancement(sf::RenderWindow *renderWindow) {

renderWindow->draw(SpriteFond);
renderWindow->draw(SpriteBouton);


 position_mouse = sf::Mouse::getPosition(*renderWindow);


if ((SpriteBouton.getGlobalBounds().contains(position_mouse.x,position_mouse.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
std::cout << "ok" << std::endl;
return true;
}






}
