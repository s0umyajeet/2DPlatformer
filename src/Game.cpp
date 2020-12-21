#include "Game.h"
#include <iostream>

Game::Game() { }

int Game::init(std::string title, int x, int y, int width, int height, int flags = 0)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LogManager::get().logMessage("SDL Subsystems", ERROR);
        return 0;
    } else {
        LogManager::get().logMessage("SDL subsystems", SUCCESS);
    }

    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (m_window == NULL) {
        LogManager::get().logMessage("Window", ERROR);
        return 0;
    } else {
        LogManager::get().logMessage("Window", SUCCESS);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    if (m_renderer == NULL) {
        LogManager::get().logMessage("Renderer", ERROR);
        return 0;
    } else {
        LogManager::get().logMessage("Renderer", SUCCESS);
        //Set the renderer to clear the screen with a solid color (for now)
        SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    }

    LogManager::get().logMessage("Init", SUCCESS);

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
    LogManager::get().logMessage("Cleaning game", SUCCESS);
    //free the renderer
    SDL_DestroyRenderer(m_renderer);

    //free the window
    SDL_DestroyWindow(m_window);

    //terminates all initialized subsystems
    SDL_Quit();
}
