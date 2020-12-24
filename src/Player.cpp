#include "Player.h"

Player::Player(const PropertyLoader* props)
: SDLGameObject(props) { }


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_position.setX(m_position.getX() + 1);
    if (m_position.getX() >= 800) {
        m_position.setX(0);
    }
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{

}

