#ifndef IMGUICUSTOM_H
#define IMGUICUSTOM_H
#include <string>

#include "imgui.h"
#include "imgui_internal.h"

#include "../Util/Util.h"

namespace ImGui {
    template<typename ... Args>
    void TextCentered(const char* text, Args ... args) {
        const float windowWidth = GetWindowSize().x;
        const float textWidth = CalcTextSize(text).x;

        SetCursorPosX((windowWidth - textWidth) * 0.5f);
        Text(text, args ...);
    }

    inline void TextWrappedCentered(const char* text) {
        ImGuiWindow* window = GetCurrentWindow();
        float width = window->Size.x;
        
        std::vector<std::string> words = Util::Strings::Split(text, " ");

        std::vector<std::string> lines;

        int currentWord = 0;
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

        for (std::string line : lines) {
            TextCentered(line.c_str());
        }
    }
}

#endif // IMGUICUSTOM_H
