#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <GameObject.h>
#include <string>


class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const PropertyLoader* props);

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        int m_currentRow;
        int m_currentFrame;
        std::string m_textureID;
};

#endif // SDLGAMEOBJECT_H
