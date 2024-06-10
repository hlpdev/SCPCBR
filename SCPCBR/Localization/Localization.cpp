#include "Localization.h"

#include <filesystem>
#include <unordered_map>
#include <vector>
#include <GLFW/glfw3.h>

#include "../Options/Options.h"

Localization::Language* ActiveLanguage = nullptr;
size_t ActiveLanguageIndex = -1;
std::vector<Localization::Language*> Languages;

void Localization::Init() {
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    for (const auto& entry : std::filesystem::directory_iterator("Assets\\Localization\\")) {
        toml::parse_result parsedToml = toml::parse_file(entry.path().string());

        const ImWchar* glyphRange = nullptr;

        std::string glyphRangeConfig = parsedToml["LanguageInfo"]["GlyphRange"].value_exact<std::string>().value();
        
        if (glyphRangeConfig == "Default") {
            glyphRange = io.Fonts->GetGlyphRangesDefault();
        } else if (glyphRangeConfig == "Greek") {
            glyphRange = io.Fonts->GetGlyphRangesGreek();
        } else if (glyphRangeConfig == "Korean") {
            glyphRange = io.Fonts->GetGlyphRangesKorean();
        } else if (glyphRangeConfig == "Japanese") {
            glyphRange = io.Fonts->GetGlyphRangesJapanese();
        } else if (glyphRangeConfig == "ChineseFull") {
            glyphRange = io.Fonts->GetGlyphRangesChineseFull();
        } else if (glyphRangeConfig == "ChineseSimplifiedCommon") {
            glyphRange = io.Fonts->GetGlyphRangesChineseSimplifiedCommon();
        } else if (glyphRangeConfig == "Cyrillic") {
            glyphRange = io.Fonts->GetGlyphRangesCyrillic();
        } else if (glyphRangeConfig == "Thai") {
            glyphRange = io.Fonts->GetGlyphRangesThai();
        } else if (glyphRangeConfig == "Vietnamese") {
            glyphRange = io.Fonts->GetGlyphRangesVietnamese();
        } else {
            glyphRange = io.Fonts->GetGlyphRangesDefault();
        }

        Language* newLanguage = new Language;

        newLanguage->Identifier = parsedToml["LanguageInfo"]["Identifier"].value_exact<std::string>().value();
        newLanguage->Name = parsedToml["LanguageInfo"]["Name"].value_exact<std::string>().value();

        const char* CourierNewFontFile = parsedToml["Fonts"]["CourierNew"].value_exact<const char*>().value();
        
        newLanguage->CourierNew = io.Fonts->AddFontFromFileTTF(CourierNewFontFile, 20.0f, 0, glyphRange);
        newLanguage->CourierNewExtraLarge = io.Fonts->AddFontFromFileTTF(CourierNewFontFile, 60.0f, 0, glyphRange);
        newLanguage->CourierNewLarge = io.Fonts->AddFontFromFileTTF(CourierNewFontFile, 50.0f, 0, glyphRange);
        newLanguage->CourierNewSmall = io.Fonts->AddFontFromFileTTF(CourierNewFontFile, 14.0f, 0, glyphRange);

        const char* CourierNewBoldFontFile = parsedToml["Fonts"]["CourierNewBold"].value_exact<const char*>().value();

        newLanguage->CourierNewBold = io.Fonts->AddFontFromFileTTF(CourierNewBoldFontFile, 20.0f, 0, glyphRange);

        const char* DSDigitalFontFile = parsedToml["Fonts"]["DSDigital"].value_exact<const char*>().value();

        newLanguage->DSDigital = io.Fonts->AddFontFromFileTTF(DSDigitalFontFile, 20.0f, 0, glyphRange);

        const char* JournalFontFile = parsedToml["Fonts"]["Journal"].value_exact<const char*>().value();

        newLanguage->Journal = io.Fonts->AddFontFromFileTTF(JournalFontFile, 20.0f, 0, glyphRange);

        const char* BadlocCompression = parsedToml["Fonts"]["BadlocCompression"].value_exact<const char*>().value();
        
        newLanguage->BadlocCompression = io.Fonts->AddFontFromFileTTF(BadlocCompression, 12.0f, 0, glyphRange);

        newLanguage->Toml = parsedToml;

        Languages.push_back(newLanguage);
    }

    std::string languageOption = Options::ReadStringOption("Misc", "Language");

    size_t counter = 0;
    for (Language* language : Languages) {
        if (language->Identifier == languageOption) {
            ActiveLanguage = language;
            ActiveLanguageIndex = counter;
            break;
        }

        counter++;
    }

    if (ActiveLanguage == nullptr) {
        Util::Error::Exit("Failed to find the selected language configuration");
    }
}

void Localization::SetActiveLanguage(std::string name) {
    size_t counter = 0;
    for (Language* language : Languages) {
        if (language->Name == name) {
            ActiveLanguage = language;
            ActiveLanguageIndex = counter;

            Options::WriteStringOption("Misc", "Language", ActiveLanguage->Identifier);
            break;
        }

        counter++;
    }
}

size_t Localization::GetActiveLanguageIndex() {
    return ActiveLanguageIndex;
}

size_t Localization::GetLanguageAmount() {
    return Languages.size();
}

Localization::Language* Localization::GetActiveLanguage() {
    return ActiveLanguage;
}

ImFont* Localization::GetActiveLanguageCourierNew() {
    return ActiveLanguage->CourierNew;
}

ImFont* Localization::GetActiveLanguageCourierNewExtraLarge() {
    return ActiveLanguage->CourierNewExtraLarge;
}

ImFont* Localization::GetActiveLanguageCourierNewLarge() {
    return ActiveLanguage->CourierNewLarge;
}

ImFont* Localization::GetActiveLanguageCourierNewSmall() {
    return ActiveLanguage->CourierNewSmall;
}

ImFont* Localization::GetActiveLanguageCourierNewBold() {
    return ActiveLanguage->CourierNewBold;
}

ImFont* Localization::GetActiveLanguageDSDigital() {
    return ActiveLanguage->DSDigital;
}

ImFont* Localization::GetActiveLanguageJournal() {
    return ActiveLanguage->Journal;
}

ImFont* Localization::GetActiveLanguageBadlocCompression() {
    return ActiveLanguage->BadlocCompression;
}

std::vector<const char*> Localization::GetAllLanguageNames() {
    std::vector<const char*> languageNames;
    
    for (const Language* language : Languages) {
        languageNames.push_back(language->Name.c_str());
    }

    return languageNames;
}

std::string Localization::GetTranslatedKey(const std::string& category, const std::string& key, const std::vector<std::string>& args) {
    std::string localizedString = ActiveLanguage->Toml[category][key].value_exact<std::string>().value();

    int index = 0;
    for (std::string arg : args) {
        std::string identifier = std::string(std::string("{") + std::to_string(index) + std::string("}"));
        localizedString = Util::Strings::ReplaceByDelimiterCopy(localizedString, identifier, arg);
        index++;
    }

    return localizedString;
}

bool KeyMappingsInitialized = false;
std::unordered_map<int, std::string> KeyMappings;

std::string Localization::KeyboardKeyToName(int key) {
    if (!KeyMappingsInitialized) {
        KeyMappings[GLFW_KEY_SPACE] = "SPACE";
        KeyMappings[GLFW_KEY_APOSTROPHE] = "'";
        KeyMappings[GLFW_KEY_COMMA] = ",";
        KeyMappings[GLFW_KEY_MINUS] = "-";
        KeyMappings[GLFW_KEY_PERIOD] = ".";
        KeyMappings[GLFW_KEY_SLASH] = "/";
        KeyMappings[GLFW_KEY_0] = "0";
        KeyMappings[GLFW_KEY_1] = "1";
        KeyMappings[GLFW_KEY_2] = "2";
        KeyMappings[GLFW_KEY_3] = "3";
        KeyMappings[GLFW_KEY_4] = "4";
        KeyMappings[GLFW_KEY_5] = "5";
        KeyMappings[GLFW_KEY_6] = "6";
        KeyMappings[GLFW_KEY_7] = "7";
        KeyMappings[GLFW_KEY_8] = "8";
        KeyMappings[GLFW_KEY_9] = "9";
        KeyMappings[GLFW_KEY_SEMICOLON] = ";";
        KeyMappings[GLFW_KEY_EQUAL] = "=";
        KeyMappings[GLFW_KEY_A] = "A";
        KeyMappings[GLFW_KEY_B] = "B";
        KeyMappings[GLFW_KEY_C] = "C";
        KeyMappings[GLFW_KEY_D] = "D";
        KeyMappings[GLFW_KEY_E] = "E";
        KeyMappings[GLFW_KEY_F] = "F";
        KeyMappings[GLFW_KEY_G] = "G";
        KeyMappings[GLFW_KEY_H] = "H";
        KeyMappings[GLFW_KEY_I] = "I";
        KeyMappings[GLFW_KEY_J] = "J";
        KeyMappings[GLFW_KEY_K] = "K";
        KeyMappings[GLFW_KEY_L] = "L";
        KeyMappings[GLFW_KEY_M] = "M";
        KeyMappings[GLFW_KEY_N] = "N";
        KeyMappings[GLFW_KEY_O] = "O";
        KeyMappings[GLFW_KEY_P] = "P";
        KeyMappings[GLFW_KEY_Q] = "Q";
        KeyMappings[GLFW_KEY_R] = "R";
        KeyMappings[GLFW_KEY_S] = "S";
        KeyMappings[GLFW_KEY_T] = "T";
        KeyMappings[GLFW_KEY_U] = "U";
        KeyMappings[GLFW_KEY_V] = "V";
        KeyMappings[GLFW_KEY_W] = "W";
        KeyMappings[GLFW_KEY_X] = "X";
        KeyMappings[GLFW_KEY_Y] = "Y";
        KeyMappings[GLFW_KEY_Z] = "Z";
        KeyMappings[GLFW_KEY_LEFT_BRACKET] = "[";
        KeyMappings[GLFW_KEY_BACKSLASH] = "\\";
        KeyMappings[GLFW_KEY_RIGHT_BRACKET] = "]";
        KeyMappings[GLFW_KEY_GRAVE_ACCENT] = "`";
        KeyMappings[GLFW_KEY_ENTER] = "ENTER";
        KeyMappings[GLFW_KEY_TAB] = "TAB";
        KeyMappings[GLFW_KEY_BACKSPACE] = "BACKSPACE";
        KeyMappings[GLFW_KEY_INSERT] = "INSERT";
        KeyMappings[GLFW_KEY_DELETE] = "DELETE";
        KeyMappings[GLFW_KEY_RIGHT] = "RIGHT";
        KeyMappings[GLFW_KEY_LEFT] = "LEFT";
        KeyMappings[GLFW_KEY_DOWN] = "DOWN";
        KeyMappings[GLFW_KEY_UP] = "UP";
        KeyMappings[GLFW_KEY_PAGE_UP] = "PAGE UP";
        KeyMappings[GLFW_KEY_PAGE_DOWN] = "PAGE DOWN";
        KeyMappings[GLFW_KEY_HOME] = "HOME";
        KeyMappings[GLFW_KEY_END] = "END";
        KeyMappings[GLFW_KEY_CAPS_LOCK] = "CAPS LOCK";
        KeyMappings[GLFW_KEY_SCROLL_LOCK] = "SCROLL LOCK";
        KeyMappings[GLFW_KEY_NUM_LOCK] = "NUM LOCK";
        KeyMappings[GLFW_KEY_PRINT_SCREEN] = "PRINT SCREEN";
        KeyMappings[GLFW_KEY_PAUSE] = "PAUSE";
        KeyMappings[GLFW_KEY_F1] = "F1";
        KeyMappings[GLFW_KEY_F2] = "F2";
        KeyMappings[GLFW_KEY_F3] = "F3";
        KeyMappings[GLFW_KEY_F4] = "F4";
        KeyMappings[GLFW_KEY_F5] = "F5";
        KeyMappings[GLFW_KEY_F6] = "F6";
        KeyMappings[GLFW_KEY_F7] = "F7";
        KeyMappings[GLFW_KEY_F8] = "F8";
        KeyMappings[GLFW_KEY_F9] = "F9";
        KeyMappings[GLFW_KEY_F10] = "F10";
        KeyMappings[GLFW_KEY_F11] = "F11";
        KeyMappings[GLFW_KEY_F12] = "F12";
        KeyMappings[GLFW_KEY_F13] = "F13";
        KeyMappings[GLFW_KEY_F14] = "F14";
        KeyMappings[GLFW_KEY_F15] = "F15";
        KeyMappings[GLFW_KEY_F16] = "F16";
        KeyMappings[GLFW_KEY_F17] = "F17";
        KeyMappings[GLFW_KEY_F18] = "F18";
        KeyMappings[GLFW_KEY_F19] = "F19";
        KeyMappings[GLFW_KEY_F20] = "F20";
        KeyMappings[GLFW_KEY_F21] = "F21";
        KeyMappings[GLFW_KEY_F22] = "F22";
        KeyMappings[GLFW_KEY_F23] = "F23";
        KeyMappings[GLFW_KEY_F24] = "F24";
        KeyMappings[GLFW_KEY_F25] = "F25";
        KeyMappings[GLFW_KEY_KP_0] = "KEYPAD 0";
        KeyMappings[GLFW_KEY_KP_1] = "KEYPAD 1";
        KeyMappings[GLFW_KEY_KP_2] = "KEYPAD 2";
        KeyMappings[GLFW_KEY_KP_3] = "KEYPAD 3";
        KeyMappings[GLFW_KEY_KP_4] = "KEYPAD 4";
        KeyMappings[GLFW_KEY_KP_5] = "KEYPAD 5";
        KeyMappings[GLFW_KEY_KP_6] = "KEYPAD 6";
        KeyMappings[GLFW_KEY_KP_7] = "KEYPAD 7";
        KeyMappings[GLFW_KEY_KP_8] = "KEYPAD 8";
        KeyMappings[GLFW_KEY_KP_9] = "KEYPAD 9";
        KeyMappings[GLFW_KEY_KP_DECIMAL] = "KEYPAD .";
        KeyMappings[GLFW_KEY_KP_DIVIDE] = "KEYPAD /";
        KeyMappings[GLFW_KEY_KP_MULTIPLY] = "KEYPAD *";
        KeyMappings[GLFW_KEY_KP_SUBTRACT] = "KEYPAD -";
        KeyMappings[GLFW_KEY_KP_ADD] = "KEYPAD +";
        KeyMappings[GLFW_KEY_KP_ENTER] = "KEYPAD ENTER";
        KeyMappings[GLFW_KEY_KP_EQUAL] = "KEYPAD =";
        KeyMappings[GLFW_KEY_LEFT_SHIFT] = "LEFT SHIFT";
        KeyMappings[GLFW_KEY_LEFT_CONTROL] = "LEFT CONTROL";
        KeyMappings[GLFW_KEY_LEFT_ALT] = "LEFT ALT";
        KeyMappings[GLFW_KEY_LEFT_SUPER] = "LEFT SUPER";
        KeyMappings[GLFW_KEY_RIGHT_SHIFT] = "RIGHT SHIFT";
        KeyMappings[GLFW_KEY_RIGHT_CONTROL] = "RIGHT CONTROL";
        KeyMappings[GLFW_KEY_RIGHT_ALT] = "RIGHT ALT";
        KeyMappings[GLFW_KEY_RIGHT_SUPER] = "RIGHT SUPER";
        KeyMappings[GLFW_KEY_MENU] = "MENU";
        KeyMappings[GLFW_KEY_UNKNOWN] = "UNKNOWN";
        KeyMappings[NULL] = "NONE";

        KeyMappingsInitialized = true;
    }

    return KeyMappings[key];
}

void Localization::Free() {
    for (Language* language : Languages) {
        delete language;
    }
}
