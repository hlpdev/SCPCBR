#include "Util.h"

#include <Windows.h>

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
