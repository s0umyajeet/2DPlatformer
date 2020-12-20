#include "LogManager.h"

LogManager::LogManager() { }

LogManager LogManager::m_instance;

LogManager& LogManager::getInstance()
{
    return m_instance;
}

void LogManager::logError(const std::string &customMessage = "")
{
    std::cout << "[ Error ]   : " << customMessage << " : " << SDL_GetError() << std::endl;
}

void LogManager::logSuccess(const std::string& customMessage = "")
{
    std::cout << "[ Success ] : " << customMessage << std::endl;
}


