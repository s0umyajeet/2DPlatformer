#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <SDL2/SDL.h>
#include <iostream>

enum LogType{
    ERROR, SUCCESS
};

class LogManager
{
    public:
        //delete the copy constructor -- for singleton
        LogManager(const LogManager&) = delete;

        //returns the static class instacne -- for singleton
        static LogManager& get();

        //error logging
        void logMessage(const std::string &customMessage, enum LogType type);

    private:
        LogManager();
        static LogManager m_instance;
};

#endif // LOGMANAGER_H
