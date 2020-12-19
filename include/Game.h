#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();

        void init();
        void render();
        void handleEvents();
        void clean();
        void greet();

        bool isRunning() { return _isRunning; }

    private:
        bool _isRunning;
};

#endif // GAME_H
