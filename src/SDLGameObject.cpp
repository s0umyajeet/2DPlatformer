#include "SDLGameObject.h"
#include <TextureManager.h>
#include <Game.h>

SDLGameObject::SDLGameObject(const PropertyLoader* props)
: GameObject(props)
{
    m_x             = props->getX();
    m_y             = props->getY();
    m_width         = props->getWidth();
    m_height        = props->getHeight();
    m_textureID     = props->getTextureID();
    m_currentRow    = 1;
    m_currentFrame  = 1;
}

void SDLGameObject::draw()
{
    TextureManager::get().drawFrame(m_textureID, m_x, m_y,
                                             m_width, m_height, m_currentRow,
                                             m_currentFrame, Game::get().getRenderer());

}

void SDLGameObject::update()
{

}

void SDLGameObject::clean()
{

}
