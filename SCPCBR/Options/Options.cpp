#include "Options.h"

#include <ini.h>

int Options::ReadIntOption(std::string category, std::string key) {
    mINI::INIFile file("options.ini");
    mINI::INIStructure ini;
    file.read(ini);
    
    return std::stoi(ini[category][key]);
}

bool Options::WriteIntOption(std::string category, std::string key, int value) {
    mINI::INIFile file("options.ini");
    mINI::INIStructure ini;
    file.read(ini);
    
    ini[category][key] = std::to_string(value);
    return file.write(ini);
}

std::string Options::ReadStringOption(std::string category, std::string key) {
    mINI::INIFile file("options.ini");
    mINI::INIStructure ini;
    file.read(ini);

    return ini[category][key];
}

bool Options::WriteStringOption(std::string category, std::string key, std::string value) {
    mINI::INIFile file("options.ini");
    mINI::INIStructure ini;
    file.read(ini);

    ini[category][key] = value;
    return file.write(ini);
}

void Options::ResetOptions() {
    WriteStringOption("Graphics", "DisplayMode", "Fullscreen");
    WriteStringOption("Misc", "Language", "en-US");
}
