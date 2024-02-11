#include "Types.h"

#include <algorithm>

TVec2::TVec2() {
    X = 0;
    Y = 0;
}

TVec2::TVec2(float x, float y) {
    X = x;
    Y = y;
}

TVec3::TVec3() : TVec2(0, 0) {
    Z = 0;
}

TVec3::TVec3(float x, float y, float z) : TVec2(x, y) {
    Z = z;
}

TVec4::TVec4() : TVec3(0, 0, 0) {
    A = 0;
}

TVec4::TVec4(float x, float y, float z, float a) : TVec3(x, y, z) {
    A = a;
}

TRGB::TRGB() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

TRGB::TRGB(int red, int green, int blue) {
    this->red = std::clamp(red, 0, 255);
    this->green = std::clamp(green, 0, 255);
    this->blue = std::clamp(blue, 0, 255);
}

int TRGB::Red() const {
    return red;
}

int TRGB::Red(int red) {
    this->red = std::clamp(red, 0, 255);
    return this->red;
}

int TRGB::Green() const {
    return red;
}

int TRGB::Green(int green) {
    this->green = std::clamp(green, 0, 255);
    return this->green;
}

int TRGB::Blue() const {
    return blue;
}

int TRGB::Blue(int blue) {
    this->blue = std::clamp(blue, 0, 255);
    return this->blue;
}

TRGBA::TRGBA() : TRGB(0, 0, 0) {
    this->alpha = 255;
}

TRGBA::TRGBA(int red, int green, int blue, int alpha)
    : TRGB(
        std::clamp(red, 0, 255),
        std::clamp(green, 0, 255),
        std::clamp(blue, 0, 255)
        ) {
    this->alpha = std::clamp(alpha, 0, 255);
}

int TRGBA::Alpha() const {
    return alpha;
}

int TRGBA::Alpha(int alpha) {
    this->alpha = std::clamp(alpha, 0, 255);
    return this->alpha;
}

TRGBf::TRGBf() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

TRGBf::TRGBf(float red, float green, float blue) {
    this->red = std::clamp(red, 0.0f, 1.0f);
    this->green = std::clamp(green, 0.0f, 1.0f);
    this->blue = std::clamp(blue, 0.0f, 1.0f);
}

float TRGBf::Red() const {
    return this->red;
}

float TRGBf::Red(float red) {
    this->red = std::clamp(red, 0.0f, 1.0f);
    return this->red;
}

float TRGBf::Green() const {
    return this->green;
}

float TRGBf::Green(float green) {
    this->green = std::clamp(green, 0.0f, 1.0f);
    return this->green;
}

float TRGBf::Blue() const {
    return this->blue;
}

float TRGBf::Blue(float blue) {
    this->blue = std::clamp(blue, 0.0f, 1.0f);
    return this->blue;
}

TRGBAf::TRGBAf() : TRGBf(0.0f, 0.0f, 0.0f) {
    this->alpha = 1.0f;
}

TRGBAf::TRGBAf(float red, float green, float blue, float alpha)
    : TRGBf(
        std::clamp(red, 0.0f, 1.0f),
        std::clamp(green, 0.0f, 1.0f),
        std::clamp(blue, 0.0f, 1.0f)
        ) {
    this->alpha = std::clamp(alpha, 0.0f, 1.0f);
}

float TRGBAf::Alpha() const {
    return this->alpha;
}

float TRGBAf::Alpha(float alpha) {
    this->alpha = std::clamp(alpha, 0.0f, 1.0f);
    return this->alpha;
}

