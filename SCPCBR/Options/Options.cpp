#include "Options.h"

#include <ini.h>

mINI::INIFile* file;
mINI::INIStructure* ini;

void Options::Init() {
    file = new mINI::INIFile("options.ini");
    ini = new mINI::INIStructure;

    file->read(*ini);
}

int Options::ReadIntOption(const std::string& category, const std::string& key) {
    return std::stoi(ini->operator[](category).operator[](key));
}

void Options::WriteIntOption(const std::string& category, const std::string& key, int value) {
    ini->operator[](category).operator[](key) = std::to_string(value);
}

std::string Options::ReadStringOption(const std::string& category, const std::string& key) {
    return ini->operator[](category).operator[](key);
}

void Options::WriteStringOption(const std::string& category, const std::string& key, std::string value) {
    ini->operator[](category).operator[](key) = value;
}

void Options::Free() {
    file->write(*ini);

    delete ini;
    delete file;
}

void Options::ResetOptions() {}
