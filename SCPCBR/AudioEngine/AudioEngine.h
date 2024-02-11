#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <string>

namespace AudioEngine {
    void Init();
    
    void RunCallbacks();

    void Free();
};

#endif // AUDIOENGINE_H