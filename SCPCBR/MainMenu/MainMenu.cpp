#include "MainMenu.h"

#include "../Util/Util.h"
#include "../AudioEngine/AudioEngine.h"

#include <imgui/imgui.h>
#include <FMOD/fmod.hpp>

Util::Image::Image* mainMenuBackgroundImage;
FMOD::Channel* mainMenuBackgroundMusic;

bool mainMenuStarted = false;

void MainMenu::Init() {
    mainMenuBackgroundImage = new Util::Image::Image;

    mainMenuBackgroundImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/MenuBackground.png", mainMenuBackgroundImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/MenuBackground.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
}

void MainMenu::Render(GLFWwindow* window, GlobalGameState* gameState) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    if (!mainMenuStarted) {
        AudioEngine::PlaySoundByName("Assets/SFX/Music/Menu.ogg", AudioEngine::GetChannelGroup("Music"));
        mainMenuStarted = true;
    }
    
    // RENDER BACKGROUND
    {
        ImVec2 pos1;
        ImVec2 pos2;

        if (height * ((double)mainMenuBackgroundImage->Width / mainMenuBackgroundImage->Height) >= width) {
            pos1 = ImVec2(0 - (height * ((double)mainMenuBackgroundImage->Width / mainMenuBackgroundImage->Height) - width) / 2, 0);
            pos2 = ImVec2(width + (height * ((double)mainMenuBackgroundImage->Width / mainMenuBackgroundImage->Height) - width) / 2, height);
        } else {
            pos1 = ImVec2(0, 0 - (width / ((double)mainMenuBackgroundImage->Width / mainMenuBackgroundImage->Height) - height) / 2);
            pos2 = ImVec2(width, height + (width / ((double)mainMenuBackgroundImage->Width / mainMenuBackgroundImage->Height) - height) / 2);
        }

        ImGui::GetBackgroundDrawList()->AddImage(reinterpret_cast<void*>(static_cast<intptr_t>(mainMenuBackgroundImage->TextureId)), pos1, pos2);
    }
}

void MainMenu::Free() {
    
}
