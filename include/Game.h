#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <LogManager.h>
#include <TextureManager.h>
#include <string>

class Game
{
    public:
        Game();

        //initalize the SDL subsystems, create a window and a renderer
        int init(std::string title, int x, int y, int width, int height, int flags);

        //render the required elements onto the screen
        void render();

        //event handling for input etc.
        void handleEvents();

        //game phycics
        void update();

        //cleaing the game
        void clean();

        //is the game loop running?
        inline bool isRunning() { return m_isRunning; }

    private:
        bool m_isRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        int m_currentFrame = 0;
};

#endif // GAME_H
