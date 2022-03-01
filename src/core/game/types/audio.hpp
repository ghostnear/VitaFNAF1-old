#ifndef ASSET_TYPE_AUDIO_HPP
#define ASSET_TYPE_AUDIO_HPP

#include "asset.hpp"
#include <SDL2/SDL_mixer.h>

namespace Engine::Game::Assets
{
    class AudioAsset : public Asset
    {
        Mix_Chunk* audio = NULL;
        int loops, channelID;

    public:
        // Load MP3s
        void loadMP3(std::string path);

        // Sets the ammount of loops
        void setLoops(int loopcount);

        // Checks if it is playing
        bool isPlaying();
        
        // Play
        void play();

        // Stop
        void stop();
    };
};

#endif