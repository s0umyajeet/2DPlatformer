#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>

Game* gameObj = new Game();

int main(int argc, char* argv[]) {

//    while (gameObj->isRunning()) {
//
//    }

    gameObj->greet();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Error initializing SDL" << std::endl;
        return 0;
    }

    SDL_Window *m_window =
    SDL_CreateWindow("hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

    if (m_window == NULL) {
        std::cout << "Error creating window" << std::endl;
        return 0;
    }

    SDL_Renderer* m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == NULL) {
        std::cout << "Error creating renderer" << std::endl;
        return 0;
    }

    while (1) {
        SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);
    }

    return 0;
}
