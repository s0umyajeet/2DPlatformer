#include "Game.h"
#include <iostream>

Game::Game() { }

int Game::init(std::string title, int x, int y, int width, int height, int flags = 0)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LogManager::getInstance().logError("SDL Subsystems");
        return 0;
    } else {
        LogManager::getInstance().logSuccess("SDL subsystems");
    }

    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (m_window == NULL) {
        LogManager::getInstance().logError("Window");
        return 0;
    } else {
        LogManager::getInstance().logSuccess("Window");
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    if (m_renderer == NULL) {
        LogManager::getInstance().logError("Renderer");
        return 0;
    } else {
        LogManager::getInstance().logSuccess("Renderer");
        //Set the renderer to clear the screen with a solid color (for now)
        SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    }

    if (!TextureManager::getInstance().load("assets/animate.png", "animate", m_renderer)) {
        LogManager::getInstance().logError("Texture Loading");
    } else {
        LogManager::getInstance().logSuccess("Texture loading");
    }


    //everyting initialized successfull, start the main loop
    m_isRunning = true;
    return 1;
}

void Game::update() {
    m_currentFrame = int(((SDL_GetTicks() / 80) % 6));
}

void Game::render()
{
    //Clear the screen with the set color
    SDL_RenderClear(m_renderer);
    TextureManager::getInstance().draw("animate", 0, 0, 128, 82, m_renderer);
    TextureManager::getInstance().drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_renderer);
    //Actually draw to the screen
    SDL_RenderPresent(m_renderer);
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
    LogManager::getInstance().logSuccess("Cleaning game");
    //free the renderer
    SDL_DestroyRenderer(m_renderer);

    //free the window
    SDL_DestroyWindow(m_window);

    //terminates all initialized subsystems
    SDL_Quit();
}
