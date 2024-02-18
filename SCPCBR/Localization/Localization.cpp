#include "Localization.h"

#include <filesystem>
#include <vector>

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
        Util::Strings::ReplaceByDelimiter(localizedString, identifier, arg);
        index++;
    }

    return localizedString;
}

void Localization::Free() {
    for (Language* language : Languages) {
        delete language;
    }
}
