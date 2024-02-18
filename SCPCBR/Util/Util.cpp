#include "Util.h"

#include <Windows.h>
#include <random>

#include "STB/stb_image.h"

bool Util::Image::LoadImageFromFile(std::string fileName, Image* image) {
    int components;
    unsigned char* imageData = stbi_load(fileName.c_str(), &image->Width, &image->Height, &components, 0);

    glGenTextures(1, &image->TextureId);

    if (imageData) {
        GLenum format{};

        if (components == 1) {
            format = GL_RED;
        } else if (components == 3) {
            format = GL_RGB;
        } else if (components == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, image->TextureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, format, image->Width, image->Height, 0, format, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(imageData);
        return true;
    }
    
    return false;
}

void Util::Error::Exit(std::string message) {
    MessageBoxA(0, message.c_str(), "SCP:CBR FATAL ERROR", MB_TOPMOST | MB_ICONERROR);
    exit(EXIT_FAILURE);
}

void Util::Error::ExitFast() {
    exit(EXIT_FAILURE);
}

void Util::Strings::ReplaceByDelimiter(std::string& string, std::string& delimiter, std::string& toReplaceWith) {
    size_t startPos = 0;
    while ((startPos = string.find(delimiter, startPos)) != std::string::npos) {
        string.replace(startPos, delimiter.length(), toReplaceWith);
        startPos += toReplaceWith.length();
    }
}

std::string Util::Strings::ReplaceByDelimiterCopy(std::string string, std::string& delimiter, std::string& toReplaceWith) {
    size_t startPos = 0;
    while ((startPos = string.find(delimiter, startPos)) != std::string::npos) {
        string.replace(startPos, delimiter.length(), toReplaceWith);
        startPos += toReplaceWith.length();
    }

    return string;
}

std::vector<std::string> Util::Strings::Split(std::string text, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = text.find(delimiter, pos_start)) != std::string::npos) {
        token = text.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (text.substr(pos_start));
    return res;
}

void Util::Strings::ReplaceAll(std::string& text, const std::string& replace, const std::string& replaceWith) {
    for( size_t pos = 0; ; pos += replace.length() ) {
        // Locate the substring to replace
        pos = text.find( replace, pos );
        if( pos == std::string::npos ) break;
        // Replace by erasing and inserting
        text.erase( pos, replace.length() );
        text.insert( pos, replaceWith );
    }
}

int Util::Math::RandomInt(int min, int max) {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<> distribution(min, max);

    return distribution(generator);
}

float Util::Math::RandomFloat(float min, float max) {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_real_distribution<> distribution(min, max);

    return distribution(generator);
}

int Util::Math::Clamp(int number, int min, int max) {
    if (number < min) {
        return min;
    }

    if (number > max) {
        return max;
    }

    return number;
}

int Util::Math::ClampMin(int number, int min) {
    if (number < min) {
        return min;
    }

    return number;
}

int Util::Math::ClampMax(int number, int max) {
    if (number > max) {
        return max;
    }

    return number;
}

float Util::Math::Clamp(float number, float min, float max) {
    if (number < min) {
        return min;
    }

    if (number > max) {
        return max;
    }

    return number;
}

float Util::Math::ClampMin(float number, float min) {
    if (number < min) {
        return min;
    }

    return number;
}

float Util::Math::ClampMax(float number, float max) {
    if (number > max) {
        return max;
    }

    return number;
}