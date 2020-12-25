#include "Enemy.h"

Enemy::Enemy(const PropertyLoader* props)
: SDLGameObject(props) { }


void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{

}

