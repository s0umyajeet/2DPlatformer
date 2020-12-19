#include "Game.h"

Game* gameObj = new Game();

int main(int argc, char* argv[]) {

    string windowTitle = "Game Window";
    int win_x = SDL_WINDOWPOS_CENTERED;
    int win_y = SDL_WINDOWPOS_CENTERED;
    int width = 800;
    int height = 600;

    gameObj->init(windowTitle, win_x, win_y, width, height, NULL)

    while (gameObj->isRunning()) {
        gameObj->handleEvents();
        gameObj->update();
        gameObj->render();
    }

    gameObj->clean();
    return 0;
}
