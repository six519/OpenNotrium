#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

#include "SDL.h"
#include "SDL_mixer.h"

class SoundSample
{
    Mix_Chunk* chunk;
    int samplefreq, bytespersample; //TODO: this does not quite belong here, I think
public:
    SoundSample(char *filename, int samplefreq, int bytespersample);

    bool initOkay();
    /**
    * Returns the length of the sound, in milliseconds.
    */
    float GetSoundLength();

    /**
    * volume clipped between 0 and 1, pan between -1 (left) and 1 (right) (TODO: is that right?)
    */
    void Play(float volume, float pan);
};

class SoundManager
{
    int samplefreq;
    int bytespersample;

    static const int numchannels = 16;
    Mix_Music *currentmusic;
public:
    bool Create( SoundSample** dest, char *filename );

    /**
    * For now, let us assume signed 16 bit data.
    */
    bool Initialize(int freq, int channels);

    void playMusic(char* filename);

    /**
    * Sets the volume of the music. Value between 0 and 1.
    */
    void setMusicVolume(float volume);
};
#endif