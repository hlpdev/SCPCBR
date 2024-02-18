#include "AudioEngine.h"

#include <unordered_map>

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

#include "../Util/Util.h"

std::unordered_map<std::string, FMOD::Sound*> LoadedSounds;
std::unordered_map<std::string, FMOD::ChannelGroup*> ChannelGroups;

FMOD::System* System = NULL;

void AudioEngine::Init() {
    FMOD_RESULT result;

    result = System_Create(&System);
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured while initializing audio engine.\nError: ") + FMOD_ErrorString(result));
    }

    result = System->init(512, FMOD_INIT_NORMAL, 0);
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured while initializing audio engine.\nError: ") + FMOD_ErrorString(result));
    }
}

void AudioEngine::RunCallbacks() {
    FMOD_RESULT result = System->update();
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine.\nError: ") + FMOD_ErrorString(result));
    }
}

void AudioEngine::LoadSoundByName(const std::string& name, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exInfo) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");
    
    FMOD_RESULT result = System->createSound(name.c_str(), mode, exInfo, &LoadedSounds[name]);

    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to load sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }
    
    result = System->playSound(LoadedSounds[name], nullptr, true, nullptr);
    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to play & pause sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }
}

FMOD::Channel* AudioEngine::PlaySoundByName(const std::string& name, FMOD::ChannelGroup* group, bool paused) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");

    FMOD::Channel* channel;
    
    FMOD_RESULT result = System->playSound(LoadedSounds[name], group, paused, &channel);

    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to play sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }

    return channel;
}

bool AudioEngine::IsSoundPlaying(FMOD::Channel* channel) {
    bool isPlaying;
    FMOD_RESULT result = channel->isPlaying(&isPlaying);
    
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine. Failed to check if sound was playing.\nError: ") + FMOD_ErrorString(result));
    }

    return isPlaying;
}

void AudioEngine::StopSound(FMOD::Channel* channel) {
    FMOD_RESULT result = channel->stop();

    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine. Failed to stop sound\nError: ") + FMOD_ErrorString(result));
    }
}

void AudioEngine::CreateChannelGroup(const std::string& name) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");
    
    FMOD_RESULT result = System->createChannelGroup(name.c_str(), &ChannelGroups[name]);

    if (result != FMOD_OK) {
        Util::Error::Exit("Failed to create channel group with name: " + name + "\nError: " + FMOD_ErrorString(result));
    }
}

FMOD::ChannelGroup* AudioEngine::GetChannelGroup(const std::string& name) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");
    
    if (ChannelGroups.contains(name)) {
        return ChannelGroups[name];
    }

    return nullptr;
}

void AudioEngine::SetChannelGroupVolume(const std::string& name, float volume) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");
    
    FMOD::ChannelGroup* group = GetChannelGroup(name);

    if (group == nullptr) {
        Util::Error::Exit("Failed to set volume of Channel Group: " + name + " because the group doesn't exist");
    }

    FMOD_RESULT result = group->setVolume(volume);
    if (result != FMOD_OK) {
        Util::Error::Exit("Failed to set volume of Channel Group: " + name + "\nError: " + FMOD_ErrorString(result));
    }
}

float AudioEngine::GetChannelGroupVolume(const std::string& name) {
    Util::Strings::ReplaceAll(const_cast<std::string&>(name), "\\", "/");
    
    FMOD::ChannelGroup* group = GetChannelGroup(name);

    if (group == nullptr) {
        Util::Error::Exit("Failed to get volume of Channel Group: " + name + " because the group doesn't exist");
    }

    float volume;
    FMOD_RESULT result = group->getVolume(&volume);

    if (result != FMOD_OK) {
        Util::Error::Exit("Failed to get volume of Channel Group: " + name + "\nError: " + FMOD_ErrorString(result));
    }

    return volume;
}

void AudioEngine::Free() {
    FMOD_RESULT result;

    result = System->close();
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured while freeing the audio engine.\nError: ") + FMOD_ErrorString(result));
    }

    result = System->release();
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured while freeing the audio engine.\nError: ") + FMOD_ErrorString(result));
    }
}
