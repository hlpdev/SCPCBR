#ifndef GENERATIONSYSTEM_H
#define GENERATIONSYSTEM_H

#include <string>

namespace GenerationSystem {
    typedef enum class Difficulty {
        SAFE,
        EUCLID,
        KETER,
        APOLLYON
    } Difficulty;

    typedef struct GenerationInstructions {
        std::string Name;
        std::string Seed;
        Difficulty Difficulty;
        
    } GenerationInstructions;

    class GenerationSystem {
    public:
    
    };
}

#endif // GENERATIONSYSTEM_H
