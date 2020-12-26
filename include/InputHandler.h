#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>
#include <Vector2D.h>
#include <LogManager.h>
#include <vector>

class InputHandler
{
    public:
        InputHandler(const InputHandler&) = delete;
        static InputHandler& get();
        void update();
        void clean();
        bool getMouseButtonState(int buttonNumber);
        Vector2D* getMousePosition() { return this->m_mousePosition; }
        bool isKeyDown(SDL_Scancode key);

    private:
        InputHandler();
        static InputHandler m_instance;
        std::vector<bool> m_mouseButtonStates;
        Vector2D* m_mousePosition;
        const Uint8* m_keyState;
};

enum mouseButtons {
    LEFT, MIDDLE, RIGHT
};

#endif // INPUTHANDLER_H
