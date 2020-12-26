#include "InputHandler.h"

InputHandler InputHandler::m_instance;

InputHandler::InputHandler() { }

InputHandler& InputHandler::get()
{
    return m_instance;
}


