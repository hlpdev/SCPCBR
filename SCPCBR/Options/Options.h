#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>

namespace Options {
    void Init();
    
    int ReadIntOption(const std::string& category, const std::string& key);
    void WriteIntOption(const std::string& category, const std::string& key, int value);
    std::string ReadStringOption(const std::string& category, const std::string& key);
    void WriteStringOption(const std::string& category, const std::string& key, std::string value);
    
    void ResetOptions();

    void Free();
}

#endif // OPTIONS_H
