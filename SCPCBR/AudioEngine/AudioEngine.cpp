#include "AudioEngine.h"

#include <unordered_map>

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

#include "../Util/Util.h"

FMOD::System* System = NULL;

void AudioEngine::Init() {
    FMOD_RESULT result;

    result = System_Create(&System);
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine.\nError: ") + FMOD_ErrorString(result));
    }

    result = System->init(512, FMOD_INIT_NORMAL, 0);
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine.\nError: ") + FMOD_ErrorString(result));
    }
}

void AudioEngine::RunCallbacks() {
    FMOD_RESULT result = System->update();
    if (result != FMOD_OK) {
        Util::Error::Exit(std::string("An error occured with the audio engine.\nError: ") + FMOD_ErrorString(result));
    }
}