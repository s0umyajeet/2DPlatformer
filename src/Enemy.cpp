#include "Enemy.h"

Enemy::Enemy(const PropertyLoader* props)
: SDLGameObject(props) { }


void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_position.setX(m_position.getX() - 1);
    if (m_position.getX() <= 0) {
        m_position.setX(800);
    }
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{

}

