#include "audio.hpp"

namespace Engine::Game::Assets
{
    void AudioAsset::loadMP3(std::string path)
    {
        audio = Mix_LoadWAV(path.c_str());
        loops = 0;
        channelID = -1;
    }

    void AudioAsset::play()
    {
        if(!isPlaying())
        {
            if(audio != NULL)
            {
                channelID = Mix_PlayChannel(-1, audio, loops);
                if(channelID == -1)
                    exit(-1);
            }
        }
    }

    Mix_Chunk* AudioAsset::getAudioChunk()
    {
        return audio;
    }

    void AudioAsset::stop()
    {
        if(isPlaying())
        {
            Mix_HaltChannel(channelID);
            channelID = -1;
        }
    }

    bool AudioAsset::isPlaying()
    {
        return channelID != -1;
    }

    void AudioAsset::setLoops(int loopcount)
    {
        loops = loopcount;
        stop();
        play();
    }
};