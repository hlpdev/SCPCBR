#include <iostream>
#include <Windows.h>

#include "GameAssembly/GameAssembly.h"
#include "Localization/Localization.h"
#include "SteamWrapper/SteamWrapper.h"
#include "DiscordWrapper/DiscordWrapper.h"
#include "AudioEngine/AudioEngine.h"
#include "Options/Options.h"
#include "Launcher/Launcher.h"
#include "SplashScreen/SplashScreen.h"
#include "PreloadManager/PreloadManager.h"
#include "MainMenu/MainMenu.h"
#include "GameManager/GameManager.h"

#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <GLAD/glad.h>

#include <string>

GLFWwindow* window;

GlobalGameState CurrentGlobalGameState;

int main(int argc, char* argv[])
{
    CurrentGlobalGameState = GlobalGameState::Splash;
    
    // Hide console window
    ShowWindowAsync(GetConsoleWindow(), SW_HIDE);

    SteamWrapper* steam = new SteamWrapper;
    DiscordWrapper* discord = new DiscordWrapper;
    
    // Initialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);  // NOLINT(concurrency-mt-unsafe)
    }

    // Set OpenGL & GLFW info
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create GLFW window
    window = glfwCreateWindow(640, 410, GameWindowTitle, 0, 0);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Set window context
    glfwMakeContextCurrent(window);

    // Disable vSync
    glfwSwapInterval(0);

    // Set window icon
    Window::SetWindowIcon(window, GameWindowIcon);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {  // NOLINT(clang-diagnostic-cast-function-type-strict)
        glfwTerminate();
        exit(EXIT_FAILURE);  // NOLINT(concurrency-mt-unsafe)
    }

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.IniFilename = "uicfg.ini";

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    Options::Init();
    AudioEngine::Init();
    Localization::Init();
    
    Launcher::Init(discord);
    SplashScreen::Init();
    PreloadManager::Init();
    MainMenu::Init(discord);
    
    GameManager::Init(discord);

    AudioEngine::CreateChannelGroup("Game");
    AudioEngine::CreateChannelGroup("Music");

    AudioEngine::SetChannelGroupVolume("Game", Options::ReadIntOption("Audio", "GameVolume") / 100.0f);
    AudioEngine::SetChannelGroupVolume("Music", Options::ReadIntOption("Audio", "MusicVolume") / 100.0f);
    
    discord::Activity activity = {};
    activity.SetDetails("In the launcher");
    activity.SetType(discord::ActivityType::Playing);
    activity.SetSupportedPlatforms(static_cast<uint32_t>(discord::ActivitySupportedPlatformFlags::Desktop));
    activity.GetAssets().SetLargeImage("scpcbr");
    activity.GetTimestamps().SetStart(Util::Time::GetCurrentEpochSeconds());
    discord->UpdateActivity(activity);
    
    while (!glfwWindowShouldClose(window)) {
        if (steam) {
            steam->RunCallbacks();
        }

        if (discord) {
            discord->RunCallbacks();
        }
        
        AudioEngine::RunCallbacks();
        
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        if (Options::ReadBoolOption("Advanced", "ShowFps")) {
            ImGui::GetForegroundDrawList()->AddText(ImVec2(1, 1), ImColor(255, 255, 255), std::string(std::to_string(static_cast<int>(ImGui::GetIO().Framerate)) + " FPS").c_str());
        }

        switch (CurrentGlobalGameState) {
            /*case GlobalGameState::Launcher: {
                Launcher::Render(window, &CurrentGlobalGameState);
                break;
            }*/
            case GlobalGameState::Splash: {
                SplashScreen::Render(window, &CurrentGlobalGameState, steam);
                break;
            }
            case GlobalGameState::Preload: {
                PreloadManager::Render(window, &CurrentGlobalGameState);
                break;
            }
            case GlobalGameState::MainMenu: {
                MainMenu::Render(window, &CurrentGlobalGameState);
                break;
            }
            case GlobalGameState::Game: {
                GameManager::Render(window, &CurrentGlobalGameState);
                break;
            }
        }

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(window);
    }

    GameManager::Free();
    
    MainMenu::Free();
    PreloadManager::Free();
    SplashScreen::Free();
    Launcher::Free();
    
    Localization::Free();
    AudioEngine::Free();
    Options::Free();

    glfwTerminate();

    delete steam;
    delete discord;
    
    exit(EXIT_SUCCESS);  // NOLINT(concurrency-mt-unsafe)
}