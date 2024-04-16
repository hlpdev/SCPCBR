#ifndef DISCORDWRAPPER_H
#define DISCORDWRAPPER_H
#include <string>
#include <discord/types.h>

class DiscordWrapper {
public:
    DiscordWrapper();
    ~DiscordWrapper();

    void UpdateActivity(discord::Activity activity);

    void OpenGuildInvite(std::string code);

    void RunCallbacks();
};
#endif // DISCORDWRAPPER_H
