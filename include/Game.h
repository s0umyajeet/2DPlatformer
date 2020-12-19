#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
    public:
        Game();

        //initalize the SDL subsystems, create a window and a renderer
        void init(string title, int x, int y, int width, int height, int flags = 0);

        //render the required elements onto the screen
        void render();

        //event handling for input etc.
        void handleEvents();

        //game phycics
        void update();

        //error logging
        void errorLogger();

        //cleaing the game
        void clean();

        //for debug
        void greet();

        //is the game loop running?
        inline bool isRunning() { return m_isRunning; }

    private:
        bool m_isRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
};

#endif // GAME_H
