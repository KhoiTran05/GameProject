#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"defs.h"

using namespace std;
struct Graphics{
    SDL_Window* window;
    SDL_Renderer* renderer;
    int textWidth, textHeight;

    void initSDL(){
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
            std::cout << "Failed to init SDL" << std::endl;
            SDL_GetError();
        }
        window = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( window == nullptr){
            std::cout << "Failed to create window" << std::endl;
            SDL_GetError();
        }
        int imgFlags = IMG_INIT_PNG;
        if ( !(IMG_Init(imgFlags) & imgFlags)){
            std::cout << "Failed to init SDL image" << std::endl;
            IMG_GetError();
        }
        if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
            std::cout << "Failed to init SDL Mixer" << std::endl;
            Mix_GetError();
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if ( renderer == nullptr){
            std::cout << "Failed to create renderer" << std::endl;
            SDL_GetError();
        }
        if ( TTF_Init() == -1){
            std::cout << "Failed to init SDL ttf" << std::endl;
            TTF_GetError();
        }
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    void close(){
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
        SDL_Quit();
        IMG_Quit();
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL){
            std::cout << "Failed to load " << filename << " texture" << std::endl;
            IMG_GetError();
        }
        return texture;
    }

    SDL_Texture* loadTextTexture( std::string path, SDL_Color textColor, TTF_Font* font){
        SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, path.c_str(), textColor);
        if ( loadedSurface == nullptr){
            std::cout << "Failed to load text surface" << std::endl;
            TTF_GetError();
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if ( texture == nullptr){
            std::cout << "Failed to load text texture" << std::endl;
            SDL_GetError();
        }
        SDL_FreeSurface(loadedSurface);
        return texture;
    }

    void prepareScene(){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
    }

    void presentScene(){
        SDL_RenderPresent(renderer);
    }

    void renderBackground(SDL_Texture* mTexture){
        SDL_RenderCopy(renderer, mTexture, nullptr, nullptr);
    }

    void renderTexture(SDL_Texture *texture, SDL_Rect* src, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE)
    {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        if ( src != nullptr){
            dest.w = src->w;
            dest.h = src->h;
        }
        SDL_RenderCopyEx(renderer, texture, src, &dest, 0.0, nullptr, flip);
    }

    TTF_Font* loadFont(string path, int fontSize){
        TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
        if ( newFont == nullptr){
            cout << "Failed to load " << path << " font" << TTF_GetError();
        }
        return newFont;
    }
    SDL_Texture* loadColorKeyTexture(string path, Uint8 red, Uint8 green, Uint8 blue ){
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());
        if ( loadedSurface == nullptr){
            cout << "Failed to load color key surface" << endl;
            IMG_GetError();
        }
        SDL_SetColorKey(loadedSurface, -1, SDL_MapRGB(loadedSurface->format, red, green, blue));
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if ( texture == nullptr){
            cout << "Failed to create color key texture from surface" << endl;
            SDL_GetError();
        }
        return texture;
    }
};

#endif // _GRAPHICS__H

