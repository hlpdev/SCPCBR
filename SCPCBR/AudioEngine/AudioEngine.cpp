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
    FMOD::Sound* sound = nullptr;
    
    FMOD_RESULT result = System->createSound(name.c_str(), mode, exInfo, &sound);

    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to load sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }

    result = System->playSound(sound, nullptr, true, nullptr);
    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to play & pause sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }

    LoadedSounds[name] = sound;
}

void AudioEngine::PlaySoundByName(const std::string& name, FMOD::ChannelGroup* group, bool paused, FMOD::Channel** channel) {
    FMOD_RESULT result = System->playSound(LoadedSounds[name], group, paused, channel);

    if (result != FMOD_OK) {
        Util::Error::Exit("An error occured with the audio engine. Failed to play sound: " + name + "\nError: " + FMOD_ErrorString(result));
    }
}

void AudioEngine::CreateChannelGroup(const std::string& name) {
    FMOD::ChannelGroup* group;
    
    FMOD_RESULT result = System->createChannelGroup(name.c_str(), &group);

    if (result != FMOD_OK) {
        Util::Error::Exit("Failed to create channel group with name: " + name + "\nError: " + FMOD_ErrorString(result));
    }

    ChannelGroups[name] = group;
}

FMOD::ChannelGroup* AudioEngine::GetChannelGroup(const std::string& name) {
    if (ChannelGroups.contains(name)) {
        return ChannelGroups[name];
    }

    return nullptr;
}

void AudioEngine::SetChannelGroupVolume(const std::string& name, float volume) {
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
