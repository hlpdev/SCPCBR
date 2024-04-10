#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <GLFW/glfw3.h>
#include "../DiscordWrapper/DiscordWrapper.h"
#include "../Types/Types.h"

namespace GameManager {
    void Init(DiscordWrapper* discordWrapper);
    void Render(GLFWwindow* window, GlobalGameState* globalGameState);
    void Free();
}

#endif // GAMEMANAGER_H
