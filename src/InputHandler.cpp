#include "InputHandler.h"
#include <Game.h>

InputHandler InputHandler::m_instance;

InputHandler::InputHandler() {
    for (int i = 0; i < 3; i++) {
        m_mouseButtonStates.push_back(false);
    }
}

InputHandler& InputHandler::get()
{
    return m_instance;
}


void InputHandler::update()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            Game::get().Quit();
        }

        //mouse button down
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
            case SDL_BUTTON_LEFT:
                m_mouseButtonStates[LEFT] = true;
                break;
            case SDL_BUTTON_MIDDLE:
                m_mouseButtonStates[MIDDLE] = true;
                break;
            case SDL_BUTTON_RIGHT:
                m_mouseButtonStates[RIGHT] = true;
                break;
            default: break;
            }
        }

        //mouse button up
        if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
            case SDL_BUTTON_LEFT:
                m_mouseButtonStates[LEFT] = false;
                break;
            case SDL_BUTTON_MIDDLE:
                m_mouseButtonStates[MIDDLE] = false;
                break;
            case SDL_BUTTON_RIGHT:
                m_mouseButtonStates[RIGHT] = false;
                break;
            default: break;
            }
        }

        //mouse motion
        if (event.type == SDL_MOUSEMOTION) {
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
        }
    }
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
    if (buttonNumber < 0 || buttonNumber > 2) {
        LogManager::get().logMessage("Invalid button (should be 0, 1, 2)", ERROR);
        Game::get().Quit();
        return false;
    } else {
        return m_mouseButtonStates[buttonNumber];
    }
}

void InputHandler::clean()
{

}
