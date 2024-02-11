#ifndef PRIMITIVETYPES_H
#define PRIMITIVETYPES_H

enum class GlobalGameState {
    Launcher,
    Splash,
    MainMenu,
    Game
};

class TVec2 {
public:
    float X;
    float Y;

    TVec2();
    TVec2(float x, float y);
};

class TVec3 : TVec2 {
public:
    float Z;

    TVec3();
    TVec3(float x, float y, float z);
};

class TVec4 : TVec3 {
public:
    float A;

    TVec4();
    TVec4(float x, float y, float z, float a);
};

class TRGB {
public:
    TRGB();
    TRGB(int red, int green, int blue);

    int Red() const;
    int Red(int red);

    int Green() const;
    int Green(int green);

    int Blue() const;
    int Blue(int blue);

protected:
    int red;
    int green;
    int blue;
};

class TRGBA : TRGB {
public:
    TRGBA();
    TRGBA(int red, int green, int blue, int alpha);

    int Alpha() const;
    int Alpha(int alpha);

protected:
    int alpha;
};

class TRGBf {
public:
    TRGBf();
    TRGBf(float red, float green, float blue);

    float Red() const;
    float Red(float red);

    float Green() const;
    float Green(float green);

    float Blue() const;
    float Blue(float blue);

protected:
    float red;
    float green;
    float blue;
};

class TRGBAf : TRGBf {
public:
    TRGBAf();
    TRGBAf(float red, float green, float blue, float alpha);

    float Alpha() const;
    float Alpha(float alpha);

protected:
    float alpha;
};

#endif // PRIMITIVETYPES_H
