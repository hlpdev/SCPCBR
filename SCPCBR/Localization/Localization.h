#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <toml.hpp>
#include <imgui/imgui.h>

#include "../Util/Util.h"

namespace Localization {
    
    struct Language {
        std::string Identifier;
        std::string Name;

        ImFont* CourierNew;
        ImFont* CourierNewExtraLarge;
        ImFont* CourierNewLarge;
        ImFont* CourierNewSmall;
        ImFont* CourierNewBold;
        ImFont* DSDigital;
        ImFont* Journal;
        ImFont* BadlocCompression;
        
        toml::parse_result Toml;
    };
    
    void Init();

    void SetActiveLanguage(std::string languageId);

    size_t GetActiveLanguageIndex();

    size_t GetLanguageAmount();
    
    Language* GetActiveLanguage();

    ImFont* GetActiveLanguageCourierNew();
    ImFont* GetActiveLanguageCourierNewExtraLarge();
    ImFont* GetActiveLanguageCourierNewLarge();
    ImFont* GetActiveLanguageCourierNewSmall();
    ImFont* GetActiveLanguageCourierNewBold();
    ImFont* GetActiveLanguageDSDigital();
    ImFont* GetActiveLanguageJournal();
    ImFont* GetActiveLanguageBadlocCompression();
    
    std::vector<const char*> GetAllLanguageNames();

    std::string GetTranslatedKey(const std::string& category, const std::string& key, const std::vector<std::string>& args = {});

    std::string KeyboardKeyToName(int key);

    void Free();
}

#endif // LOCALIZATION_H
