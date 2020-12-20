#include "Game.h"
#include <iostream>

Game::Game()
{

}

void Game::errorLogger()
{
    std::cout << "Something went wrong" << std::endl;
    std::cout << "Error message: " << SDL_GetError() << std::endl;
}

int Game::init(std::string title, int x, int y, int width, int height, int flags = 0)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        errorLogger();
        return 0;
    } else {
        std::cout << "SDL subsystems initialized!" << std::endl;
    }

    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (m_window == NULL) {
        errorLogger();
        return 0;
    } else {
        std::cout << "Window created successfully!" << std::endl;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    if (m_renderer == NULL) {
        errorLogger();
        return 0;
    } else {
        std::cout << "Renderer created successfully!" << std::endl;
        //Set the renderer to clear the screen with a solid color (for now)
        SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    }

    std::cout << "Init success!" << std::endl;

    //everyting initialized successfull, start the main loop
    m_isRunning = true;
    return 1;
}

void Game::update() {
}

void Game::render()
{
    //Clear the screen with the set color
    SDL_RenderClear(m_renderer);

    //Actually draw to the screen
    SDL_RenderPresent(m_renderer);
}

void Game::greet()
{
    std::cout << "running" << std::endl;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
        //if the user presses the 'x' button in order to close the game
        case SDL_QUIT:
                m_isRunning = false;
                break;
        default:
                break;
        }
    }
}

void Game::clean()
{
    std::cout << "Cleaning game!" << std::endl;
    //free the renderer
    SDL_DestroyRenderer(m_renderer);

    //free the window
    SDL_DestroyWindow(m_window);

    //terminates all initialized subsystems
    SDL_Quit();
}
