#include "Game.h"

int main(int argc, char* argv[]) {

    std::string windowTitle = "Game Window";
    int win_x = SDL_WINDOWPOS_CENTERED;
    int win_y = SDL_WINDOWPOS_CENTERED;
    int width = 1000;
    int height = 800;

    Game::get().init(windowTitle, win_x, win_y, width, height, NULL);

    while (Game::get().isRunning()) {
        Game::get().handleEvents();
        Game::get().update();
        Game::get().render();
        SDL_Delay(10);
    }

    Game::get().clean();
    return 0;
}
