#ifndef SDLDEMO_GAME_GAME_H
#define SDLDEMO_GAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    // TODO: Make into unique pointer with custom deleter.
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
};

#endif