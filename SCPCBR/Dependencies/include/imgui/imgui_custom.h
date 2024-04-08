#ifndef IMGUICUSTOM_H
#define IMGUICUSTOM_H
#include <string>

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_stdlib.h"

#include "../../../Localization/Localization.h"
#include "../../../Util/Util.h"

namespace ImGui {
    /**
     * \brief Renders the default Dear ImGui text, but centers it relative to the width of the current window
     */
    inline void TextCentered(const char* text) {
        const float windowWidth = GetWindowSize().x;
        const float textWidth = CalcTextSize(text).x;

        SetCursorPosX((windowWidth - textWidth) * 0.5f);
        Text("%s", text);
    }

    /**
     * \brief Renders the default Dear ImGui Wrapped text but centers each individual line relative to the width of the current window
     * \param text The text to wrap and center
     */
    inline void TextWrappedCentered(const char* text) {
        const ImGuiWindow* window = GetCurrentWindow();
        float width = window->Size.x;

        const std::vector<std::string> words = Util::Strings::Split(text, " ");

        std::vector<std::string> lines;

        size_t currentWord = 0;
        std::string line;
        while (currentWord < words.size()) {
            if (CalcTextSize((line + words.at(currentWord) + " ").c_str()).x >= (width - 50)) {
                lines.push_back(line);
                line = "";
            }
            
            line += words.at(currentWord) + " ";
            
            currentWord++;
        }
        lines.push_back(line);

        for (const std::string& lineRef : lines) {
            TextCentered(lineRef.c_str());
        }
    }

    /**
     * \brief Draw a custom frame at the given coordinates with a given size that resembles the original SCP:CB UI
     * \param x The X position of the top left corner of the frame
     * \param y The Y position of the top left corner of the frame
     * \param width The width of the frame
     * \param height The height of the frame
     * \param whiteImage A pointer to the image displayed on the border of the frame, should be the white UI texture found in the original SCP:CB
     * \param blackImage A pointer to the image displayed in the main content of the frame, should be the black UI texture found in the original SCP:CB
     * \param dim Whether to slightly dim the frame, giving it a disabled look
     */
    inline void DrawFrameCustom(float x, float y, float width, float height, Util::Image::Image* whiteImage, Util::Image::Image* blackImage, bool dim = false) {
        const float whiteUvMaxX = width / static_cast<float>(whiteImage->Width);
        const float whiteUvMaxY = height / static_cast<float>(whiteImage->Width);
        const float blackUvMaxX = (width - 6) / static_cast<float>(blackImage->Width);
        const float blackUvMaxY = (height - 6) / static_cast<float>(blackImage->Height);

        const ImVec2 whiteUvMax = ImVec2(whiteUvMaxX, whiteUvMaxY);
        const ImVec2 blackUvMax = ImVec2(blackUvMaxX, blackUvMaxY);

        const ImColor whiteColor = !dim ? ImColor(255, 255, 255) : ImColor(150, 150, 150);
        const ImColor blackColor = !dim ? ImColor(255, 255, 255) : ImColor(150, 150, 150);
        
        GetBackgroundDrawList()->AddImage(whiteImage->TextureIdPtr, ImVec2(x, y), ImVec2(x + width, y + height), ImVec2(0, 0), whiteUvMax, whiteColor);
        GetBackgroundDrawList()->AddImage(blackImage->TextureIdPtr, ImVec2(x + 3, y + 3), ImVec2(x + width - 3, y + height - 3), ImVec2(0, 0), blackUvMax, blackColor);
    }

    /**
     * \brief Draws a custom frame using DrawFrameCustom, but creates a window inside of it with proper spacing.
     * \param id The ID of the window to be created
     * \param x The X position of the top left corner of the frame
     * \param y The Y position of the top left corner of the frame
     * \param width The width of the frame / window
     * \param height The height of the frame / window
     * \param whiteImage A pointer to the image displayed on the border of the frame, should be the white UI texture found in the original SCP:CB
     * \param blackImage A pointer to the image displayed in the main content of the frame, should be the black UI texture found in the original SCP:CB
     * \param padding A boolean to decide whether padding should be enabled or disabled on the inner window created.
     */
    inline bool BeginChildCustom(const char* id, float x, float y, float width, float height, Util::Image::Image* whiteImage, Util::Image::Image* blackImage, float padding = 14.0f) {
        DrawFrameCustom(x, y, width, height, whiteImage, blackImage);
        SetNextWindowPos(ImVec2(x + padding, y + padding));
        SetNextWindowSize(ImVec2(width - padding, height - padding));
        return Begin(id, nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
    }

    /**
     * \brief Marks the end of the custom child window
     */
    inline void EndChildCustom() {
        End();
    }

    /**
     * \brief Creates the usual InputText UI element, but in the style of the original SCP:CB
     * \param label The text that appears to the left of the input box
     * \param str A pointer to the string that will be modified inside of the input box
     * \param whiteImage A pointer to the image displayed on the border of the frame, should be the white UI texture found in the original SCP:CB
     * \param blackImage A pointer to the image displayed in the main content of the frame, should be the black UI texture found in the original SCP:CB
     */
    inline void InputTextCustom(const char* label, std::string* str, Util::Image::Image* whiteImage, Util::Image::Image* blackImage) {
        Text("%s", label);
        SameLine(160, 0);

        const ImVec2 pos = GetWindowPos() + GetCursorPos();

        DrawFrameCustom(pos.x, pos.y - 6, 250, 35, whiteImage, blackImage);
        
        PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0));
        PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0));
        PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(1, 1, 1, 0.3f));
        PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(0.649f, 0.043f, 0, 0.6f));
        SetCursorPosX(GetCursorPosX() + 3);
        SetCursorPosY(GetCursorPosY() - 2);
        PushItemWidth(244);
        InputText(std::string("##" + std::string(label) + "input").c_str(), str);
        PopItemWidth();
        PopStyleColor(4);

        Dummy(ImVec2(1, 8));
    }

    /**
     * \brief Creates the usual Checkbox UI element, but in the style of the original SCP:CB
     * \param label The text that appears to the left of the checkbox
     * \param value A pointer to the bool value that will be modified inside of the checkbox
     * \param whiteImage A pointer to the image displayed on the border of the frame, should be the white UI texture found in the original SCP:CB
     * \param blackImage A pointer to the image displayed in the main content of the frame, should be the black UI texture found in the original SCP:CB
     * \param sameLineDistance The distance the checkbox will appear from the beginning X coordinate
     * \param disabled Whether the checkbox should be rendered as disabled
     * \return Returns true if the checkbox was clicked
     */
    inline bool CheckboxCustom(const char* label, bool* value, Util::Image::Image* whiteImage, Util::Image::Image* blackImage, float sameLineDistance = 300.0f, bool disabled = false) {
        Text("%s", label);
        SameLine(sameLineDistance, 0);

        const ImVec2 pos = GetWindowPos() + GetCursorPos();
        
        DrawFrameCustom(pos.x, pos.y - 3, 25, 25, whiteImage, blackImage, disabled);

        PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
        PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0.25f));
        PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0.5f));
        SetCursorPosY(GetCursorPosY() - 3);
        const bool clicked = Button(std::string("##" + std::string(label) + "checkbox").c_str(), ImVec2(25, 25));
        PopStyleColor(3);

        if (clicked) {
            *value = !*value;
        }

        if (*value) {
            const float whiteUvMaxX = 15 / static_cast<float>(whiteImage->Width);
            const float whiteUvMaxY = 15 / static_cast<float>(whiteImage->Width);
            ImVec2 whiteUvMax = ImVec2(whiteUvMaxX, whiteUvMaxY);
            GetBackgroundDrawList()->AddImage(whiteImage->TextureIdPtr, ImVec2(pos.x + 5, pos.y + 2), ImVec2(pos.x + 20, pos.y + 17), ImVec2(0, 0), whiteUvMax);
        }

        return clicked;
    }

    /**
     * \brief The usual Button UI element but in the style of the original SCP:CB
     * \param label The text that appears on the button
     * \param size The size of the button
     * \param whiteImage A pointer to the image displayed on the border of the frame, should be the white UI texture found in the original SCP:CB
     * \param blackImage A pointer to the image displayed in the main content of the frame, should be the black UI texture found in the original SCP:CB
     * \param font The font that the label will be rendered in
     * \param selected Whether to render a green square around the button indicating that it is selected
     * \return Returns true if the button was clicked
     */
    inline bool ButtonCustom(const std::string& label, ImVec2 size, Util::Image::Image* whiteImage, Util::Image::Image* blackImage, ImFont* font = nullptr) {
        const ImVec2 pos = GetWindowPos() + GetCursorPos();

        if (selected) {
            GetBackgroundDrawList()->AddRectFilled(ImVec2(pos.x - 3, pos.y - 3), ImVec2(pos.x + size.x + 3, pos.y + size.y + 3), ImColor(0, 255, 0));
        }
        
        DrawFrameCustom(pos.x, pos.y, size.x, size.y, whiteImage, blackImage);

        PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
        PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0.25f));
        PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0.5f));
        if (font == nullptr) {
            PushFont(Localization::GetActiveLanguageCourierNewExtraLarge());
        } else {
            PushFont(font);
        }
        
        const bool result = Button(label.c_str(), size);
        PopFont();
        PopStyleColor(3);
        
        return result;
    }
}

#endif // IMGUICUSTOM_H
