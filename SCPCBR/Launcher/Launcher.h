#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "GLFW/glfw3.h"

namespace Launcher {
    void Init();
    void Render(GLFWwindow* window);
    void Free();
}
#endif // LAUNCHER_H
