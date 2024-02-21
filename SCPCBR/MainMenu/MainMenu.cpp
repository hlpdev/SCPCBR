#include "MainMenu.h"

#include "../Util/Util.h"
#include "../AudioEngine/AudioEngine.h"

#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>
#include <FMOD/fmod.hpp>

#include "archive_entry.h"
#include "../Localization/Localization.h"

Util::Image::Image* mainMenuBackgroundImage;
FMOD::Channel* mainMenuBackgroundMusic;

Util::Image::Image* newGameImage;
Util::Image::Image* loadGameImage;
Util::Image::Image* optionsImage;
Util::Image::Image* quitImage;
Util::Image::Image* backImage;

bool mainMenuStarted = false;

ImVec4 nonHovered = ImVec4(1, 1, 1, 1);
ImVec4 hovered = ImVec4(0.8f, 0.8f, 0.8f, 1);

void MainMenu::Init() {
    mainMenuBackgroundImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/MenuBackground.jpg", mainMenuBackgroundImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/MenuBackground.jpg\" failed to load. Ensure the file exists, or verify your game files.");
    }

    newGameImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/NewGame.png", newGameImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/NewGame.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    loadGameImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/LoadGame.png", loadGameImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/LoadGame.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    optionsImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/Options.png", optionsImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/Options.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    quitImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/Quit.png", quitImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/Quit.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
    
    backImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/Back.png", backImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/Back.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
}

void MainMenu::Render(GLFWwindow* window, GlobalGameState* gameState) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    if (!mainMenuStarted) {
        AudioEngine::PlaySoundByName("Assets/SFX/Music/Menu.ogg", AudioEngine::GetChannelGroup("Music"));
        mainMenuStarted = true;
    }

    std::string verString = "SCP: CONTAINMENT BREACH REMASTERED V2.0.0 ALPHA";
    ImGui::GetForegroundDrawList()->AddText(ImVec2(1, height - ImGui::CalcTextSize(verString.c_str()).y - 1), ImColor(255, 255, 255), std::string(std::to_string(ImGui::GetMousePos().x) + "x" + std::to_string(ImGui::GetMousePos().y)).c_str());
    
    // RENDER BACKGROUND
    { 
        ImGui::GetBackgroundDrawList()->AddImage(
            reinterpret_cast<void*>(static_cast<intptr_t>(mainMenuBackgroundImage->TextureId)), ImVec2(0, 0),
            ImVec2(mainMenuBackgroundImage->Width, mainMenuBackgroundImage->Height));
    }

    static int selectedMenu = 0;
    
    // MAIN
    if (selectedMenu == 0) {
        ImGui::SetNextWindowPos(ImVec2(144, 270));
        ImGui::SetNextWindowSize(ImVec2(435, 480));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::Begin("## MAIN-MENU-0", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        static bool newGameHovered = false;
        ImGui::Image(reinterpret_cast<void*>(newGameImage->TextureId), ImVec2(newGameImage->Width, newGameImage->Height), ImVec2(0, 0), ImVec2(1, 1), newGameHovered ? hovered : nonHovered);
        if (ImGui::IsItemHovered()) {
            newGameHovered = true;
        } else {
            newGameHovered = false;
        }
        if (ImGui::IsItemClicked()) {
            selectedMenu = 1;
            AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
        }

        ImGui::Dummy(ImVec2(1, 20));

        static bool loadGameHovered = false;
        ImGui::Image(reinterpret_cast<void*>(loadGameImage->TextureId), ImVec2(loadGameImage->Width, loadGameImage->Height), ImVec2(0, 0), ImVec2(1, 1), loadGameHovered ? hovered : nonHovered);
        if (ImGui::IsItemHovered()) {
            loadGameHovered = true;
        } else {
            loadGameHovered = false;
        }
        if (ImGui::IsItemClicked()) {
            selectedMenu = 2;
            AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
        }

        ImGui::Dummy(ImVec2(1, 20));
        
        static bool optionsHovered = false;
        ImGui::Image(reinterpret_cast<void*>(optionsImage->TextureId), ImVec2(optionsImage->Width, optionsImage->Height), ImVec2(0, 0), ImVec2(1, 1), optionsHovered ? hovered : nonHovered);
        if (ImGui::IsItemHovered()) {
            optionsHovered = true;
        } else {
            optionsHovered = false;
        }
        if (ImGui::IsItemClicked()) {
            selectedMenu = 3;
            AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
        }

        ImGui::Dummy(ImVec2(1, 20));

        static bool quitHovered = false;
        ImGui::Image(reinterpret_cast<void*>(quitImage->TextureId), ImVec2(quitImage->Width, quitImage->Height), ImVec2(0, 0), ImVec2(1, 1), quitHovered ? hovered : nonHovered);
        if (ImGui::IsItemHovered()) {
            quitHovered = true;
        } else {
            quitHovered = false;
        }
        if (ImGui::IsItemClicked()) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
        }
        
        ImGui::End();
        ImGui::PopStyleColor(2);
    } else if (selectedMenu == 1) {
        ImGui::SetNextWindowPos(ImVec2(144, 270));
        ImGui::SetNextWindowSize(ImVec2(610, 480));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::Begin("## MAIN-MENU-1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        ImGui::Image(reinterpret_cast<void*>(newGameImage->TextureId), ImVec2(newGameImage->Width, newGameImage->Height), ImVec2(0, 0), ImVec2(1, 1), nonHovered);
        ImGui::SameLine(0, 5);

        static bool backHovered = false;
        ImGui::Image(reinterpret_cast<void*>(backImage->TextureId), ImVec2(backImage->Width, backImage->Height), ImVec2(0, 0), ImVec2(1, 1), backHovered ? hovered : nonHovered);
        if (ImGui::IsItemHovered()) {
            backHovered = true;
        } else {
            backHovered = false;
        }
        if (ImGui::IsItemClicked()) {
            AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            selectedMenu = 0;
        }
        
        ImGui::End();
        ImGui::PopStyleColor(2);
    }
}

void MainMenu::Free() {
    delete mainMenuBackgroundImage;
    delete newGameImage;
    delete loadGameImage;
    delete optionsImage;
    delete quitImage;
    delete backImage;
}
