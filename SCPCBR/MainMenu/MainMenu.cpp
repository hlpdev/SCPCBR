#include "MainMenu.h"

#include <thread>

#include "../Util/Util.h"
#include "../AudioEngine/AudioEngine.h"
#include "../Localization/Localization.h"

#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>
#include <FMOD/fmod.hpp>

#include <archive_entry.h>

#include "../GameAssembly/GameAssembly.h"
#include "../GenerationSystem/GenerationSystem.h"
#include "../Options/Options.h"

#define MAIN_MENU 0
#define NEW_GAME 1
#define LOAD_MAP 2
#define LOAD_GAME 3
#define OPTIONS 4

#define GRAPHICS 0
#define AUDIO 1
#define CONTROLS 2
#define ADVANCED 3

class DiscordWrapper;

namespace MainMenu {
    GenerationSystem::GenerationInstructions* generationInstructions = nullptr;
    
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
        std::string Info;
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
        std::string Discord;
        std::string GitHub;
        std::string StorePage;
        std::string Mods;
        std::string Credits;
        std::string Close;
        std::string Disclaimer1;
        std::string Disclaimer2;
        std::string Disclaimer3;
        std::string DebugWarning;

        std::string Graphics;
        std::string Audio;
        std::string Controls;
        std::string ControlsWarning;
        std::string Advanced;

        std::string VSync;
        std::string FOV;
        std::string FrameLimit;
        std::string FrameLimitValue;
        std::string GameVolume;
        std::string MusicVolume;
        std::string EnableUserTracks;
        std::string MouseSensitivity;
        std::string InvertMouseXAxis;
        std::string InvertMouseYAxis;
        std::string MoveForward;
        std::string MoveLeft;
        std::string MoveRight;
        std::string MoveBackward;
        std::string QuickSave;
        std::string ManualBlink;
        std::string Sprint;
        std::string OpenCloseInventory;
        std::string Crouch;
        std::string TakeScreenshot;
        std::string ShowHud;
        std::string EnableConsole;
        std::string ShowFps;
        
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

        std::vector<std::string> RandomSeeds {
            "DIE",
            "DONTBLINK",
            "SNAP",
            "5CPI73",
            "LARRYSOME",
            "D9341",
            "JORGE",
            "SEBOTAN"
        };
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

    generationInstructions = new GenerationSystem::GenerationInstructions;
    generationInstructions->Name = "Untitled";
    generationInstructions->Difficulty = GenerationSystem::Difficulty::SAFE;
    
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
    PreTranslatedStrings::Info = Localization::GetTranslatedKey("MainMenu", "info");
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
    PreTranslatedStrings::Discord = Localization::GetTranslatedKey("MainMenu", "discordbutton");
    PreTranslatedStrings::GitHub = Localization::GetTranslatedKey("MainMenu", "githubbutton");
    PreTranslatedStrings::StorePage = Localization::GetTranslatedKey("MainMenu", "storepagebutton");
    PreTranslatedStrings::Mods = Localization::GetTranslatedKey("MainMenu", "modsbutton");
    PreTranslatedStrings::Credits = Localization::GetTranslatedKey("MainMenu", "creditsbutton");
    PreTranslatedStrings::Close = Localization::GetTranslatedKey("MainMenu", "closebutton");
    PreTranslatedStrings::Disclaimer1 = Localization::GetTranslatedKey("MainMenu", "disclaimerpart1");
    PreTranslatedStrings::Disclaimer2 = Localization::GetTranslatedKey("MainMenu", "disclaimerpart2");
    PreTranslatedStrings::Disclaimer3 = Localization::GetTranslatedKey("MainMenu", "disclaimerpart3");
    PreTranslatedStrings::DebugWarning = Localization::GetTranslatedKey("MainMenu", "debugwarning");
    
    PreTranslatedStrings::Graphics = Localization::GetTranslatedKey("MainMenu", "graphics");
    PreTranslatedStrings::Audio = Localization::GetTranslatedKey("MainMenu", "audio");
    PreTranslatedStrings::Controls = Localization::GetTranslatedKey("MainMenu", "controls");
    PreTranslatedStrings::ControlsWarning = Localization::GetTranslatedKey("MainMenu", "controlswarning");
    PreTranslatedStrings::Advanced = Localization::GetTranslatedKey("MainMenu", "advanced");

    PreTranslatedStrings::VSync = Localization::GetTranslatedKey("MainMenu", "vsync");
    PreTranslatedStrings::FOV = Localization::GetTranslatedKey("MainMenu", "fov");
    PreTranslatedStrings::FrameLimit = Localization::GetTranslatedKey("MainMenu", "framelimit");
    PreTranslatedStrings::FrameLimitValue = Localization::GetTranslatedKey("MainMenu", "framelimitvalue");
    PreTranslatedStrings::GameVolume = Localization::GetTranslatedKey("MainMenu", "gamevolume");
    PreTranslatedStrings::MusicVolume = Localization::GetTranslatedKey("MainMenu", "musicvolume");
    PreTranslatedStrings::EnableUserTracks = Localization::GetTranslatedKey("MainMenu", "usertracks");
    PreTranslatedStrings::MouseSensitivity = Localization::GetTranslatedKey("MainMenu", "mousesensitivity");
    PreTranslatedStrings::InvertMouseXAxis = Localization::GetTranslatedKey("MainMenu", "invertmouseaxis", {"X"});
    PreTranslatedStrings::InvertMouseYAxis = Localization::GetTranslatedKey("MainMenu", "invertmouseaxis", {"Y"});
    PreTranslatedStrings::MoveForward = Localization::GetTranslatedKey("MainMenu", "moveforward");
    PreTranslatedStrings::MoveLeft = Localization::GetTranslatedKey("MainMenu", "moveleft");
    PreTranslatedStrings::MoveRight = Localization::GetTranslatedKey("MainMenu", "moveright");
    PreTranslatedStrings::MoveBackward = Localization::GetTranslatedKey("MainMenu", "movebackward");
    PreTranslatedStrings::QuickSave = Localization::GetTranslatedKey("MainMenu", "quicksave");
    PreTranslatedStrings::ManualBlink = Localization::GetTranslatedKey("MainMenu", "manualblink");
    PreTranslatedStrings::Sprint = Localization::GetTranslatedKey("MainMenu", "sprint");
    PreTranslatedStrings::OpenCloseInventory = Localization::GetTranslatedKey("MainMenu", "opencloseinventory");
    PreTranslatedStrings::Crouch = Localization::GetTranslatedKey("MainMenu", "crouch");
    PreTranslatedStrings::TakeScreenshot = Localization::GetTranslatedKey("MainMenu", "takescreenshot");
    PreTranslatedStrings::ShowHud = Localization::GetTranslatedKey("MainMenu", "showhud");
    PreTranslatedStrings::EnableConsole = Localization::GetTranslatedKey("MainMenu", "enableconsole");
    PreTranslatedStrings::ShowFps = Localization::GetTranslatedKey("MainMenu", "showfps");

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

void MainMenu::Render(GLFWwindow* window, GlobalGameState* gameState, SteamWrapper* steam) {
    try {
        glfwGetFramebufferSize(window, &width, &height);

        if (!mainMenuStarted) {
            AudioEngine::PlaySoundByName("Assets/SFX/Music/Menu.ogg", AudioEngine::GetChannelGroup("Music"));
            mainMenuStarted = true;
        }

        std::string verString = "SCP: CONTAINMENT BREACH REMASTERED V2.0.0 ALPHA";
        ImGui::GetForegroundDrawList()->AddText(ImVec2(1, height - ImGui::CalcTextSize(verString.c_str()).y - 1), ImColor(255, 255, 255), verString.c_str());

        static bool InfoPopupOpen = false;
        if (InfoPopupOpen) {
            ImGui::BeginDisabled();
        }
        
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

        static int selectedMenu = 0;
        
        // MAIN
        if (selectedMenu == MAIN_MENU) {
            ImGui::SetNextWindowPos(ImVec2(144, 270));
            ImGui::SetNextWindowSize(ImVec2(435, 480));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## MAIN-MENU-0", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            if (ImGui::ButtonCustom(PreTranslatedStrings::NewGame, ImVec2(430, 75), whiteImage, blackImage)) {
                if (Util::Math::RandomInt(1, 10) == 1) {
                    generationInstructions->Seed = PreTranslatedStrings::RandomSeeds.at(Util::Math::RandomInt(0, PreTranslatedStrings::RandomSeeds.size() - 1));
                } else {
                    generationInstructions->Seed = Util::Strings::Random(8);
                }
                
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
            ImGui::Dummy(ImVec2(588, 315));
            if (ImGui::BeginChildCustom("MAIN-MENU-1-OPTIONS", currentPos.x, currentPos.y, 588, 315, whiteImage, blackImage)) {
                ImGui::InputTextCustom(PreTranslatedStrings::SaveName.c_str(), &generationInstructions->Name, whiteImage, blackImage);
                ImGui::InputTextCustom(PreTranslatedStrings::SaveSeed.c_str(), &generationInstructions->Seed, whiteImage, blackImage);

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
                    generationInstructions->Difficulty = GenerationSystem::Difficulty::SAFE;
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                }
                ImGui::PopStyleColor();

                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(152 / 255.0f, 152 / 255.0f, 10 / 255.0f, 1));
                if (ImGui::CheckboxCustom(PreTranslatedStrings::EuclidDifficulty.c_str(), &euclid, whiteImage, blackImage, 110)) {
                    safe = false;
                    keter = false;
                    apollyon = false;
                    description = PreTranslatedStrings::EuclidDifficultyDescription.c_str();
                    generationInstructions->Difficulty = GenerationSystem::Difficulty::EUCLID;
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                }
                ImGui::PopStyleColor();

                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(152 / 255.0f, 11 / 255.0f, 10 / 255.0f, 1));
                if (ImGui::CheckboxCustom(PreTranslatedStrings::KeterDifficulty.c_str(), &keter, whiteImage, blackImage, 110)) {
                    safe = false;
                    euclid = false;
                    apollyon = false;
                    description = PreTranslatedStrings::KeterDifficultyDescription.c_str();
                    generationInstructions->Difficulty = GenerationSystem::Difficulty::KETER;
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
                    generationInstructions->Difficulty = GenerationSystem::Difficulty::APOLLYON;
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                }
                ImGui::PopStyleColor();
                if (apollyonDisabled) {
                    ImGui::EndDisabled();
                }

                if (ImGui::BeginChildCustom("DIFFICULTY-DESCRIPTION", 316, 549, 399, 103, whiteImage, blackImage, 1.0f)) {
                    ImGui::PushFont(Localization::GetActiveLanguageCourierNewSmall());
                    ImGui::TextWrapped("%s", description);
                    ImGui::PopFont();
                    ImGui::EndChildCustom();
                }
                
                ImGui::EndChildCustom();
            }

            if (ImGui::ButtonCustom(PreTranslatedStrings::LoadMap, ImVec2(138, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                selectedMenu = LOAD_MAP;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::SameLine(458);

            if (ImGui::ButtonCustom(PreTranslatedStrings::Start, ImVec2(138, 75), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));

                // TODO
                // TESTING PURPOSES CURRENTLY
                *gameState = GlobalGameState::Game;
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

            static int selectedOptionsMenu = GRAPHICS;

            ImGui::Dummy(ImVec2(3, 0));
            
            ImGui::SameLine(11);
            
            if (ImGui::ButtonCustom(PreTranslatedStrings::Graphics, ImVec2(100, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall(), selectedOptionsMenu == GRAPHICS)) {
                selectedOptionsMenu = GRAPHICS;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::SameLine(165);

            if (ImGui::ButtonCustom(PreTranslatedStrings::Audio, ImVec2(100, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall(), selectedOptionsMenu == AUDIO)) {
                selectedOptionsMenu = AUDIO;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::SameLine(325);

            if (ImGui::ButtonCustom(PreTranslatedStrings::Controls, ImVec2(100, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall(), selectedOptionsMenu == CONTROLS)) {
                selectedOptionsMenu = CONTROLS;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            ImGui::SameLine(493);
            
            if (ImGui::ButtonCustom(PreTranslatedStrings::Advanced, ImVec2(100, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall(), selectedOptionsMenu == ADVANCED)) {
                selectedOptionsMenu = ADVANCED;
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            
            
            ImGui::Dummy(ImVec2(1, 3));

            const ImVec2 currentPos2 = ImGui::GetWindowPos() + ImGui::GetCursorPos();
            if (selectedOptionsMenu == GRAPHICS) {
                if (ImGui::BeginChildCustom("MAIN-MENU-OPTIONS-GRAPHICS", currentPos2.x, currentPos2.y, 588, 173, whiteImage, blackImage)) {
                    {
                        static bool value = Options::ReadBoolOption("Graphics", "VSync");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::VSync.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Graphics", "VSync", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 4));
                
                    {
                        static int value = Options::ReadIntOption("Graphics", "FOV");
                        ImGui::Text("%s", PreTranslatedStrings::FOV.c_str());
                        
                        ImGui::SameLine(300);
                        
                        ImGui::SetNextItemWidth(200);
                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
                        
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() - ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() + ImVec2(201, 27),
                            ImColor(255, 255, 255)
                            );

                        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.95f, 0.0f, 0.0f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.93f, 0.0f, 0.0f, 1.0f));
                        if (ImGui::SliderInt("##FOV-SLIDER", &value, 50, 90)) {
                            Options::WriteIntOption("Graphics", "FOV", value);
                        }
                        ImGui::PopStyleColor(5);
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Graphics", "Framelimit");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::FrameLimit.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Graphics", "Framelimit", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    if (Options::ReadBoolOption("Graphics", "Framelimit")) {
                        static int value = Options::ReadIntOption("Graphics", "FramelimitValue");
                        ImGui::Text("%s", PreTranslatedStrings::FrameLimitValue.c_str());
                        
                        ImGui::SameLine(300);
                        
                        ImGui::SetNextItemWidth(200);
                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
                        
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() - ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() + ImVec2(201, 27),
                            ImColor(255, 255, 255)
                            );

                        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.95f, 0.0f, 0.0f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.93f, 0.0f, 0.0f, 1.0f));
                        if (ImGui::SliderInt("##FRAME-LIMIT-SLIDER", &value,  20, 360)) {
                            Options::WriteIntOption("Graphics", "FramelimitValue", value);
                        }
                        ImGui::PopStyleColor(5);
                    }

                    ImGui::EndChildCustom();
                }
            } else if (selectedOptionsMenu == AUDIO) {
                if (ImGui::BeginChildCustom("MAIN-MENU-OPTIONS-AUDIO", currentPos2.x, currentPos2.y, 588, 140, whiteImage, blackImage)) {
                    {
                        static int value = Options::ReadIntOption("Audio", "GameVolume");
                        ImGui::Text("%s", PreTranslatedStrings::GameVolume.c_str());
                        
                        ImGui::SameLine(300);
                        
                        ImGui::SetNextItemWidth(200);
                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
                        
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() - ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() + ImVec2(201, 27),
                            ImColor(255, 255, 255)
                            );

                        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.95f, 0.0f, 0.0f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.93f, 0.0f, 0.0f, 1.0f));
                        if (ImGui::SliderInt("##GAME-VOLUME-SLIDER", &value, 0, 100, "%d%%")) {
                            Options::WriteIntOption("Audio", "GameVolume", value);
                            AudioEngine::SetChannelGroupVolume("Game", value / 100.0f);
                        }
                        ImGui::PopStyleColor(5);
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static int value = Options::ReadIntOption("Audio", "MusicVolume");
                        ImGui::Text("%s", PreTranslatedStrings::MusicVolume.c_str());
                        
                        ImGui::SameLine(300);
                        
                        ImGui::SetNextItemWidth(200);
                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
                        
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() - ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() + ImVec2(201, 27),
                            ImColor(255, 255, 255)
                            );

                        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.95f, 0.0f, 0.0f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.93f, 0.0f, 0.0f, 1.0f));
                        if (ImGui::SliderInt("##MUSIC-VOLUME-SLIDER", &value, 0, 100, "%d%%")) {
                            Options::WriteIntOption("Audio", "MusicVolume", value);
                            AudioEngine::SetChannelGroupVolume("Music", value / 100.0f);
                        }
                        ImGui::PopStyleColor(5);
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Audio", "EnableUserTracks");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::EnableUserTracks.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Audio", "EnableUserTracks", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::EndChildCustom();
                }
            } else if (selectedOptionsMenu == CONTROLS) {
                if (ImGui::BeginChildCustom("MAIN-MENU-OPTIONS-CONTROLS", currentPos2.x, currentPos2.y, 588, 480, whiteImage, blackImage)) {
                    {
                        static float value = static_cast<float>(Options::ReadIntOption("Controls", "MouseSensitivity")) / 10.0f;
                        ImGui::Text("%s", PreTranslatedStrings::MouseSensitivity.c_str());
                        
                        ImGui::SameLine(300);
                        
                        ImGui::SetNextItemWidth(200);
                        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
                        
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() - ImVec2(1, 1),
                            ImGui::GetWindowPos() + ImGui::GetCursorPos() + ImVec2(201, 27),
                            ImColor(255, 255, 255)
                            );

                        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.95f, 0.0f, 0.0f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.93f, 0.0f, 0.0f, 1.0f));
                        if (ImGui::SliderFloat("##MOUSE-SENSITIVITY-SLIDER", &value, 0.1f, 3.0f, "%.1f")) {
                            Options::WriteIntOption("Controls", "MouseSensitivity", static_cast<int>(value * 10));
                        }
                        ImGui::PopStyleColor(5);
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Controls", "InvertMouseXAxis");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::InvertMouseXAxis.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Controls", "InvertMouseXAxis", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Controls", "InvertMouseYAxis");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::InvertMouseYAxis.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Controls", "InvertMouseYAxis", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 1));

                    ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(1, 1, 1, 1));
                    ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(1, 1, 1, 1));
                    ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(1, 1, 1, 1));
                    ImGui::Separator();
                    
                    ImGui::TextWrappedCentered(PreTranslatedStrings::ControlsWarning.c_str());

                    ImGui::Separator();
                    ImGui::PopStyleColor(3);
                    
                    ImGui::Dummy(ImVec2(1, 2));
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "MoveForward");
                        if (ImGui::Hotkey(PreTranslatedStrings::MoveForward.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "MoveForward")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "MoveForward", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "MoveLeft");
                        if (ImGui::Hotkey(PreTranslatedStrings::MoveLeft.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "MoveLeft")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "MoveLeft", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "MoveBackward");
                        if (ImGui::Hotkey(PreTranslatedStrings::MoveBackward.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "MoveBackward")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "MoveBackward", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "MoveRight");
                        if (ImGui::Hotkey(PreTranslatedStrings::MoveRight.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "MoveRight")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "MoveRight", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "QuickSave");
                        if (ImGui::Hotkey(PreTranslatedStrings::QuickSave.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "QuickSave")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "QuickSave", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "ManualBlink");
                        if (ImGui::Hotkey(PreTranslatedStrings::ManualBlink.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "ManualBlink")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "ManualBlink", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "Sprint");
                        if (ImGui::Hotkey(PreTranslatedStrings::Sprint.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "Sprint")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "Sprint", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "OpenCloseInventory");
                        if (ImGui::Hotkey(PreTranslatedStrings::OpenCloseInventory.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "OpenCloseInventory")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "OpenCloseInventory", value);
                        }
                    }
                    
                    {
                        static int value = Options::ReadIntOption("Controls", "Crouch");
                        if (ImGui::Hotkey(PreTranslatedStrings::Crouch.c_str(), value, window, whiteImage, blackImage, Localization::GetActiveLanguageCourierNew())) {
                            if (value != Options::ReadIntOption("Controls", "Crouch")) {
                                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                            }
                            Options::WriteIntOption("Controls", "Crouch", value);
                        }
                    }

                    ImGui::EndChildCustom();
                }
            } else if (selectedOptionsMenu == ADVANCED) {
                if (ImGui::BeginChildCustom("MAIN-MENU-OPTIONS-ADVANCED", currentPos2.x, currentPos2.y, 588, 139, whiteImage, blackImage)) {
                    {
                        static bool value = Options::ReadBoolOption("Advanced", "ShowHud");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::ShowHud.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Advanced", "ShowHud", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Advanced", "EnableInGameConsole");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::EnableConsole.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Advanced", "EnableInGameConsole", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::Dummy(ImVec2(1, 4));

                    {
                        static bool value = Options::ReadBoolOption("Advanced", "ShowFps");
                        if (ImGui::CheckboxCustom(PreTranslatedStrings::ShowFps.c_str(), &value, whiteImage, blackImage)) {
                            Options::WriteBoolOption("Advanced", "ShowFps", value);
                            AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                        }
                    }

                    ImGui::EndChildCustom();
                }
            }

            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        if (InfoPopupOpen) {
            ImGui::EndDisabled();
        }

        // RENDER INFO POPUP
        {
            if (InfoPopupOpen) {
                ImGui::BeginDisabled();
            }

            bool InfoPopupOpenRn = InfoPopupOpen;
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowPos(ImVec2(width - 95, 5));
            ImGui::Begin("## INFO-BUTTON", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(0, 0));
            if (ImGui::ButtonCustom(PreTranslatedStrings::Info, ImVec2(90, 40), whiteImage, blackImage, Localization::GetActiveLanguageCourierNewSmall())) {
                AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                InfoPopupOpen = true;
            }
            ImGui::End();
            ImGui::PopStyleColor(2);
            
            if (InfoPopupOpenRn) {
                ImGui::EndDisabled();
            }

            if (InfoPopupOpen) {
                ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0.7f));
                ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
                ImGui::SetNextWindowSize(ImVec2(width, height));
                ImGui::SetNextWindowPos(ImVec2(0, 0));
                ImGui::Begin("## INFO-WINDOW-BACKGROUND", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
                ImGui::End();
                ImGui::PopStyleColor(2);

                ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0.7f));
                ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
                ImGui::SetNextWindowSize(ImVec2(441, 611));
                ImGui::SetNextWindowPos(ImVec2((width / 2) - (435 / 2), (height / 2) - (605 / 2)));
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(19, 15));
                ImGui::Begin("## INFO-WINDOW-CONTAINER", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

                ImGui::DrawFrameCustom((width / 2) - (429.0f / 2) + 6, (height / 2) - (603.0f / 2), 423, 603, whiteImage, blackImage, false, true);

                ImGui::TextWrappedCentered(GameTitle);
                ImGui::TextWrappedCentered(GameVersion);

                #if _DEBUG
                ImGui::TextWrappedCentered(PreTranslatedStrings::DebugWarning.c_str());
                #endif

                ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleVar(ImGuiStyleVar_SeparatorTextBorderSize, 3.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_SeparatorTextPadding, ImVec2(0, 3));
                ImGui::Separator();
                ImGui::PopStyleVar(2);
                ImGui::PopStyleColor(3);
                
                ImGui::TextWrapped("%s", PreTranslatedStrings::Disclaimer1.c_str());
                ImGui::TextWrapped("%s", PreTranslatedStrings::Disclaimer2.c_str());
                ImGui::TextWrapped("%s", PreTranslatedStrings::Disclaimer3.c_str());

                ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
                ImGui::PushStyleVar(ImGuiStyleVar_SeparatorTextBorderSize, 3.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_SeparatorTextPadding, ImVec2(0, 3));
                ImGui::Separator();
                ImGui::PopStyleVar(2);
                ImGui::PopStyleColor(3);
                
                if (ImGui::ButtonCustom(PreTranslatedStrings::Discord, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                    discord->OpenGuildInvite("Q7VKS6hwEV");
                }

                if (ImGui::ButtonCustom(PreTranslatedStrings::GitHub, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                    steam->OpenLinkInOverlay("https://github.com/hlpdev/SCPCBR");
                }

                if (ImGui::ButtonCustom(PreTranslatedStrings::StorePage, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                    steam->OpenLinkInOverlay("https://store.steampowered.com/app/2090230/SCP_Containment_Breach_Remastered/");
                }

                if (ImGui::ButtonCustom(PreTranslatedStrings::Mods, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                    steam->OpenLinkInOverlay("https://steamcommunity.com/app/2090230/workshop/");
                }

                if (ImGui::ButtonCustom(PreTranslatedStrings::Credits, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                }

                if (ImGui::ButtonCustom(PreTranslatedStrings::Close, ImVec2(401, 30), whiteImage, blackImage, Localization::GetActiveLanguageCourierNew(), false, true)) {
                    AudioEngine::PlaySoundByName("Assets/SFX/Splash/Button.ogg", AudioEngine::GetChannelGroup("Game"));
                    InfoPopupOpen = false;
                }

                ImGui::End();
                ImGui::PopStyleVar();
                ImGui::PopStyleColor(2);
            }
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
