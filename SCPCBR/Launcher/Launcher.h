#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <GLFW/glfw3.h>

#include "../Types/Types.h"
#include "../DiscordWrapper/DiscordWrapper.h"

namespace Launcher {
    void Init(DiscordWrapper* discordWrapper);
    void Render(GLFWwindow* window, GlobalGameState* globalGameState);
    void Free();
}
#endif // LAUNCHER_H
