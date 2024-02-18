#ifndef PRELOADMANAGER_H
#define PRELOADMANAGER_H
#include <GLFW/glfw3.h>

#include "../Types/Types.h"

namespace PreloadManager {
    float ProcessPreload();
    
    void Init();
    void Render(GLFWwindow* window, GlobalGameState* gameState);
    void Free();
}
#endif // PRELOADMANAGER_H
