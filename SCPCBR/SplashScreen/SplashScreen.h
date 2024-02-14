#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <GLFW/glfw3.h>

#include "../Types/Types.h"

namespace SplashScreen {
    void Init(GLFWwindow* window);
    void Render(GLFWwindow* window, GlobalGameState* gameState);
    void Free();
}

#endif // SPLASHSCREEN_H
