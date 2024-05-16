#ifndef _MENU__H
#define _MENU__H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"graphics.h"
#include"defs.h"
#include"game.h"
#include"sound.h"

using namespace std;

struct Menu{
    int menuStatus, mouse_x, mouse_y;
    SDL_Texture* startBackground, *borderTexture, *titleTextTexture, *startTextTexture, *helpTextTexture, *exitTextTexture, *menuTextTexture, *menuTextTexture2, *deadTextTexture, *deadBackground, *helpBackground, *instructTextTexture, *endBackground, *endTextTexture;
    SDL_Texture* aButton, *dButton, *wButton, *jButton, *kButton, *spaceButton, *moveTextTexture, *climbTextTexture, *attackTextTexture, *dashTextTexture, *jumpTextTexture, *clickTextTexture;
    SDL_Color titleTextColor, startTextColor, helpTextColor, exitTextColor, menuTextColor, menuTextColor2, instructTextColor;
    TTF_Font* titleTextFont, *textFont, *instructFont, *buttonFont;
    Mix_Music* bgMusic;

    void init(Graphics& graphic, Sound& sound){
        endBackground = graphic.loadTexture("Image//EndBg.png");
        startBackground = graphic.loadTexture("Image//StartBg.png");
        deadBackground = graphic.loadTexture("Image//DeadBG.png");
        borderTexture = graphic.loadTexture("Image//Border.png");
        titleTextFont = graphic.loadFont("Image//Uncial_WIP.ttf", 200);
        textFont = graphic.loadFont("Image//Uncial_WIP.ttf", 70);
        instructFont = graphic.loadFont("Image//NotJamChunkySans.ttf", 17);
        buttonFont = graphic.loadFont("Image//NotJamChunkySans.ttf", 30);
        titleTextColor = {200, 10, 10, 0};
        startTextColor = { 255, 255, 255, 255};
        helpTextColor = { 255, 255, 255, 255};
        exitTextColor = { 255, 255, 255, 255};
        menuTextColor = { 255, 255, 255, 255};
        menuTextColor2 = { 255, 255, 255, 255};
        instructTextColor = {255, 255, 255, 255};
        titleTextTexture = graphic.loadTextTexture("Great Wizard", titleTextColor, titleTextFont);
        endTextTexture = graphic.loadTextTexture("You Win", titleTextColor, titleTextFont);
        deadTextTexture = graphic.loadTextTexture("You Died", titleTextColor, titleTextFont);
        helpBackground = graphic.loadTexture("Image//01.jpg");
        instructTextTexture = graphic.loadTextTexture("There are total of 3 stages. Kill monsters and collect keys to go to the next stage", instructTextColor, instructFont);
        aButton = graphic.loadTexture("Image//A-Key.png");
        dButton = graphic.loadTexture("Image//D-Key.png");
        wButton = graphic.loadTexture("Image//W-Key.png");
        kButton = graphic.loadTexture("Image//K-Key.png");
        jButton = graphic.loadTexture("Image//J-Key.png");
        spaceButton = graphic.loadTexture("Image//Space-Key.png");
        moveTextTexture = graphic.loadTextTexture("Move", instructTextColor, buttonFont);
        climbTextTexture = graphic.loadTextTexture("Climb", instructTextColor, buttonFont);
        jumpTextTexture = graphic.loadTextTexture("Jump", instructTextColor, buttonFont);
        attackTextTexture = graphic.loadTextTexture("Attack", instructTextColor, buttonFont);
        dashTextTexture = graphic.loadTextTexture("Dash", instructTextColor, buttonFont);
        clickTextTexture = graphic.loadTextTexture("Click anywhere to back to menu", instructTextColor, instructFont);
        bgMusic = sound.loadMusic("Sound//Background.mp3");
    }

    void doMenu1(Game& game, Sound& sound){
        if ( sound.musicPlaying() && game.soundStatus != 0) sound.stopMusic();
        game.soundStatus = 0;
        if ( !sound.musicPlaying()) sound.playMusic(bgMusic);
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
//        cout << mouse_x << " " << mouse_y << endl;
        if ( mouse_x >= 575 && mouse_x <= 700 && mouse_y >= 420 && mouse_y <= 460){
            startTextColor = {0, 0, 0, 0};
        }
        else startTextColor = {255, 255, 255, 255};
        if ( mouse_x >= 590 && mouse_x <= 686 && mouse_y >= 505 && mouse_y <= 546){
            helpTextColor = {0, 0, 0, 0};
        }
        else helpTextColor = {255, 255, 255, 255};
        if ( mouse_x >= 578 && mouse_x <= 686 && mouse_y >= 597 && mouse_y <= 635){
            exitTextColor = {0, 0, 0, 0};
        }
        else exitTextColor = {255, 255, 255, 255};

        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 575 && mouse_x <= 700 && mouse_y >= 420 && mouse_y <= 460){
                    game.gameStatus = 1;
                }
                if ( mouse_x >= 590 && mouse_x <= 686 && mouse_y >= 505 && mouse_y <= 546){
                    game.gameStatus = 7;
                }
                if ( mouse_x >= 578 && mouse_x <= 686 && mouse_y >= 597 && mouse_y <= 635){
                    exit(0);
                }
                break;
            }
        }
    }

    void drawMenu1(Graphics& graphic){
        startTextTexture = graphic.loadTextTexture("Start", startTextColor, textFont);
        helpTextTexture = graphic.loadTextTexture("Help", helpTextColor, textFont);
        exitTextTexture = graphic.loadTextTexture("Exit", exitTextColor, textFont);
        graphic.renderTexture(startBackground, nullptr, 0, 0);
        graphic.renderTexture(titleTextTexture, nullptr, 160, 100);
        graphic.renderTexture(startTextTexture, nullptr, 570, 414);
        graphic.renderTexture(helpTextTexture, nullptr, 590, 504);
        graphic.renderTexture(exitTextTexture, nullptr, 580, 590);
        graphic.renderTexture(borderTexture, nullptr, SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2+40);
        graphic.renderTexture(borderTexture, nullptr, SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2+126);
        graphic.renderTexture(borderTexture, nullptr, SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2+212);
    }

    void doMenu2(Game& game, Sound& sound){
        if ( sound.musicPlaying() && game.soundStatus != 0) sound.stopMusic();
        game.soundStatus = 0;
        if ( !sound.musicPlaying()) sound.playMusic(bgMusic);
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
//        cout << mouse_x << " " << mouse_y << endl;
        if ( mouse_x >= 570 && mouse_x <= 715 && mouse_y >= 420 && mouse_y <= 460){
            menuTextColor = {0, 0, 0, 0};
        }
        else menuTextColor = {255, 255, 255, 255};

        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 575 && mouse_x <= 700 && mouse_y >= 420 && mouse_y <= 460){
                   game.gameStatus = 0;
                }
                break;
            }
        }

    }

    void drawMenu2(Graphics& graphic){
        menuTextTexture = graphic.loadTextTexture("Menu", menuTextColor, textFont);
        graphic.renderTexture(deadBackground, nullptr, 0, 0);
        graphic.renderTexture(borderTexture, nullptr, SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2+40);
        graphic.renderTexture(deadTextTexture, nullptr, 360, 100);
        graphic.renderTexture(menuTextTexture, nullptr, 570, 416);
    }

    void doMenu3(Game& game, Sound& sound){
        if ( sound.musicPlaying() && game.soundStatus != 0) sound.stopMusic();
        game.soundStatus = 0;
        if ( !sound.musicPlaying()) sound.playMusic(bgMusic);
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
//        cout << mouse_x << " " << mouse_y << endl;
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                game.gameStatus = 0;
                break;
            }
        }
    }

    void drawMenu3(Graphics& graphic){
        graphic.renderTexture(helpBackground, nullptr, 0, 0);
        graphic.renderTexture(instructTextTexture, nullptr, 25, 70);
        graphic.renderTexture(aButton, nullptr, 80, 200);
        graphic.renderTexture(dButton, nullptr, 144, 200);
        graphic.renderTexture(wButton, nullptr, 80, 300);
        graphic.renderTexture(kButton, nullptr, 80, 400);
        graphic.renderTexture(spaceButton, nullptr, 80, 500);
        graphic.renderTexture(jButton, nullptr, 80, 600);
        graphic.renderTexture(moveTextTexture, nullptr, 250, 220);
        graphic.renderTexture(climbTextTexture, nullptr, 250, 320);
        graphic.renderTexture(dashTextTexture, nullptr, 250, 420);
        graphic.renderTexture(jumpTextTexture, nullptr, 250, 520);
        graphic.renderTexture(attackTextTexture, nullptr, 250, 620);
        graphic.renderTexture(clickTextTexture, nullptr, 800, 670);
    }

    void doMenu4(Game& game, Sound& sound){
//        if ( sound.musicPlaying() && game.soundStatus != 0) sound.stopMusic();
//        game.soundStatus = 0;
//        if ( !sound.musicPlaying()) sound.playMusic(bgMusic);
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
//        cout << mouse_x << " " << mouse_y << endl;
        if ( mouse_x >= 570 && mouse_x <= 715 && mouse_y >= 420 && mouse_y <= 460){
            menuTextColor2 = {0, 0, 0, 0};
        }
        else menuTextColor2 = {255, 255, 255, 255};

        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 575 && mouse_x <= 700 && mouse_y >= 420 && mouse_y <= 460){
                   game.gameStatus = 0;
                }
                break;
            }
        }

    }

    void drawMenu4(Graphics& graphic){
        menuTextTexture2 = graphic.loadTextTexture("Menu", menuTextColor2, textFont);
        graphic.renderTexture(endBackground, nullptr, 0, 0);
        graphic.renderTexture(endTextTexture, nullptr, 370, 100);
        graphic.renderTexture(borderTexture, nullptr, SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2+40);
        graphic.renderTexture(menuTextTexture2, nullptr, 570, 416);
    }
};
#endif // _MENU__H
