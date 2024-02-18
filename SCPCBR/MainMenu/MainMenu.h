#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Types/Types.h"

#include <GLFW/glfw3.h>

namespace MainMenu {
    void Init();
    void Render(GLFWwindow* window, GlobalGameState* gameState);
    void Free();
}

#endif // MAINMENU_H
