#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <GLFW/glfw3.h>

#include "../Types/Types.h"
#include "../SteamWrapper/SteamWrapper.h"

namespace SplashScreen {
    void Init();
    void Render(GLFWwindow* window, GlobalGameState* gameState, SteamWrapper* steam);
    void Free();
}

#endif // SPLASHSCREEN_H
