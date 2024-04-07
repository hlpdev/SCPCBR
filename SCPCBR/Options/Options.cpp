#include "Options.h"

#include <ini.h>

#include "../Util/Util.h"

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

bool Options::ReadBoolOption(const std::string& category, const std::string& key) {
    return Util::Strings::ToLower(ini->operator[](category).operator[](key)) == "true";
}

void Options::WriteBoolOption(const std::string& category, const std::string& key, bool value) {
    ini->operator[](category).operator[](key) = value ? "true" : "false";
}

void Options::Free() {
    file->write(*ini);

    delete ini;
    delete file;
}

void Options::ResetOptions() {}
