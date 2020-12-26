#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <LogManager.h>

class InputHandler
{
    public:
        InputHandler(const InputHandler&) = delete;
        static InputHandler& get();
        void update();
        void clean();
        bool getMouseButtonState(int buttonNumber);

    private:
        InputHandler();
        static InputHandler m_instance;
        std::vector<bool> m_mouseButtonStates;
};

enum mouseButtons {
    LEFT, MIDDLE, RIGHT
};

#endif // INPUTHANDLER_H
