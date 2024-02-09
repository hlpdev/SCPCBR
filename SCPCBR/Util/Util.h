#ifndef UTIL_H
#define UTIL_H

#include <string>

#ifndef __gl_h_
#include "glad/glad.h"
#endif

namespace Util {
    namespace Image {
        struct Image {
            int Width;
            int Height;
            unsigned int TextureId;
        };
        typedef Image Image;
        
        bool LoadImageFromFile(std::string fileName, Image* image);
    }

    namespace Error {
        void Exit(std::string message);
    }
}

#endif // UTIL_H