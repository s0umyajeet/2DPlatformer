#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <GameObject.h>
#include <Vector2D.h>
#include <SDL2/SDL.h>
#include <string>


class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const PropertyLoader* props);

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:
        Vector2D m_position;
        int m_width;
        int m_height;
        int m_currentRow;
        int m_currentFrame;
        std::string m_textureID;
};

#endif // SDLGAMEOBJECT_H
