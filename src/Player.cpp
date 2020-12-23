#include "Player.h"

Player::Player(const PropertyLoader* props)
: SDLGameObject(props) { }


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Player::clean()
{

}

