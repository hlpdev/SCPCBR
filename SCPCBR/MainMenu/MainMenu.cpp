#include "MainMenu.h"

#include <thread>

#include "../Util/Util.h"
#include "../AudioEngine/AudioEngine.h"
#include "../Localization/Localization.h"

#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>
#include <FMOD/fmod.hpp>

#include <archive_entry.h>

#include "../Options/Options.h"

#define MAIN_MENU 0
#define NEW_GAME 1
#define LOAD_MAP 2
#define LOAD_GAME 3
#define OPTIONS 4

class DiscordWrapper;

namespace MainMenu {
    int width, height;
    
    Util::Image::Image* mainMenuBackgroundImage;
    FMOD::Channel* mainMenuBackgroundMusic;

    Util::Image::Image* whiteImage;
    Util::Image::Image* blackImage;
    Util::Image::Image* scp173Image;
    Util::Image::Image* scpTextImage;

    bool mainMenuStarted = false;

    ImVec4 nonHovered = ImVec4(1, 1, 1, 1);
    ImVec4 hovered = ImVec4(0.8f, 0.8f, 0.8f, 1);

    DiscordWrapper* discord = nullptr;

    namespace PreTranslatedStrings {
        std::string NewGame;
        std::string LoadGame;
        std::string Options;
        std::string Quit;
        std::string Back;
        std::string SaveName;
        std::string SaveSeed;
        std::string IntroSeq;
        std::string Difficulty;
        std::string SafeDifficulty;
        std::string SafeDifficultyDescription;
        std::string EuclidDifficulty;
        std::string EuclidDifficultyDescription;
        std::string KeterDifficulty;
        std::string KeterDifficultyDescription;
        std::string ApollyonDifficulty;
        std::string ApollyonDifficultyDescription;
        std::string LoadMap;
        std::string Start;

        std::string DontBlink;
        std::string SecureContainProtect;
        std::string HappyEndings;
        std::string SometimesScream;
        std::string Nil;
        std::string No;
        std::string BlackWhite;
        std::string StoneCare;
        std::string D9341;
        std::string ControlsDoors;
        std::string Random;
        std::string TakenOver;
        std::string Spiral;
        std::string RealityDamage;
    }
}

namespace RandomText {
    bool ShouldShow = false;
    std::string Text;
    ImVec2 Position;
    bool ShouldStopGenerating = false;
}

void RandomTextThread() {
    Sleep(6000);
    while (!RandomText::ShouldStopGenerating) {
        switch (Util::Math::RandomInt(0, 13)) {
            case 0: {
                RandomText::Text = MainMenu::PreTranslatedStrings::DontBlink;
                break;
            }
            case 1: {
                RandomText::Text = MainMenu::PreTranslatedStrings::SecureContainProtect;
                break;
            }
            case 2: {
                RandomText::Text = MainMenu::PreTranslatedStrings::HappyEndings;
                break;
            }
            case 3: {
                RandomText::Text = MainMenu::PreTranslatedStrings::SometimesScream;
                break;
            }
            case 4: {
                RandomText::Text = MainMenu::PreTranslatedStrings::Nil;
                break;
            }
            case 5: {
                RandomText::Text = MainMenu::PreTranslatedStrings::No;
                break;
            }
            case 6: {
                RandomText::Text = MainMenu::PreTranslatedStrings::BlackWhite;
                break;
            }
            case 7: {
                RandomText::Text = MainMenu::PreTranslatedStrings::StoneCare;
                break;
            }
            case 8: {
                RandomText::Text = MainMenu::PreTranslatedStrings::D9341;
                break;
            }
            case 9: {
                RandomText::Text = MainMenu::PreTranslatedStrings::ControlsDoors;
                break;
            }
            case 10: {
                RandomText::Text = MainMenu::PreTranslatedStrings::Random;
                break;
            }
            case 11: {
                RandomText::Text = MainMenu::PreTranslatedStrings::TakenOver;
                break;
            }
            case 12: {
                RandomText::Text = MainMenu::PreTranslatedStrings::Spiral;
                break;
            }
            case 13: {
                RandomText::Text = MainMenu::PreTranslatedStrings::RealityDamage;
                break;
            }
        }

        RandomText::Position = ImVec2(Util::Math::RandomInt(MainMenu::width / 2.0f - 300, MainMenu::width / 2.0f + 300), Util::Math::RandomInt(MainMenu::height / 2.0f - 300, MainMenu::height / 2.0f + 300));
        RandomText::ShouldShow = true;
        Sleep(1000);
        RandomText::ShouldShow = false;
        Sleep(Util::Math::RandomInt(10000, 45000));
    }
}

void MainMenu::Init(DiscordWrapper* discordWrapper) {
    discord = discordWrapper;
    
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

    PreTranslatedStrings::NewGame = Localization::GetTranslatedKey("MainMenu", "newgame");
    PreTranslatedStrings::LoadGame = Localization::GetTranslatedKey("MainMenu", "loadgame");
    PreTranslatedStrings::Options = Localization::GetTranslatedKey("MainMenu", "options");
    PreTranslatedStrings::Quit = Localization::GetTranslatedKey("MainMenu", "quit");
    PreTranslatedStrings::Back = Localization::GetTranslatedKey("MainMenu", "back");
    PreTranslatedStrings::SaveName = Localization::GetTranslatedKey("MainMenu", "savename");
    PreTranslatedStrings::SaveSeed = Localization::GetTranslatedKey("MainMenu", "saveseed");
    PreTranslatedStrings::IntroSeq = Localization::GetTranslatedKey("MainMenu", "introseq");
    PreTranslatedStrings::Difficulty = Localization::GetTranslatedKey("MainMenu", "difficulty");
    PreTranslatedStrings::SafeDifficulty = Localization::GetTranslatedKey("MainMenu", "safe");
    PreTranslatedStrings::SafeDifficultyDescription = Localization::GetTranslatedKey("MainMenu", "safedescription");
    PreTranslatedStrings::EuclidDifficulty = Localization::GetTranslatedKey("MainMenu", "euclid");
    PreTranslatedStrings::EuclidDifficultyDescription = Localization::GetTranslatedKey("MainMenu", "eucliddescription");
    PreTranslatedStrings::KeterDifficulty = Localization::GetTranslatedKey("MainMenu", "keter");
    PreTranslatedStrings::KeterDifficultyDescription = Localization::GetTranslatedKey("MainMenu", "keterdescription");
    PreTranslatedStrings::ApollyonDifficulty = Localization::GetTranslatedKey("MainMenu", "apollyon");
    PreTranslatedStrings::ApollyonDifficultyDescription = Localization::GetTranslatedKey("MainMenu", "apollyondescription");
    PreTranslatedStrings::LoadMap = Localization::GetTranslatedKey("MainMenu", "loadmap");
    PreTranslatedStrings::Start = Localization::GetTranslatedKey("MainMenu", "start");

    PreTranslatedStrings::DontBlink = Localization::GetTranslatedKey("MainMenu", "dontblink");
    PreTranslatedStrings::SecureContainProtect = Localization::GetTranslatedKey("MainMenu", "securecontainprotect");
    PreTranslatedStrings::HappyEndings = Localization::GetTranslatedKey("MainMenu", "happyendings");
    PreTranslatedStrings::SometimesScream = Localization::GetTranslatedKey("MainMenu", "sometimesscream");
    PreTranslatedStrings::Nil = Localization::GetTranslatedKey("MainMenu", "nil");
    PreTranslatedStrings::No = Localization::GetTranslatedKey("MainMenu", "no");
    PreTranslatedStrings::BlackWhite = Localization::GetTranslatedKey("MainMenu", "blackwhite");
    PreTranslatedStrings::StoneCare = Localization::GetTranslatedKey("MainMenu", "stonecare");
    PreTranslatedStrings::D9341 = Localization::GetTranslatedKey("MainMenu", "d9341");
    PreTranslatedStrings::ControlsDoors = Localization::GetTranslatedKey("MainMenu", "controlsdoors");
    PreTranslatedStrings::Random = Localization::GetTranslatedKey("MainMenu", "random");
    PreTranslatedStrings::TakenOver = Localization::GetTranslatedKey("MainMenu", "takenover");
    PreTranslatedStrings::Spiral = Localization::GetTranslatedKey("MainMenu", "spiral");
    PreTranslatedStrings::RealityDamage = Localization::GetTranslatedKey("MainMenu", "realitydamage");

    std::thread(RandomTextThread).detach();
}

void MainMenu::Render(GLFWwindow* window, GlobalGameState* gameState) {
    try {
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
                mainMenuBackgroundImage->TextureIdPtr,
                ImVec2(0, 0),
                ImVec2(mainMenuBackgroundImage->Width, mainMenuBackgroundImage->Height)
            );
            
            ImGui::GetBackgroundDrawList()->AddImage(
                whiteImage->TextureIdPtr,
                ImVec2(1280, 407),
                ImVec2(width, 413),
                ImVec2(0, 0),
                ImVec2((width - 1280) / static_cast<float>(whiteImage->Width), 6 / static_cast<float>(whiteImage->Height)),
                ImColor(230, 230, 230, 255)
            );
        }

        // RENDER SCP TEXT
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width / 2.0f, height), 0, ImVec2(0.5f, 1));
            ImGui::SetNextWindowSize(ImVec2(scpTextImage->Width / 2.0f, scpTextImage->Height / 2.0f));
            ImGui::Begin("## SCP-TEXT", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
            ImGui::SetCursorPos(ImVec2(0, 0));
            ImGui::Image(scpTextImage->TextureIdPtr, ImVec2(scpTextImage->Width / 2.0f, scpTextImage->Height / 2.0f));
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        // RENDER RANDOM TEXT
        if (RandomText::ShouldShow) {
            ImVec2 newPos = RandomText::Position + ImVec2(Util::Math::RandomInt(-5, 5), Util::Math::RandomInt(-5, 5));
            ImGui::GetForegroundDrawList()->AddText(newPos, ImColor(100, 100, 100), RandomText::Text.c_str());
        }

        // RENDER SCP 173
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width, height), 0, ImVec2(1, 1));
            ImGui::SetNextWindowSize(ImVec2(scp173Image->Width, scp173Image->Height));
            ImGui::Begin("## SCP-173", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
            ImGui::SetCursorPos(ImVec2(0, 0));
            if (Util::Math::RandomFloat(0.0f, 1.0f) <= 0.3f) {
                ImGui::Image(scp173Image->TextureIdPtr, ImVec2(scp173Image->Width, scp173Image->Height));
            }
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        // RENDER DISCORD BUTTON
        {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width - 95, 5));
            ImGui::Begin("## DISCORD-BUTTON", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(0, 0));
            if (ImGui::ButtonCustom("DISCORD", ImVec2(90, 40), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall())) {
                discord->OpenGuildInvite("Q7VKS6hwEV");
            }
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        static int selectedMenu = 0;
        
        // MAIN
        if (selectedMenu == MAIN_MENU) {
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(435, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-0", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::NewGame, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = NEW_GAME;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));

            if (ImGui::ButtonCustom(PreTranslatedStrings::LoadGame, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = LOAD_GAME;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));
            
            if (ImGui::ButtonCustom(PreTranslatedStrings::Options, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = OPTIONS;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 16));

            if (ImGui::ButtonCustom(PreTranslatedStrings::Quit, ImVec2(430, 75), whiteImage, blackImage)) {
                RandomText::ShouldStopGenerating = true;
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        } else if (selectedMenu == NEW_GAME) { // NEW GAME
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(610, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::NewGame, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = 1;
            }
            ImGui::SameLine();
            if (ImGui::ButtonCustom(PreTranslatedStrings::Back, ImVec2(150, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = 0;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 1));

            const ImVec2 currentPos = ImGui::GetWindowPos() + ImGui::GetCursorPos();
            ImGui::Dummy(ImVec2(590, 315));
            ImGui::BeginChildCustom("MAIN-MENU-1-OPTIONS", currentPos.x, currentPos.y, 590, 315, whiteImage, blackImage);
            
            static std::string saveName = "untitled";
            ImGui::InputTextCustom(PreTranslatedStrings::SaveName.c_str(), &saveName, whiteImage, blackImage);
            
            static std::string seed = "9SOI25GEU";
            ImGui::InputTextCustom(PreTranslatedStrings::SaveSeed.c_str(), &seed, whiteImage, blackImage);

            ImGui::Dummy(ImVec2(1, 10));
            
            static bool introEnabled = true;
            if (ImGui::CheckboxCustom(PreTranslatedStrings::IntroSeq.c_str(), &introEnabled, whiteImage, blackImage)) {
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 10));

            ImGui::Text("%s", PreTranslatedStrings::Difficulty.c_str());

            ImGui::Dummy(ImVec2(1, 6));

            static bool safe = true;
            static bool euclid = false;
            static bool keter = false;
            static bool apollyon = false;
            static const char* description = PreTranslatedStrings::SafeDifficultyDescription.c_str();

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(96 / 255.0f, 117 / 255.0f, 46 / 255.0f, 1));
            if (ImGui::CheckboxCustom(PreTranslatedStrings::SafeDifficulty.c_str(), &safe, whiteImage, blackImage, 110)) {
                euclid = false;
                keter = false;
                apollyon = false;
                description = PreTranslatedStrings::SafeDifficultyDescription.c_str();
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(152 / 255.0f, 152 / 255.0f, 10 / 255.0f, 1));
            if (ImGui::CheckboxCustom(PreTranslatedStrings::EuclidDifficulty.c_str(), &euclid, whiteImage, blackImage, 110)) {
                safe = false;
                keter = false;
                apollyon = false;
                description = PreTranslatedStrings::EuclidDifficultyDescription.c_str();
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(152 / 255.0f, 11 / 255.0f, 10 / 255.0f, 1));
            if (ImGui::CheckboxCustom(PreTranslatedStrings::KeterDifficulty.c_str(), &keter, whiteImage, blackImage, 110)) {
                safe = false;
                euclid = false;
                apollyon = false;
                description = PreTranslatedStrings::KeterDifficultyDescription.c_str();
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            ImGui::PopStyleColor();

            const bool apollyonDisabled = !Options::ReadBoolOption("SaveGame", "Apollyon");
            if (apollyonDisabled) {
                ImGui::BeginDisabled();
            }
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(80 / 255.0f, 79 / 255.0f, 79 / 255.0f, 1));
            if (ImGui::CheckboxCustom(PreTranslatedStrings::ApollyonDifficulty.c_str(), &apollyon, whiteImage, blackImage, 110, apollyonDisabled)) {
                safe = false;
                euclid = false;
                keter = false;
                description = PreTranslatedStrings::ApollyonDifficultyDescription.c_str();
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            ImGui::PopStyleColor();
            if (apollyonDisabled) {
                ImGui::EndDisabled();
            }

            ImGui::BeginChildCustom("DIFFICULTY-DESCRIPTION", 316, 549, 399, 103, whiteImage, blackImage, 1.0f);
            ImGui::PushFont(Localization::GetActiveLanguageCourierNewSmall());
            ImGui::TextWrapped("%s", description);
            ImGui::PopFont();
            ImGui::EndChildCustom();
            
            ImGui::EndChildCustom();

            if (ImGui::ButtonCustom(PreTranslatedStrings::LoadMap, ImVec2(138, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = LOAD_MAP;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::SameLine(460);

            if (ImGui::ButtonCustom(PreTranslatedStrings::Start, ImVec2(138, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        } else if (selectedMenu == LOAD_MAP) { // LOAD MAP
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(610, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::LoadMap, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = LOAD_MAP;
            }
            ImGui::SameLine();
            if (ImGui::ButtonCustom(PreTranslatedStrings::Back, ImVec2(150, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = NEW_GAME;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 1));

            ImGui::End();
            ImGui::PopStyleColor(2);
        } else if (selectedMenu == LOAD_GAME) { // LOAD GAME
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(610, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::LoadGame, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = LOAD_GAME;
            }
            ImGui::SameLine();
            if (ImGui::ButtonCustom(PreTranslatedStrings::Back, ImVec2(150, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = MAIN_MENU;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 1));

            ImGui::End();
            ImGui::PopStyleColor(2);
        } else if (selectedMenu == OPTIONS) { // OPTIONS
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(610, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::Options, ImVec2(430, 75), whiteImage, blackImage)) {
                selectedMenu = OPTIONS;
            }
            ImGui::SameLine();
            if (ImGui::ButtonCustom(PreTranslatedStrings::Back, ImVec2(150, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = MAIN_MENU;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::Dummy(ImVec2(1, 1));

            const ImVec2 currentPos = ImGui::GetWindowPos() + ImGui::GetCursorPos();
            ImGui::BeginChildCustom("MAIN-MENU-1-OPTIONS", currentPos.x, currentPos.y, 590, 315, whiteImage, blackImage);

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
