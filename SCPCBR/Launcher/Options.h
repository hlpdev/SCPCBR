#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>

namespace Options {
    int ReadIntOption(std::string category, std::string key);
    bool WriteIntOption(std::string category, std::string key, int value);
    std::string ReadStringOption(std::string category, std::string key);
    bool WriteStringOption(std::string category, std::string key, std::string value);
    
    bool ResetOptions();
}

#endif // OPTIONS_H
