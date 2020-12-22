#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <PropertyLoader.h>

class GameObject
{
    public:
        GameObject();

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

    protected:
        GameObject(const PropertyLoader *props) {}
};

#endif // GAMEOBJECT_H
