#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <string>

#include <FMOD/fmod.hpp>

namespace AudioEngine {
    void Init();
    
    void RunCallbacks();

    void LoadSoundByName(const std::string& name, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo = nullptr);
    FMOD::Channel* PlaySoundByName(const std::string& name, FMOD::ChannelGroup* group = nullptr, bool paused = false);
    
    bool IsSoundPlaying(FMOD::Channel* channel);
    void StopSound(FMOD::Channel* channel);

    void CreateChannelGroup(const std::string& name);
    FMOD::ChannelGroup* GetChannelGroup(const std::string& name);

    void SetChannelGroupVolume(const std::string& name, float volume);
    float GetChannelGroupVolume(const std::string& name);

    void Free();
};

#endif // AUDIOENGINE_H