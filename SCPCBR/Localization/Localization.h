#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include "toml.hpp"
#include "imgui/imgui.h"
#include "../Util/Util.h"

namespace Localization {
    
    struct Language {
        std::string Identifier;
        std::string Name;

        ImFont* CourierNew;
        ImFont* CourierNewSmall;
        ImFont* CourierNewBold;
        ImFont* DSDigital;
        ImFont* Journal;
        
        toml::parse_result Toml;
    };
    
    void Init();

    void SetActiveLanguage(std::string languageId);

    size_t GetActiveLanguageIndex();

    size_t GetLanguageAmount();
    
    Language* GetActiveLanguage();

    ImFont* GetActiveLanguageCourierNew();
    ImFont* GetActiveLanguageCourierNewSmall();
    ImFont* GetActiveLanguageCourierNewBold();
    ImFont* GetActiveLanguageDSDigital();
    ImFont* GetActiveLanguageJournal();
    
    std::vector<const char*> GetAllLanguageNames();

    std::string GetTranslatedKey(const std::string& category, const std::string& key, const std::vector<std::string>& args = {});

    void Free();
}

#endif // LOCALIZATION_H
