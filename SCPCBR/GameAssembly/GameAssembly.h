#ifndef GAMEASSEMBLY_H
#define GAMEASSEMBLY_H

#define GameTitle "SCP: Containment Breach Remastered"
#define GameVersion "v2.0.0"
#define GameWindowTitle GameTitle " " GameVersion
#define GameWindowIcon "Assets\\GFX\\Window\\Remastered.png"

#include <string>
#include <GLFW/glfw3.h>

namespace Window {
    void SetWindowIcon(GLFWwindow* window, std::string iconPath);
}

#endif // GAMEASSEMBLY_H
