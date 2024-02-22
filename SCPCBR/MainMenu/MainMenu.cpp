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

Util::Image::Image* whiteImage;
Util::Image::Image* blackImage;
Util::Image::Image* scp173Image;
Util::Image::Image* scpTextImage;

bool mainMenuStarted = false;

ImVec4 nonHovered = ImVec4(1, 1, 1, 1);
ImVec4 hovered = ImVec4(0.8f, 0.8f, 0.8f, 1);

void MainMenu::Init() {
    mainMenuBackgroundImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/MenuBackground.jpg", mainMenuBackgroundImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/MenuBackground.jpg\" failed to load. Ensure the file exists, or verify your game files.");
    }

    whiteImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/White.png", whiteImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/White.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    blackImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/Black.png", blackImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/Black.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    scp173Image = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/SCP173.jpg", scp173Image)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/SCP173.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
    
    scpTextImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/SCPText.jpg", scpTextImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/SCPText.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
}

void MainMenu::Render(GLFWwindow* window, GlobalGameState* gameState) {
    try {
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

        // RENDER SCP TEXT
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width / 2.0f, height), 0, ImVec2(0.5f, 1));
            ImGui::SetNextWindowSize(ImVec2(scpTextImage->Width / 2.0f, scpTextImage->Height / 2.0f));
            ImGui::Begin("## SCP-TEXT", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(0, 0));
            ImGui::Image(reinterpret_cast<void*>(scpTextImage->TextureId), ImVec2(scpTextImage->Width / 2.0f, scpTextImage->Height / 2.0f));
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        // RENDER SCP 173
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width, height), 0, ImVec2(1, 1));
            ImGui::SetNextWindowSize(ImVec2(scp173Image->Width, scp173Image->Height));
            ImGui::Begin("## SCP-173", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(0, 0));
            ImGui::Image(reinterpret_cast<void*>(scp173Image->TextureId), ImVec2(scp173Image->Width, scp173Image->Height));
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        static int selectedMenu = 0;
        
        // MAIN
        if (selectedMenu == 0) {
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(435, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-0", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom("NEW GAME", ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = 1;
                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));

            if (ImGui::ButtonCustom("LOAD GAME", ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = 2;
                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));
            
            if (ImGui::ButtonCustom("OPTIONS", ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = 3;
                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));

            if (ImGui::ButtonCustom("QUIT", ImVec2(430, 75), whiteImage, blackImage)) {
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

            if (ImGui::ButtonCustom("NEW GAME", ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = 1;
            }
            ImGui::SameLine();
            if (ImGui::ButtonCustom("BACK", ImVec2(150, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = 0;
                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 15));

            const ImVec2 currentPos = ImGui::GetWindowPos() + ImGui::GetCursorPos();
            ImGui::BeginChildCustom("MAIN-MENU-1-OPTIONS", currentPos.x, currentPos.y, 590, 330, whiteImage, blackImage);

            static std::string saveName = "untitled";
            ImGui::InputTextCustom("Name:", &saveName, whiteImage, blackImage);
            
            static std::string seed = "9SOI25GEU";
            ImGui::InputTextCustom("Map Seed:", &seed, whiteImage, blackImage);

            ImGui::Dummy(ImVec2(1, 10));
            
            static bool introEnabled = true;
            if (ImGui::CheckboxCustom("Enable intro sequence:", &introEnabled, whiteImage, blackImage)) {
                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            
            ImGui::EndChildCustom();
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        }
    } catch (...) {
        // IGNORE, CONTINUE TO NEXT FRAME
    }
}

void MainMenu::Free() {
    delete mainMenuBackgroundImage;
    delete blackImage;
    delete whiteImage;
    delete scp173Image;
    delete scpTextImage;
}
