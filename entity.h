#ifndef _ENTITY__H
#define _ENTITY__H

#include"sprite.h"
#include"map.h"
#include"defs.h"

struct Entity{
    int x, y, w, h, attackReload, flipStatus, moveStatus, health, hitStatus, attackStatus, firstPos;
    float dx, dy;
    SDL_Texture* texture;
    SDL_RendererFlip flip;
    Sprite idleSprite, attackSprite, runSprite, hurtSprite, castSprite;


    void move(){
        x += dx;
        y += dy;
    }

    void moveBack(){
        x -= dx;
        y -= dy;
    }

    bool outScreen(){
        return x > SCREEN_WIDTH || y > SCREEN_HEIGHT || x < 0 || y < 0;
    }

    bool onGround1(Map gameMap){
        int _x = x+PLAYER_WIDTH_EXCEED;
        if ((y+h) % TILE_SIZE == 0 && gameMap.map1[(y+h)/TILE_SIZE][(_x)/TILE_SIZE] != 0 && gameMap.map1[(y+h)/TILE_SIZE][_x/TILE_SIZE] != 75 && ( gameMap.map1[(y+h)/TILE_SIZE-1][(_x)/TILE_SIZE] == 0 || gameMap.map1[(y+h)/TILE_SIZE-1][(_x)/TILE_SIZE] == 75) )return true;
        int xPos1 =  (_x)/TILE_SIZE;
//        int xPos2 = (x+12)/TILE_SIZE;
        int yPos = (y + h + dy)/TILE_SIZE;
        if ( gameMap.map1[yPos][xPos1] != 0 && gameMap.map1[yPos][xPos1] != 75 && ( gameMap.map1[yPos-1][xPos1] == 0 || gameMap.map1[yPos-1][xPos1] == 75)){
            y = yPos*TILE_SIZE - h ;
            return true;
        }
//        else if (gameMap.map1[yPos][xPos2] != 0 && gameMap.map1[yPos][xPos2] != 75 && ( gameMap.map1[yPos-1][xPos2] == 0 || gameMap.map1[yPos-1][xPos2] == 75)){
//            y = yPos*TILE_SIZE - h ;
//            return true;
//        }
        return false;
    }

    bool onGround2(Map gameMap){
        int curPos = gameMap.map2[(y+h)/TILE_SIZE][(x+32)/TILE_SIZE];
        int xPos1 = (x+32)/TILE_SIZE;
        int xPos2 = (x+12)/TILE_SIZE;
        int yPos = (y + h + dy)/TILE_SIZE;
        if ((y+h)% TILE_SIZE == 0 && curPos != 5 && curPos != 49 && curPos != 53 && curPos != 20 && curPos != 21 && curPos != 26 && curPos != 27 && curPos != 32 && curPos != 33 && curPos != 38 && curPos != 39) return true;
        if ( gameMap.map2[yPos][xPos1] != 5 && gameMap.map2[yPos][xPos1] != 49 && gameMap.map2[yPos][xPos1] != 53 && gameMap.map2[yPos][xPos1] != 20 && gameMap.map2[yPos][xPos1] != 21 && gameMap.map2[yPos][xPos1] != 26 && gameMap.map2[yPos][xPos1] != 27 && gameMap.map2[yPos][xPos1] != 32 && gameMap.map2[yPos][xPos1] != 33 && gameMap.map2[yPos][xPos1] != 38 && gameMap.map2[yPos][xPos1] != 39){
            y = yPos*TILE_SIZE - h ;
            return true;
        }
        else if (gameMap.map2[yPos][xPos2] != 5 && gameMap.map2[yPos][xPos2] != 49 && gameMap.map2[yPos][xPos2] != 53 && gameMap.map2[yPos][xPos2] != 20 && gameMap.map2[yPos][xPos2] != 21 && gameMap.map2[yPos][xPos2] != 26 && gameMap.map2[yPos][xPos2] != 27 && gameMap.map2[yPos][xPos2] != 32 && gameMap.map2[yPos][xPos2] != 33 && gameMap.map2[yPos][xPos2] != 38 && gameMap.map2[yPos][xPos2] != 39){
            y = yPos*TILE_SIZE - h ;
            return true;
        }
        return false;
    }

    bool onGround3(Map gameMap){
        if ( y + h >= 630) y = 630 - h;
        return y == 630 - h;
    }

    void horizontalCollide2(Map gameMap){
        int curPos1 = gameMap.map2[int(y+20)/TILE_SIZE][int(x+w+dx)/TILE_SIZE];
        int curPos2 = gameMap.map2[int(y+20)/TILE_SIZE][int(x-dx)/TILE_SIZE];
        if ( curPos1 != 5 && curPos1 != 49 && curPos1 != 53 && curPos1 != 20 && curPos1 != 21 && curPos1 != 26 && curPos1 != 27 && curPos1 != 32 && curPos1 != 33 && curPos1 != 38 && curPos1 != 39){
            x -= PLAYER_RUN_SPEED;
        }
        else if ( curPos2 != 5 && curPos2 != 49 && curPos2 != 53 && curPos2 != 20 && curPos2 != 21 && curPos2 != 26 && curPos2 != 27 && curPos2 != 32 && curPos2 != 33 && curPos2 != 38 && curPos2 != 39){
            x += PLAYER_RUN_SPEED;
        }
    }

    void verticalCollide2(Map gameMap){
        int curPos = gameMap.map2[int(y)/TILE_SIZE][int(x)/TILE_SIZE];
        if ( curPos != 5 && curPos != 49 && curPos != 53 && curPos != 20 && curPos != 21 && curPos != 26 && curPos != 27 && curPos != 32 && curPos != 33 && curPos != 38 && curPos != 39){
            y += 10;
        }
    }

    bool collide(Entity* other){
        return (max(x, other->x) < min(x + w, other->x + other->w))
	        && (max(y, other->y) < min(y + h, other->y + other->h));
    }

    int getEntityStatus(){
        return moveStatus;
    }
};
#endif // _ENTITY__H

