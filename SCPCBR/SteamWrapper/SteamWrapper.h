#ifndef STEAMWRAPPER_H
#define STEAMWRAPPER_H

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
};

#endif // STEAMWRAPPER_H
