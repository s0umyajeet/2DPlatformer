#include "TextureManager.h"

TextureManager::TextureManager() { }

TextureManager TextureManager::m_instance;

TextureManager& TextureManager::get()
{
    return m_instance;
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface *tempSurface = IMG_Load(fileName.c_str());

    if (tempSurface == NULL) {
        LogManager::get().logMessage("Temp Surface", ERROR);
        return false;
    } else {
        LogManager::get().logMessage("Temp Surface", SUCCESS);
    }

    SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

    //Let go of the temporary surface
    SDL_FreeSurface(tempSurface);

    if (tempTexture == NULL) {
        LogManager::get().logMessage("Temp Texture", ERROR);
        return false;
    } else {
        LogManager::get().logMessage("Temp Texture", SUCCESS);
    }

    m_texMap[id] = tempTexture;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    //for source rectangle
    srcRect.x = srcRect.y = 0;
    srcRect.w = width;  // Texture width
    srcRect.h = height;  // Texture height

    //for destination rectangle
    dstRect.x = x;      //coordinates of where to draw on the screen
    dstRect.y = y;      //coordinates of where to draw on the screen
    dstRect.w = width;  //destination width same as texture width (basically copying the whole texture)
    dstRect.h = height; //destination height same as texture height (-------------11------------------)

    SDL_RenderCopyEx(renderer, m_texMap[id], &srcRect, &dstRect, 0, 0, flip);

}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    //for source rectangle
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;
    srcRect.w = width;
    srcRect.h = height;

    //for destinantion rectangle
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;

    SDL_RenderCopyEx(renderer, m_texMap[id], &srcRect, &dstRect, 0, 0, flip);
}
