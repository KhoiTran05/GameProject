#ifndef _SOUND__H
#define _SOUND__H

#include<SDL_mixer.h>
#include<bits/stdc++.h>
using namespace std;

struct Sound{
    void initSound(){
        if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
            std::cout << "Failed to init SDL Mixer" << std::endl;
            Mix_GetError();
        }
    }

    Mix_Chunk* loadSoundEffect(string path){
        Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
        if ( sound == nullptr){
            cout << "Failed to load" << path << "sound" << endl;
            Mix_GetError();
        }
        return sound;
    }

    Mix_Music* loadMusic(string path){
        Mix_Music* music = Mix_LoadMUS(path.c_str());
        if ( music == nullptr){
            cout << "Failed to load" << path << "music" << endl;
            Mix_GetError();
        }
        return music;
    }

    bool musicPaused(){
        return Mix_PausedMusic() == 1;
    }

    bool musicPlaying(){
        return Mix_PlayingMusic() != 0;
    }

    void playMusic(Mix_Music* music){
        Mix_PlayMusic(music, -1);
    }

    void pauseMusic(){
        Mix_PauseMusic();
    }

    void resumeMusic(){
        Mix_ResumeMusic();
    }

    void stopMusic(){
        Mix_HaltMusic();
    }

    void playSoundEffect(Mix_Chunk* soundEffect){
        Mix_PlayChannel(-1, soundEffect, 0);
    }
};

#endif // SOUND__H
