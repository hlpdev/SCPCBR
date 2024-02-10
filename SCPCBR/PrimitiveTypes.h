#ifndef PRIMITIVETYPES_H
#define PRIMITIVETYPES_H

#include <algorithm>

struct Vec2 {
    float X;
    float Y;

    Vec2() {
        X = 0;
        Y = 0;
    }
    
    Vec2(float x, float y) {
        X = x;
        Y = y;
    }
};

struct Vec3 : Vec2 {
    float Z;

    Vec3() {
        X = 0;
        Y = 0;
        Z = 0;
    }
    
    Vec3(float x, float y, float z) {
        X = x;
        Y = y;
        Z = z;
    }
};

struct Vec4 : Vec3 {
    float A;

    Vec4() {
        X = 0;
        Y = 0;
        Z = 0;
        A = 0;
    }

    Vec4(float x, float y, float z, float a) {
        X = x;
        Y = y;
        Z = z;
        A = a;
    }
};

struct RGB {
    RGB() {
        this->red = 0;
        this->green = 0;
        this->blue = 0;
    }

    RGB(int red, int green, int blue) {
        this->red = std::clamp(red, 0, 255);
        this->green = std::clamp(green, 0, 255);
        this->blue = std::clamp(blue, 0, 255);
    }

    int Red() {
        return red;
    }

    int Red(int red) {
        this->red = std::clamp(red, 0, 255);
        return this->red;
    }

    int Green() {
        return red;
    }

    int Green(int green) {
        this->green = std::clamp(green, 0, 255);
        return this->green;
    }

    int Blue() {
        return blue;
    }

    int Blue(int blue) {
        this->blue = std::clamp(blue, 0, 255);
        return this->blue;
    }

protected:
    int red;
    int green;
    int blue;
};

struct RGBA : RGB {
    RGBA() {
        this->red = 0;
        this->green = 0;
        this->blue = 0;
        this->alpha = 255;
    }

    RGBA(int red, int green, int blue, int alpha) {
        this->red = std::clamp(red, 0, 255);
        this->green = std::clamp(green, 0, 255);
        this->blue = std::clamp(blue, 0, 255);
        this->alpha = std::clamp(alpha, 0, 255);
    }

    int Alpha() {
        return alpha;
    }

    int Alpha(int alpha) {
        this->alpha = std::clamp(alpha, 0, 255);
        return this->alpha;
    }

protected:
    int alpha;
};

struct RGBf {
    RGBf() {
        this->red = 0;
        this->green = 0;
        this->blue = 0;
    }

    RGBf(float red, float green, float blue) {
        this->red = std::clamp(red, 0.0f, 1.0f);
        this->green = std::clamp(green, 0.0f, 1.0f);
        this->blue = std::clamp(blue, 0.0f, 1.0f);
    }

    float Red() {
        return this->red;
    }

    float Red(float red) {
        this->red = std::clamp(red, 0.0f, 1.0f);
        return this->red;
    }

    float Green() {
        return this->green;
    }

    float Green(float green) {
        this->green = std::clamp(green, 0.0f, 1.0f);
        return this->green;
    }

    float Blue() {
        return this->blue;
    }

    float Blue(float blue) {
        this->blue = std::clamp(blue, 0.0f, 1.0f);
        return this->blue;
    }

protected:
    float red;
    float green;
    float blue;
};

struct RGBAf : RGBf {
    RGBAf() {
        this->red = 0.0f;
        this->green = 0.0f;
        this->blue = 0.0f;
        this->alpha = 1.0f;
    }

    RGBAf(float red, float green, float blue, float alpha) {
        this->red = std::clamp(red, 0.0f, 1.0f);
        this->green = std::clamp(green, 0.0f, 1.0f);
        this->blue = std::clamp(blue, 0.0f, 1.0f);
        this->alpha = std::clamp(alpha, 0.0f, 1.0f);
    }

    float Alpha() {
        return this->alpha;
    }

    float Alpha(float alpha) {
        this->alpha = std::clamp(alpha, 0.0f, 1.0f);
        return this->alpha;
    }

protected:
    float alpha;
};

typedef Vec2 Vec2;
typedef Vec3 Vec3;
typedef Vec4 Vec4;
typedef RGB RGB;
typedef RGBf RGBf;
typedef RGBA RGBA;
typedef RGBAf RGBAf;

#endif // PRIMITIVETYPES_H
