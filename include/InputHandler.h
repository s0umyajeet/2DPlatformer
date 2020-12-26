#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H


class InputHandler
{
    public:
        InputHandler(const InputHandler) = delete;
        static InputHandler& get();

    private:
        InputHandler();
        static InputHandler m_instance;
};

#endif // INPUTHANDLER_H
