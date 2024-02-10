#include "SteamWrapper.h"

#include "../Util/Util.h"

#include <steam/steam_api.h>

SteamWrapper::SteamWrapper() {
    if (!SteamAPI_IsSteamRunning()) {
        Util::Error::Exit("Please start Steam before attempting to open the game.");
    }
    
    if (SteamAPI_RestartAppIfNecessary(2090230)) {
        Util::Error::ExitFast();
    }
    
    if (!SteamAPI_Init()) {
        Util::Error::Exit("Failed to initialize the Steam API. Ensure you are launching the game through Steam!");
    }
}

SteamWrapper::~SteamWrapper() {
    SteamAPI_Shutdown();
}

void SteamWrapper::RunCallbacks() {
    SteamAPI_RunCallbacks();
}

void SteamWrapper::SetNotificationPosition(NotificationPosition notificationPosition) {
    SteamUtils()->SetOverlayNotificationPosition(static_cast<ENotificationPosition>(notificationPosition));
}