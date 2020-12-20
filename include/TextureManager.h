#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <SDL2/SDL_image.h>

class TextureManager
{
    public:
        TextureManager();
        bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
        void draw(std::string id, int x, int y, int width, int  height,
                  SDL_Renderer* pRenderer, SDL_RendererFlip flip =  SDL_FLIP_NONE);

        void drawFrame(std::string id, int x, int y, int width, int  height,
                       int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        std::unordered_map<std::string, SDl_Texture*> m_texMap;
    protected:

    private:
};

#endif // TEXTUREMANAGER_H
