#include "GameManager.h"

namespace GameManager {
    DiscordWrapper* discord;
}

void GameManager::Init(DiscordWrapper* discordWrapper) {
    discord = discordWrapper;

    
}

void GameManager::Render(GLFWwindow* window, GlobalGameState* globalGameState) {
    
}

void GameManager::Free() {
    
}
