#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"graphics.h"
#include"defs.h"
#include"map.h"
#include"input.h"
#include"game.h"
#include"entity.h"
#include"menu.h"
#include"sound.h"

using namespace std;

int main(int argc, char *argv[]){
    Graphics graphic;
    graphic.initSDL();
    Sound sound;
    sound.initSound();
    Menu menu;
    menu.init(graphic, sound);
    Map first_stage;
    first_stage.initMap1(graphic);
    first_stage.readMap1("map1.dat");
    Map second_stage;
    second_stage.initMap2(graphic);
    second_stage.readMap2("map2.dat");
    Map third_stage;
    third_stage.initMap3(graphic);
    Input input;
    input.init();
    Game game;
    game.init(graphic, sound);
    while(1){
        graphic.prepareScene();
        if ( game.gameStatus == 0){
            menu.drawMenu1(graphic);
            menu.doMenu1(game, sound);
        }
        if (game.gameStatus == 6){
            menu.doMenu2(game, sound);
            menu.drawMenu2(graphic);
            game.init2();
            input.init();
        }
        if ( game.gameStatus == 7){
            menu.doMenu3(game, sound);
            menu.drawMenu3(graphic);
        }
        if ( game.gameStatus == 8){
            menu.doMenu4(game, sound);
            menu.drawMenu4(graphic);
        }
        input.getInput();
        if ( game.gameStatus == 1){
            first_stage.drawMap1(graphic);
            game.doStage1(input.keyboard, first_stage, sound);
            game.drawGame(graphic, sound);
        }
        if ( game.gameStatus == 2){
            game.init2();
            game.gameStatus = 3;
        }
        if ( game.gameStatus == 3){
            second_stage.drawMap2(graphic);
            game.doStage2(input.keyboard, second_stage, sound);
            game.drawGame2(graphic, sound);
        }
        if (game.gameStatus == 4){
            game.init2();
            game.init3();
            game.gameStatus = 5;
        }
        if (game.gameStatus == 5){
            third_stage.drawMap3(graphic);
            game.doStage3(input.keyboard, third_stage, sound);
            game.drawGame3(graphic, sound);
        }
        graphic.presentScene();
    }
    graphic.close();
    return 0;
}
