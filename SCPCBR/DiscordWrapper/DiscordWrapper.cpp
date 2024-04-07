#include "DiscordWrapper.h"

#include <iostream>
#include <discord/discord.h>

discord::Core* DiscordCore;

DiscordWrapper::DiscordWrapper() {
    discord::Core::Create(767487208684650536, static_cast<uint8_t>(discord::CreateFlags::Default), &DiscordCore);

    DiscordCore->ActivityManager().RegisterSteam(2090230);
    
    DiscordCore->SetLogHook(discord::LogLevel::Info, [](discord::LogLevel, const char* message) {
        std::cout << message << '\n';
    });
}

DiscordWrapper::~DiscordWrapper() {
    delete DiscordCore;
}

void DiscordWrapper::UpdateActivity(discord::Activity activity) {
    DiscordCore->ActivityManager().UpdateActivity(activity, nullptr);
}

void DiscordWrapper::OpenGuildInvite(std::string code) {
    DiscordCore->OverlayManager().OpenGuildInvite(code.c_str(), nullptr);
}

void DiscordWrapper::RunCallbacks() {
    DiscordCore->RunCallbacks();
}
