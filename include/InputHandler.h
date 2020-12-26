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

        //wrapper functions for different types of events

        //keyboard events
        void onKeyDown();
        void onKeyUp();

        //mouse events
        void onMouseMotion(SDL_Event& event);
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);
};

enum mouseButtons {
    LEFT, MIDDLE, RIGHT
};

#endif // INPUTHANDLER_H
