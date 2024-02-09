#ifndef IMGUICUSTOM_H
#define IMGUICUSTOM_H
#include <string>

#include "imgui.h"

namespace ImGui {
    template<typename ... Args>
    void TextCentered(const char* text, Args ... args) {
        const float windowWidth = GetWindowSize().x;
        const float textWidth = CalcTextSize(text).x;

        SetCursorPosX((windowWidth - textWidth) * 0.5f);
        Text(text, args ...);
    }
}

#endif // IMGUICUSTOM_H
