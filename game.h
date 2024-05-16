#ifndef _GAME__H
#define _GAME__H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"defs.h"
#include"entity.h"
#include"graphics.h"
#include"sound.h"

using namespace std;

struct Game{
    Entity player, angel_1, angel_2, angel_3, angel_4, angel_5, chest_1, chest_2, chest_3, chest_4, chest_5, chest_6, chest_7, chest_8, chest_9, key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8, key_9, portal, skeleton1, skeleton2, flyingEye1, flyingEye2, boss;
    Entity spikeTrap1, spikeTrap2, spikeTrap3, spikeTrap4, spikeTrap5, spearTrap1, spearTrap2, shooter1, shooter2, shooter3, shooter4, spell;
    list<Entity*> skills, bullets_1, bullets_2, bullets_3, bullets_4, bullets_5, arrow1, arrow2, arrow3, arrow4, swords1, bombs1, swords2, bombs2, bossSkills;
    SDL_Texture* skillTexture, *enemyBulletTexture_1, *enemyBulletTexture_2, *healthBar[11], *keyTextTexure, *keyTexture, *portalTexture, *arrowTexture, *swordTexture, *bombTexture, *bossSkillTexture1, *bossHealthTextTexrture;
    SDL_Texture* warningTextTexture, *suggestTextTexture1, *suggestTextTexture2, *healthTexture, *bossNameTexture, *timeTexture, *spellTexture1, *spellTexture2;
    SDL_Color textColor, healthTextColor, nameColor;
    TTF_Font* textFont, *textFont2;
    stringstream keyText1, keyText2, bossHealthText, bossName, timeText, warningText, suggestText1, suggestText2;
    int keyCount1, keyCount2, gameStatus = 0, jumpCount = 0, soundStatus = 0;
    Uint32 lastTrapDropTime1 = 0, lastTrapDropTime1_1 = 0, lastTrapDropTime2 = 0, lastTrapDropTime2_1 = 0, arrowSpawnTime1 = 0, arrowSpawnTime2 = 0, arrowSpawnTime3 = 0, arrowSpawnTime4 = 0, swordSpawnTime = 0, swordSpawnTime2 = 0, bombSpawnTime = 0, bombSpawnTime2 = 0, bossSkillSpawnTime, spellSpawnTime, time;
    Uint32 dashReloadTime = 0, skillReloadTime = 0;
    Mix_Chunk* angelAttack1, *angelAttack2, *bossAttack, *bossSpell, *flyingEyeAttack, *skeletonAttack, *playerAttack, *playerRun, *playerJump, *collectKey;
    Mix_Music* stage1, *stage2, *stage3;

    void init(Graphics& graphic, Sound& sound){
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
        initSkeleton2();
        initFlyingEye();
        initFlyingEye2();
        initBoss();
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
        chest_8.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_8.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
        chest_9.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Chest.png");
        chest_9.idleSprite.init(CHEST_CLIPS, CHEST_FRAMES);
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
        key_8.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_8.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
        key_9.idleSprite.spriteSheetTexture = graphic.loadTexture("Animated//Key.png");
        key_9.idleSprite.init(KEY_CLIPS, KEY_FRAMES);
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
        key_8.health = 1;
        key_9.health = 1;
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
        skeleton1.attackSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Attack.png");
        skeleton1.idleSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Idle.png");
        skeleton1.runSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Walk.png");
        skeleton1.hurtSprite.spriteSheetTexture = graphic.loadTexture("Skeleton///Hurt.png");
        skeleton2.attackSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Attack.png");
        skeleton2.idleSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Idle.png");
        skeleton2.runSprite.spriteSheetTexture = graphic.loadTexture("Skeleton//Walk.png");
        skeleton2.hurtSprite.spriteSheetTexture = graphic.loadTexture("Skeleton///Hurt.png");
        swordTexture = graphic.loadTexture("Skeleton//Sword.png");
        flyingEye1.idleSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Flight.png");
        flyingEye1.attackSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Attack.png");
        flyingEye1.hurtSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Hurt.png");
        flyingEye2.idleSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Flight.png");
        flyingEye2.attackSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Attack.png");
        flyingEye2.hurtSprite.spriteSheetTexture = graphic.loadTexture("Flying Eye//Hurt.png");
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
        angelAttack1 = sound.loadSoundEffect("Sound//Angel1Attack.wav");
        angelAttack2 = sound.loadSoundEffect("Sound//Angel2Attack.wav");
        bossAttack = sound.loadSoundEffect("Sound//BossAttack.wav");
        bossSpell = sound.loadSoundEffect("Sound//BossSpell.wav");
        flyingEyeAttack = sound.loadSoundEffect("Sound//FlyingEyeAttack.wav");
        skeletonAttack = sound.loadSoundEffect("Sound//SkeletonAttack.wav");
        playerAttack = sound.loadSoundEffect("Sound//PlayerAttack.wav");
        playerRun = sound.loadSoundEffect("Sound//PlayerRun.wav");
        playerJump = sound.loadSoundEffect("Sound//PlayerJump.wav");
        stage1 = sound.loadMusic("Sound//Stage1.wav");
        stage2 = sound.loadMusic("Sound//Stage2.wav");
        stage3 = sound.loadMusic("Sound//Stage3.wav");
        collectKey = sound.loadSoundEffect("Sound//CollectKey.wav");
    }

    void init2(){
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
        initSkeleton2();
        initFlyingEye();
        initFlyingEye2();
        initBoss();
        key_1.health = 1;
        key_2.health = 1;
        key_3.health = 1;
        key_4.health = 1;
        key_5.health = 1;
        key_6.health = 1;
        key_7.health = 1;
        key_8.health = 1;
        key_9.health = 1;
        keyCount1 = 0;
        keyCount2 = 0;
        dashReloadTime = 0;
    }

    void init3(){
        dashReloadTime = 0;
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

    void initSpell(Sound sound){
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
        skeleton1.attackSprite.init(SKELETON_ATTACK_CLIPS, SKELETON_ATTACK_FRAMES);
        skeleton1.idleSprite.init(SKELETON_IDLE_CLIPS, SKELETON_IDLE_FRAMES);
        skeleton1.runSprite.init(SKELETON_WALK_CLIPS, SKELETON_WALK_FRAMES);
        skeleton1.hurtSprite.init(SKELETON_HURT_CLIPS, SKELETON_HURT_FRAMES);
        skeleton1.health = 5;
        skeleton1.attackStatus = 0;
        skeleton1.moveStatus = 0;
        skeleton1.w = 75;
        skeleton1.h = 86;
        skeleton1.x = 800;
        skeleton1.y = 362;
        skeleton1.dx = 2;
        skeleton1.dy = 0;
        skeleton1.firstPos = skeleton1.x;
        skeleton1.flip= SDL_FLIP_NONE;
    }

    void initSkeleton2(){
        skeleton2.attackSprite.init(SKELETON_ATTACK_CLIPS, SKELETON_ATTACK_FRAMES);
        skeleton2.idleSprite.init(SKELETON_IDLE_CLIPS, SKELETON_IDLE_FRAMES);
        skeleton2.runSprite.init(SKELETON_WALK_CLIPS, SKELETON_WALK_FRAMES);
        skeleton2.hurtSprite.init(SKELETON_HURT_CLIPS, SKELETON_HURT_FRAMES);
        skeleton2.health = 5;
        skeleton2.attackStatus = 0;
        skeleton2.moveStatus = 0;
        skeleton2.w = 75;
        skeleton2.h = 86;
        skeleton2.x = 600;
        skeleton2.y = 106;
        skeleton2.dx = 2;
        skeleton2.dy = 0;
        skeleton2.firstPos = skeleton2.x;
        skeleton2.flip= SDL_FLIP_NONE;
    }

    void initFlyingEye(){
        flyingEye1.attackSprite.init(EYE_ATTACK_CLIPS, EYE_ATTACK_FRAMES);
        flyingEye1.idleSprite.init(EYE_IDLE_CLIPS, EYE_IDLE_FRAMES);
        flyingEye1.hurtSprite.init(EYE_HURT_CLIPS, EYE_HURT_FRAMES);
        flyingEye1.health = 5;
        flyingEye1.attackStatus = 0;
        flyingEye1.moveStatus = 0;
        flyingEye1.w = 70;
        flyingEye1.h = 55;
        flyingEye1.x = 500;
        flyingEye1.y = 260;
        flyingEye1.dx = 2;
        flyingEye1.dy = 0;
        flyingEye1.firstPos = flyingEye1.x;
        flyingEye1.flip = SDL_FLIP_NONE;
    }

    void initFlyingEye2(){
        flyingEye2.attackSprite.init(EYE_ATTACK_CLIPS, EYE_ATTACK_FRAMES);
        flyingEye2.idleSprite.init(EYE_IDLE_CLIPS, EYE_IDLE_FRAMES);
        flyingEye2.hurtSprite.init(EYE_HURT_CLIPS, EYE_HURT_FRAMES);
        flyingEye2.health = 5;
        flyingEye2.attackStatus = 0;
        flyingEye2.moveStatus = 0;
        flyingEye2.w = 70;
        flyingEye2.h = 55;
        flyingEye2.x = 400;
        flyingEye2.y = 4;
        flyingEye2.dx = 2;
        flyingEye2.dy = 0;
        flyingEye2.firstPos = flyingEye2.x;
        flyingEye2.flip = SDL_FLIP_NONE;
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

    void initEnemyBullet_1(Sound sound){
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
            sound.playSoundEffect(angelAttack1);
        }
        angel_1.attackReload--;
    }

    void initEnemyBullet_2(Sound sound){
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
            sound.playSoundEffect(angelAttack1);
        }
        angel_2.attackReload--;
    }

    void initEnemyBullet_3(Sound sound){
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
            sound.playSoundEffect(angelAttack2);
        }
        angel_3.attackReload--;
    }

    void initEnemyBullet_4(Sound sound){
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
            sound.playSoundEffect(angelAttack2);
        }
        angel_4.attackReload--;
    }

    void initEnemyBullet_5(Sound sound){
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
            sound.playSoundEffect(angelAttack2);
        }
        angel_5.attackReload--;
    }

    void initSword1(Sound sound){
        Entity* sword = new Entity();
        swords1.push_back(sword);
        sword->attackSprite.spriteSheetTexture = swordTexture;
        sword->attackSprite.init(SWORD_CLIPS, SWORD_FRAMES);
        if ( skeleton1.flip == SDL_FLIP_HORIZONTAL) sword->x = skeleton1.x - 40;
        else sword->x = skeleton1.x + 80;
        sword->y = skeleton1.y + (skeleton1.h - sword->h)/2 - 20;
        sword->w = 33;
        sword->h = 33;
        sword->dx = 4;
        sword->dy = 0;
        sword->health = 1;
        sword->flip = skeleton1.flip;
        sword->firstPos = sword->x;
        sound.playSoundEffect(skeletonAttack);
    }

    void initSword2(Sound sound){
        Entity* sword = new Entity();
        swords2.push_back(sword);
        sword->attackSprite.spriteSheetTexture = swordTexture;
        sword->attackSprite.init(SWORD_CLIPS, SWORD_FRAMES);
        if ( skeleton2.flip == SDL_FLIP_HORIZONTAL) sword->x = skeleton2.x - 40;
        else sword->x = skeleton2.x + 80;
        sword->y = skeleton2.y + (skeleton2.h - sword->h)/2 - 20;
        sword->w = 33;
        sword->h = 33;
        sword->dx = 4;
        sword->dy = 0;
        sword->health = 1;
        sword->flip = skeleton2.flip;
        sword->firstPos = sword->x;
        sound.playSoundEffect(skeletonAttack);
    }

    void initBomb1(Sound sound){
        Entity* bomb = new Entity();
        bombs1.push_back(bomb);
        bomb->attackSprite.spriteSheetTexture = bombTexture;
        bomb->attackSprite.init(BOMB_CLIPS, BOMB_FRAMES);
        if ( flyingEye1.flip == SDL_FLIP_HORIZONTAL) bomb->x = flyingEye1.x - 40;
        else bomb->x = flyingEye1.x + 60;
        bomb->y = 380;
        bomb->w = 35;
        bomb->h = 35;
        bomb->dx = 4;
        bomb->dy = 0;
        bomb->health = 1;
        bomb->flip = flyingEye1.flip;
        bomb->firstPos = bomb->x;
        sound.playSoundEffect(flyingEyeAttack);
    }

    void initBomb2(Sound sound){
        Entity* bomb = new Entity();
        bombs2.push_back(bomb);
        bomb->attackSprite.spriteSheetTexture = bombTexture;
        bomb->attackSprite.init(BOMB_CLIPS, BOMB_FRAMES);
        if ( flyingEye2.flip == SDL_FLIP_HORIZONTAL) bomb->x = flyingEye2.x - 40;
        else bomb->x = flyingEye2.x + 60;
        bomb->y = 124;
        bomb->w = 35;
        bomb->h = 35;
        bomb->dx = 4;
        bomb->dy = 0;
        bomb->health = 1;
        bomb->flip = flyingEye2.flip;
        bomb->firstPos = bomb->x;
        sound.playSoundEffect(flyingEyeAttack);
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
        spearTrap1.x = 1080;
        spearTrap1.y = -20;
    }

    void initSpearTrap2(){
        spearTrap2.w = 32;
        spearTrap2.h = 192;
        spearTrap2.x = 1040;
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

    void doPlayer( int keyInput[], Map gameMap, Sound sound){
        if ( gameStatus == 1){
            if ( player.y >= 617) player.health = 0;
        }

        if ( gameStatus == 1 || gameStatus == 5){
            if (keyInput[SDL_SCANCODE_K] && SDL_GetTicks() - dashReloadTime >= 2000){
                if ( player.flip == SDL_FLIP_NONE){
                    player.x += 100;
                }
                else{
                    player.x -= 100;
                }
                dashReloadTime= SDL_GetTicks();
            }
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
            if (keyInput[SDL_SCANCODE_K] && SDL_GetTicks() - dashReloadTime >= 2000){
                if ( player.flip == SDL_FLIP_NONE){
                    player.x += 100;
                }
                else{
                    player.x -= 100;
                }
                dashReloadTime= SDL_GetTicks();
            }
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
            sound.playSoundEffect(playerAttack);
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
                sound.playSoundEffect(playerJump);
                player.dy  -= PLAYER_JUMP_SPEED;
            }
        }
        else if (gameStatus == 3){
            if (!player.onGround2(gameMap)){
                player.dy += GRAVITY_ACCELERATION2;
            }
            else player.dy = 0;

            if (keyInput[SDL_SCANCODE_SPACE] && player.onGround2(gameMap)){
                sound.playSoundEffect(playerJump);
                player.dy  -= PLAYER_JUMP_SPEED;
            }
        }
        else{
            if (!player.onGround3(gameMap)){
                player.dy += GRAVITY_ACCELERATION1;
            }
            else player.dy = 0;

            if (keyInput[SDL_SCANCODE_SPACE] && player.onGround3(gameMap)){
                sound.playSoundEffect(playerJump);
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
        if (skeleton1.attackStatus == 1 && skeleton1.health > 0){
            if ( player.x > skeleton1.x){
                skeleton1.flip = SDL_FLIP_NONE;
                if ( abs(skeleton1.x - player.x) > 160 && 500 < skeleton1.x && skeleton1.x < 1000 ){
                    skeleton1.move();
                }
                else skeleton1.attackStatus = 1;
            }
            else if ( player.x < skeleton1.x){
                skeleton1.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(skeleton1.x - player.x) > 160 && 500 < skeleton1.x && skeleton1.x < 1000){
                    skeleton1.moveBack();
                }
                else skeleton1.attackStatus = 1;
            }
            skeleton1.w = skeleton1.attackSprite.clips[skeleton1.attackSprite.frame/10].w;
            skeleton1.h = skeleton1.attackSprite.clips[skeleton1.attackSprite.frame/10].h;
            skeleton1.y = 448 - skeleton1.h;
        }
        else if ( skeleton1.attackStatus == 2 && skeleton1.health > 0){
            skeleton1.w = skeleton1.hurtSprite.clips[skeleton1.hurtSprite.frame/6].w;
            skeleton1.h = skeleton1.hurtSprite.clips[skeleton1.hurtSprite.frame/6].h;
            skeleton1.y = 448 - skeleton1.h;
        }
        else{
            if ( player.x > skeleton1.x ) skeleton1.flip = SDL_FLIP_NONE;
            else skeleton1.flip = SDL_FLIP_HORIZONTAL;
            skeleton1.w = skeleton1.idleSprite.clips[skeleton1.idleSprite.frame/10].w;
            skeleton1.w = skeleton1.idleSprite.clips[skeleton1.idleSprite.frame/10].h;
            skeleton1.y = 448 - skeleton1.h;
        }
    }

    void doSkeleton2(){
        if (skeleton2.attackStatus == 1 && skeleton2.health > 0){
            if ( player.x > skeleton2.x){
                skeleton2.flip = SDL_FLIP_NONE;
                if ( abs(skeleton2.x - player.x) > 160 && 256 < skeleton2.x && skeleton2.x < 630 ){
                    skeleton2.move();
                }
                else skeleton2.attackStatus = 1;
            }
            else if ( player.x < skeleton2.x){
                skeleton2.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(skeleton2.x - player.x) > 160 && 256 < skeleton2.x && skeleton2.x < 630){
                    skeleton2.moveBack();
                }
                else skeleton2.attackStatus = 1;
            }
            skeleton2.w = skeleton2.attackSprite.clips[skeleton2.attackSprite.frame/10].w;
            skeleton2.h = skeleton2.attackSprite.clips[skeleton2.attackSprite.frame/10].h;
            skeleton2.y = 192 - skeleton2.h;
        }
        else if ( skeleton2.attackStatus == 2 && skeleton2.health > 0){
            skeleton2.w = skeleton2.hurtSprite.clips[skeleton2.hurtSprite.frame/6].w;
            skeleton2.h = skeleton2.hurtSprite.clips[skeleton2.hurtSprite.frame/6].h;
            skeleton2.y = 192 - skeleton2.h;
        }
        else{
            if ( player.x > skeleton2.x ) skeleton2.flip = SDL_FLIP_NONE;
            else skeleton2.flip = SDL_FLIP_HORIZONTAL;
            skeleton2.w = skeleton2.idleSprite.clips[skeleton2.idleSprite.frame/10].w;
            skeleton2.w = skeleton2.idleSprite.clips[skeleton2.idleSprite.frame/10].h;
            skeleton2.y = 192 - skeleton2.h;
        }
    }

    void doFlyingEye(){
        if (flyingEye1.attackStatus == 1 && flyingEye1.health > 0){
            if ( player.x > flyingEye1.x){
                flyingEye1.flip = SDL_FLIP_NONE;
                if ( abs(flyingEye1.x - player.x) > 160 && 448 < flyingEye1.x && flyingEye1.x < 1000 ){
                    flyingEye1.move();
                }
                else flyingEye1.attackStatus = 1;
            }
            else if ( player.x < flyingEye1.x){
                flyingEye1.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(flyingEye1.x - player.x) > 160 && 448 < flyingEye1.x && flyingEye1.x < 1000){
                    flyingEye1.moveBack();
                }
                else flyingEye1.attackStatus = 1;
            }
            flyingEye1.w = flyingEye1.attackSprite.clips[flyingEye1.attackSprite.frame/10].w;
            flyingEye1.h = flyingEye1.attackSprite.clips[flyingEye1.attackSprite.frame/10].h;
            flyingEye1.y = 408 - flyingEye1.h;
        }
        else if ( flyingEye1.attackStatus == 2 && flyingEye1.health > 0){
            flyingEye1.w = flyingEye1.hurtSprite.clips[flyingEye1.hurtSprite.frame/6].w;
            flyingEye1.h = flyingEye1.hurtSprite.clips[flyingEye1.hurtSprite.frame/6].h;
            flyingEye1.y = 408 - flyingEye1.h;
        }
        else{
            if ( player.x > flyingEye1.x ) flyingEye1.flip = SDL_FLIP_NONE;
            else flyingEye1.flip = SDL_FLIP_HORIZONTAL;
            flyingEye1.w = flyingEye1.idleSprite.clips[flyingEye1.idleSprite.frame/10].w;
            flyingEye1.w = flyingEye1.idleSprite.clips[flyingEye1.idleSprite.frame/10].h;
            flyingEye1.y = 408 - flyingEye1.h;
        }
    }

    void doFlyingEye2(){
        if (flyingEye2.attackStatus == 1 && flyingEye2.health > 0){
            if ( player.x > flyingEye2.x){
                flyingEye2.flip = SDL_FLIP_NONE;
                if ( abs(flyingEye2.x - player.x) > 160 && 256 < flyingEye2.x && flyingEye2.x < 630 ){
                    flyingEye2.move();
                }
                else flyingEye2.attackStatus = 1;
            }
            else if ( player.x < flyingEye2.x){
                flyingEye2.flip = SDL_FLIP_HORIZONTAL;
                if ( abs(flyingEye2.x - player.x) > 160 && 256 < flyingEye2.x && flyingEye2.x < 630){
                    flyingEye2.moveBack();
                }
                else flyingEye2.attackStatus = 1;
            }
            flyingEye2.w = flyingEye2.attackSprite.clips[flyingEye2.attackSprite.frame/10].w;
            flyingEye2.h = flyingEye2.attackSprite.clips[flyingEye2.attackSprite.frame/10].h;
            flyingEye2.y = 152 - flyingEye2.h;
        }
        else if ( flyingEye2.attackStatus == 2 && flyingEye2.health > 0){
            flyingEye2.w = flyingEye2.hurtSprite.clips[flyingEye2.hurtSprite.frame/6].w;
            flyingEye2.h = flyingEye2.hurtSprite.clips[flyingEye2.hurtSprite.frame/6].h;
            flyingEye2.y = 152 - flyingEye2.h;
        }
        else{
            if ( player.x > flyingEye2.x ) flyingEye2.flip = SDL_FLIP_NONE;
            else flyingEye2.flip = SDL_FLIP_HORIZONTAL;
            flyingEye2.w = flyingEye2.idleSprite.clips[flyingEye2.idleSprite.frame/10].w;
            flyingEye2.w = flyingEye2.idleSprite.clips[flyingEye2.idleSprite.frame/10].h;
            flyingEye2.y = 152 - flyingEye2.h;
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
                if (skeleton1.health > 0 && currSkill->collide(&skeleton1)){
                    delete currSkill;
                    skills.erase(tmp);
                    skeleton1.health--;
                    skeleton1.attackStatus = 2;
                }
                if (skeleton2.health > 0 && currSkill->collide(&skeleton2)){
                    delete currSkill;
                    skills.erase(tmp);
                    skeleton2.health--;
                    skeleton2.attackStatus = 2;
                }
                if (flyingEye1.health > 0 && currSkill->collide(&flyingEye1)){
                    delete currSkill;
                    skills.erase(tmp);
                    flyingEye1.health--;
                    flyingEye1.attackStatus = 2;
                }
                if (flyingEye2.health > 0 && currSkill->collide(&flyingEye2)){
                    delete currSkill;
                    skills.erase(tmp);
                    flyingEye2.health--;
                    flyingEye2.attackStatus = 2;
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
        auto it = swords1.begin();
        while ( it != swords1.end()){
            auto tmp = it;
            Entity* currSword = *tmp;
            if ( currSword->flip == SDL_FLIP_HORIZONTAL) currSword->moveBack();
            else currSword->move();
            if ( currSword->outScreen() || abs(currSword->x - currSword->firstPos) > 200 ){
                delete currSword;
                swords1.erase(tmp);
            }
            if ( player.health > 0 && currSword->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currSword;
                swords1.erase(tmp);
            }
            it++;
        }
    }

    void doSword2(){
        auto it = swords2.begin();
        while ( it != swords2.end()){
            auto tmp = it;
            Entity* currSword = *tmp;
            if ( currSword->flip == SDL_FLIP_HORIZONTAL) currSword->moveBack();
            else currSword->move();
            if ( currSword->outScreen() || abs(currSword->x - currSword->firstPos) > 200 ){
                delete currSword;
                swords2.erase(tmp);
            }
            if ( player.health > 0 && currSword->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currSword;
                swords2.erase(tmp);
            }
            it++;
        }
    }

    void doBomb(){
        auto it = bombs1.begin();
        while ( it != bombs1.end()){
            auto tmp = it;
            Entity* currBomb = *tmp;
            if ( currBomb->flip == SDL_FLIP_HORIZONTAL) currBomb->moveBack();
            else currBomb->move();
            if ( currBomb->outScreen() || abs(currBomb->x - currBomb->firstPos) > 200 ){
                delete currBomb;
                bombs1.erase(tmp);
            }
            if ( player.health > 0 && currBomb->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBomb;
                bombs1.erase(tmp);
            }
            it++;
        }
    }

    void doBomb2(){
        auto it = bombs2.begin();
        while ( it != bombs2.end()){
            auto tmp = it;
            Entity* currBomb = *tmp;
            if ( currBomb->flip == SDL_FLIP_HORIZONTAL) currBomb->moveBack();
            else currBomb->move();
            if ( currBomb->outScreen() || abs(currBomb->x - currBomb->firstPos) > 200 ){
                delete currBomb;
                bombs2.erase(tmp);
            }
            if ( player.health > 0 && currBomb->collide(&player)){
                player.health--;
                player.attackStatus = 2;
                delete currBomb;
                bombs2.erase(tmp);
            }
            it++;
        }
    }


    void doBoss(Sound sound){
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

        if (boss.attackStatus == 1 && boss.attackSprite.frame == 20 ){
            sound.playSoundEffect(bossAttack);
            if ( boss.collide(&player) ){
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
    void doStage1(int keyInput[], Map gameMap, Sound sound){
        if ( soundStatus == 0){
            sound.stopMusic();
            soundStatus = 1;
        }
        if (!sound.musicPlaying()) sound.playMusic(stage1);
        doPlayer(keyInput, gameMap, sound);
        doSkill();
        doFirstAngel();
        doSecondAngel();
        doThirdAngel();
        doFourthAngel();
        doFifthAngel();
        if ( angel_1.health > 0){
            initEnemyBullet_1(sound);
            doEnemyBullet_1();
        }
        if ( angel_2.health > 0){
            initEnemyBullet_2(sound);
            doEnemyBullet_2();
        }
        if ( angel_3.health > 0){
            initEnemyBullet_3(sound);
            doEnemyBullet_3();
        }
        if ( angel_4.health > 0){
            initEnemyBullet_4(sound);
            doEnemyBullet_4();
        }
        if ( angel_5.health > 0){
            initEnemyBullet_5(sound);
            doEnemyBullet_5();
        }
        if ( player.health == 0) gameStatus = 6;
    }

    void doStage2(int keyInput[], Map gameMap, Sound sound){
        if ( soundStatus == 1){
            sound.stopMusic();
            soundStatus = 2;
        }
        if (!sound.musicPlaying()) sound.playMusic(stage2);
        doPlayer(keyInput, gameMap, sound);
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
        if ( SDL_GetTicks() - swordSpawnTime >= 1200 && skeleton1.attackStatus == 1){
            initSword1(sound);
            swordSpawnTime = SDL_GetTicks();
        }
        if ( SDL_GetTicks() - swordSpawnTime2>= 1200 && skeleton2.attackStatus == 1){
            initSword2(sound);
            swordSpawnTime2 = SDL_GetTicks();
        }
        doSword();
        doSword2();
        doSkeleton();
        doSkeleton2();
        if ( SDL_GetTicks() - bombSpawnTime >= 1200 && flyingEye1.attackStatus == 1){
            initBomb1(sound);
            bombSpawnTime = SDL_GetTicks();
        }
        if ( SDL_GetTicks() - bombSpawnTime2 >= 1200 && flyingEye2.attackStatus == 1){
            initBomb2(sound);
            bombSpawnTime2 = SDL_GetTicks();
        }
        doBomb();
        doBomb2();
        doFlyingEye();
        doFlyingEye2();
        if ( player.health == 0) gameStatus = 6;
    }

    void doStage3(int keyInput[], Map gameMap, Sound sound){
        if ( soundStatus == 2){
            sound.stopMusic();
            soundStatus = 3;
        }
        if (!sound.musicPlaying()) sound.playMusic(stage3);
        if ( SDL_GetTicks() - time >= 38000){
            boss.dx = 4;
        }
        doPlayer(keyInput, gameMap, sound);
        doSkill();
        doBoss(sound);
        if ( player.health == 0) gameStatus = 6;
        if ( boss.health == 0) gameStatus = 8;
    }

    void drawGame(Graphics& graphic, Sound sound){
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
                sound.playSoundEffect(collectKey);
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
                sound.playSoundEffect(collectKey);
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
                sound.playSoundEffect(collectKey);
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
                sound.playSoundEffect(collectKey);
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
                sound.playSoundEffect(collectKey);
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


    void drawGame2(Graphics& graphic, Sound sound){
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

        if ( skeleton1.health > 0){
            if ( skeleton1.attackStatus == 2) skeleton1.hurtSprite.doSlowSprite_2(graphic, SKELETON_HURT_FRAMES, skeleton1.x, skeleton1.y, skeleton1.flip);
            else if (skeleton1.attackStatus == 1) skeleton1.attackSprite.doSlowSprite2(graphic, SKELETON_ATTACK_FRAMES, skeleton1.x, skeleton1.y, skeleton1.flip);
            else if (skeleton1.moveStatus == 1) skeleton1.runSprite.doSlowSprite2(graphic, SKELETON_WALK_FRAMES, skeleton1.x, skeleton1.y, skeleton1.flip);
            else skeleton1.idleSprite.doSlowSprite2(graphic, SKELETON_IDLE_FRAMES, skeleton1.x, skeleton1.y, skeleton1.flip);
            if ( skeleton1.hurtSprite.frame/6 >= SKELETON_HURT_FRAMES){
                skeleton1.hurtSprite.frame = 0;
                skeleton1.attackStatus = 1;
            }
        }
        else{
            chest_6.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, skeleton1.x, 404);
            if ( key_6.health == 1 ) key_6.idleSprite.doSprite(graphic, KEY_FRAMES, skeleton1.x+20, skeleton1.y-10);
            if ( key_6.health == 1 && (( player.x + player.w >=  skeleton1.x + 20 && player.x + player.w <= skeleton1.x + 35 && player.flipStatus == 0) || ( player.x >=  skeleton1.x + 20 && player.x <= skeleton1.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                sound.playSoundEffect(collectKey);
                key_6.health = 0;
            }
        }

        if ( skeleton2.health > 0){
            if ( skeleton2.attackStatus == 2) skeleton2.hurtSprite.doSlowSprite_2(graphic, SKELETON_HURT_FRAMES, skeleton2.x, skeleton2.y, skeleton2.flip);
            else if (skeleton2.attackStatus == 1) skeleton2.attackSprite.doSlowSprite2(graphic, SKELETON_ATTACK_FRAMES, skeleton2.x, skeleton2.y, skeleton2.flip);
            else if (skeleton2.moveStatus == 1) skeleton2.runSprite.doSlowSprite2(graphic, SKELETON_WALK_FRAMES, skeleton2.x, skeleton2.y, skeleton2.flip);
            else skeleton2.idleSprite.doSlowSprite2(graphic, SKELETON_IDLE_FRAMES, skeleton2.x, skeleton2.y, skeleton2.flip);
            if ( skeleton2.hurtSprite.frame/6 >= SKELETON_HURT_FRAMES){
                skeleton2.hurtSprite.frame = 0;
                skeleton2.attackStatus = 1;
            }
        }
       else{
            chest_8.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, skeleton2.x, 150);
            if ( key_8.health == 1 ) key_8.idleSprite.doSprite(graphic, KEY_FRAMES, skeleton2.x+20, skeleton2.y-10);
            if ( key_8.health == 1 && (( player.x + player.w >=  skeleton2.x + 20 && player.x + player.w <= skeleton2.x + 35 && player.flipStatus == 0) || ( player.x >=  skeleton2.x + 20 && player.x <= skeleton2.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                sound.playSoundEffect(collectKey);
                key_8.health = 0;
            }
        }

        if ( flyingEye1.health > 0){
            if ( flyingEye1.attackStatus == 2) flyingEye1.hurtSprite.doSlowSprite_2(graphic, EYE_HURT_FRAMES, flyingEye1.x, flyingEye1.y, flyingEye1.flip);
            else if (flyingEye1.attackStatus == 1) flyingEye1.attackSprite.doSlowSprite2(graphic, EYE_ATTACK_FRAMES, flyingEye1.x, flyingEye1.y, flyingEye1.flip);
            else flyingEye1.idleSprite.doSlowSprite2(graphic, EYE_IDLE_FRAMES, flyingEye1.x, flyingEye1.y, flyingEye1.flip);
            if ( flyingEye1.hurtSprite.frame/6 >= EYE_HURT_FRAMES){
                flyingEye1.hurtSprite.frame = 0;
                flyingEye1.attackStatus = 1;
            }
        }
        else{
            chest_7.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, flyingEye1.x, 404);
            if ( key_7.health == 1 ) key_7.idleSprite.doSprite(graphic, KEY_FRAMES, flyingEye1.x+20, skeleton1.y-10);
            if ( key_7.health == 1 && (( player.x + player.w >=  flyingEye1.x + 20 && player.x + player.w <= flyingEye1.x + 35 && player.flipStatus == 0) || ( player.x >=  flyingEye1.x + 20 && player.x <= flyingEye1.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                sound.playSoundEffect(collectKey);
                key_7.health = 0;
            }
        }

        if ( flyingEye2.health > 0){
            if ( flyingEye2.attackStatus == 2) flyingEye2.hurtSprite.doSlowSprite_2(graphic, EYE_HURT_FRAMES, flyingEye2.x, flyingEye2.y, flyingEye2.flip);
            else if (flyingEye2.attackStatus == 1) flyingEye2.attackSprite.doSlowSprite2(graphic, EYE_ATTACK_FRAMES, flyingEye2.x, flyingEye2.y, flyingEye2.flip);
            else flyingEye2.idleSprite.doSlowSprite2(graphic, EYE_IDLE_FRAMES, flyingEye2.x, flyingEye2.y, flyingEye2.flip);
            if ( flyingEye2.hurtSprite.frame/6 >= EYE_HURT_FRAMES){
                flyingEye2.hurtSprite.frame = 0;
                flyingEye2.attackStatus = 1;
            }
        }
        else{
            chest_9.idleSprite.doSlowSprite(graphic, CHEST_FRAMES, flyingEye2.x, 150);
            if ( key_9.health == 1 ) key_9.idleSprite.doSprite(graphic, KEY_FRAMES, flyingEye2.x+20, flyingEye2.y-10);
            if ( key_9.health == 1 && (( player.x + player.w >=  flyingEye2.x + 20 && player.x + player.w <= flyingEye2.x + 35 && player.flipStatus == 0) || ( player.x >=  flyingEye2.x + 20 && player.x <= flyingEye2.x + 35 && player.flipStatus == 1))){
                keyCount2++;
                sound.playSoundEffect(collectKey);
                key_9.health = 0;
            }
        }

        if ( player.health > 0){
            graphic.renderTexture(healthBar[player.health], nullptr, 10, 10);
            if ( keyCount2 == 4 && player.x+player.w >= SCREEN_WIDTH-50 && player.y == 560) gameStatus = 4;
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

        for (Entity* sword : swords1){
            sword->attackSprite.doSprite(graphic, SWORD_FRAMES, sword->x, sword->y, sword->flip);
        }

        for (Entity* sword : swords2){
            sword->attackSprite.doSprite(graphic, SWORD_FRAMES, sword->x, sword->y, sword->flip);
        }

        for (Entity* bomb : bombs1){
            bomb->attackSprite.doSprite(graphic, BOMB_FRAMES, bomb->x, bomb->y, bomb->flip);
        }

        for (Entity* bomb : bombs2){
            bomb->attackSprite.doSprite(graphic, BOMB_FRAMES, bomb->x, bomb->y, bomb->flip);
        }

        keyText2.str("");
        keyText2 << to_string(keyCount2) << "/4";
        keyTextTexure = graphic.loadTextTexture(keyText2.str().c_str(), textColor, textFont);
        graphic.renderTexture(keyTextTexure, nullptr, SCREEN_WIDTH/2, 10);
        graphic.renderTexture(keyTexture, nullptr, SCREEN_WIDTH/2 + 70, 6);

        if ( keyCount2 == 4){
            portal.idleSprite.doSprite(graphic, PORTAL_FRAMES, SCREEN_WIDTH-68, SCREEN_HEIGHT-164, SDL_FLIP_HORIZONTAL);
        }
    }

    void drawGame3(Graphics& graphic, Sound sound){
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
            else if (boss.attackStatus == 1){
                boss.attackSprite.doSprite(graphic, BOSS_ATTACK_FRAMES, boss.x, boss.y, boss.flip);
            }
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
                initSpell(sound);
//            if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks();
            }
            if ((SDL_GetTicks()- time - spellSpawnTime) >= 6200){
                sound.playSoundEffect(bossSpell);
                spell.attackSprite.doSprite(graphic, BOSS_SPELL_FRAMES, spell.x, spell.y);
                if ( spell.collide(&player) && spell.attackSprite.frame == 36) player.health--;
                if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks()-time;
            }
        }
        else{
            if ( spell.castSprite.frame == 0 ){
                initSpell(sound);
//            if ( spell.attackSprite.frame == 0 ) spellSpawnTime = SDL_GetTicks();
            }
            if ((SDL_GetTicks()- time - spellSpawnTime) >= 6200){
                sound.playSoundEffect(bossSpell);
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
        suggestText1.str("");
        suggestText1 << "Remember to use dash!!!";
        suggestTextTexture1 = graphic.loadTextTexture(suggestText1.str().c_str(), healthTextColor, textFont2);
        if ( SDL_GetTicks() - time >= 5000 && SDL_GetTicks() - time <= 10000){
            graphic.renderTexture(suggestTextTexture1, nullptr, 470, 80);
        }
        suggestText2.str("");
        suggestText2 << "The spell appears unpredictably!!!Be careful";
        suggestTextTexture2 = graphic.loadTextTexture(suggestText2.str().c_str(), healthTextColor, textFont2);
        if ( SDL_GetTicks() - time >= 10000 && SDL_GetTicks() - time <= 15000){
            graphic.renderTexture(suggestTextTexture2, nullptr, 360, 80);
        }
    }
};
#endif // _GAME__H
