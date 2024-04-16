#ifndef STEAMWRAPPER_H
#define STEAMWRAPPER_H

#include <string>

class SteamWrapper {
public:
    SteamWrapper();
    ~SteamWrapper();

    void RunCallbacks();

    typedef enum class NotificationPosition {
        TopLeft = 0,
        TopRight = 1,
        BottomLeft = 2,
        BottomRight = 3,
    } NotificationPosition;
    
    void SetNotificationPosition(NotificationPosition notificationPosition);

    void SetRichPresence(const std::string& key, const std::string& value);
    void ClearRichPresence();

    void OpenLinkInOverlay(const std::string& url);
};

#endif // STEAMWRAPPER_H
