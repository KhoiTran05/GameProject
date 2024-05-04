#ifndef _GAME__H
#define _GAME__H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"defs.h"
#include"entity.h"
#include"graphics.h"

using namespace std;

struct Game{
    Entity player, angel_1, angel_2, angel_3, angel_4, angel_5, chest_1, chest_2, chest_3, chest_4, chest_5, chest_6, chest_7, key_1, key_2, key_3, key_4, key_5, key_6, key_7, portal, skeleton, flyingEye, boss;
    Entity spikeTrap1, spikeTrap2, spikeTrap3, spikeTrap4, spikeTrap5, spearTrap1, spearTrap2, shooter1, shooter2, shooter3, shooter4, spell;
    list<Entity*> skills, bullets_1, bullets_2, bullets_3, bullets_4, bullets_5, arrow1, arrow2, arrow3, arrow4, swords, bombs, bossSkills;
    SDL_Texture* skillTexture, *enemyBulletTexture_1, *enemyBulletTexture_2, *healthBar[11], *keyTextTexure, *keyTexture, *portalTexture, *arrowTexture, *swordTexture, *bombTexture, *bossSkillTexture1, *bossHealthTextTexrture;
    SDL_Texture* warningTextTexture, *healthTexture, *bossNameTexture, *timeTexture, *spellTexture1, *spellTexture2;
    SDL_Color textColor, healthTextColor, nameColor;
    TTF_Font* textFont, *textFont2;
    stringstream keyText1, keyText2, bossHealthText, bossName, timeText, warningText;
    int keyCount1, keyCount2, gameStatus = 0, jumpCount = 0;
    Uint32 lastTrapDropTime1 = 0, lastTrapDropTime1_1 = 0, lastTrapDropTime2 = 0, lastTrapDropTime2_1 = 0, arrowSpawnTime1 = 0, arrowSpawnTime2 = 0, arrowSpawnTime3 = 0, arrowSpawnTime4 = 0, swordSpawnTime = 0, bombSpawnTime = 0, bossSkillSpawnTime, spellSpawnTime, time;
    Uint32 dashReloadTime = 0, skillReloadTime = 0;

    void init(Graphics& graphic){
        initPlayer();
        initFirstAngel();
        initSecondAngel();
        initThirdAngel();
        initFourthAngel();
        initFifthAngel();
        initSpikeTrap1();
        initSpikeTrap2();
        initSpikeTrap3();
        initSpikeTrap4();
        initSpikeTrap5();
        initSpearTrap1();
        initSpearTrap2();
        initShooter1();
        initShooter2();
        initShooter3();
        initShooter4();
        initSkeleton();
        initFlyingEye();
        initBoss(); asdagadsafasfa
        player.attackSprite.spriteSheetTexture = graphic.loadTexture("Wizard//Attack1.png");
        player.idleSprite.spriteSheetTexture = graphic.loadTexture("Wizard//Idle1.png");
        player.runSprite.spriteSheetTexture = graphic.loadTexture("Wizard//Run1.png");
        player.hurtSprite.spriteSheetTexture = graphic.loadTexture("Wizard//Hurt.png");
        skillTexture = graphic.loadTexture("Wizard//Skill.png");
        angel_1.attackSprite.spriteSheetTexture = graphic.loadTexture("Angel1//RunThrow.png");
        angel_1.idleSprite.spriteSheetTexture = graphic.loadTexture("Angel1//Idle.png");
        angel_1.hurtSprite.spriteSheetTexture = graphic.loadTexture("Angel1//Hurt.png");
        angel_2.attackSprite.spriteSheetTexture = graphic.loadTexture("Angel1//RunThrow.png");
        angel_2.idleSprite.spriteSheetTexture = graphic.loadTexture("Angel1//Idle.png");
        angel_2.hurtSprite.spriteSheetTexture = graphic.loadTexture("Angel1//Hurt.png");
        angel_3.attackSprite.spriteSheetTexture = graphic.loadTexture("Angel2//RunThrow.png");
        angel_3.idleSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Idle.png");
        angel_3.hurtSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Hurt.png");
        angel_4.attackSprite.spriteSheetTexture = graphic.loadTexture("Angel2//RunThrow.png");
        angel_4.idleSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Idle.png");
        angel_4.hurtSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Hurt.png");
        angel_5.attackSprite.spriteSheetTexture = graphic.loadTexture("Angel2//RunThrow.png");
        angel_5.idleSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Idle.png");
        angel_5.hurtSprite.spriteSheetTexture = graphic.loadTexture("Angel2//Hurt.png");
        chest_1.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_1.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_2.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_2.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_3.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_3.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_4.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_4.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_5.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_5.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_6.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_6.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_7.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_7.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        enemyBulletTexture_1 = graphic.loadTexture("Angel1//Sword1.png");
        enemyBulletTexture_2 = graphic.loadTexture("Angel2//Sword.png");
        key_1.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_1.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_2.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_2.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_3.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_3.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_4.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_4.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_5.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_5.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_6.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_6.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_7.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_7.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        healthBar[0] = graphic.loadTexture("Image//HB0.png");
        healthBar[1] = graphic.loadTexture("Image//HB1.png");
        healthBar[2] = graphic.loadTexture("Image//HB2.png");
        healthBar[3] = graphic.loadTexture("Image//HB3.png");
        healthBar[4] = graphic.loadTexture("Image//HB4.png");
        healthBar[5] = graphic.loadTexture("Image//HB5.png");
        healthBar[6] = graphic.loadTexture("Image//HB6.png");
        healthBar[7] = graphic.loadTexture("Image//HB7.png");
        healthBar[8] = graphic.loadTexture("Image//HB8.png");
        healthBar[9] = graphic.loadTexture("Image//HB9.png");
        healthBar[10] = graphic.loadTexture("Image//HB10.png");
        portal.idleSprite.spriteSheetTexture = graphic.loadTexture("Image//Portal1.png");
        portal.idleSprite.init(PORTAL_CLIPS, PORTAL_FRAMES);
        textFont = graphic.loadFont("Image/NotJamChunkySans.ttf", 25);
        textFont2 = graphic.loadFont("Image/NotJamChunkySans.ttf", 17);
        textColor = {225, 225, 125, 255};
        keyTexture = graphic.loadTexture("Image//Key.png");
        key_1.health = 1;
        key_2.health = 1;
        key_3.health = 1;
        key_4.health = 1;
        key_5.health = 1;
        key_6.health = 1;
        key_7.health = 1;
        keyCount1 = 0;
        keyCount2 = 0;
        spikeTrap1.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spike.png");
        spikeTrap1.idleSprite.init(SPIKE_TRAP_CLIPS, SPIKE_TRAP_FRAMES);
        spikeTrap2.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spike.png");
        spikeTrap2.idleSprite.init(SPIKE_TRAP_CLIPS, SPIKE_TRAP_FRAMES);
        spikeTrap3.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spike.png");
        spikeTrap3.idleSprite.init(SPIKE_TRAP_CLIPS, SPIKE_TRAP_FRAMES);
        spikeTrap4.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spike.png");
        spikeTrap4.idleSprite.init(SPIKE_TRAP_CLIPS, SPIKE_TRAP_FRAMES);
        spikeTrap5.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spike.png");
        spikeTrap5.idleSprite.init(SPIKE_TRAP_CLIPS, SPIKE_TRAP_FRAMES);
        spearTrap1.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spear.png");
        spearTrap1.idleSprite.init(SPEAR_CLIPS, SPEAR_FRAMES);
        spearTrap2.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Spear.png");
        spearTrap2.idleSprite.init(SPEAR_CLIPS, SPEAR_FRAMES);
        shooter1.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Shooter.png");
        shooter1.idleSprite.init(SHOOTER_TRAP_CLIPS,SHOOTER_TRAP_FRAMES);
        arrowTexture = graphic.loadTexture("Tiles2//Arrow.png");
        shooter2.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Shooter.png");
        shooter2.idleSprite.init(SHOOTER_TRAP_CLIPS,SHOOTER_TRAP_FRAMES);
        shooter3.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Shooter.png");
        shooter3.idleSprite.init(SHOOTER_TRAP_CLIPS,SHOOTER_TRAP_FRAMES);
        shooter4.idleSprite.spriteSheetTexture = graphic.loadTexture("Tiles2//Shooter.png");
        shooter4.idleSprite.init(SHOOTER_TRAP_CLIPS,SHOOTER_TRAP_FRAMES);
        skeleton.attackSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Attack.png");
        skeleton.idleSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Idle.png");
        skeleton.runSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Walk.png");
        skeleton.hurtSprite.spriteSheetTexture = graphic.loadTexture("Skeleton///Hurt.png");
        swordTexture = graphic.loadTexture("Skeleton//Sword.png");
        flyingEye.idleSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Flight.png");
        flyingEye.attackSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Attack.png");
        flyingEye.hurtSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Hurt.png");
        bombTexture = graphic.loadTexture("Flying Eye//Bomb.png");
        boss.attackSprite.spriteSheetTexture = graphic.loadTexture("Boss//Attack.png");
        boss.idleSprite.spriteSheetTexture = graphic.loadTexture("Boss//Idle.png");
        boss.hurtSprite.spriteSheetTexture = graphic.loadTexture("Boss//Hurt.png");
        boss.runSprite.spriteSheetTexture = graphic.loadTexture("Boss//Walk.png");
        boss.castSprite.spriteSheetTexture = graphic.loadTexture("Boss//Cast.png");
        spellTexture1 = graphic.loadTexture("Boss//Spell.png");
        healthTextColor = {255, 255, 255, 255};
        healthTexture = graphic.loadTexture("Boss//Health.png");
        nameColor = {170, 100, 200, 0};
        spellTexture2 = graphic.loadTexture("Boss//Spell.2.png");
    }

    void init2(){
        initPlayer();
        initPlayer();
        initFirstAngel();
        initSecondAngel();
        initThirdAngel();
        initFourthAngel();
        initFifthAngel();
        initSpikeTrap1();
        initSpikeTrap2();
        initSpikeTrap3();
        initSpikeTrap4();
        initSpikeTrap5();
        initSpearTrap1();
        initSpearTrap2();
        initShooter1();
        initShooter2();
        initShooter3();
        initShooter4();
        initSkeleton();
        initFlyingEye();
        initBoss();
        key_1.health = 1;
        key_2.health = 1;
        key_3.health = 1;
        key_4.health = 1;
        key_5.health = 1;
        key_6.health = 1;
        key_7.health = 1;
        keyCount1 = 0;
        keyCount2 = 0;
    }

    void init3(){
        bossSkillSpawnTime = 0;
        spellSpawnTime = 0;
        time = SDL_GetTicks();
    }

    void initPlayer(){
        player.w = 50;
        player.h = 80;
        if ( gameStatus == 0){
            player.x = 0;
            player.y = 512 - player.h;
        }
        else if ( gameStatus == 2){
            player.x = 0;
            player.y = 640 - player.h;
//            player.x = 750;
//            player.y = 448 - player.w;
        }
        else if ( gameStatus == 4){
            player.x = 0;
            player.y = 630 - player.h;
        }
        player.dx = 0;
        player.dy = 0;
        player.attackStatus = 0;
        player.moveStatus = 0;
        player.attackReload = 0;
        player.health = 10;
        player.flip = SDL_FLIP_NONE;
        player.flipStatus = 0;
        player.idleSprite.init(PLAYER_IDLE_CLIPS, PLAYER_IDLE_FRAMES);
        player.attackSprite.init(PLAYER_ATTACK_CLIPS, PLAYER_ATTACK_FRAMES);
        player.runSprite.init(PLAYER_RUN_CLIPS, PLAYER_RUN_FRAMES);
        player.hurtSprite.init(PLAYER_HURT_CLIPS, PLAYER_HURT_FRAMES);
    }

    void initBoss(){
        boss.attackSprite.init(BOSS_ATTACK_CLIPS, BOSS_ATTACK_FRAMES);
        boss.idleSprite.init(BOSS_IDLE_CLIPS, BOSS_IDLE_FRAMES);
        boss.hurtSprite.init(BOSS_HURT_CLIPS, BOSS_HURT_FRAMES);
        boss.runSprite.init(BOSS_WALK_CLIPS, BOSS_WALK_FRAMES);
        boss.castSprite.init(BOSS_CAST_CLIPS, BOSS_CAST_FRAMES);
        boss.w = 300;
        boss.h = 200;
        boss.x = SCREEN_WIDTH - 300;
        boss.y = 630 - boss.h;
        boss.dx = 3;
        boss.dy = 0;
        boss.attackStatus = 0;
        boss.moveStatus = 0;
        boss.health = 40;
        boss.firstPos = boss.x;
        boss.flip = SDL_FLIP_NONE;
    }

    void initSpell(){
        if ( SDL_GetTicks() - time < 38000){
            spell.attackSprite.init(BOSS_SPELL_CLIPS, BOSS_SPELL_FRAMES);
            spell.attackSprite.spriteSheetTexture = spellTexture1;
            spell.w = 136;
            spell.h = 250;
            spell.x = player.x-30;
            spell.y = 380;
        }
        else{
            spell.castSprite.init(BOSS_SPELL_CLIPS2, BOSS_SPELL_FRAMES);
            spell.castSprite.spriteSheetTexture = spellTexture2;
            spell.w = 191;
            spell.h = 350;
            spell.x = player.x - 85;
            spell.y = 280;
        }
    }

    void initFirstAngel(){
        angel_1.attackSprite.init(ANGEL_ATTACK_CLIPS, ANGEL_ATTACK_FRAMES);
        angel_1.idleSprite.init(ANGEL_IDLE_CLIPS, ANGEL_IDLE_FRAMES);
        angel_1.hurtSprite.init(ANGEL_HURT_CLIPS, ANGEL_HURT_FRAMES);
        angel_1.health = 5;
        angel_1.attackStatus = 0;
        angel_1.moveStatus = 0;
        angel_1.flip = SDL_FLIP_HORIZONTAL;
        angel_1.w = 70;
        angel_1.h = 80;
        angel_1.x = 650;
        angel_1.y = 580 - angel_1.h;
        angel_1.dx = 1.5;
        angel_1.dy = 0;
        angel_1.firstPos = angel_1.x;
        angel_1.attackReload = 0;
    }

    void initSecondAngel(){
        angel_2.attackSprite.init(ANGEL_ATTACK_CLIPS, ANGEL_ATTACK_FRAMES);
        angel_2.idleSprite.init(ANGEL_IDLE_CLIPS, ANGEL_IDLE_FRAMES);
        angel_2.hurtSprite.init(ANGEL_HURT_CLIPS, ANGEL_HURT_FRAMES);
        angel_2.health = 5;
        angel_2.attackStatus = 0;
        angel_2.moveStatus = 0;
        angel_2.flip = SDL_FLIP_HORIZONTAL;
        angel_2.w = 70;
        angel_2.h = 80;
        angel_2.x = 1150;
        angel_2.y = 642 - angel_2.h;
        angel_2.dx = 1.5;
        angel_2.dy = 0;
        angel_2.firstPos = angel_2.x;
        angel_2.attackReload = 0;
    }

    void initThirdAngel(){
        angel_3.attackSprite.init(ANGEL_ATTACK_CLIPS, ANGEL_ATTACK_FRAMES);
        angel_3.idleSprite.init(ANGEL_IDLE_CLIPS, ANGEL_IDLE_FRAMES);
        angel_3.hurtSprite.init(ANGEL_HURT_CLIPS, ANGEL_HURT_FRAMES);
        angel_3.health = 5;
        angel_3.attackStatus = 0;
        angel_3.moveStatus = 0;
        angel_3.flip = SDL_FLIP_NONE;
        angel_3.w = 70;
        angel_3.h = 80;
        angel_3.x = 1000;
        angel_3.y = 194 - angel_3.h;
        angel_3.dx = 1.5;
        angel_3.dy = 0;
        angel_3.firstPos = angel_3.x;
        angel_3.attackReload = 0;
    }

    void initFourthAngel(){
        angel_4.attackSprite.init(ANGEL_ATTACK_CLIPS, ANGEL_ATTACK_FRAMES);
        angel_4.idleSprite.init(ANGEL_IDLE_CLIPS, ANGEL_IDLE_FRAMES);
        angel_4.hurtSprite.init(ANGEL_HURT_CLIPS, ANGEL_HURT_FRAMES);
        angel_4.health = 5;
        angel_4.attackStatus = 0;
        angel_4.moveStatus = 0;
        angel_4.flip = SDL_FLIP_NONE;
        angel_4.w = 70;
        angel_4.h = 80;
        angel_4.x = 60;
        angel_4.y = 386 - angel_4.h;
        angel_4.dx = 1.5;
        angel_4.dy = 0;
        angel_4.firstPos = angel_4.x;
        angel_4.attackReload = 0;
    }

    void initFifthAngel(){
        angel_5.attackSprite.init(ANGEL_ATTACK_CLIPS, ANGEL_ATTACK_FRAMES);
        angel_5.idleSprite.init(ANGEL_IDLE_CLIPS, ANGEL_IDLE_FRAMES);
        angel_5.hurtSprite.init(ANGEL_HURT_CLIPS, ANGEL_HURT_FRAMES);
        angel_5.health = 5;
        angel_5.attackStatus = 0;
        angel_5.moveStatus = 0;
        angel_5.flip = SDL_FLIP_NONE;
        angel_5.w = 70;
        angel_5.h = 80;
        angel_5.x = 100;
        angel_5.y = 194 - angel_5.h;
        angel_5.dx = 1.5;
        angel_5.dy = 0;
        angel_5.firstPos = angel_5.x;
        angel_5.attackReload = 0;
    }

    void initSkeleton(){
        skeleton.attackSprite.init(SKELETON_ATTACK_CLIPS, SKELETON_ATTACK_FRAMES);
        skeleton.idleSprite.init(SKELETON_IDLE_CLIPS, SKELETON_IDLE_FRAMES);
        skeleton.runSprite.init(SKELETON_WALK_CLIPS, SKELETON_WALK_FRAMES);
        skeleton.hurtSprite.init(SKELETON_HURT_CLIPS, SKELETON_HURT_FRAMES);
        skeleton.health = 5;
        skeleton.attackStatus = 0;
        skeleton.moveStatus = 0;
        skeleton.w = 75;
        skeleton.h = 86;
        skeleton.x = 800;
        skeleton.y = 362;
        skeleton.dx = 2;
        skeleton.dy = 0;
        skeleton.firstPos = skeleton.x;
        skeleton.flip= SDL_FLIP_NONE;
    }

    void initFlyingEye(){
        flyingEye.attackSprite.init(EYE_ATTACK_CLIPS, EYE_ATTACK_FRAMES);
        flyingEye.idleSprite.init(EYE_IDLE_CLIPS, EYE_IDLE_FRAMES);
        flyingEye.hurtSprite.init(EYE_HURT_CLIPS, EYE_HURT_FRAMES);
        flyingEye.health = 5;
        flyingEye.attackStatus = 0;
        flyingEye.moveStatus = 0;
        flyingEye.w = 70;
        flyingEye.h = 55;
        flyingEye.x = 500;
        flyingEye.y = 260;
        flyingEye.dx = 2;
        flyingEye.dy = 0;
        flyingEye.firstPos = flyingEye.x;
        flyingEye.flip = SDL_FLIP_NONE;
    }

    void initSkill(){
        Entity* skill = new Entity();
        skills.push_back(skill);
        skill->texture = skillTexture;
        SDL_QueryTexture(skill->texture, nullptr, nullptr, &skill->w, &skill->h);
        if ( !player.flipStatus) skill->x = player.x + 40;
        else skill->x = player.x - 20;
        skill->y = player.y + (player.h-skill->h)/2+10;
        skill->firstPos = skill->x;
        skill->dx = SKILL_SPEED;
        skill->health = 0;
        skill->flipStatus = 2;
    }

    void initEnemyBullet_1(){
        if (angel_1.attackStatus == 1 && angel_1.attackReload < 0){
            //cout << "1" << " ";
            Entity* bullet = new Entity();
            bullets_1.push_back(bullet);
            bullet->texture = enemyBulletTexture_1;
            SDL_QueryTexture(bullet->texture, nullptr, nullptr, &bullet->w, &bullet->h);
            if ( angel_1.flip == SDL_FLIP_HORIZONTAL) bullet->x = angel_1.x - 30;
            else bullet->x = angel_1.x + 40;
            bullet->y = angel_1.y + (angel_1.h - bullet->h)/2+20;
            bullet->firstPos = bullet->x;
            bullet->dx = 3;
            bullet->dy = 0;
            bullet->flip = angel_1.flip;
            bullet->health = 1;
            angel_1.attackReload = 80;
        }
        angel_1.attackReload--;
    }

    void initEnemyBullet_2(){
        if (angel_2.attackStatus == 1 && angel_2.attackReload < 0){
            Entity* bullet = new Entity();
            bullets_2.push_back(bullet);
            bullet->texture = enemyBulletTexture_1;
            SDL_QueryTexture(bullet->texture, nullptr, nullptr, &bullet->w, &bullet->h);
            if ( angel_2.flip == SDL_FLIP_HORIZONTAL) bullet->x = angel_2.x - 30;
            else bullet->x = angel_2.x + 40;
            bullet->y = angel_2.y + (angel_2.h - bullet->h)/2+20;
            bullet->firstPos = bullet->x;
            bullet->dx = 3;
            bullet->dy = 0;
            bullet->flip = angel_2.flip;
            bullet->health = 1;
            angel_2.attackReload = 80;
        }
        angel_2.attackReload--;
    }

    void initEnemyBullet_3(){
        if (angel_3.attackStatus == 1 && angel_3.attackReload < 0){
            Entity* bullet = new Entity();
            bullets_3.push_back(bullet);
            bullet->texture = enemyBulletTexture_2;
            SDL_QueryTexture(bullet->texture, nullptr, nullptr, &bullet->w, &bullet->h);
            if ( angel_3.flip == SDL_FLIP_HORIZONTAL) bullet->x = angel_3.x - 30;
            else bullet->x = angel_3.x + 40;
            bullet->y = angel_3.y + (angel_3.h - bullet->h)/2+20;
            bullet->firstPos = bullet->x;
            bullet->dx = 3;
            bullet->dy = 0;
            bullet->flip = angel_3.flip;
            bullet->health = 1;
            angel_3.attackReload = 80;
        }
        angel_3.attackReload--;
    }

    void initEnemyBullet_4(){
        if (angel_4.attackStatus == 1 && angel_4.attackReload < 0){
            Entity* bullet = new Entity();
            bullets_4.push_back(bullet);
            bullet->texture = enemyBulletTexture_2;
            SDL_QueryTexture(bullet->texture, nullptr, nullptr, &bullet->w, &bullet->h);
            if ( angel_4.flip == SDL_FLIP_HORIZONTAL) bullet->x = angel_4.x - 30;
            else bullet->x = angel_4.x + 40;
            bullet->y = angel_4.y + (angel_4.h - bullet->h)/2+20;
            bullet->firstPos = bullet->x;
            bullet->dx = 3;
            bullet->dy = 0;
            bullet->flip = angel_4.flip;
            bullet->health = 1;
            angel_4.attackReload = 80;
        }
        angel_4.attackReload--;
    }

    void initEnemyBullet_5(){
        if (angel_5.attackStatus == 1 && angel_5.attackReload < 0){
            Entity* bullet = new Entity();
            bullets_5.push_back(bullet);
            bullet->texture = enemyBulletTexture_2;
            SDL_QueryTexture(bullet->texture, nullptr, nullptr, &bullet->w, &bullet->h);
            if ( angel_5.flip == SDL_FLIP_HORIZONTAL) bullet->x = angel_5.x - 30;
            else bullet->x = angel_5.x + 40;
            bullet->y = angel_5.y + (angel_5.h - bullet->h)/2+20;
            bullet->firstPos = bullet->x;
            bullet->dx = 3;
            bullet->dy = 0;
            bullet->flip = angel_5.flip;
            bullet->health = 1;
            angel_5.attackReload = 80;
        }
        angel_5.attackReload--;
    }

    void initSword(){
        Entity* sword = new Entity();
        swords.push_back(sword);
        sword->attackSprite.spriteSheetTexture = swordTexture;
        sword->attackSprite.init(SWORD_CLIPS, SWORD_FRAMES);
        if ( skeleton.flip == SDL_FLIP_HORIZONTAL) sword->x = skeleton.x - 40;
        else sword->x = skeleton.x + 80;
        sword->y = skeleton.y + (skeleton.h - sword->h)/2 - 20;
        sword->w = 33;
        sword->h = 33;
        sword->dx = 4;
        sword->dy = 0;
        sword->health = 1;
        sword->flip = skeleton.flip;
        sword->firstPos = sword->x;
    }

    void initBomb(){
        Entity* bomb = new Entity();
        bombs.push_back(bomb);
        bomb->attackSprite.spriteSheetTexture = bombTexture;
        bomb->attackSprite.init(BOMB_CLIPS, BOMB_FRAMES);
        if ( flyingEye.flip == SDL_FLIP_HORIZONTAL) bomb->x = flyingEye.x - 40;
        else bomb->x = flyingEye.x + 60;
        bomb->y = 380;
        bomb->w = 35;
        bomb->h = 35;
        bomb->dx = 4;
        bomb->dy = 0;
        bomb->health = 1;
        bomb->flip = flyingEye.flip;
        bomb->firstPos = bomb->x;
    }
    void initArrow1(){
        Entity* arrow = new Entity();
        arrow1.push_back(arrow);
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, nullptr, nullptr, &arrow->w, &arrow->h);
        arrow->x = 799;
        arrow->y = 520;
        arrow->dx = 0;
        arrow->dy = 2;
        arrow->health = 1;
        arrow->firstPos = arrow->y;
    }

    void initArrow2(){
        Entity* arrow = new Entity();
        arrow2.push_back(arrow);
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, nullptr, nullptr, &arrow->w, &arrow->h);
        arrow->x = 899;
        arrow->y = 520;
        arrow->dx = 0;
        arrow->dy = 2;
        arrow->health = 1;
        arrow->firstPos = arrow->y;
    }

    void initArrow3(){
        Entity* arrow = new Entity();
        arrow3.push_back(arrow);
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, nullptr, nullptr, &arrow->w, &arrow->h);
        arrow->x = 999;
        arrow->y = 520;
        arrow->dx = 0;
        arrow->dy = 2;
        arrow->health = 1;
        arrow->firstPos = arrow->y;
    }

    void initArrow4(){
        Entity* arrow = new Entity();
        arrow4.push_back(arrow);
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, nullptr, nullptr, &arrow->w, &arrow->h);
        arrow->x = 1099;
        arrow->y = 520;
        arrow->dx = 0;
        arrow->dy = 2;
        arrow->health = 1;
        arrow->firstPos = arrow->y;
    }
    void initSpikeTrap1(){
        spikeTrap1.w = 64;
        spikeTrap1.h = 64;
        spikeTrap1.x = 34;
        spikeTrap1.y = 404;
    }

    void initSpikeTrap2(){
        spikeTrap2.w = 64;
        spikeTrap2.h = 64;
        spikeTrap2.x = 228;
        spikeTrap2.y = 276;
    }

    void initSpikeTrap3(){
        spikeTrap3.w = 64;
        spikeTrap3.h = 64;
        spikeTrap3.x = 38;
        spikeTrap3.y = 148;
    }

    void initSpikeTrap4(){
        spikeTrap4.w = 64;
        spikeTrap4.h = 64;
        spikeTrap4.x = 1150;
        spikeTrap4.y = 404;
    }

    void initSpikeTrap5(){
        spikeTrap5.w = 64;
        spikeTrap5.h = 64;
        spikeTrap5.x = 1110;
        spikeTrap5.y = 404;
    }

    void initSpearTrap1(){
        spearTrap1.w = 32;
        spearTrap1.h = 192;
        spearTrap1.x = 610;
        spearTrap1.y = -20;
    }

    void initSpearTrap2(){
        spearTrap2.w = 32;
        spearTrap2.h = 192;
        spearTrap2.x = 1060;
        spearTrap2.y = -20;
    }

    void initShooter1(){
        shooter1.w = 32;
        shooter1.h = 32;
        shooter1.x = 790;
        shooter1.y = 510;
    }
     void initShooter2(){
        shooter2.w = 32;
        shooter2.h = 32;
        shooter2.x = 890;
        shooter2.y = 510;
    }

     void initShooter3(){
        shooter3.w = 32;
        shooter3.h = 32;
        shooter3.x = 990;
        shooter3.y = 510;
    }

     void initShooter4(){
        shooter4.w = 32;
        shooter4.h = 32;
        shooter4.x = 1090;
        shooter4.y = 510;
    }

    void doPlayer( int keyInput[], Map gameMap){
        if ( gameStatus == 1){
            if ( player.y >= 617) player.health = 0;
        }
        if ( gameStatus == 5){
            if (keyInput[SDL_SCANCODE_K] && SDL_GetTicks() - dashReloadTime >= 2000){
                if ( player.flip == SDL_FLIP_NONE){
                    player.x += 100;
                }
                else{
                    player.x -= 100;
                }
                dashReloadTime= SDL_GetTicks();
            }
        }
        if ( gameStatus == 1 || gameStatus == 5){
            if (keyInput[SDL_SCANCODE_D]){
                player.x += PLAYER_RUN_SPEED;
                player.flip = SDL_FLIP_NONE;
                player.flipStatus = 0;
            }
            if (keyInput[SDL_SCANCODE_A]){
                player.x -= PLAYER_RUN_SPEED;
                player.flip = SDL_FLIP_HORIZONTAL;
                player.flipStatus = 1;
            }
//            player.horizontalCollide1(gameMap);
//            player.verticalCollide1(gameMap);
        }
        else if ( gameStatus == 3){
            if (keyInput[SDL_SCANCODE_D]){
                player.x += PLAYER_RUN_SPEED;
                player.flip = SDL_FLIP_NONE;
                player.flipStatus = 0;
            }
            if (keyInput[SDL_SCANCODE_A]){
                player.x -= PLAYER_RUN_SPEED;
                player.flip = SDL_FLIP_HORIZONTAL;
                player.flipStatus = 1;
            }
            player.horizontalCollide2(gameMap);
            player.verticalCollide2(gameMap);
        }

        if ( keyInput[SDL_SCANCODE_A] == 1 || keyInput[SDL_SCANCODE_D] == 1){
            player.moveStatus = 1;
            player.attackStatus = 3;
        }
        else if (keyInput[SDL_SCANCODE_A] == 0 || keyInput[SDL_SCANCODE_D] == 0){
            player.moveStatus = 0;
        }

        if (keyInput[SDL_SCANCODE_J] && SDL_GetTicks() - skillReloadTime >= 1000){
            initSkill();
            player.attackStatus = 1;
            player.moveStatus = 2;
            skillReloadTime = SDL_GetTicks();
        }
        if ( gameStatus == 1){
            if ( (gameMap.map1[(player.y+player.h)/TILE_SIZE][(player.x+PLAYER_WIDTH_EXCEED)/TILE_SIZE] == 75 || gameMap.map1[(player.y+player.h)/TILE_SIZE-1][(player.x+PLAYER_WIDTH_EXCEED)/TILE_SIZE] == 75) && keyInput[SDL_SCANCODE_W]){
                player.dy = 0;
                player.y -= PLAYER_RUN_SPEED;
            }
            if( !player.onGround1 (gameMap)){
                player.dy += GRAVITY_ACCELERATION1;
            }
            else player.dy = 0;

            if (keyInput[SDL_SCANCODE_SPACE] && player.onGround1(gameMap)){
                player.dy  -= PLAYER_JUMP_SPEED;
            }
        }
        else if (gameStatus == 3){
            if (!player.onGround2(gameMap)){
                player.dy += GRAVITY_ACCELERATION2;
            }
            else player.dy = 0;

            if (keyInput[SDL_SCANCODE_SPACE] && player.onGround2(gameMap)){
                player.dy  -= PLAYER_JUMP_SPEED;
            }
        }
        else{
            if (!player.onGround3(gameMap)){
                player.dy += GRAVITY_ACCELERATION1;
            }
            else player.dy = 0;

            if (keyInput[SDL_SCANCODE_SPACE] && player.onGround3(gameMap)){
                player.dy  -= PLAYER_JUMP_SPEED;
            }
        }

        player.dy = min(player.dy, (float)MAX_GRAVITY_SPEED);
        player.move();
        if ( player.x + player.w >= SCREEN_WIDTH) player.x -= PLAYER_RUN_SPEED;
        if ( player.x < 0) player.x = 0;
        if ( player.y + player.h >= SCREEN_HEIGHT) player.y -= PLAYER_RUN_SPEED;
        if ( player.y < 0) player.y = 0;
    }

    void doFirstAngel(){
        if (angel_1.attackStatus == 1 && angel_1.health > 0){
            if (angel_1.x > player.x){
                angel_1.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(angel_1.x - player.x) > 120 && 448 < angel_1.x && angel_1.x < 664){
                    angel_1.moveBack();
                }
            }
            else if ( angel_1.x < player.x ){
                angel_1.flip = SDL_FLIP_NONE;
                if ( abs(angel_1.x - player.x) > 120 && 448 < angel_1.x && angel_1.x < 664){
                    angel_1.move();
                }
            }
        }
    }

    void doSecondAngel(){
        if (angel_2.attackStatus == 1 && angel_2.health > 0){
            if (angel_2.x > player.x){
                angel_2.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(angel_2.x - player.x) > 120 && 960 < angel_2.x && angel_2.x < 1210){
                    angel_2.moveBack();
                }
            }
            else if ( angel_2.x < player.x ){
                angel_2.flip = SDL_FLIP_NONE;
                if ( abs(angel_2.x - player.x) > 120 && 960 < angel_2.x && angel_2.x < 1210){
                    angel_2.move();
                }
            }
        }
    }

    void doThirdAngel(){
        if (angel_3.attackStatus == 1 && angel_3.health > 0){
            if (angel_3.x > player.x){
                angel_3.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(angel_3.x - player.x) > 120 && 960 < angel_3.x && angel_3.x < 1210){
                    angel_3.moveBack();
                }
            }
            else if ( angel_3.x < player.x ){
                angel_3.flip = SDL_FLIP_NONE;
                if ( abs(angel_3.x - player.x) > 120 && 960 < angel_3.x && angel_3.x < 1210){
                    angel_3.move();
                }
            }
        }
    }

    void doFourthAngel(){
        if (angel_4.attackStatus == 1 && angel_4.health > 0){
            if (angel_4.x > player.x){
                angel_4.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(angel_4.x - player.x) > 120 && 0 < angel_4.x && angel_4.x < 170){
                    angel_4.moveBack();
                }
            }
            else if ( angel_4.x < player.x ){
                angel_4.flip = SDL_FLIP_NONE;
                if ( abs(angel_4.x - player.x) > 120 && 0 < angel_4.x && angel_4.x < 170){
                    angel_4.move();
                }
            }
        }
    }

    void doFifthAngel(){
        if (angel_5.attackStatus == 1 && angel_5.health > 0){
            if (angel_5.x > player.x){
                angel_5.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(angel_5.x - player.x) > 120 && 0 < angel_5.x && angel_5.x < 230){
                    angel_5.moveBack();
                }
            }
            else if ( angel_5.x < player.x ){
                angel_5.flip = SDL_FLIP_NONE;
                if ( abs(angel_5.x - player.x) > 120 && 0 < angel_5.x && angel_5.x < 230){
                    angel_5.move();
                }
            }
        }
    }

    void doSkeleton(){
        if (skeleton.attackStatus == 1 && skeleton.health > 0){
            if ( player.x > skeleton.x){
                skeleton.flip = SDL_FLIP_NONE;
                if ( abs(skeleton.x - player.x) > 160 && 500 < skeleton.x && skeleton.x < 1000 ){
                    skeleton.move();
                }
                else skeleton.attackStatus = 1;
            }
            else if ( player.x < skeleton.x){
                skeleton.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(skeleton.x - player.x) > 160 && 500 < skeleton.x && skeleton.x < 1000){
                    skeleton.moveBack();
                }
                else skeleton.attackStatus = 1;
            }
            skeleton.w = skeleton.attackSprite.clips[skeleton.attackSprite.frame/10].w;
            skeleton.h = skeleton.attackSprite.clips[skeleton.attackSprite.frame/10].h;
            skeleton.y = 448 - skeleton.h;
        }
        else if ( skeleton.attackStatus == 2 && skeleton.health > 0){
            skeleton.w = skeleton.hurtSprite.clips[skeleton.hurtSprite.frame/6].w;
            skeleton.h = skeleton.hurtSprite.clips[skeleton.hurtSprite.frame/6].h;
            skeleton.y = 448 - skeleton.h;
        }
        else{
            if ( player.x > skeleton.x ) skeleton.flip = SDL_FLIP_NONE;
            else skeleton.flip = SDL_FLIP_HORIZONTAL;
            skeleton.w = skeleton.idleSprite.clips[skeleton.idleSprite.frame/10].w;
            skeleton.w = skeleton.idleSprite.clips[skeleton.idleSprite.frame/10].h;
            skeleton.y = 448 - skeleton.h;
        }
    }

    void doFlyingEye(){
        if (flyingEye.attackStatus == 1 && flyingEye.health > 0){
            if ( player.x > flyingEye.x){
                flyingEye.flip = SDL_FLIP_NONE;
                if ( abs(flyingEye.x - player.x) > 160 && 448 < flyingEye.x && flyingEye.x < 1000 ){
                    flyingEye.move();
                }
                else flyingEye.attackStatus = 1;
            }
            else if ( player.x < flyingEye.x){
                flyingEye.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(flyingEye.x - player.x) > 160 && 448 < flyingEye.x && flyingEye.x < 1000){
                    flyingEye.moveBack();
                }
                else flyingEye.attackStatus = 1;
            }
            flyingEye.w = flyingEye.attackSprite.clips[flyingEye.attackSprite.frame/10].w;
            flyingEye.h = flyingEye.attackSprite.clips[flyingEye.attackSprite.frame/10].h;
            flyingEye.y = 408 - flyingEye.h;
        }
        else if ( flyingEye.attackStatus == 2 && flyingEye.health > 0){
            flyingEye.w = flyingEye.hurtSprite.clips[flyingEye.hurtSprite.frame/6].w;
            flyingEye.h = flyingEye.hurtSprite.clips[flyingEye.hurtSprite.frame/6].h;
            flyingEye.y = 408 - flyingEye.h;
        }
        else{
            if ( player.x > flyingEye.x ) flyingEye.flip = SDL_FLIP_NONE;
            else flyingEye.flip = SDL_FLIP_HORIZONTAL;
            flyingEye.w = flyingEye.idleSprite.clips[flyingEye.idleSprite.frame/10].w;
            flyingEye.w = flyingEye.idleSprite.clips[flyingEye.idleSprite.frame/10].h;
            flyingEye.y = 408 - flyingEye.h;
        }
    }

    void doSkill(){
        auto it = skills.begin();
        while (it != skills.end()){
            auto tmp = it;
            Entity* currSkill = *tmp;
            if (!player.flipStatus && currSkill->flipStatus == 2) currSkill->flipStatus = 0;
            if ( player.flipStatus && currSkill->flipStatus == 2) currSkill->flipStatus = 1;
            if ( !currSkill->flipStatus) currSkill->move();
            if ( currSkill->flipStatus){
                currSkill->moveBack();
                currSkill->flip = SDL_FLIP_HORIZONTAL;
            }

            if (gameStatus == 1){
                if ( currSkill->outScreen()){
                    delete currSkill;
                    skills.erase(tmp);
                }
                else if ( abs(currSkill->x - currSkill->firstPos) > 150){
                    delete currSkill;
                    skills.erase(tmp);
                }
                if ( angel_1.health > 0 && currSkill->collide(&angel_1)){
                    delete currSkill;
                    skills.erase(tmp);
                    angel_1.health--;
                    angel_1.attackStatus = 2;
                }
                if ( angel_2.health > 0 && currSkill->collide(&angel_2)){
                    delete currSkill;
                    skills.erase(tmp);
                    angel_2.health--;
                    angel_2.attackStatus = 2;
                }
                if ( angel_3.health > 0 && currSkill->collide(&angel_3)){
                    delete currSkill;
                    skills.erase(tmp);
                    angel_3.health--;
                    angel_3.attackStatus = 2;
                }
               if ( angel_4.health > 0 && currSkill->collide(&angel_4)){
                    delete currSkill;
                    skills.erase(tmp);
                    angel_4.health--;
                    angel_4.attackStatus = 2;
                }
                if ( angel_5.health > 0 && currSkill->collide(&angel_5)){
                    delete currSkill;
                    skills.erase(tmp);
                    angel_5.health--;
                    angel_5.attackStatus = 2;
                }
            }

            if ( gameStatus == 3){
                if ( currSkill->outScreen()){
                    delete currSkill;
                    skills.erase(tmp);
                }
                else if ( abs(currSkill->x - currSkill->firstPos) > 150){
                    delete currSkill;
                    skills.erase(tmp);
                }
                if (skeleton.health > 0 && currSkill->collide(&skeleton)){
                    delete currSkill;
                    skills.erase(tmp);
                    skeleton.health--;
                    skeleton.attackStatus = 2;
                }
                if (flyingEye.health > 0 && currSkill->collide(&flyingEye)){
                    delete currSkill;
                    skills.erase(tmp);
                    flyingEye.health--;
                    flyingEye.attackStatus = 2;
                }
            }

            if ( gameStatus == 5){
                if ( boss.health > 0){
                    if ( currSkill->outScreen()){
                        delete currSkill;
                        skills.erase(tmp);
                    }
                    else if ( abs(currSkill->x - currSkill->firstPos) > 200){
                        delete currSkill;
                        skills.erase(tmp);
                    }
                    else if ( boss.flip == SDL_FLIP_NONE){
                        if ( currSkill->x >= boss.x + 170){
                            if ( boss.attackStatus != 3) boss.health--;
                            if ( boss.castSprite.frame == 0 ) boss.attackStatus = 2;
                            delete currSkill;
                            skills.erase(tmp);
                        }
                    }
                    else{
                        if ( currSkill->x <= boss.x + 120){
                            if ( boss.attackStatus != 3 ) boss.health--;
                            if ( boss.castSprite.frame == 0 ) boss.attackStatus = 2;
                            delete currSkill;
                            skills.erase(tmp);
                        }
                    }
                }
            }
            it++;
        }
    }

    void doEnemyBullet_1(){
        auto it = bullets_1.begin();
        while ( it != bullets_1.end()){
            auto tmp = it;
            Entity* currBullet = *tmp;
            if ( currBullet->flip == SDL_FLIP_HORIZONTAL) currBullet->moveBack();
            else currBullet->move();
            if ( currBullet->outScreen() || abs(currBullet->x - currBullet->firstPos) > 200){
                delete currBullet;
                bullets_1.erase(tmp);
            }
            if ( player.health > 0 && currBullet->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBullet;
                bullets_1.erase(tmp);
            }
            it++;
        }
    }

    void doEnemyBullet_2(){
        auto it = bullets_2.begin();
        while ( it != bullets_2.end()){
            auto tmp = it;
            Entity* currBullet = *tmp;
            if ( currBullet->flip == SDL_FLIP_HORIZONTAL) currBullet->moveBack();
            else currBullet->move();
            if ( currBullet->outScreen() || abs(currBullet->x - currBullet->firstPos) > 200){
                delete currBullet;
                bullets_2.erase(tmp);
            }
            if ( player.health > 0 && currBullet->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBullet;
                bullets_2.erase(tmp);
            }
            it++;
        }
    }

    void doEnemyBullet_3(){
        auto it = bullets_3.begin();
        while ( it != bullets_3.end()){
            auto tmp = it;
            Entity* currBullet = *tmp;
            if ( currBullet->flip == SDL_FLIP_HORIZONTAL) currBullet->moveBack();
            else currBullet->move();
            if ( currBullet->outScreen() || abs(currBullet->x - currBullet->firstPos) > 200){
                delete currBullet;
                bullets_3.erase(tmp);
            }
            if ( player.health > 0 && currBullet->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBullet;
                bullets_3.erase(tmp);
            }
            it++;
        }
    }

    void doEnemyBullet_4(){
        auto it = bullets_4.begin();
        while ( it != bullets_4.end()){
            auto tmp = it;
            Entity* currBullet = *tmp;
            if ( currBullet->flip == SDL_FLIP_HORIZONTAL) currBullet->moveBack();
            else currBullet->move();
            if ( currBullet->outScreen() || abs(currBullet->x - currBullet->firstPos) > 200){
                delete currBullet;
                bullets_4.erase(tmp);
            }
            if ( player.health > 0 && currBullet->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBullet;
                bullets_4.erase(tmp);
            }
            it++;
        }
    }

    void doEnemyBullet_5(){
        auto it = bullets_5.begin();
        while ( it != bullets_5.end()){
            auto tmp = it;
            Entity* currBullet = *tmp;
            if ( currBullet->flip == SDL_FLIP_HORIZONTAL) currBullet->moveBack();
            else currBullet->move();
            if ( currBullet->outScreen() || abs(currBullet->x - currBullet->firstPos) > 200){
                delete currBullet;
                bullets_5.erase(tmp);
            }
            if ( player.health > 0 && currBullet->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBullet;
                bullets_5.erase(tmp);
            }
            it++;
        }
    }

    void doSword(){
        auto it = swords.begin();
        while ( it != swords.end()){
            auto tmp = it;
            Entity* currSword = *tmp;
            if ( currSword->flip == SDL_FLIP_HORIZONTAL) currSword->moveBack();
            else currSword->move();
            if ( currSword->outScreen() || abs(currSword->x - currSword->firstPos) > 200 ){
                delete currSword;
                swords.erase(tmp);
            }
            if ( player.health > 0 && currSword->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currSword;
                swords.erase(tmp);
            }
            it++;
        }
    }

    void doBomb(){
        auto it = bombs.begin();
        while ( it != bombs.end()){
            auto tmp = it;
            Entity* currBomb = *tmp;
            if ( currBomb->flip == SDL_FLIP_HORIZONTAL) currBomb->moveBack();
            else currBomb->move();
            if ( currBomb->outScreen() || abs(currBomb->x - currBomb->firstPos) > 200 ){
                delete currBomb;
                bombs.erase(tmp);
            }
            if ( player.health > 0 && currBomb->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBomb;
                bombs.erase(tmp);
            }
            it++;
        }
    }


    void doBoss(){
        if ( boss.x+160 >= player.x ) boss.flip = SDL_FLIP_NONE;
        else{
            boss.flip = SDL_FLIP_HORIZONTAL;
        }

        if ( boss.flip == SDL_FLIP_NONE){
            if ( boss.attackStatus != 2 ){
                if ( SDL_GetTicks() - time - bossSkillSpawnTime >= 6000 && abs(boss.x+160-player.x-player.w) >= 140){
                    boss.attackStatus = 3;
                    bossSkillSpawnTime = SDL_GetTicks()-time;
                }
                else {
                    if ( boss.castSprite.frame == 0){
                        if( abs(boss.x+160-player.x-player.w) >= 140 && boss.attackSprite.frame == 0){
                           boss.attackStatus = 0;
                           boss.moveStatus = 1;
                           boss.moveBack();
                         }
                    else boss.attackStatus = 1;
                    }
               }
            }
        }
        else{
            if ( boss.attackStatus != 2){
                if ( SDL_GetTicks()-time - bossSkillSpawnTime >= 6000 && abs(boss.x+120-player.x) >= 140){
                    boss.attackStatus = 3;
                    bossSkillSpawnTime = SDL_GetTicks()-time;
                }
                else{
                    if ( boss.castSprite.frame == 0){
                        if ( abs(boss.x+120-player.x) >= 140 && boss.attackSprite.frame == 0){
                            boss.attackStatus = 0;
                            boss.moveStatus = 1;
                            boss.move();
                        }
                        else boss.attackStatus = 1;
                    }
                }
            }
        }

        if (boss.attackStatus == 1 && boss.attackSprite.frame == 20 && boss.collide(&player) ){
            if ( boss.flip == SDL_FLIP_NONE){
                player.health--;
                player.x -= 30;
            }
            else{
                player.health--;
                player.x += 30;
            }
        }
    }
    void doArrow1(){
        auto it = arrow1.begin();
        while ( it != arrow1.end()){
            auto tmp = it;
            Entity* currArrow = *tmp;
            currArrow->move();
            if ( abs(currArrow->y - currArrow->firstPos) > 80){
                delete currArrow;
                arrow1.erase(tmp);
            }
            if ( player.health > 0 && currArrow->collide(&player)){
                player.health--;
                player.x += 10;
                delete currArrow;
                arrow1.erase(tmp);
            }
            it++;
        }
    }

    void doArrow2(){
        auto it = arrow2.begin();
        while ( it != arrow2.end()){
            auto tmp = it;
            Entity* currArrow = *tmp;
            currArrow->move();
            if ( abs(currArrow->y - currArrow->firstPos) > 80){
                delete currArrow;
                arrow2.erase(tmp);
            }
            if ( player.health > 0 && currArrow->collide(&player)){
                player.health--;
                player.x += 10;
                delete currArrow;
                arrow2.erase(tmp);
            }
            it++;
        }
    }

    void doArrow3(){
        auto it = arrow3.begin();
        while ( it != arrow3.end()){
            auto tmp = it;
            Entity* currArrow = *tmp;
            currArrow->move();
            if ( abs(currArrow->y - currArrow->firstPos) > 80){
                delete currArrow;
                arrow3.erase(tmp);
            }
            if ( player.health > 0 && currArrow->collide(&player)){
                player.health--;
                player.x += 10;
                delete currArrow;
                arrow3.erase(tmp);
            }
            it++;
        }
    }

    void doArrow4(){
        auto it = arrow4.begin();
        while ( it != arrow4.end()){
            auto tmp = it;
            Entity* currArrow = *tmp;
            currArrow->move();
            if ( abs(currArrow->y - currArrow->firstPos) > 80){
                delete currArrow;
                arrow4.erase(tmp);
            }
            if ( player.health > 0 && currArrow->collide(&player)){
                player.health--;
                player.x += 10;
                delete currArrow;
                arrow4.erase(tmp);
            }
            it++;
        }
    }
    void doSpikeTrap1(){
        if (spikeTrap1.collide(&player)){
            player.health--;
            player.x += 15;
        }
    }

    void doSpikeTrap2(){
        if (spikeTrap2.collide(&player)){
            player.health--;
            player.x -= 15;
        }
    }

    void doSpikeTrap3(){
        if (spikeTrap3.collide(&player)){
            player.health--;
            player.x += 15;
        }
    }

    void doSpikeTrap4(){
        if (spikeTrap4.collide(&player)){
            player.health--;
            player.x -= 15;
        }
    }

    void doSpikeTrap5(){
        if (spikeTrap5.collide(&player)){
            player.health--;
            player.x -= 15;
        }
    }

    void doSpearTrap1(){
        if ( spearTrap1.collide(&player)){
            player.health--;
            if ( player.x < spearTrap1.x) player.x += 20;
            else player.x -= 20;
        }
    }

    void doSpearTrap2(){
        if ( spearTrap2.collide(&player)){
            player.health--;
            if ( player.x < spearTrap2.x) player.x += 20;
            else player.x -= 20;
        }
    }
    void doStage1(int keyInput[], Map gameMap){
        doPlayer(keyInput, gameMap);
        doSkill();
        doFirstAngel();
        doSecondAngel();
        doThirdAngel();
        doFourthAngel();
        doFifthAngel();
        if ( angel_1.health > 0){
            initEnemyBullet_1();
            doEnemyBullet_1();
        }
        if ( angel_2.health > 0){
            initEnemyBullet_2();
            doEnemyBullet_2();
        }
        if ( angel_3.health > 0){
            initEnemyBullet_3();
            doEnemyBullet_3();
        }
        if ( angel_4.health > 0){
            initEnemyBullet_4();
            doEnemyBullet_4();
        }
        if ( angel_5.health > 0){
            initEnemyBullet_5();
            doEnemyBullet_5();
        }
        if ( player.health == 0) gameStatus = 6;
    }

    void doStage2(int keyInput[], Map gameMap){
        doPlayer(keyInput, gameMap);
        doSkill();
        doSpikeTrap1();
        doSpikeTrap2();
        doSpikeTrap3();
        doSpikeTrap4();
        doSpikeTrap5();
        if (SDL_GetTicks() - lastTrapDropTime1 >= 300) {
            doSpearTrap1();
            lastTrapDropTime1 = SDL_GetTicks();
        }
        if (SDL_GetTicks() - lastTrapDropTime2 >= 300) {
            doSpearTrap2();
            lastTrapDropTime2 = SDL_GetTicks();
        }
        if ( SDL_GetTicks() - arrowSpawnTime1 >= 1000){
            initArrow1();
            arrowSpawnTime1 = SDL_GetTicks();
        }
        doArrow1();
        if ( SDL_GetTicks() - arrowSpawnTime2 >= 1000){
            initArrow2();
            arrowSpawnTime2 = SDL_GetTicks();
        }
        doArrow2();
        if ( SDL_GetTicks() - arrowSpawnTime3 >= 1000){
            initArrow3();
            arrowSpawnTime3 = SDL_GetTicks();
        }
        doArrow3();
        if ( SDL_GetTicks() - arrowSpawnTime4 >= 1000){
            initArrow4();
            arrowSpawnTime4 = SDL_GetTicks();
        }
        doArrow4();
        if ( SDL_GetTicks() - swordSpawnTime >= 1200 && skeleton.attackStatus == 1){
            initSword();
            swordSpawnTime = SDL_GetTicks();
        }
        doSword();
        doSkeleton();
        if ( SDL_GetTicks() - bombSpawnTime >= 1200 && flyingEye.attackStatus == 1){
            initBomb();
            bombSpawnTime = SDL_GetTicks();
        }
        doBomb();
        doFlyingEye();
        if ( player.health == 0) gameStatus = 6;
    }

    void doStage3(int keyInput[], Map gameMap){
        if ( SDL_GetTicks() - time >= 38000){
            boss.dx = 4;
        }
        doPlayer(keyInput, gameMap);
        doSkill();
        doBoss();
        if ( player.health == 0) gameStatus = 6;
    }

    void drawGame(Graphics& graphic){
        if ( angel_1.health > 0){
            if (angel_1.attackStatus == 2) angel_1.hurtSprite.doQuickSprite2(graphic, ANGEL_HURT_FRAMES, angel_1.x, angel_1.y, angel_1.flip);
            else if (angel_1.attackStatus == 1) angel_1.attackSprite.doSlowSprite4(graphic, ANGEL_ATTACK_FRAMES, angel_1.x, angel_1.y, angel_1.flip);
            else angel_1.idleSprite.doSlowSprite2(graphic, ANGEL_IDLE_FRAMES, angel_1.x, angel_1.y, angel_1.flip);
            if ( angel_1.hurtSprite.frame/2 >= ANGEL_HURT_FRAMES){
                angel_1.attackStatus = 1;
                angel_1.hurtSprite.frame = 0;
            }
        }
        else{
            chest_1.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, angel_1.x, angel_1.y+36);
            if ( key_1.health == 1 ) key_1.idleSprite.doSprite(graphic, KEY_FRAMES, angel_1.x+20, angel_1.y+5);
            if ( key_1.health == 1 && (( player.x + player.w >=  angel_1.x + 20 && player.x + player.w <= angel_1.x + 35 && player.flipStatus == 0) || ( player.x >=  angel_1.x + 20 && player.x <= angel_1.x + 35 && player.flipStatus == 1))){
                keyCount1++;
                key_1.health = 0;
            }
        }

        if ( angel_2.health > 0){
            if (angel_2.attackStatus == 2) angel_2.hurtSprite.doQuickSprite2(graphic, ANGEL_HURT_FRAMES, angel_2.x, angel_2.y, angel_2.flip);
            else if (angel_2.attackStatus == 1) angel_2.attackSprite.doSlowSprite4(graphic, ANGEL_ATTACK_FRAMES, angel_2.x, angel_2.y, angel_2.flip);
            else angel_2.idleSprite.doSlowSprite2(graphic, ANGEL_IDLE_FRAMES, angel_2.x, angel_2.y, angel_2.flip);
            if ( angel_2.hurtSprite.frame/2 >= ANGEL_HURT_FRAMES){
                angel_2.attackStatus = 1;
                angel_2.hurtSprite.frame = 0;
            }
        }
        else{
            chest_2.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, angel_2.x, angel_2.y+36);
            if ( key_2.health == 1) key_2.idleSprite.doSprite(graphic, KEY_FRAMES, angel_2.x+20, angel_2.y+5);
            if ( key_2.health == 1 && (( player.x + player.w >=  angel_2.x + 20 && player.x + player.w <= angel_2.x + 35 && player.flipStatus == 0) || ( player.x >=  angel_2.x + 20 && player.x <= angel_2.x + 35 && player.flipStatus == 1))){
                keyCount1++;
                key_2.health = 0;
            }
        }

        if ( angel_3.health > 0){
            if (angel_3.attackStatus == 2) angel_3.hurtSprite.doQuickSprite2(graphic, ANGEL_HURT_FRAMES, angel_3.x, angel_3.y, angel_3.flip);
            else if (angel_3.attackStatus == 1) angel_3.attackSprite.doSlowSprite4(graphic, ANGEL_ATTACK_FRAMES, angel_3.x, angel_3.y, angel_3.flip);
            else angel_3.idleSprite.doSlowSprite2(graphic, ANGEL_IDLE_FRAMES, angel_3.x, angel_3.y, angel_3.flip);
            if ( angel_3.hurtSprite.frame/2 >= ANGEL_HURT_FRAMES){
                angel_3.attackStatus = 1;
                angel_3.hurtSprite.frame = 0;
            }
        }
        else{
            chest_3.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, angel_3.x, angel_3.y+36);
            if ( key_3.health == 1) key_3.idleSprite.doSprite(graphic, KEY_FRAMES, angel_3.x+20, angel_3.y+5);
            if ( key_3.health == 1 && (( player.x + player.w >=  angel_3.x + 20 && player.x + player.w <= angel_3.x + 35 && player.flipStatus == 0) || ( player.x >=  angel_3.x + 20 && player.x <= angel_3.x + 35 && player.flipStatus == 1))){
                keyCount1++;
                key_3.health = 0;
            }
        }

        if ( angel_4.health > 0){
            if (angel_4.attackStatus == 2) angel_4.hurtSprite.doQuickSprite2(graphic, ANGEL_HURT_FRAMES, angel_4.x, angel_4.y, angel_4.flip);
            else if (angel_4.attackStatus == 1) angel_4.attackSprite.doSlowSprite4(graphic, ANGEL_ATTACK_FRAMES, angel_4.x, angel_4.y, angel_4.flip);
            else angel_4.idleSprite.doSlowSprite2(graphic, ANGEL_IDLE_FRAMES, angel_4.x, angel_4.y, angel_4.flip);
            if ( angel_4.hurtSprite.frame/2 >= ANGEL_HURT_FRAMES){
                angel_4.attackStatus = 1;
                angel_4.hurtSprite.frame = 0;
            }
        }
        else{
            chest_4.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, angel_4.x, angel_4.y+36);
            if ( key_4.health == 1) key_4.idleSprite.doSprite(graphic, KEY_FRAMES, angel_4.x+20, angel_4.y+5);
            if ( key_4.health == 1 && (( player.x + player.w >=  angel_4.x + 20 && player.x + player.w <= angel_4.x + 35 && player.flipStatus == 0) || ( player.x >=  angel_4.x + 20 && player.x <= angel_4.x + 35 && player.flipStatus == 1))){
                keyCount1++;
                key_4.health = 0;
            }
        }

        if ( angel_5.health > 0){
            if (angel_5.attackStatus == 2) angel_5.hurtSprite.doQuickSprite2(graphic, ANGEL_HURT_FRAMES, angel_5.x, angel_5.y, angel_5.flip);
            else if (angel_5.attackStatus == 1) angel_5.attackSprite.doSlowSprite4(graphic, ANGEL_ATTACK_FRAMES, angel_5.x, angel_5.y, angel_5.flip);
            else angel_5.idleSprite.doSlowSprite2(graphic, ANGEL_IDLE_FRAMES, angel_5.x, angel_5.y, angel_5.flip);
            if ( angel_5.hurtSprite.frame/2 >= ANGEL_HURT_FRAMES){
                angel_5.attackStatus = 1;
                angel_5.hurtSprite.frame = 0;
            }
        }
        else{
            chest_5.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, angel_5.x, angel_5.y+36);
            if ( key_5.health == 1) key_5.idleSprite.doSprite(graphic, KEY_FRAMES, angel_5.x+20, angel_5.y+5);
            if ( key_5.health == 1 && (( player.x + player.w >=  angel_5.x + 20 && player.x + player.w <= angel_5.x + 35 && player.flipStatus == 0) || ( player.x >=  angel_5.x + 20 && player.x <= angel_5.x + 35 && player.flipStatus == 1))){
                keyCount1++;
                key_5.health = 0;
            }
        }

        for ( Entity* skill : skills){
            graphic.renderTexture(skill->texture, nullptr, skill->x, skill->y, skill->flip);
        }

        if ( angel_1.health > 0){
            for (Entity* bullet : bullets_1){
                graphic.renderTexture(bullet->texture, nullptr, bullet->x, bullet->y, bullet->flip);
            }
        }

        if ( angel_2.health > 0){
            for (Entity* bullet : bullets_2){
                graphic.renderTexture(bullet->texture, nullptr, bullet->x, bullet->y, bullet->flip);
            }
        }

        if ( angel_3.health > 0){
            for (Entity* bullet : bullets_3){
                graphic.renderTexture(bullet->texture, nullptr, bullet->x, bullet->y, bullet->flip);
            }
        }

        if ( angel_4.health > 0){
            for (Entity* bullet : bullets_4){
                graphic.renderTexture(bullet->texture, nullptr, bullet->x, bullet->y, bullet->flip);
            }
        }

        if ( angel_5.health > 0){
            for (Entity* bullet : bullets_5){
                graphic.renderTexture(bullet->texture, nullptr, bullet->x, bullet->y, bullet->flip);
            }
        }

        keyText1.str("");
        keyText1 << to_string(keyCount1) << "/5";
        keyTextTexure = graphic.loadTextTexture(keyText1.str().c_str(), textColor, textFont);
        graphic.renderTexture(keyTextTexure, nullptr, SCREEN_WIDTH/2, 10);

        graphic.renderTexture(keyTexture, nullptr, SCREEN_WIDTH/2 + 70, 6);

        if ( keyCount1 == 5){
            portal.idleSprite.doSprite(graphic, PORTAL_FRAMES, SCREEN_WIDTH-68, SCREEN_HEIGHT-164, SDL_FLIP_HORIZONTAL);
        }

        if ( player.health > 0){
            if ( keyCount1 == 5 && player.x+player.w >= SCREEN_WIDTH-50 && player.y == 560) gameStatus = 2;
            graphic.renderTexture(healthBar[player.health], nullptr, 10, 10);
            if ( player.moveStatus == 0 && player.attackStatus != 1 && player.attackStatus != 2){
                player.idleSprite.doSlowSprite2(graphic, PLAYER_IDLE_FRAMES, player.x, player.y+2, player.flip);
            }

            if (player.moveStatus == 1 && player.attackStatus != 1 && player.attackStatus != 2){
                player.runSprite.doSprite(graphic, PLAYER_RUN_FRAMES, player.x, player.y+2, player.flip);
            }

            if ( player.attackStatus == 1){
                if ( player.flip != SDL_FLIP_NONE) player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y+2, player.flip);
                else player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y+2, player.flip);
                if ( player.attackSprite.frame/2 >= PLAYER_ATTACK_FRAMES){
                    player.attackStatus = 3;
                    player.attackSprite.frame = 0;
                }
            }
            else if ( player.attackStatus == 2){
                player.hurtSprite.doSlowSprite3(graphic, PLAYER_HURT_FRAMES, player.x, player.y, player.flip);
                if ( player.hurtSprite.frame/4 >= PLAYER_HURT_FRAMES){
                    player.attackStatus = 3;
                    player.hurtSprite.frame = 0;
                }
            }
        }
    }


    void drawGame2(Graphics& graphic){
        spikeTrap1.idleSprite.doSprite(graphic, SPIKE_TRAP_FRAMES, spikeTrap1.x, spikeTrap1.y);
        spikeTrap2.idleSprite.doSprite(graphic, SPIKE_TRAP_FRAMES, spikeTrap2.x, spikeTrap2.y);
        spikeTrap3.idleSprite.doSprite(graphic, SPIKE_TRAP_FRAMES, spikeTrap3.x, spikeTrap3.y);
        spikeTrap4.idleSprite.doSprite(graphic, SPIKE_TRAP_FRAMES, spikeTrap4.x, spikeTrap4.y);
        spikeTrap5.idleSprite.doSprite(graphic, SPIKE_TRAP_FRAMES, spikeTrap5.x, spikeTrap5.y);
        shooter1.idleSprite.doSlowSprite2(graphic, SHOOTER_TRAP_FRAMES, shooter1.x, shooter1.y);
        shooter2.idleSprite.doSlowSprite2(graphic, SHOOTER_TRAP_FRAMES, shooter2.x, shooter2.y);
        shooter3.idleSprite.doSlowSprite2(graphic, SHOOTER_TRAP_FRAMES, shooter3.x, shooter3.y);
        shooter4.idleSprite.doSlowSprite2(graphic, SHOOTER_TRAP_FRAMES, shooter4.x, shooter4.y);
        if (SDL_GetTicks() - lastTrapDropTime1_1 >= 1000) {
            spearTrap1.idleSprite.doSprite(graphic, SPEAR_FRAMES, spearTrap1.x, spearTrap1.y, SDL_FLIP_VERTICAL);
        }
        if (SDL_GetTicks() - lastTrapDropTime2_1 >= 1000) {
            spearTrap2.idleSprite.doSprite(graphic, SPEAR_FRAMES, spearTrap2.x, spearTrap2.y, SDL_FLIP_VERTICAL);
        }

        if ( skeleton.health > 0){
            if ( skeleton.attackStatus == 2) skeleton.hurtSprite.doSlowSprite_2(graphic, SKELETON_HURT_FRAMES, skeleton.x, skeleton.y, skeleton.flip);
            else if (skeleton.attackStatus == 1) skeleton.attackSprite.doSlowSprite2(graphic, SKELETON_ATTACK_FRAMES, skeleton.x, skeleton.y, skeleton.flip);
            else if (skeleton.moveStatus == 1) skeleton.runSprite.doSlowSprite2(graphic, SKELETON_WALK_FRAMES, skeleton.x, skeleton.y, skeleton.flip);
            else skeleton.idleSprite.doSlowSprite2(graphic, SKELETON_IDLE_FRAMES, skeleton.x, skeleton.y, skeleton.flip);
            if ( skeleton.hurtSprite.frame/6 >= SKELETON_HURT_FRAMES){
                skeleton.hurtSprite.frame = 0;
                skeleton.attackStatus = 1;
            }
        }
        else{
            chest_6.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, skeleton.x, 404);
            if ( key_6.health == 1 ) key_6.idleSprite.doSprite(graphic, KEY_FRAMES, skeleton.x+20, skeleton.y-10);
            if ( key_6.health == 1 && (( player.x + player.w >=  skeleton.x + 20 && player.x + player.w <= skeleton.x + 35 && player.flipStatus == 0) || ( player.x >=  skeleton.x + 20 && player.x <= skeleton.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                key_6.health = 0;
            }
        }

        if ( flyingEye.health > 0){
            if ( flyingEye.attackStatus == 2) flyingEye.hurtSprite.doSlowSprite_2(graphic, EYE_HURT_FRAMES, flyingEye.x, flyingEye.y, flyingEye.flip);
            else if (flyingEye.attackStatus == 1) flyingEye.attackSprite.doSlowSprite2(graphic, EYE_ATTACK_FRAMES, flyingEye.x, flyingEye.y, flyingEye.flip);
            else flyingEye.idleSprite.doSlowSprite2(graphic, EYE_IDLE_FRAMES, flyingEye.x, flyingEye.y, flyingEye.flip);
            if ( flyingEye.hurtSprite.frame/6 >= EYE_HURT_FRAMES){
                flyingEye.hurtSprite.frame = 0;
                flyingEye.attackStatus = 1;
            }
        }
        else{
            chest_7.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, flyingEye.x, 404);
            if ( key_7.health == 1 ) key_7.idleSprite.doSprite(graphic, KEY_FRAMES, flyingEye.x+20, skeleton.y-10);
            if ( key_7.health == 1 && (( player.x + player.w >=  flyingEye.x + 20 && player.x + player.w <= flyingEye.x + 35 && player.flipStatus == 0) || ( player.x >=  flyingEye.x + 20 && player.x <= flyingEye.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                key_7.health = 0;
            }
        }

        if ( player.health > 0){
            graphic.renderTexture(healthBar[player.health], nullptr, 10, 10);
            if ( keyCount2 == 2 && player.x+player.w >= SCREEN_WIDTH-50 && player.y == 560) gameStatus = 4;
            if ( player.moveStatus == 0 && player.attackStatus != 1 && player.attackStatus != 2){
                player.idleSprite.doSlowSprite2(graphic, PLAYER_IDLE_FRAMES, player.x, player.y, player.flip);
            }

            if (player.moveStatus == 1 && player.attackStatus != 1 && player.attackStatus != 2){
                player.runSprite.doSprite(graphic, PLAYER_RUN_FRAMES, player.x, player.y, player.flip);
            }

            if ( player.attackStatus == 1){
                if ( player.flip != SDL_FLIP_NONE) player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y, player.flip);
                else player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y, player.flip);
                if ( player.attackSprite.frame/2 >= PLAYER_ATTACK_FRAMES){
                    player.attackStatus = 3;
                    player.attackSprite.frame = 0;
                }
            }
            else if ( player.attackStatus == 2){
                player.hurtSprite.doSlowSprite3(graphic, PLAYER_HURT_FRAMES, player.x, player.y, player.flip);
                if ( player.hurtSprite.frame/4 >= PLAYER_HURT_FRAMES){
                    player.attackStatus = 3;
                    player.hurtSprite.frame = 0;
                }
            }
        }

        for ( Entity* skill : skills){
            graphic.renderTexture(skill->texture, nullptr, skill->x, skill->y, skill->flip);
        }

        for ( Entity* arrow : arrow1){
            graphic.renderTexture(arrow->texture, nullptr, arrow->x, arrow->y);
        }

        for ( Entity* arrow : arrow2){
            graphic.renderTexture(arrow->texture, nullptr, arrow->x, arrow->y);
        }

        for ( Entity* arrow : arrow3){
            graphic.renderTexture(arrow->texture, nullptr, arrow->x, arrow->y);
        }

        for ( Entity* arrow : arrow4){
            graphic.renderTexture(arrow->texture, nullptr, arrow->x, arrow->y);
        }

        for (Entity* sword : swords){
            sword->attackSprite.doSprite(graphic, SWORD_FRAMES, sword->x, sword->y, sword->flip);
        }

        for (Entity* bomb : bombs){
            bomb->attackSprite.doSprite(graphic, BOMB_FRAMES, bomb->x, bomb->y, bomb->flip);
        }

        keyText2.str("");
        keyText2 << to_string(keyCount2) << "/2";
        keyTextTexure = graphic.loadTextTexture(keyText2.str().c_str(), textColor, textFont);
        graphic.renderTexture(keyTextTexure, nullptr, SCREEN_WIDTH/2, 10);
        graphic.renderTexture(keyTexture, nullptr, SCREEN_WIDTH/2 + 70, 6);

        if ( keyCount2 == 2){
            portal.idleSprite.doSprite(graphic, PORTAL_FRAMES, SCREEN_WIDTH-68, SCREEN_HEIGHT-164, SDL_FLIP_HORIZONTAL);
        }
    }

    void drawGame3(Graphics& graphic){
        if ( player.health > 0){
            graphic.renderTexture(healthBar[player.health], nullptr, 10, 10);
            if ( keyCount2 == 2 && player.x+player.w >= SCREEN_WIDTH-50 && player.y == 560) gameStatus = 4;
            if ( player.moveStatus == 0 && player.attackStatus != 1 && player.attackStatus != 2){
                player.idleSprite.doSlowSprite2(graphic, PLAYER_IDLE_FRAMES, player.x, player.y, player.flip);
            }

            if (player.moveStatus == 1 && player.attackStatus != 1 && player.attackStatus != 2){
                player.runSprite.doSprite(graphic, PLAYER_RUN_FRAMES, player.x, player.y, player.flip);
            }

            if ( player.attackStatus == 1){
                if ( player.flip != SDL_FLIP_NONE) player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y, player.flip);
                else player.attackSprite.doQuickSprite2(graphic, PLAYER_ATTACK_FRAMES, player.x, player.y, player.flip);
                if ( player.attackSprite.frame/2 >= PLAYER_ATTACK_FRAMES){
                    player.attackStatus = 3;
                    player.attackSprite.frame = 0;
                }
            }
            else if ( player.attackStatus == 2){
                player.hurtSprite.doSlowSprite3(graphic, PLAYER_HURT_FRAMES, player.x, player.y, player.flip);
                if ( player.hurtSprite.frame/4 >= PLAYER_HURT_FRAMES){
                    player.attackStatus = 3;
                    player.hurtSprite.frame = 0;
                }
            }
        }
        if ( boss.health > 0){
            if ( boss.attackStatus == 2 ) boss.hurtSprite.doSlowSprite3(graphic, BOSS_HURT_FRAMES, boss.x, boss.y, boss.flip);
            else if (boss.attackStatus == 1) boss.attackSprite.doSprite(graphic, BOSS_ATTACK_FRAMES, boss.x, boss.y, boss.flip);
            else if (boss.attackStatus == 3) boss.castSprite.doSlowSprite2(graphic, BOSS_CAST_FRAMES, boss.x, boss.y, boss.flip);
            else if (boss.moveStatus == 1) boss.runSprite.doSlowSprite2(graphic, BOSS_WALK_FRAMES, boss.x, boss.y, boss.flip);
            else boss.idleSprite.doSlowSprite2(graphic, BOSS_IDLE_FRAMES, boss.x, boss.y, boss.flip);
            if ( boss.hurtSprite.frame/4 >= BOSS_HURT_FRAMES){
                boss.hurtSprite.frame = 0;
                boss.attackStatus = 0;
            }
        }

        for ( Entity* skill : skills){
            graphic.renderTexture(skill->texture, nullptr, skill->x, skill->y, skill->flip);
        }
        if (SDL_GetTicks() - time < 38000){
            if ( spell.attackSprite.frame == 0 ){
                initSpell();
//            if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks();
            }
            if ((SDL_GetTicks()- time - spellSpawnTime) >= 6700){
                spell.attackSprite.doSprite(graphic, BOSS_SPELL_FRAMES, spell.x, spell.y);
                if ( spell.collide(&player) && spell.attackSprite.frame == 36) player.health--;
                if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks()-time;
            }
        }
        else{
            if ( spell.castSprite.frame == 0 ){
                initSpell();
//            if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks();
            }
            if ((SDL_GetTicks()- time - spellSpawnTime) >= 6700){
                spell.castSprite.doSprite(graphic, BOSS_SPELL_FRAMES, spell.x, spell.y);
                if ( spell.collide(&player) && spell.castSprite.frame == 36) player.health--;
                if ( spell.castSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks()-time;
            }
        }
        bossHealthText.str("");
        bossHealthText << to_string(boss.health);
        bossHealthTextTexrture = graphic.loadTextTexture(bossHealthText.str().c_str(), healthTextColor, textFont);
        graphic.renderTexture(bossHealthTextTexrture, nullptr, 1100, 50);
        graphic.renderTexture(healthTexture, nullptr, 1040, 40);
        bossName.str("");
        bossName << "Bringer Of Death";
        bossNameTexture = graphic.loadTextTexture(bossName.str().c_str(), nameColor, textFont);
        graphic.renderTexture(bossNameTexture, nullptr, 900, 20);
        timeText.str("");
        timeText << (SDL_GetTicks() - time)/100/10.f;
        timeTexture = graphic.loadTextTexture(timeText.str().c_str(), healthTextColor, textFont);
        graphic.renderTexture(timeTexture, nullptr, SCREEN_WIDTH/2, 20);
        warningText.str("");
        warningText << "Be careful!!!Death comes quicker";
        warningTextTexture = graphic.loadTextTexture(warningText.str().c_str(), healthTextColor, textFont2);
        if ( SDL_GetTicks() - time >= 38000 && SDL_GetTicks() - time <= 43000){
            graphic.renderTexture(warningTextTexture, nullptr, 450, 80);
        }
    }
};
#endif // _GAME__H
