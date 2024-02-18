#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

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

    namespace Strings {
        void ReplaceByDelimiter(std::string& string, std::string& delimiter, std::string& toReplaceWith);
        std::string ReplaceByDelimiterCopy(std::string string, std::string& delimiter, std::string& toReplaceWith);

        std::vector<std::string> Split(std::string text, std::string delimiter);

        void ReplaceAll(std::string& text, const std::string& replace, const std::string& replaceWith);
    }

    namespace Error {
        void Exit(std::string message);
        void ExitFast();
    }

    namespace Math {
        int RandomInt(int min, int max);
        float RandomFloat(float min, float max);

        int Clamp(int number, int min, int max);
        int ClampMin(int number, int min);
        int ClampMax(int number, int max);

        float Clamp(float number, float min, float max);
        float ClampMin(float number, float min);
        float ClampMax(float number, float max);
    }
}

#endif // UTIL_H
