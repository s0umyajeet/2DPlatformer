#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <SDL2/SDL_image.h>
#include <LogManager.h>

class TextureManager
{
    public:
        //delete the copy constructor -- for singleton
        TextureManager(const TextureManager&) = delete;

        //load textures from images/sprites
        bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

        //static draw (no animation)
        void draw(std::string id, int x, int y, int width, int  height,
                  SDL_Renderer* pRenderer, SDL_RendererFlip flip =  SDL_FLIP_NONE);

        //drawing for animation
        void drawFrame(std::string id, int x, int y, int width, int  height,
                       int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        //returns the static class instacne -- for singleton
        static TextureManager& getInstance();

    private:
        //ctor private --  for singleton
        TextureManager();

        //Texture map for storing references to textures against string id(s)
        std::unordered_map<std::string, SDL_Texture*> m_texMap;

        //private static instance  -- for singleton
        static TextureManager m_instance;
};

#endif // TEXTUREMANAGER_H
