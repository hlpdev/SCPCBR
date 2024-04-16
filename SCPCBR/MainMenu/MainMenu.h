#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Types/Types.h"

#include <GLFW/glfw3.h>

#include "../DiscordWrapper/DiscordWrapper.h"
#include "../SteamWrapper/SteamWrapper.h"

namespace MainMenu {
    void Init(DiscordWrapper* discordWrapper);
    void Render(GLFWwindow* window, GlobalGameState* gameState, SteamWrapper* steam);
    void Free();
}

#endif // MAINMENU_H
