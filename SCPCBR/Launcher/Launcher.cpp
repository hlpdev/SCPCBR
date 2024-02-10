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

    ImGui::PushFont(smallFont);
    ImGui::TextWrapped("This is a faithful recreation of SCP: Containment Breach Remastered created in C++ using GLFW, OpenGL, ImGui, and more.");
    ImGui::TextWrapped("Created by Hunter & the HNT8 Organization, the original developers of SCP: Containment Breach Remastered.");
    ImGui::TextWrapped("This project is open source. You can find the source code on our github page.");
    ImGui::PopFont();

    ImGui::Separator();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));

    if (ImGui::Button("Discord", ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::Button("Mods", ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    
    if (ImGui::Button("Store Page", ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::Button("GitHub", ImVec2(ImGui::GetWindowSize().x * 0.5f - 10, 0.0f))) {
        
    }

    ImGui::PopStyleColor(3);
    
    ImGui::End();

    ImGui::SetNextWindowSize(ImVec2(width / 2.0 * 0.9 + (width / 2.0 - width / 2.0 * 0.9) / 4.0, 245));
    ImGui::SetNextWindowPos(ImVec2(width / 2.0 + (width / 2.0 - width / 2.0 * 0.9) / 2.0 - (width / 2.0 - width / 2.0 * 0.9) / 4.0, 150));
    ImGui::Begin("### LAUNCHER-OPTIONS-WINDOW", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

    ImGui::TextCentered("Launch Options");

    ImGui::Separator();
    
    ImGui::Text("Display Mode:");

    const char* displayModes[] = { "Windowed", "Fullscreen", "Exclusive Fullscreen" };
    static const char* currentItem = displayModes[Options::ReadIntOption("Graphics", "DisplayMode")];
    static int currentIndex = Options::ReadIntOption("Graphics", "DisplayMode");

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushItemWidth(ImGui::CalcItemWidth() - ImGui::GetStyle().ItemInnerSpacing.x * 2.0f - ImGui::GetFrameHeight() * 2.0f + 87);
    if (ImGui::BeginCombo("## DISPLAY-MODE-COMBO", currentItem, ImGuiComboFlags_NoArrowButton)) {
        for (int i = 0; i < IM_ARRAYSIZE(displayModes); i++) {
            bool is_selected = (currentItem == displayModes[i]);
            if (ImGui::Selectable(displayModes[i], is_selected)) {
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
    ImGui::PopStyleColor(6);
    
    ImGui::Separator();

    ImGui::Text("Language:");

    const char* languages[] = { "English" };
    static const char* currentLang = languages[Options::ReadIntOption("Misc", "Language")];
    static int currentLangIndex = Options::ReadIntOption("Misc", "Language");

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    ImGui::PushItemWidth(ImGui::CalcItemWidth() - ImGui::GetStyle().ItemInnerSpacing.x * 2.0f - ImGui::GetFrameHeight() * 2.0f + 87);
    if (ImGui::BeginCombo("## LANGUAGE-COMBO", currentLang, ImGuiComboFlags_NoArrowButton)) {
        for (int i = 0; i < IM_ARRAYSIZE(languages); i++) {
            bool is_selected = (currentLang == languages[i]);
            if (ImGui::Selectable(languages[i], is_selected)) {
                currentLang = languages[i];
                currentLangIndex = i;
                Options::WriteIntOption("Misc", "Language", i);
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
            currentLang = languages[currentLangIndex];
            Options::WriteIntOption("Misc", "Language", currentLangIndex);
        } else {
            currentLangIndex = IM_ARRAYSIZE(languages) - 1;
            currentLang = languages[currentLangIndex];
            Options::WriteIntOption("Misc", "Language", currentLangIndex);
        }
    }
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (ImGui::ArrowButton("## LANGUAGE-COMBO-RIGHT", ImGuiDir_Right)) {
        if (currentLangIndex != IM_ARRAYSIZE(languages) - 1) {
            currentLangIndex++;
            currentLang = languages[currentLangIndex];
            Options::WriteIntOption("Misc", "Language", currentLangIndex);
        } else {
            currentLangIndex = 0;
            currentLang = languages[currentLangIndex];
            Options::WriteIntOption("Misc", "Language", currentLangIndex);
        }
    }
    ImGui::PopStyleColor(6);

    ImGui::Separator();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.05f, 0.05f, 0.05f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.09f, 0.09f, 0.09f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.12f, 0.12f, 1.0f));
    if (ImGui::Button("LAUNCH", ImVec2(width / 2.0 * 0.9 + (width / 2.0 - width / 2.0 * 0.9) / 4.0 - 16, 82))) {
        
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
