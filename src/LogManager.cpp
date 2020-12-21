#include "LogManager.h"

LogManager::LogManager() { }

LogManager LogManager::m_instance;

LogManager& LogManager::get()
{
    return m_instance;
}

void LogManager::logMessage(const std::string& customMessage, enum LogType type)
{
    switch (type) {
    case ERROR:
        std::cout << "[ Error ]   : " << customMessage << " : " << SDL_GetError() << std::endl;
        break;
    case SUCCESS:
        std::cout << "[ Success ] : " << customMessage << std::endl;
        break;
    default:
        break;
    }
}


