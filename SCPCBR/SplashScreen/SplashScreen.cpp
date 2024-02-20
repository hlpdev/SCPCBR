#include "SplashScreen.h"

#include <vector>
#include <string>
#include <thread>
#include <Windows.h>
#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>

#include "../AudioEngine/AudioEngine.h"
#include "../Localization/Localization.h"

bool splashStarted = false;
bool finished = false;
std::vector<std::string> consoleMessages;
int mode = 1;
ImVec4 backColor = ImVec4(0, 0, 0, 0);

void SplashScreenThread() {
    Sleep(1400);
    
    backColor = ImVec4(1, 1, 1, 1);
    
    Sleep(50);
    
    backColor = ImVec4(0, 0, 0, 0);
    
    Sleep(550);

    consoleMessages.push_back("SCP:CBR, An HNT8 Production");
    consoleMessages.push_back("Copyright (C) 2024, HNT8 Organization.");

    Sleep(500);
    
    consoleMessages.push_back("");
    consoleMessages.push_back("Krait 400 CPU at 2500 MHz , 4 Processor(s)");

    Sleep(750);

    consoleMessages.push_back("Memory Test : 195815K");

    Sleep(100);

    consoleMessages.pop_back();
    consoleMessages.push_back("Memory Test : 285718K");

    Sleep(100);

    consoleMessages.pop_back();
    consoleMessages.push_back("Memory Test: 728591K");

    Sleep(100);

    consoleMessages.pop_back();
    consoleMessages.push_back("Memory Test: 958126K");

    Sleep(100);

    consoleMessages.pop_back();
    consoleMessages.push_back("Memory Test: 10485761K");

    Sleep(100);

    consoleMessages.pop_back();
    consoleMessages.push_back("Memory Test: 11958967K");

    Sleep(500);

    consoleMessages.push_back("");
    consoleMessages.push_back("OpenGL Extension v3.3");
    consoleMessages.push_back("Copyright (C) 1997-2024, KHRONOS GROUP");

    Sleep(500);

    consoleMessages.push_back("");
    consoleMessages.push_back("GLFW Extension v3.3.9");
    consoleMessages.push_back("Copyright (C) 2002-2006, Marcus Geelnard");
    consoleMessages.push_back("Copyright (C) 2006-2019, Camilla Löwy");

    Sleep(500);

    consoleMessages.push_back("");
    consoleMessages.push_back("Dear ImGui Extension v1.90.3");
    consoleMessages.push_back("MIT License");

    Sleep(500);

    consoleMessages.push_back("");
    consoleMessages.push_back("FMOD Extension v2.02");
    consoleMessages.push_back("Copyright (C) 2024, Firelight Technologies Pty Ltd");

    Sleep(100);

    consoleMessages.push_back("");
    consoleMessages.push_back("   Detecting Flash ROM        . . .  ");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting Flash ROM        . . .  __");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting Flash ROM        . . .  CyanogenMod 12");

    Sleep(100);

    consoleMessages.push_back("   Detecting Flash Extension  . . .  ");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting Flash Extension  . . .  __");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting Flash Extension  . . .  Generic microSD");

    Sleep(100);

    consoleMessages.push_back("   Detecting MPU              . . .  ");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting MPU              . . .  __");

    Sleep(30);

    consoleMessages.pop_back();
    consoleMessages.push_back("   Detecting MPU              . . .  Generic S1M Card");

    Sleep(1600);

    consoleMessages.clear();

    mode = 2;

    consoleMessages.push_back("");
    consoleMessages.push_back("");
    consoleMessages.push_back("PCI device listening.....");

    Sleep(300);

    consoleMessages.push_back("Bus  Device  Device ID  Device Class");
    consoleMessages.push_back("_________________________________________________________");
    
    Sleep(300);
    
    consoleMessages.push_back(" 0     37      24C2     IEEE 802.11 Networking Controller");

    Sleep(100);
    
    consoleMessages.push_back(" 0     23      24C4     IEEE 802.15.1 WPAN Controller");

    Sleep(100);
    
    consoleMessages.push_back(" 0     22      24C7     Display Controller");

    Sleep(100);
    
    consoleMessages.push_back(" 0     21      24C8     A-GPS Receiver Device");

    Sleep(100);
    
    consoleMessages.push_back(" 1     8       4E44     Multi-Axis Accelerometer");

    Sleep(100);
    
    consoleMessages.push_back(" 1     4       5F33     Proximity Sensor");

    Sleep(100);
    
    consoleMessages.push_back(" 1     3       5F34     Ambient Light Sensor");

    Sleep(100);
    
    consoleMessages.push_back(" 1     2       5F55     Digital Compass");

    Sleep(1500);

    consoleMessages.push_back("");
    consoleMessages.push_back("");
    consoleMessages.push_back("Initialization finished.");

    Sleep(2500);

    finished = true;
}

Util::Image::Image* scpcbrImage = static_cast<Util::Image::Image*>(malloc(sizeof(Util::Image::Image)));

FMOD::Channel* splashChannel;

void SplashScreen::Init() {
    AudioEngine::LoadSoundByName("Assets/SFX/Splash/Splash.mp3", FMOD_3D);

    bool res = LoadImageFromFile("Assets/GFX/Window/remastered2.png", scpcbrImage);
    if (!res) {
        Util::Error::Exit("The texture \"Assets\\GFX\\Window\\remastered2.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
}

std::thread splashScreenThread;

void SplashScreen::Render(GLFWwindow* window, GlobalGameState* gameState, SteamWrapper* steam) {
    try {
        if (!splashStarted) {
            splashStarted = true;
            splashChannel = AudioEngine::PlaySoundByName("Assets/SFX/Splash/Splash.mp3", AudioEngine::GetChannelGroup("Game"));
            splashScreenThread = std::thread(SplashScreenThread);
            splashScreenThread.detach();

            steam = new SteamWrapper();
            steam->SetNotificationPosition(SteamWrapper::NotificationPosition::TopRight);
            steam->SetRichPresence("steam_display", "#Launcher");
        }
        
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        ImGui::PushFont(Localization::GetActiveLanguageCourierNew());

        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, backColor);
        ImGui::SetNextWindowPos(ImVec2(width - 250, 10));
        ImGui::SetNextWindowSize(ImVec2(240, 240));
        ImGui::Begin("## SPLASH-SCREEN-LOGO", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SetCursorPos(ImVec2(0, 0));
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(scpcbrImage->TextureId)), ImVec2(240, 240));
        ImGui::End();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
        
        if (mode == 1) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, backColor);
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(width, height));
            ImGui::Begin("## SPLASH-SCREEN1", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            for (const std::string& log : consoleMessages) {
                ImGui::Text(log.c_str());
            }

            if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                ImGui::SetScrollHereY(1.0f);
        
            ImGui::End();
            ImGui::PopStyleColor();
            ImGui::PopStyleVar();
        } else if (mode == 2) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 3);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, backColor);
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 1));
            ImGui::SetNextWindowPos(ImVec2(10, 10));
            ImGui::SetNextWindowSize(ImVec2(490, 90));
            ImGui::Begin("## SPLASH-SCREEN2", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            ImGui::Text("CPU Type          : Krait 400 CPU at 2500MHz");
            ImGui::Text("Cache Memory      : 1048756K");
            ImGui::Text("Memory Installed  : 1024M DRAM");

            if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                ImGui::SetScrollHereY(1.0f);
        
            ImGui::End();
            ImGui::PopStyleColor(2);
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 3);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, backColor);
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 1));
            ImGui::SetNextWindowPos(ImVec2(10, 100));
            ImGui::SetNextWindowSize(ImVec2(490, 180));
            ImGui::Begin("## SPLASH-SCREEN3", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            ImGui::Text("Pri. Master Disk  : 2048MB, ROM");
            ImGui::Text("Pri. Slave Disk   : 12582912MB");
            ImGui::Text("Sec. Master Disk  : 16777216MB");
            ImGui::Text("");
            ImGui::Text("Display Type      : True HD-IPS*LCD 2560x1440");
            ImGui::Text("Serial Port (s)   : A2DP");
            ImGui::Text("Parallel Port (s) : 378");
            ImGui::Text("GPS On Module (s) : Yes");

            if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                ImGui::SetScrollHereY(1.0f);
        
            ImGui::End();
            ImGui::PopStyleColor(2);
            ImGui::PopStyleVar();
            
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, backColor);
            ImGui::SetNextWindowPos(ImVec2(10, 290));
            ImGui::SetNextWindowSize(ImVec2(width, height - 290));
            ImGui::Begin("## SPLASH-SCREEN4", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            for (const std::string& log : consoleMessages) {
                ImGui::Text(log.c_str());
            }

            if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                ImGui::SetScrollHereY(1.0f);
        
            ImGui::End();
            ImGui::PopStyleColor();
            ImGui::PopStyleVar();
        }

        // PRESS SPACE TO CONTINUE
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::SetNextWindowSize(ImVec2(width, 30));
        ImGui::SetNextWindowPos(ImVec2(0, height - 50));
        ImGui::Begin("## SKIP", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        ImGui::TextCentered(Localization::GetTranslatedKey("LoadingScreens", "anykey").c_str());

        if (glfwGetKey(window, GLFW_KEY_SPACE)) {
            *gameState = GlobalGameState::Preload;

            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            AudioEngine::StopSound(splashChannel);
        }
            
        ImGui::End();
        ImGui::PopStyleColor(2);

        ImGui::PopFont();

        if (finished) {
            *gameState = GlobalGameState::Preload;
        }
    } catch (...) {
        // IGNORE, UNKNOWN FATAL ERROR THROWS HERE FOR SOME REASON, JUST SKIP DISPLAYING THE SPLASH FOR A SINGLE FRAME
    }
}

void SplashScreen::Free() {
    free(scpcbrImage);
}
