#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <LogManager.h>
#include <TextureManager.h>
#include <SDLGameObject.h>
#include <Player.h>
#include <Enemy.h>
#include <PropertyLoader.h>
#include <string>
#include <vector>

class Game
{
    public:
        //for singleton
        Game(const Game&) = delete;

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

        SDL_Renderer* getRenderer() { return m_renderer; }

        //is the game loop running?
        inline bool isRunning() { return m_isRunning; }

        static Game& get();

    private:
        Game();
        static Game m_instance;

        bool m_isRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        int m_currentFrame;
        //testing player and enemy classes
        GameObject *m_player;
        GameObject *m_enemy;

        //GameObject Vector
//        std::vector<GameObject*> m_gameObjects;
};

#endif // GAME_H
