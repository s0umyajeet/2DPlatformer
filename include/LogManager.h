#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <SDL2/SDL.h>
#include <iostream>

class LogManager
{
    public:
        //delete the copy constructor -- for singleton
        LogManager(const LogManager&) = delete;

        //returns the static class instacne -- for singleton
        static LogManager& getInstance();

        //error logging
        void logError(const std::string &customMessage);

        //success message
        void logSuccess(const std::string &customMessage);
    private:
        LogManager();
        static LogManager m_instance;
};

#endif // LOGMANAGER_H
