#ifndef _MAP__H
#define _MAP__H

#include<SDL.h>
#include<SDL_image.h>
#include"graphics.h"
#include"defs.h"
#include"sprite.h"

using namespace std;

struct Map{
    SDL_Texture* tile_01, *tile_02, *tile_03, *tile_10, *tile_11, *tile_12, *tile_13, *tile_18, *tile_31, *tile_32, *tile_33, *tile_34, *tile_47, *tile_60;
    SDL_Texture* tile1, *tile5, *tile7, *tile10, *tile11, *tile13, *tile14, *tile20, *tile21, *tile26, *tile27, *tile30, *tile31, *tile32, *tile33, *tile38, *tile39, *tile49, *tile53;
    SDL_Texture* backgroundTexture, *background;
    SDL_Texture* ladder_4, *ladder_5, *ladder_3;
    SDL_Texture* tree, *willow, *bush_1, *bush_2, *pointer_1, *pointer_2, *stone_1, *stone_2, *ridge_1, *ridge_2, *ridge_3, *box, *net1, *net2, *chain1, *chain2, *skull, *cage, *pot1, *pot2;
    Sprite flag;
    int map1[11][20];
    int map2[11][20];

    void initMap1(Graphics& graphic){
        flag.spriteSheetTexture = graphic.loadTexture("Image//flag.png");
        flag.init(FLAG_CLIPS, FLAG_FRAMES);
        box = graphic.loadTexture("Boxes//1.png");
        stone_1 = graphic.loadTexture("Stones//1.png");
        stone_2 = graphic.loadTexture("Stones//2.png");
        ridge_1 = graphic.loadTexture("Ridges//1.png");
        ridge_2 = graphic.loadTexture("Ridges//3.png");
        ridge_3 = graphic.loadTexture("Ridges//4.png");
        tree = graphic.loadTexture("Trees//3.png");
        willow = graphic.loadTexture("Willows//3.png");
        bush_1 = graphic.loadTexture("Bushes//9.png");
        bush_2 = graphic.loadTexture("Bushes//7.png");
        pointer_1 = graphic.loadTexture("Pointers//3.png");
        pointer_2 = graphic.loadTexture("Pointers//4.png");
        ladder_4 = graphic.loadTexture("Ladders//4.png");//74
        ladder_5 = graphic.loadTexture("Ladders//5.png");//75
        ladder_3 = graphic.loadTexture("Ladders//3.png");//73
        tile_01 = graphic.loadTexture("Tiles//Tile_01.png");
        tile_02 = graphic.loadTexture("Tiles//Tile_02.png");
        tile_03 = graphic.loadTexture("Tiles//Tile_03.png");
        tile_10 = graphic.loadTexture("Tiles//Tile_10.png");
        tile_11 = graphic.loadTexture("Tiles//Tile_11.png");
        tile_12 = graphic.loadTexture("Tiles//Tile_12.png");
        tile_13 = graphic.loadTexture("Tiles//Tile_13.png");
        tile_18 = graphic.loadTexture("Tiles//Tile_18.png");
        tile_31 = graphic.loadTexture("Tiles//Tile_31.png");
        tile_32 = graphic.loadTexture("Tiles//Tile_32.png");
        tile_33 = graphic.loadTexture("Tiles//Tile_33.png");
        tile_34 = graphic.loadTexture("Tiles//Tile_34.png");
        tile_47 = graphic.loadTexture("Tiles//Tile_47.png");
        tile_60 = graphic.loadTexture("Tiles//Tile_60.png");
        backgroundTexture = graphic.loadTexture("image//Background.png");
    }

    void initMap2(Graphics& graphic){
        net1 = graphic.loadTexture("Tiles2//Net1.png");
        net2 = graphic.loadTexture("Tiles2//Net2.png");
        chain1 = graphic.loadTexture("Tiles2//Chain1.png");
        chain2 = graphic.loadTexture("Tiles2//Chain2.png");
        skull = graphic.loadTexture("Tiles2//Skull.png");
        cage = graphic.loadTexture("Tiles2//Cage.png");
        pot1 = graphic.loadTexture("Tiles2//Pot1.png");
        pot2 = graphic.loadTexture("Tiles2//Pot2.png");
        tile1 = graphic.loadTexture("Tiles2//Tile1.png");
        tile5 = graphic.loadTexture("Tiles2//Tile5.png");
        tile7 = graphic.loadTexture("Tiles2//Tile7.png");
        tile10 = graphic.loadTexture("Tiles2//Tile10.png");
        tile11 = graphic.loadTexture("Tiles2//Tile11.png");
        tile13 = graphic.loadTexture("Tiles2//Tile13.png");
        tile14 = graphic.loadTexture("Tiles2//Tile14.png");
        tile20 = graphic.loadTexture("Tiles2//Tile20.png");
        tile21 = graphic.loadTexture("Tiles2//Tile21.png");
        tile26 = graphic.loadTexture("Tiles2//Tile26.png");
        tile27 = graphic.loadTexture("Tiles2//Tile27.png");
        tile30 = graphic.loadTexture("Tiles2//Tile30.png");
        tile31 = graphic.loadTexture("Tiles2//Tile31.png");
        tile32 = graphic.loadTexture("Tiles2//Tile32.png");
        tile33 = graphic.loadTexture("Tiles2//Tile33.png");
        tile38 = graphic.loadTexture("Tiles2//Tile38.png");
        tile39 = graphic.loadTexture("Tiles2//Tile39.png");
        tile49 = graphic.loadTexture("Tiles2//Tile49.png");
        tile53 = graphic.loadTexture("Tiles2//Tile53.png");
    }

    void initMap3(Graphics& graphic){
        background = graphic.loadTexture("Boss//Background.png");
    }

    void readMap1(const char* fileName){
        ifstream file (fileName);
        if (file.fail()){
            cout << "Unable to load map" << endl;
        }
        int type;
        while ( file && !file.eof()){
            for ( int i = 0; i < 11; i++){
                for ( int j = 0; j < 20; j++){
                    file >> type;
                    map1[i][j] = type;
                }
            }
        }
    }

    void readMap2(const char* fileName){
        ifstream file (fileName);
        if (file.fail()){
            cout << "Unable to load map" << endl;
        }
        int type;
        while ( file && !file.eof()){
            for ( int i = 0; i < 11; i++){
                for ( int j = 0; j < 20; j++){
                    file >> type;
                    map2[i][j] = type;
                }
            }
        }
    }

    void drawMap1(Graphics& graphic){
        graphic.renderTexture(backgroundTexture, nullptr, 0, 0);
        graphic.renderTexture(willow, nullptr, 852, 117);
        graphic.renderTexture(tree, nullptr, 465, 278);
        graphic.renderTexture(bush_1, nullptr, 10, 547);
        graphic.renderTexture(bush_2, nullptr, 500, 547);
        graphic.renderTexture(box, nullptr, 580, 536);
        graphic.renderTexture(pointer_1, nullptr, 140, 547);
        graphic.renderTexture(pointer_1, nullptr, 1170, 356);
        graphic.renderTexture(pointer_2, nullptr, 1070, 610);
        //flag.doSlowSprite(graphic, FLAG_FRAMES, 550, 480);
        flag.doSlowSprite2(graphic, FLAG_FRAMES, 690, 290);
        graphic.renderTexture(stone_1, nullptr, 760, 140);
        graphic.renderTexture(ridge_1, nullptr, 50, 352);
        graphic.renderTexture(stone_2, nullptr, 20, 330);
        graphic.renderTexture(ridge_2, nullptr, 60, 102);
        graphic.renderTexture(ridge_3, nullptr, 960, 540);
        flag.doSlowSprite2(graphic, FLAG_FRAMES, 20, 96);
        int type = 0;
        for ( int row = 0; row < 11; row++){
            for ( int col = 0 ; col < 20; col++){
                type = map1[row][col];
                switch(type){
                case 1:
                    graphic.renderTexture(tile_01, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 2:
                    graphic.renderTexture(tile_02, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 3:
                    graphic.renderTexture(tile_03, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 10:
                    graphic.renderTexture(tile_10, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 11:
                    graphic.renderTexture(tile_11, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 12:
                    graphic.renderTexture(tile_12, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 13:
                    graphic.renderTexture(tile_13, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 18:
                    graphic.renderTexture(tile_18, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 31:
                    graphic.renderTexture(tile_31, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 32:
                    graphic.renderTexture(tile_32, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 33:
                    graphic.renderTexture(tile_33, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 34:
                    graphic.renderTexture(tile_34, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 47:
                    graphic.renderTexture(tile_47, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 60:
                    graphic.renderTexture(tile_60, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 74:
                    graphic.renderTexture(ladder_4, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 75:
                    graphic.renderTexture(ladder_5, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 73:
                    graphic.renderTexture(ladder_3, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                }
            }
        }
    }

    void drawMap2(Graphics& graphic){
        int type = 0;
        for ( int row = 0; row < 11; row++){
            for ( int col = 0 ; col < 20; col++){
                type = map2[row][col];
                switch(type){
                case 1:
                    graphic.renderTexture(tile1, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 5:
                    graphic.renderTexture(tile5, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 7:
                    graphic.renderTexture(tile7, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 10:
                    graphic.renderTexture(tile10, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 11:
                    graphic.renderTexture(tile11, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 13:
                    graphic.renderTexture(tile13, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 14:
                    graphic.renderTexture(tile14, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 20:
                    graphic.renderTexture(tile20, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 21:
                    graphic.renderTexture(tile21, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 26:
                    graphic.renderTexture(tile26, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 27:
                    graphic.renderTexture(tile27, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 30:
                    graphic.renderTexture(tile30, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 31:
                    graphic.renderTexture(tile31, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 32:
                    graphic.renderTexture(tile32, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 33:
                    graphic.renderTexture(tile33, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 38:
                    graphic.renderTexture(tile38, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 39:
                    graphic.renderTexture(tile39, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 49:
                    graphic.renderTexture(tile49, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;
                case 53:
                    graphic.renderTexture(tile53, nullptr, col*TILE_SIZE, row*TILE_SIZE);
                    break;

                }
            }
        }
        graphic.renderTexture(net1, nullptr, 384, 190);
        graphic.renderTexture(net2, nullptr, 0, 510);
        graphic.renderTexture(chain1, nullptr, 600, 510);
        graphic.renderTexture(skull, nullptr, 700, 430);
        graphic.renderTexture(cage, nullptr, 820, 190);
        graphic.renderTexture(chain2, nullptr, 300, 0);
        graphic.renderTexture(chain2, nullptr, 900, 0);
        graphic.renderTexture(pot1, nullptr, 300, 88);
        graphic.renderTexture(pot1, nullptr, 800, 88);
        graphic.renderTexture(pot2, nullptr, 840, 88);
        graphic.renderTexture(pot1, nullptr, 400, 600);
        graphic.renderTexture(pot2, nullptr, 450, 600);
    }

    void drawMap3(Graphics& graphic){
        graphic.renderTexture(background, nullptr, 0, 0);
    }
};

#endif // _MAP__H
