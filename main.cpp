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

using namespace std;

int main(int argc, char *argv[]){
    Graphics graphic;
    graphic.initSDL();
    Menu menu;
    menu.init(graphic);
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
    game.init(graphic);
    while(1){
        graphic.prepareScene();
        if ( game.gameStatus == 0){
            menu.drawMenu1(graphic);
            menu.doMenu1(game);
        }
        if (game.gameStatus == 6){
            menu.doMenu2(game);
            menu.drawMenu2(graphic);
            game.init2();
            input.init();
        }
        if ( game.gameStatus == 7){
            menu.doMenu3(game);
            menu.drawMenu3(graphic);
        }
        input.getInput();
        if ( game.gameStatus == 1){
            first_stage.drawMap1(graphic);
            game.doStage1(input.keyboard, first_stage);
            game.drawGame(graphic);
        }
        if ( game.gameStatus == 2){
            game.init2();
            game.gameStatus = 3;
        }
        if ( game.gameStatus == 3){
            second_stage.drawMap2(graphic);
            game.doStage2(input.keyboard, second_stage);
            game.drawGame2(graphic);
        }
        if (game.gameStatus == 4){
            game.init2();
            game.init3();
            game.gameStatus = 5;
        }
        if (game.gameStatus == 5){
            third_stage.drawMap3(graphic);
            game.doStage3(input.keyboard, third_stage);
            game.drawGame3(graphic);
        }
        graphic.presentScene();
    }
    return 0;
}
