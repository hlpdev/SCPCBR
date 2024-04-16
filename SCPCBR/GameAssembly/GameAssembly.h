#ifndef GAMEASSEMBLY_H
#define GAMEASSEMBLY_H

#define GameTitle "SCP: Containment Breach Remastered"
#define GameVersion "v2.0.0"

#define GameWindowIcon "Assets\\GFX\\Window\\Remastered.png"

#ifndef _DEBUG
#define GameWindowTitle GameTitle " " GameVersion
#else
#define GameWindowTitle GameTitle " " GameVersion " Development Build"
#endif

#include <string>
#include <GLFW/glfw3.h>

namespace Window {
    void SetWindowIcon(GLFWwindow* window, std::string iconPath);
    void SetWindowDisplayMode(GLFWwindow* window, int displayMode);
}

#endif // GAMEASSEMBLY_H
