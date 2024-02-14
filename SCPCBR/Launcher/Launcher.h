#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "GLFW/glfw3.h"
#include "../Types/Types.h"

namespace Launcher {
    void Init();
    void Render(GLFWwindow* window, GlobalGameState* globalGameState);
    void Free();
}
#endif // LAUNCHER_H
