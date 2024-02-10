#include "Launcher.h"

#include <Windows.h>

#include "Options.h"
#include "../Localization/Localization.h"
#include "../Util/Util.h"
#include "GLFW/glfw3.h"
#include "imgui/imgui.h"
#include "imgui/imguicustom.h"

Util::Image::Image* backgroundImage;

Util::Image::Image* titleImage;

void Launcher::Init() {
    bool res;

    backgroundImage = (Util::Image::Image*)malloc(sizeof(Util::Image::Image));
    res = LoadImageFromFile("Assets\\GFX\\Window\\LauncherBackground.png", backgroundImage);
    if (!res) {
        Util::Error::Exit("The texture \"Assets\\GFX\\Window\\LauncherBackground.png\" failed to load. Ensure the file exists, or verify your game files.");
    }

    titleImage = (Util::Image::Image*)malloc(sizeof(Util::Image::Image));
    res = LoadImageFromFile("Assets\\GFX\\Window\\LauncherTitle.png", titleImage);
    if (!res) {
        Util::Error::Exit("The texture \"Assets\\GFX\\Window\\LauncherTitle.png\" failed to load. Ensure the file exists, or verify your game files.");
    }
}

void Launcher::Render(GLFWwindow* window) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    ImGui::PushFont(Localization::GetActiveLanguageCourierNew());
    
    // RENDER BACKGROUND
    {
        ImVec2 pos1;
        ImVec2 pos2;

        if (height * ((double)backgroundImage->Width / backgroundImage->Height) >= width) {
            pos1 = ImVec2(0 - (height * ((double)backgroundImage->Width / backgroundImage->Height) - width) / 2, 0);
            pos2 = ImVec2(width + (height * ((double)backgroundImage->Width / backgroundImage->Height) - width) / 2, height);
        } else {
            pos1 = ImVec2(0, 0 - (width / ((double)backgroundImage->Width / backgroundImage->Height) - height) / 2);
            pos2 = ImVec2(width, height + (width / ((double)backgroundImage->Width / backgroundImage->Height) - height) / 2);
        }

        ImGui::GetBackgroundDrawList()->AddImage((void*)(intptr_t)backgroundImage->TextureId, pos1, pos2);

#ifdef _DEBUG
        ImGui::GetBackgroundDrawList()->AddText(ImVec2(1, 1), ImColor(255, 255, 255), std::string(std::to_string((int)ImGui::GetIO().Framerate) + " FPS").c_str());
#endif
        
    }

    // RENDER TITLE
    {
        ImGui::SetNextWindowSize(ImVec2(width, height));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::Begin("### LAUNCHER-TITLE-IMAGE", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        ImGui::SetCursorPos(ImVec2(-15, -10));
        ImGui::Image((void*)titleImage->TextureId, ImVec2(titleImage->Width, titleImage->Height));
        
        ImGui::End();
        ImGui::PopStyleColor(2);
    }

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.05f, 0.05f, 0.05f, 0.3f));
    ImGui::SetNextWindowSize(ImVec2(width / 2.0 * 0.9 + (width / 2.0 - width / 2.0 * 0.9) / 4.0, 245));
    ImGui::SetNextWindowPos(ImVec2((width / 2.0 - width / 2.0 * 0.9) / 2.0, 150));
    ImGui::Begin("### LAUNCHER-RESOLUTION-WINDOW", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

    ImGui::PushFont(Localization::GetActiveLanguageCourierNewSmall());
    ImGui::TextWrapped(Localization::GetTranslatedKey("Launcher", "DisclaimerPart1").c_str());
    ImGui::TextWrapped(Localization::GetTranslatedKey("Launcher", "DisclaimerPart2").c_str());
    ImGui::TextWrapped(Localization::GetTranslatedKey("Launcher", "DisclaimerPart3").c_str());
    ImGui::PopFont();

    ImGui::Separator();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));

    if (ImGui::Button(Localization::GetTranslatedKey("Launcher", "DiscordButton").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::Button(Localization::GetTranslatedKey("Launcher", "ModsButton").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    
    if (ImGui::Button(Localization::GetTranslatedKey("Launcher", "StorePageButton").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::Button(Localization::GetTranslatedKey("Launcher", "GitHubButton").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }

    ImGui::PopStyleColor(3);
    
    ImGui::End();

    ImGui::SetNextWindowSize(ImVec2(width / 2.0 * 0.9 + (width / 2.0 - width / 2.0 * 0.9) / 4.0, 245));
    ImGui::SetNextWindowPos(ImVec2(width / 2.0 + (width / 2.0 - width / 2.0 * 0.9) / 2.0 - (width / 2.0 - width / 2.0 * 0.9) / 4.0, 150));
    ImGui::Begin("### LAUNCHER-OPTIONS-WINDOW", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

    ImGui::TextCentered(Localization::GetTranslatedKey("Launcher", "OptionsHeader").c_str());

    ImGui::Separator();
    
    ImGui::Text(Localization::GetTranslatedKey("Launcher", "DisplayModeHeader").c_str());

    std::string displayModes[] = {
        Localization::GetTranslatedKey("Launcher", "DisplayMode1"),
        Localization::GetTranslatedKey("Launcher", "DisplayMode2"),
        Localization::GetTranslatedKey("Launcher", "DisplayMode3")
    };
    std::string currentItem = displayModes[Options::ReadIntOption("Graphics", "DisplayMode")];
    static int currentIndex = Options::ReadIntOption("Graphics", "DisplayMode");

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushItemWidth(ImGui::CalcItemWidth() - ImGui::GetStyle().ItemInnerSpacing.x * 2.0f - ImGui::GetFrameHeight() * 2.0f + 87);
    if (ImGui::BeginCombo("## DISPLAY-MODE-COMBO", currentItem.c_str(), ImGuiComboFlags_NoArrowButton)) {
        for (int i = 0; i < IM_ARRAYSIZE(displayModes); i++) {
            bool is_selected = (currentItem == displayModes[i]);
            if (ImGui::Selectable(displayModes[i].c_str(), is_selected)) {
                currentItem = displayModes[i];
                currentIndex = i;
                Options::WriteIntOption("Graphics", "DisplayMode", i);
            }
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::ArrowButton("## DISPLAY-MODE-COMBO-LEFT", ImGuiDir_Left)) {
        if (currentIndex != 0) {
            currentIndex--;
            currentItem = displayModes[currentIndex];
            Options::WriteIntOption("Graphics", "DisplayMode", currentIndex);
        } else {
            currentIndex = IM_ARRAYSIZE(displayModes) - 1;
            currentItem = displayModes[currentIndex];
            Options::WriteIntOption("Graphics", "DisplayMode", currentIndex);
        }
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::ArrowButton("## DISPLAY-MODE-COMBO-RIGHT", ImGuiDir_Right)) {
        if (currentIndex != IM_ARRAYSIZE(displayModes) - 1) {
            currentIndex++;
            currentItem = displayModes[currentIndex];
            Options::WriteIntOption("Graphics", "DisplayMode", currentIndex);
        } else {
            currentIndex = 0;
            currentItem = displayModes[currentIndex];
            Options::WriteIntOption("Graphics", "DisplayMode", currentIndex);
        }
    }
    ImGui::PopStyleColor(9);
    
    ImGui::Separator();

    ImGui::Text(Localization::GetTranslatedKey("Launcher", "LanguageHeader").c_str());

    std::vector<const char*> languages = Localization::GetAllLanguageNames();
    static const char* currentLang = Localization::GetActiveLanguage()->Name.c_str();
    static size_t currentLangIndex = Localization::GetActiveLanguageIndex();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushItemWidth(ImGui::CalcItemWidth() - ImGui::GetStyle().ItemInnerSpacing.x * 2.0f - ImGui::GetFrameHeight() * 2.0f + 87);
    if (ImGui::BeginCombo("## LANGUAGE-COMBO", currentLang, ImGuiComboFlags_NoArrowButton)) {
        for (size_t i = 0; i < Localization::GetLanguageAmount(); i++) {
            bool is_selected = currentLang == languages.at(i);
            if (ImGui::Selectable(languages.at(i), is_selected)) {
                currentLang = languages.at(i);
                currentLangIndex = i;
                Localization::SetActiveLanguage(currentLang);
            }
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::ArrowButton("## LANGUAGE-COMBO-LEFT", ImGuiDir_Left)) {
        if (currentLangIndex != 0) {
            currentLangIndex--;
            currentLang = languages.at(currentLangIndex);
            Localization::SetActiveLanguage(currentLang);
        } else {
            currentLangIndex = Localization::GetLanguageAmount() - 1;
            currentLang = languages.at(currentLangIndex);
            Localization::SetActiveLanguage(currentLang);
        }
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::ArrowButton("## LANGUAGE-COMBO-RIGHT", ImGuiDir_Right)) {
        if (currentLangIndex != Localization::GetLanguageAmount() - 1) {
            currentLangIndex++;
            currentLang = languages.at(currentLangIndex);
            Localization::SetActiveLanguage(currentLang);
        } else {
            currentLangIndex = 0;
            currentLang = languages.at(currentLangIndex);
            Localization::SetActiveLanguage(currentLang);
        }
    }
    ImGui::PopStyleColor(9);

    ImGui::Separator();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    if (ImGui::Button(Localization::GetTranslatedKey("Launcher", "LaunchButton").c_str(), ImVec2(width / 2.0 * 0.9 + (width / 2.0 - width / 2.0 * 0.9) / 4.0 - 16, 82))) {
        
    }
    ImGui::PopStyleColor(3);
    
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);

    ImGui::PopFont();
}

void Launcher::Free() {
    free(backgroundImage);
    free(titleImage);
}
