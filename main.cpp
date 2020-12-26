#include "Game.h"

#define FPS 60
#define DELAY_TIME (1000.0f / (FPS))

int main(int argc, char* argv[]) {

    std::string windowTitle = "Game Window";
    int win_x = SDL_WINDOWPOS_CENTERED;
    int win_y = SDL_WINDOWPOS_CENTERED;
    int width = 1000;
    int height = 800;

    Game::get().init(windowTitle, win_x, win_y, width, height, NULL);

    Uint32 loopStart, loopTime;

    while (Game::get().isRunning()) {
        //starting of the game loop
        loopStart = SDL_GetTicks();

        Game::get().handleEvents();
        Game::get().update();
        Game::get().render();

        //ending of the game loop
        loopTime = SDL_GetTicks() - loopStart;

        if (DELAY_TIME > loopTime) {
            SDL_Delay((int)(DELAY_TIME - loopTime));
        }
    }

    Game::get().clean();
    return 0;
}
