#ifndef _SPRITE__H
#define _SPRITE__H

#include<SDL.h>
#include<SDL_image.h>
#include"graphics.h"
#include"defs.h"

using namespace std;

struct Sprite{
    SDL_Texture* spriteSheetTexture;
    vector<SDL_Rect> clips;
    SDL_Rect* currentClips = nullptr;
    double frame = 0.0;
    int status = 0;

    void init(const int spriteClips[][4], int totalFrame){
        SDL_Rect clip;
        for ( int i = 0; i < totalFrame; i++){
            clip = { spriteClips[i][0], spriteClips[i][1], spriteClips[i][2], spriteClips[i][3]};
            clips.push_back(clip);
        }
    }

    void doSprite(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/4];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
        if ( frame/4 >= totalFrame) frame = 0;
    }

    void doSlowSprite(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/15];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
        if ( frame/15 >= totalFrame) frame = 0;
    }

    void doSlowSprite2(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/10];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
        if ( frame/10 >= totalFrame) frame = 0;
    }

    void doSlowSprite_2(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/6];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
    }

    void doSlowSprite3(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/4];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
    }

    void doSlowSprite4(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/6];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
        if ( frame/6 >= totalFrame) frame = 0;
    }
    void doQuickSprite(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
        if ( frame >= totalFrame){
            frame = 0;
        }
    }

    void doQuickSprite2(Graphics& graphics, int totalFrame, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE){
        currentClips = &clips[frame/2];
        graphics.renderTexture(spriteSheetTexture, currentClips, x, y, flip);
        frame++;
//        if ( frame/10 >= totalFrame) frame = 0;
    }

    int getWidth(){
        return currentClips->w;
    }

    int getHeight(){
        return currentClips->h;
    }
};
#endif // _SPRITE__H
