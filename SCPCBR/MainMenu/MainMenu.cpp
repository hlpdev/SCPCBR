#include "MainMenu.h"

#include "../Util/Util.h"
#include "../AudioEngine/AudioEngine.h"

#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>
#include <FMOD/fmod.hpp>

#include "../Localization/Localization.h"

Util::Image::Image* mainMenuBackgroundImage;
FMOD::Channel* mainMenuBackgroundMusic;

bool mainMenuStarted = false;

void MainMenu::Init() {
    mainMenuBackgroundImage = new Util::Image::Image;

    mainMenuBackgroundImage = new Util::Image::Image;
    if (!Util::Image::LoadImageFromFile("Assets/GFX/Menu/MenuBackground.jpg", mainMenuBackgroundImage)) {
        Util::Error::Exit("The texture \"Assets/GFX/Menu/MenuBackground.jpg\" failed to load. Ensure the file exists, or verify your game files.");
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
    ImGui::GetForegroundDrawList()->AddText(ImVec2(1, height - ImGui::CalcTextSize(verString.c_str()).y - 1), ImColor(255, 255, 255), verString.c_str());
    
    // RENDER BACKGROUND
    { 
        ImGui::GetBackgroundDrawList()->AddImage(
            reinterpret_cast<void*>(static_cast<intptr_t>(mainMenuBackgroundImage->TextureId)), ImVec2(0, 0),
            ImVec2(mainMenuBackgroundImage->Width, mainMenuBackgroundImage->Height));
    }

    // RENDER MENU
    /*{
        static int menu = 0;

        switch (menu) {
            case 0: {
                ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
                ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0));
                ImGui::SetNextWindowSize(ImVec2(700, 500));
                ImGui::SetNextWindowPos(ImVec2(width / 2.0f, height / 2.0f), 0, ImVec2(0.5f, 0.5f));
                ImGui::Begin("## MAINMENU-MENU", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
                
                ImGui::PushFont(Localization::GetActiveLanguageCourierNewExtraLarge());
                
                if (ImGui::Button("NEW GAME", ImVec2(700, 80))) {
                    
                }

                if (ImGui::Button("LOAD GAME", ImVec2(700, 80))) {
                    
                }

                if (ImGui::Button("OPTIONS", ImVec2(700, 80))) {
                    
                }

                if (ImGui::Button("QUIT", ImVec2(700, 80))) {
                    
                }
                
                ImGui::PopFont();

                ImGui::End();
                ImGui::PopStyleColor(5);
            }
        }
    }*/
}

void MainMenu::Free() {
    
}
