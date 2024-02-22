#include "PreloadManager.h"

#include <thread>
#include <Windows.h>
#include <toml.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_custom.h>

#include "../AudioEngine/AudioEngine.h"
#include "../Localization/Localization.h"
#include "../Util/Util.h"

bool preloadStarted = false;
float progress = 0;

void ProcessPreloadThread() {
        // SFX\ALARM
    progress = 0.00084388186f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm.ogg", FMOD_2D);
    progress = 0.0016877637f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2.ogg", FMOD_2D);
    progress = 0.0025316456f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_1.ogg", FMOD_2D);
    progress = 0.0033755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_2.ogg", FMOD_2D);
    progress = 0.004219409f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_3.ogg", FMOD_2D);
    progress = 0.005063291f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_4.ogg", FMOD_2D);
    progress = 0.005907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_5.ogg", FMOD_2D);
    progress = 0.006751055f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_6.ogg", FMOD_2D);
    progress = 0.0075949365f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_7.ogg", FMOD_2D);
    progress = 0.008438818f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_8.ogg", FMOD_2D);
    progress = 0.009282701f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_9.ogg", FMOD_2D);
    progress = 0.010126582f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_10.ogg", FMOD_2D);
    progress = 0.010970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_11.ogg", FMOD_2D);
    progress = 0.011814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm3.ogg", FMOD_2D);
    progress = 0.012658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm4.ogg", FMOD_3D);
    progress = 0.01350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm5.ogg", FMOD_3D);
    progress = 0.014345991f;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm6.ogg", FMOD_3D);
    progress = 0.015189873f;

    progress = 0.016033756f;
    // SFX\AMBIENT
    progress = 0.016877636f;
    // SFX\AMBIENT\FOREST
    progress = 0.017721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient1.ogg", FMOD_2D);
    progress = 0.018565401f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient2.ogg", FMOD_2D);
    progress = 0.019409282f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient3.ogg", FMOD_2D);
    progress = 0.020253165f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient4.ogg", FMOD_2D);
    progress = 0.021097047f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient5.ogg", FMOD_2D);
    progress = 0.021940928f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient6.ogg", FMOD_2D);
    progress = 0.02278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient7.ogg", FMOD_2D);
    progress = 0.023628691f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient8.ogg", FMOD_2D);
    progress = 0.024472574f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient9.ogg", FMOD_2D);
    progress = 0.025316456f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient10.ogg", FMOD_2D);
    progress = 0.026160337f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient11.ogg", FMOD_2D);
    progress = 0.02700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient12.ogg", FMOD_2D);
    progress = 0.027848102f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient13.ogg", FMOD_2D);
    progress = 0.028691983f;
    // SFX\AMBIENT\GENERAL
    progress = 0.029535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient1.ogg", FMOD_2D);
    progress = 0.030379746f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient2.ogg", FMOD_2D);
    progress = 0.031223629f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient3.ogg", FMOD_2D);
    progress = 0.03206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient4.ogg", FMOD_2D);
    progress = 0.032911394f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient5.ogg", FMOD_2D);
    progress = 0.033755273f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient6.ogg", FMOD_2D);
    progress = 0.034599155f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient7.ogg", FMOD_2D);
    progress = 0.035443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient8.ogg", FMOD_2D);
    progress = 0.03628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient9.ogg", FMOD_2D);
    progress = 0.037130803f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient10.ogg", FMOD_2D);
    progress = 0.03797468f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient11.ogg", FMOD_2D);
    progress = 0.038818564f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient12.ogg", FMOD_2D);
    progress = 0.039662447f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient13.ogg", FMOD_2D);
    progress = 0.04050633f;
    // SFX\AMBIENT\PRE-BREACH
    progress = 0.041350212f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient1.ogg", FMOD_2D);
    progress = 0.042194095f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient2.ogg", FMOD_2D);
    progress = 0.043037973f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient3.ogg", FMOD_2D);
    progress = 0.043881856f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient4.ogg", FMOD_2D);
    progress = 0.04472574f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient5.ogg", FMOD_2D);
    progress = 0.04556962f;
    // SFX\AMBIENT\ROOM AMBIENCE
    progress = 0.046413504f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/895.ogg", FMOD_2D);
    progress = 0.047257382f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Drip.ogg", FMOD_2D);
    progress = 0.048101265f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Drips.ogg", FMOD_2D);
    progress = 0.048945148f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Fan.ogg", FMOD_2D);
    progress = 0.04978903f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FanOff.ogg", FMOD_2D);
    progress = 0.050632913f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FanOn.ogg", FMOD_2D);
    progress = 0.05147679f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Feuer.ogg", FMOD_2D);
    progress = 0.052320674f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FuelPump.ogg", FMOD_2D);
    progress = 0.053164557f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/LowDrone.ogg", FMOD_2D);
    progress = 0.05400844f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Pulsing.ogg", FMOD_2D);
    progress = 0.05485232f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Servers1.ogg", FMOD_2D);
    progress = 0.055696204f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Ventilation.ogg", FMOD_2D);
    progress = 0.056540083f;
    // SFX\AMBIENT\ZONE1
    progress = 0.057383966f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient1.ogg", FMOD_2D);
    progress = 0.05822785f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient2.ogg", FMOD_2D);
    progress = 0.05907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient3.ogg", FMOD_2D);
    progress = 0.059915613f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient4.ogg", FMOD_2D);
    progress = 0.060759492f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient5.ogg", FMOD_2D);
    progress = 0.061603375f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient6.ogg", FMOD_2D);
    progress = 0.062447257f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient7.ogg", FMOD_2D);
    progress = 0.06329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient8.ogg", FMOD_2D);
    progress = 0.06413502f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient9.ogg", FMOD_2D);
    progress = 0.064978905f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient10.ogg", FMOD_2D);
    progress = 0.06582279f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient11.ogg", FMOD_2D);
    progress = 0.06666667f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient12.ogg", FMOD_2D);
    progress = 0.067510545f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient13.ogg", FMOD_2D);
    progress = 0.06835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient14.ogg", FMOD_2D);
    progress = 0.06919831f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient15.ogg", FMOD_2D);
    progress = 0.07004219f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient16.ogg", FMOD_2D);
    progress = 0.070886075f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient17.ogg", FMOD_2D);
    progress = 0.07172996f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient18.ogg", FMOD_2D);
    progress = 0.07257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient19.ogg", FMOD_2D);
    progress = 0.07341772f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient20.ogg", FMOD_2D);
    progress = 0.074261606f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient21.ogg", FMOD_2D);
    progress = 0.07510549f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient22.ogg", FMOD_2D);
    progress = 0.07594936f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient23.ogg", FMOD_2D);
    progress = 0.076793246f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient24.ogg", FMOD_2D);
    progress = 0.07763713f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient25.ogg", FMOD_2D);
    progress = 0.07848101f;
    // SFX\AMBIENT\ZONE2
    progress = 0.07932489f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient1.ogg", FMOD_2D);
    progress = 0.080168776f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient2.ogg", FMOD_2D);
    progress = 0.08101266f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient3.ogg", FMOD_2D);
    progress = 0.08185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient4.ogg", FMOD_2D);
    progress = 0.082700424f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient5.ogg", FMOD_2D);
    progress = 0.08354431f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient6.ogg", FMOD_2D);
    progress = 0.08438819f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient7.ogg", FMOD_2D);
    progress = 0.085232064f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient8.ogg", FMOD_2D);
    progress = 0.08607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient9.ogg", FMOD_2D);
    progress = 0.08691983f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient10.ogg", FMOD_2D);
    progress = 0.08776371f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient11.ogg", FMOD_2D);
    progress = 0.088607594f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient12.ogg", FMOD_2D);
    progress = 0.08945148f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient13.ogg", FMOD_2D);
    progress = 0.09029536f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient14.ogg", FMOD_2D);
    progress = 0.09113924f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient15.ogg", FMOD_2D);
    progress = 0.091983125f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient16.ogg", FMOD_2D);
    progress = 0.09282701f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient17.ogg", FMOD_2D);
    progress = 0.09367089f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient18.ogg", FMOD_2D);
    progress = 0.094514765f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient19.ogg", FMOD_2D);
    progress = 0.09535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient20.ogg", FMOD_2D);
    progress = 0.09620253f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient21.ogg", FMOD_2D);
    progress = 0.09704641f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient22.ogg", FMOD_2D);
    progress = 0.097890295f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient23.ogg", FMOD_2D);
    progress = 0.09873418f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient24.ogg", FMOD_2D);
    progress = 0.09957806f;
    // SFX\AMBIENT\ZONE3
    progress = 0.10042194f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient1.ogg", FMOD_2D);
    progress = 0.101265825f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient2.ogg", FMOD_2D);
    progress = 0.10210971f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient3.ogg", FMOD_2D);
    progress = 0.10295358f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient4.ogg", FMOD_2D);
    progress = 0.103797466f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient5.ogg", FMOD_2D);
    progress = 0.10464135f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient6.ogg", FMOD_2D);
    progress = 0.10548523f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient7.ogg", FMOD_2D);
    progress = 0.10632911f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient8.ogg", FMOD_2D);
    progress = 0.107172996f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient9.ogg", FMOD_2D);
    progress = 0.10801688f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient10.ogg", FMOD_2D);
    progress = 0.10886076f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient11.ogg", FMOD_2D);
    progress = 0.10970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient12.ogg", FMOD_2D);
    progress = 0.110548526f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient13.ogg", FMOD_2D);
    progress = 0.11139241f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient14.ogg", FMOD_2D);
    progress = 0.11223628f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient15.ogg", FMOD_2D);
    progress = 0.11308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient16.ogg", FMOD_2D);
    progress = 0.11392405f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient17.ogg", FMOD_2D);
    progress = 0.11476793f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient18.ogg", FMOD_2D);
    progress = 0.115611814f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient19.ogg", FMOD_2D);
    progress = 0.1164557f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient20.ogg", FMOD_2D);
    progress = 0.11729958f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient21.ogg", FMOD_2D);
    progress = 0.11814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient22.ogg", FMOD_2D);
    progress = 0.118987344f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient23.ogg", FMOD_2D);
    progress = 0.11983123f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient24.ogg", FMOD_2D);
    progress = 0.1206751f;
    // SFX\AMBIENT
    progress = 0.121518984f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/ToZone2.ogg", FMOD_2D);
    progress = 0.12236287f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/ToZone3.ogg", FMOD_2D);
    progress = 0.12320675f;

    progress = 0.12405063f;
    // SFX\CHARACTER
    progress = 0.124894515f;
    // SFX\CHARACTER\APACHE
    progress = 0.1257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Crash1.ogg", FMOD_2D);
    progress = 0.12658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Crash2.ogg", FMOD_2D);
    progress = 0.12742616f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Propeller.ogg", FMOD_3D);
    progress = 0.12827004f;
    // SFX\CHARACTER\D9341
    progress = 0.12911393f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip0.ogg", FMOD_3D);
    progress = 0.12995781f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip1.ogg", FMOD_3D);
    progress = 0.1308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip2.ogg", FMOD_3D);
    progress = 0.13164558f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip3.ogg", FMOD_3D);
    progress = 0.13248946f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip4.ogg", FMOD_3D);
    progress = 0.13333334f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip5.ogg", FMOD_3D);
    progress = 0.13417721f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath0.ogg", FMOD_2D);
    progress = 0.13502109f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath0gas.ogg", FMOD_2D);
    progress = 0.13586497f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath1.ogg", FMOD_2D);
    progress = 0.13670886f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath1gas.ogg", FMOD_2D);
    progress = 0.13755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath2.ogg", FMOD_2D);
    progress = 0.13839662f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath2gas.ogg", FMOD_2D);
    progress = 0.1392405f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath3.ogg", FMOD_2D);
    progress = 0.14008439f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath3gas.ogg", FMOD_2D);
    progress = 0.14092827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath4.ogg", FMOD_2D);
    progress = 0.14177215f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath4gas.ogg", FMOD_2D);
    progress = 0.14261603f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough1.ogg", FMOD_2D);
    progress = 0.14345992f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough2.ogg", FMOD_2D);
    progress = 0.1443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough3.ogg", FMOD_2D);
    progress = 0.14514768f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Crouch.ogg", FMOD_2D);
    progress = 0.14599156f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage1.ogg", FMOD_2D);
    progress = 0.14683545f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage2.ogg", FMOD_2D);
    progress = 0.14767933f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage3.ogg", FMOD_2D);
    progress = 0.14852321f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage4.ogg", FMOD_2D);
    progress = 0.1493671f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage5.ogg", FMOD_2D);
    progress = 0.15021098f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage6.ogg", FMOD_2D);
    progress = 0.15105486f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage7.ogg", FMOD_2D);
    progress = 0.15189873f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage8.ogg", FMOD_2D);
    progress = 0.15274261f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage9.ogg", FMOD_2D);
    progress = 0.15358649f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage10.ogg", FMOD_2D);
    progress = 0.15443037f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Heartbeat.ogg", FMOD_2D);
    progress = 0.15527426f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/RelaxedBreathGas.ogg", FMOD_2D);
    progress = 0.15611814f;
    // SFX\CHARACTER\GUARD
    progress = 0.15696202f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom1.ogg", FMOD_3D);
    progress = 0.1578059f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom2.ogg", FMOD_3D);
    progress = 0.15864979f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom3.ogg", FMOD_3D);
    progress = 0.15949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/SuicideGuard1.ogg", FMOD_3D);
    progress = 0.16033755f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/SuicideGuard2.ogg", FMOD_3D);
    progress = 0.16118143f;
    // SFX\CHARACTER\JANITOR
    progress = 0.16202532f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Janitor/106Abduct.ogg", FMOD_3D);
    progress = 0.1628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Janitor/Idle.ogg", FMOD_3D);
    progress = 0.16371308f;
    // SFX\CHARACTER\LURESUBJECT
    progress = 0.16455697f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/106Bait.ogg", FMOD_2D);
    progress = 0.16540085f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle1.ogg", FMOD_2D);
    progress = 0.16624473f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle2.ogg", FMOD_2D);
    progress = 0.16708861f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle3.ogg", FMOD_2D);
    progress = 0.1679325f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle4.ogg", FMOD_2D);
    progress = 0.16877638f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle5.ogg", FMOD_2D);
    progress = 0.16962026f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle6.ogg", FMOD_2D);
    progress = 0.17046413f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Sniffling.ogg", FMOD_2D);
    progress = 0.17130801f;
    // SFX\CHARACTER\MTF
    progress = 0.1721519f;
    // SFX\CHARACTER\MTF\049
    progress = 0.17299578f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Player0492_1.ogg", FMOD_3D);
    progress = 0.17383966f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Player0492_2.ogg", FMOD_3D);
    progress = 0.17468354f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted1.ogg", FMOD_3D);
    progress = 0.17552742f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted2.ogg", FMOD_3D);
    progress = 0.1763713f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted3.ogg", FMOD_3D);
    progress = 0.17721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted4.ogg", FMOD_3D);
    progress = 0.17805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted5.ogg", FMOD_3D);
    progress = 0.17890295f;
    // SFX\CHARACTER\MTF\096
    progress = 0.17974684f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/096/Spotted1.ogg", FMOD_3D);
    progress = 0.18059072f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/096/Spotted2.ogg", FMOD_3D);
    progress = 0.1814346f;
    // SFX\CHARACTER\MTF\106
    progress = 0.18227848f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted1.ogg", FMOD_3D);
    progress = 0.18312237f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted2.ogg", FMOD_3D);
    progress = 0.18396625f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted3.ogg", FMOD_3D);
    progress = 0.18481013f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted4.ogg", FMOD_3D);
    progress = 0.18565401f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted5.ogg", FMOD_3D);
    progress = 0.1864979f;
    // SFX\CHARACTER\MTF\173
    progress = 0.18734178f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/BLINKING.ogg", FMOD_3D);
    progress = 0.18818565f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box1.ogg", FMOD_3D);
    progress = 0.18902953f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box2.ogg", FMOD_3D);
    progress = 0.18987341f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box3.ogg", FMOD_3D);
    progress = 0.1907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont1.ogg", FMOD_3D);
    progress = 0.19156118f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont2.ogg", FMOD_3D);
    progress = 0.19240506f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont3.ogg", FMOD_3D);
    progress = 0.19324894f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont4.ogg", FMOD_3D);
    progress = 0.19409283f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted1.ogg", FMOD_3D);
    progress = 0.19493671f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted2.ogg", FMOD_3D);
    progress = 0.19578059f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted3.ogg", FMOD_3D);
    progress = 0.19662447f;
    // SFX\CHARACTER\MTF
    progress = 0.19746836f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Announc.ogg", FMOD_2D);
    progress = 0.19831224f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Announc173Contain.ogg", FMOD_2D);
    progress = 0.19915612f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncAfter1.ogg", FMOD_2D);
    progress = 0.2f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncAfter2.ogg", FMOD_2D);
    progress = 0.20084389f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraCheck.ogg", FMOD_2D);
    progress = 0.20168777f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraFound1.ogg", FMOD_2D);
    progress = 0.20253165f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraFound2.ogg", FMOD_2D);
    progress = 0.20337553f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraNoFound.ogg", FMOD_2D);
    progress = 0.20421942f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Beep.ogg", FMOD_3D);
    progress = 0.2050633f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Breath.ogg", FMOD_3D);
    progress = 0.20590717f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD1.ogg", FMOD_3D);
    progress = 0.20675105f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD2.ogg", FMOD_3D);
    progress = 0.20759493f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD3.ogg", FMOD_3D);
    progress = 0.20843881f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD4.ogg", FMOD_3D);
    progress = 0.2092827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB1.ogg", FMOD_3D);
    progress = 0.21012658f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB2.ogg", FMOD_3D);
    progress = 0.21097046f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB3.ogg", FMOD_3D);
    progress = 0.21181434f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB4.ogg", FMOD_3D);
    progress = 0.21265823f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random1.ogg", FMOD_3D);
    progress = 0.21350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random2.ogg", FMOD_3D);
    progress = 0.21434599f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random3.ogg", FMOD_3D);
    progress = 0.21518987f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random4.ogg", FMOD_3D);
    progress = 0.21603376f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random5.ogg", FMOD_3D);
    progress = 0.21687764f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random6.ogg", FMOD_3D);
    progress = 0.21772152f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random7.ogg", FMOD_3D);
    progress = 0.2185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching1.ogg", FMOD_3D);
    progress = 0.21940929f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching2.ogg", FMOD_3D);
    progress = 0.22025317f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching3.ogg", FMOD_3D);
    progress = 0.22109705f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching4.ogg", FMOD_3D);
    progress = 0.22194093f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching5.ogg", FMOD_3D);
    progress = 0.22278482f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching6.ogg", FMOD_3D);
    progress = 0.22362868f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step1.ogg", FMOD_3D);
    progress = 0.22447257f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step2.ogg", FMOD_3D);
    progress = 0.22531645f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step3.ogg", FMOD_3D);
    progress = 0.22616033f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop1.ogg", FMOD_3D);
    progress = 0.22700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop2.ogg", FMOD_3D);
    progress = 0.2278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop3.ogg", FMOD_3D);
    progress = 0.22869198f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop4.ogg", FMOD_3D);
    progress = 0.22953586f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop5.ogg", FMOD_3D);
    progress = 0.23037975f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop6.ogg", FMOD_3D);
    progress = 0.23122363f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost1.ogg", FMOD_3D);
    progress = 0.23206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost2.ogg", FMOD_3D);
    progress = 0.2329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost3.ogg", FMOD_3D);
    progress = 0.23375528f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated1.ogg", FMOD_3D);
    progress = 0.23459916f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated2.ogg", FMOD_3D);
    progress = 0.23544304f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated3.ogg", FMOD_3D);
    progress = 0.23628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated4.ogg", FMOD_3D);
    progress = 0.2371308f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla0.ogg", FMOD_3D);
    progress = 0.23797469f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla1.ogg", FMOD_2D);
    progress = 0.23881857f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla2.ogg", FMOD_2D);
    progress = 0.23966245f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla3.ogg", FMOD_2D);
    progress = 0.24050634f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs1.ogg", FMOD_3D);
    progress = 0.2413502f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs2.ogg", FMOD_3D);
    progress = 0.24219409f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs3.ogg", FMOD_3D);
    progress = 0.24303797f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs4.ogg", FMOD_3D);
    progress = 0.24388185f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs5.ogg", FMOD_3D);
    progress = 0.24472573f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs6.ogg", FMOD_3D);
    progress = 0.24556962f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc1.ogg", FMOD_2D);
    progress = 0.2464135f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc2.ogg", FMOD_2D);
    progress = 0.24725738f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc3.ogg", FMOD_2D);
    progress = 0.24810126f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnouncFinal.ogg", FMOD_2D);
    progress = 0.24894515f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnouncPossession.ogg", FMOD_2D);
    progress = 0.24978903f;
    // SFX\CHARACTER\MTF2
    progress = 0.2506329f;
    // SFX\CHARACTER\MTF2\049
    progress = 0.2514768f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/049/Player0492_1.ogg", FMOD_3D);
    progress = 0.25232068f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/049/Player0492_2.ogg", FMOD_3D);
    progress = 0.25316456f;
    // SFX\CHARACTER\MTF2\096
    progress = 0.25400844f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/096/Spotted1.ogg", FMOD_3D);
    progress = 0.25485232f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/096/Spotted2.ogg", FMOD_3D);
    progress = 0.2556962f;
    // SFX\CHARACTER\MTF2\106
    progress = 0.2565401f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted1.ogg", FMOD_3D);
    progress = 0.25738397f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted2.ogg", FMOD_3D);
    progress = 0.25822785f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted3.ogg", FMOD_3D);
    progress = 0.25907174f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted4.ogg", FMOD_3D);
    progress = 0.25991562f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted5.ogg", FMOD_3D);
    progress = 0.2607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted6.ogg", FMOD_3D);
    progress = 0.2616034f;
    // SFX\CHARACTER\MTF2\173
    progress = 0.26244727f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING1.ogg", FMOD_3D);
    progress = 0.26329115f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING2.ogg", FMOD_3D);
    progress = 0.26413503f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING3.ogg", FMOD_3D);
    progress = 0.26497892f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING4.ogg", FMOD_3D);
    progress = 0.2658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box1.ogg", FMOD_3D);
    progress = 0.26666668f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box2.ogg", FMOD_3D);
    progress = 0.26751056f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box3.ogg", FMOD_3D);
    progress = 0.26835442f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box4.ogg", FMOD_3D);
    progress = 0.2691983f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont1.ogg", FMOD_3D);
    progress = 0.27004218f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont2.ogg", FMOD_3D);
    progress = 0.27088606f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont3.ogg", FMOD_3D);
    progress = 0.27172995f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont4.ogg", FMOD_3D);
    progress = 0.27257383f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont5.ogg", FMOD_3D);
    progress = 0.2734177f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont6.ogg", FMOD_3D);
    progress = 0.2742616f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted1.ogg", FMOD_3D);
    progress = 0.27510548f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted2.ogg", FMOD_3D);
    progress = 0.27594936f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted3.ogg", FMOD_3D);
    progress = 0.27679324f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted4.ogg", FMOD_3D);
    progress = 0.27763712f;
    // SFX\CHARACTER\MTF2
    progress = 0.278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Announc.ogg", FMOD_2D);
    progress = 0.2793249f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Beep.ogg", FMOD_3D);
    progress = 0.28016877f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ClassD1.ogg", FMOD_3D);
    progress = 0.28101265f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ClassD2.ogg", FMOD_3D);
    progress = 0.28185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Random1.ogg", FMOD_3D);
    progress = 0.28270042f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Random2.ogg", FMOD_3D);
    progress = 0.2835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching1.ogg", FMOD_3D);
    progress = 0.28438818f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching2.ogg", FMOD_3D);
    progress = 0.28523207f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching3.ogg", FMOD_3D);
    progress = 0.28607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching4.ogg", FMOD_3D);
    progress = 0.28691983f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching5.ogg", FMOD_3D);
    progress = 0.2877637f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching6.ogg", FMOD_3D);
    progress = 0.2886076f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop1.ogg", FMOD_3D);
    progress = 0.28945148f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop2.ogg", FMOD_3D);
    progress = 0.29029536f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop3.ogg", FMOD_3D);
    progress = 0.29113925f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop4.ogg", FMOD_3D);
    progress = 0.29198313f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop5.ogg", FMOD_3D);
    progress = 0.292827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop6.ogg", FMOD_3D);
    progress = 0.2936709f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost1.ogg", FMOD_3D);
    progress = 0.29451478f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost2.ogg", FMOD_3D);
    progress = 0.29535866f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost3.ogg", FMOD_3D);
    progress = 0.29620254f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost4.ogg", FMOD_3D);
    progress = 0.29704642f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated1.ogg", FMOD_3D);
    progress = 0.2978903f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated2.ogg", FMOD_3D);
    progress = 0.2987342f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated3.ogg", FMOD_3D);
    progress = 0.29957807f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated4.ogg", FMOD_3D);
    progress = 0.30042195f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated5.ogg", FMOD_3D);
    progress = 0.30126584f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Tesla0.ogg", FMOD_3D);
    progress = 0.30210972f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs1.ogg", FMOD_3D);
    progress = 0.3029536f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs2.ogg", FMOD_3D);
    progress = 0.30379745f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs3.ogg", FMOD_3D);
    progress = 0.30464134f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs4.ogg", FMOD_3D);
    progress = 0.30548522f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs5.ogg", FMOD_3D);
    progress = 0.3063291f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs6.ogg", FMOD_3D);
    progress = 0.30717298f;
    // SFX\CHARACTER\SCIENTIST
    progress = 0.30801687f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/EmilyScream.ogg", FMOD_2D);
    progress = 0.30886075f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/Radio0.ogg", FMOD_3D);
    progress = 0.30970463f;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/Radio1.ogg", FMOD_3D);
    progress = 0.3105485f;

    progress = 0.3113924f;
    // SFX\DOOR
    progress = 0.31223628f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/1123DoorOpen.ogg", FMOD_3D);
    progress = 0.31308016f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Airlock.ogg", FMOD_3D);
    progress = 0.31392404f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose.ogg", FMOD_3D);
    progress = 0.31476793f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose1.ogg", FMOD_3D);
    progress = 0.3156118f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose2.ogg", FMOD_3D);
    progress = 0.3164557f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen.ogg", FMOD_3D);
    progress = 0.31729957f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen1.ogg", FMOD_3D);
    progress = 0.31814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen2.ogg", FMOD_3D);
    progress = 0.31898734f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close1.ogg", FMOD_3D);
    progress = 0.31983122f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close2.ogg", FMOD_3D);
    progress = 0.3206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close3.ogg", FMOD_3D);
    progress = 0.321519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open1.ogg", FMOD_3D);
    progress = 0.32236287f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open1_dist.ogg", FMOD_2D);
    progress = 0.32320675f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open2.ogg", FMOD_3D);
    progress = 0.32405064f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open3.ogg", FMOD_3D);
    progress = 0.32489452f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorCheckpoint.ogg", FMOD_3D);
    progress = 0.3257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose1.ogg", FMOD_3D);
    progress = 0.32658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose2.ogg", FMOD_3D);
    progress = 0.32742617f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose3.ogg", FMOD_3D);
    progress = 0.32827005f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose079.ogg", FMOD_3D);
    progress = 0.32911393f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorError.ogg", FMOD_3D);
    progress = 0.3299578f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen1.ogg", FMOD_3D);
    progress = 0.3308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen2.ogg", FMOD_3D);
    progress = 0.33164558f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen3.ogg", FMOD_3D);
    progress = 0.33248946f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen079.ogg", FMOD_3D);
    progress = 0.33333334f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen173.ogg", FMOD_3D);
    progress = 0.33417723f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpenFast1.ogg", FMOD_3D);
    progress = 0.3350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpenFast2.ogg", FMOD_3D);
    progress = 0.335865f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorSparks.ogg", FMOD_3D);
    progress = 0.33670887f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose1.ogg", FMOD_3D);
    progress = 0.33755276f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose2.ogg", FMOD_3D);
    progress = 0.33839664f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose3.ogg", FMOD_3D);
    progress = 0.33924052f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen1.ogg", FMOD_3D);
    progress = 0.34008437f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen2.ogg", FMOD_3D);
    progress = 0.34092826f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen3.ogg", FMOD_3D);
    progress = 0.34177214f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/EndroomDoor.ogg", FMOD_2D);
    progress = 0.34261602f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorBudge.ogg", FMOD_3D);
    progress = 0.3434599f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorClose.ogg", FMOD_3D);
    progress = 0.3443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorOpen.ogg", FMOD_3D);
    progress = 0.34514767f;

    progress = 0.34599155f;
    // SFX\ENDING
    progress = 0.34683543f;
    // SFX\ENDING\GATEA
    progress = 0.34767932f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/106Escape.ogg", FMOD_3D);
    progress = 0.3485232f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/106Retreat.ogg", FMOD_3D);
    progress = 0.34936708f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Bell1.ogg", FMOD_2D);
    progress = 0.35021096f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Bell2.ogg", FMOD_2D);
    progress = 0.35105485f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/CI.ogg", FMOD_3D);
    progress = 0.35189873f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/EndingA1.ogg", FMOD_2D);
    progress = 0.3527426f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/EndingA2.ogg", FMOD_2D);
    progress = 0.3535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Franklin.ogg", FMOD_2D);
    progress = 0.35443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/HIDTurret.ogg", FMOD_2D);
    progress = 0.35527426f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/STOPRIGHTTHERE.ogg", FMOD_2D);
    progress = 0.35611814f;
    // SFX\ENDING\GATEB
    progress = 0.35696203f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/682Battle.ogg", FMOD_3D);
    progress = 0.3578059f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/AlphaWarheadsFail.ogg", FMOD_3D);
    progress = 0.3586498f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/DetonatingAlphaWarheads.ogg", FMOD_3D);
    progress = 0.35949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB1.ogg", FMOD_2D);
    progress = 0.36033756f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB2.ogg", FMOD_2D);
    progress = 0.36118144f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB3.ogg", FMOD_2D);
    progress = 0.36202532f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Gunshot.ogg", FMOD_2D);
    progress = 0.3628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Nuke1.ogg", FMOD_2D);
    progress = 0.3637131f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Nuke2.ogg", FMOD_2D);
    progress = 0.36455697f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/PlayerDetect.ogg", FMOD_3D);
    progress = 0.36540085f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Siren.ogg", FMOD_2D);
    progress = 0.36624473f;
    // SFX\ENDING
    progress = 0.36708862f;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/MenuBreath.ogg", FMOD_2D);
    progress = 0.3679325f;

    progress = 0.36877638f;
    // SFX\GENERAL
    progress = 0.36962026f;
    // SFX\GENERAL\ELEVATOR
    progress = 0.37046415f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Elevator/Beep.ogg", FMOD_3D);
    progress = 0.37130803f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Elevator/Moving.ogg", FMOD_3D);
    progress = 0.3721519f;
    // SFX\GENERAL
    progress = 0.3729958f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BodyFall.ogg", FMOD_3D);
    progress = 0.37383968f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BulletHit.ogg", FMOD_2D);
    progress = 0.37468356f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BulletMiss.ogg", FMOD_2D);
    progress = 0.3755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Camera.ogg", FMOD_3D);
    progress = 0.3763713f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/GeneratorOn.ogg", FMOD_2D);
    progress = 0.37721518f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/GlassBreak.ogg", FMOD_3D);
    progress = 0.37805906f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot.ogg", FMOD_3D);
    progress = 0.37890294f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot2.ogg", FMOD_3D);
    progress = 0.37974682f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot3.ogg", FMOD_3D);
    progress = 0.3805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Hiss.ogg", FMOD_3D);
    progress = 0.3814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/LightSwitch.ogg", FMOD_2D);
    progress = 0.38227847f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Save1.ogg", FMOD_2D);
    progress = 0.38312235f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Save2.ogg", FMOD_3D);
    progress = 0.38396624f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Slash1.ogg", FMOD_3D);
    progress = 0.38481012f;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Slash2.ogg", FMOD_3D);
    progress = 0.385654f;

    progress = 0.38649788f;
    // SFX\HORROR
    progress = 0.38734177f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror0.ogg", FMOD_2D);
    progress = 0.38818565f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror1.ogg", FMOD_2D);
    progress = 0.38902953f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror2.ogg", FMOD_2D);
    progress = 0.38987342f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror3.ogg", FMOD_2D);
    progress = 0.3907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror4.ogg", FMOD_2D);
    progress = 0.39156118f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror5.ogg", FMOD_2D);
    progress = 0.39240506f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror6.ogg", FMOD_2D);
    progress = 0.39324895f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror7.ogg", FMOD_2D);
    progress = 0.39409283f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror8.ogg", FMOD_2D);
    progress = 0.3949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror9.ogg", FMOD_2D);
    progress = 0.3957806f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror10.ogg", FMOD_2D);
    progress = 0.39662448f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror11.ogg", FMOD_2D);
    progress = 0.39746836f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror12.ogg", FMOD_2D);
    progress = 0.39831224f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror13.ogg", FMOD_2D);
    progress = 0.39915612f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror14.ogg", FMOD_2D);
    progress = 0.4f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror15.ogg", FMOD_2D);
    progress = 0.4008439f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror16.ogg", FMOD_2D);
    progress = 0.40168777f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror17.ogg", FMOD_2D);
    progress = 0.40253165f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror18.ogg", FMOD_2D);
    progress = 0.40337554f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror19.ogg", FMOD_2D);
    progress = 0.40421942f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror20.ogg", FMOD_2D);
    progress = 0.4050633f;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror21.ogg", FMOD_2D);
    progress = 0.40590718f;

    progress = 0.40675107f;
    // SFX\INTERACT
    progress = 0.40759495f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/Button.ogg", FMOD_3D);
    progress = 0.40843883f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/Button2.ogg", FMOD_3D);
    progress = 0.4092827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/KeycardUse1.ogg", FMOD_3D);
    progress = 0.4101266f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/KeycardUse2.ogg", FMOD_3D);
    progress = 0.41097045f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/LeverFlip.ogg", FMOD_3D);
    progress = 0.41181433f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/NVGUse0.ogg", FMOD_3D);
    progress = 0.4126582f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/NVGUse1.ogg", FMOD_3D);
    progress = 0.4135021f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem0.ogg", FMOD_3D);
    progress = 0.41434598f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem1.ogg", FMOD_3D);
    progress = 0.41518986f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem2.ogg", FMOD_3D);
    progress = 0.41603374f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem3.ogg", FMOD_3D);
    progress = 0.41687763f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem4.ogg", FMOD_3D);
    progress = 0.4177215f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem5.ogg", FMOD_3D);
    progress = 0.4185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/ScannerUse1.ogg", FMOD_3D);
    progress = 0.41940928f;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/ScannerUse2.ogg", FMOD_3D);
    progress = 0.42025316f;

    progress = 0.42109704f;
    // SFX\MUSIC
    progress = 0.42194092f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/049Chase.ogg", FMOD_2D);
    progress = 0.4227848f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096.ogg", FMOD_2D);
    progress = 0.4236287f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096Angered.ogg", FMOD_2D);
    progress = 0.42447257f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096Chase.ogg", FMOD_2D);
    progress = 0.42531645f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/106Chase.ogg", FMOD_2D);
    progress = 0.42616034f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/650Chase.ogg", FMOD_2D);
    progress = 0.42700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/860_2Chase.ogg", FMOD_2D);
    progress = 0.4278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Credits.ogg", FMOD_2D);
    progress = 0.42869198f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Dimension1499.ogg", FMOD_2D);
    progress = 0.42953587f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Dimension1499Danger.ogg", FMOD_2D);
    progress = 0.43037975f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Ending.ogg", FMOD_2D);
    progress = 0.43122363f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/EntranceZone.ogg", FMOD_2D);
    progress = 0.4320675f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Forest.ogg", FMOD_2D);
    progress = 0.4329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateA.ogg", FMOD_2D);
    progress = 0.43375528f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateB1.ogg", FMOD_2D);
    progress = 0.43459916f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateB2.ogg", FMOD_2D);
    progress = 0.43544304f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HaveMercyOnMe(Choir).ogg", FMOD_2D);
    progress = 0.43628693f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HaveMercyOnMe(NoChoir).ogg", FMOD_2D);
    progress = 0.4371308f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HeavyContainment.ogg", FMOD_2D);
    progress = 0.4379747f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Intro.ogg", FMOD_2D);
    progress = 0.43881857f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Menu.ogg", FMOD_2D | FMOD_LOOP_NORMAL);
    progress = 0.44050634f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/PD.ogg", FMOD_2D);
    progress = 0.44135022f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/PDTrench.ogg", FMOD_2D);
    progress = 0.4421941f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room2Tunnel.ogg", FMOD_2D);
    progress = 0.443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room3Storage.ogg", FMOD_2D);
    progress = 0.44388187f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room012.ogg", FMOD_2D);
    progress = 0.44472575f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room012Golgotha.ogg", FMOD_2D);
    progress = 0.44556963f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room035.ogg", FMOD_2D);
    progress = 0.44641352f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room049.ogg", FMOD_2D);
    progress = 0.44725737f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room079.ogg", FMOD_2D);
    progress = 0.44810125f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room106.ogg", FMOD_2D);
    progress = 0.44894513f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room205.ogg", FMOD_2D);
    progress = 0.44978902f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room409.ogg", FMOD_2D);
    progress = 0.4506329f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room457.ogg", FMOD_2D);
    progress = 0.45147678f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room914.ogg", FMOD_2D);
    progress = 0.45232067f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room1123.ogg", FMOD_2D);
    progress = 0.45316455f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/SaveMeFrom.ogg", FMOD_2D);
    progress = 0.45400843f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/The Dread.ogg", FMOD_2D);
    progress = 0.4548523f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using178.ogg", FMOD_2D);
    progress = 0.4556962f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using215.ogg", FMOD_2D);
    progress = 0.45654008f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using420J.ogg", FMOD_2D);
    progress = 0.45738396f;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using1033RU.ogg", FMOD_2D);
    progress = 0.45822784f;

    progress = 0.45907173f;
    // SFX\RADIO
    progress = 0.4599156f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Buzz.ogg", FMOD_2D);
    progress = 0.4607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter1.ogg", FMOD_2D);
    progress = 0.46160337f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter2.ogg", FMOD_2D);
    progress = 0.46244726f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter3.ogg", FMOD_2D);
    progress = 0.46329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter4.ogg", FMOD_2D);
    progress = 0.46413502f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin1.ogg", FMOD_2D);
    progress = 0.4649789f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin2.ogg", FMOD_2D);
    progress = 0.4658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin3.ogg", FMOD_2D);
    progress = 0.46666667f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin4.ogg", FMOD_2D);
    progress = 0.46751055f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/OhGod.ogg", FMOD_2D);
    progress = 0.46835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/RadioAlarm.ogg", FMOD_2D);
    progress = 0.46919832f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/RadioAlarm2.ogg", FMOD_2D);
    progress = 0.4700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio0.ogg", FMOD_2D);
    progress = 0.47088608f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio1.ogg", FMOD_2D);
    progress = 0.47172996f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio2.ogg", FMOD_2D);
    progress = 0.47257385f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio3.ogg", FMOD_2D);
    progress = 0.47341773f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio4.ogg", FMOD_2D);
    progress = 0.4742616f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio5.ogg", FMOD_2D);
    progress = 0.4751055f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio6.ogg", FMOD_2D);
    progress = 0.47594938f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio7.ogg", FMOD_2D);
    progress = 0.47679326f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio8.ogg", FMOD_2D);
    progress = 0.47763714f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Squelch.ogg", FMOD_2D);
    progress = 0.47848102f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Static.ogg", FMOD_2D);
    progress = 0.4793249f;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Static895.ogg", FMOD_2D);
    progress = 0.4801688f;

    progress = 0.48101267f;
    // SFX\ROOM
    progress = 0.48185655f;
    // SFX\ROOM\035CHAMBER
    progress = 0.4827004f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/InProximity.ogg", FMOD_2D);
    progress = 0.4835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleAttack1.ogg", FMOD_2D);
    progress = 0.48438817f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleAttack2.ogg", FMOD_2D);
    progress = 0.48523206f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleIdle.ogg", FMOD_2D);
    progress = 0.48607594f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleSpawn.ogg", FMOD_2D);
    progress = 0.48691982f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/Whispers1.ogg", FMOD_2D);
    progress = 0.4877637f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/Whispers2.ogg", FMOD_2D);
    progress = 0.4886076f;
    // SFX\ROOM\096CHAMBER
    progress = 0.48945147f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/096Chamber/096ChamberEvent.ogg", FMOD_2D);
    progress = 0.49029535f;
    // SFX\ROOM\106CHAMBER
    progress = 0.49113923f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/FemurBreaker.ogg", FMOD_2D);
    progress = 0.49198312f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/MagnetDown.ogg", FMOD_3D);
    progress = 0.492827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/MagnetUp.ogg", FMOD_3D);
    progress = 0.49367088f;
    // SFX\ROOM\457CHAMBER
    progress = 0.49451476f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/457Chamber/Drips.ogg", FMOD_2D);
    progress = 0.49535865f;
    // SFX\ROOM\895CHAMBER
    progress = 0.49620253f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle1.ogg", FMOD_3D);
    progress = 0.4970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle2.ogg", FMOD_3D);
    progress = 0.4978903f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle3.ogg", FMOD_3D);
    progress = 0.49873418f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardRadio.ogg", FMOD_3D);
    progress = 0.49957806f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream1.ogg", FMOD_3D);
    progress = 0.50042194f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream2.ogg", FMOD_3D);
    progress = 0.5012658f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream3.ogg", FMOD_3D);
    progress = 0.5021097f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/NVG.ogg", FMOD_2D);
    progress = 0.5029536f;
    // SFX\ROOM\INTRO
    progress = 0.5037975f;
    // SFX\ROOM\INTRO\CLASSD
    progress = 0.50464135f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/Breen.ogg", FMOD_3D);
    progress = 0.50548524f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/DontLikeThis.ogg", FMOD_3D);
    progress = 0.5063291f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/Gasp.ogg", FMOD_3D);
    progress = 0.507173f;
    // SFX\ROOM\INTRO\COMMOTION
    progress = 0.5080169f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion1.ogg", FMOD_2D);
    progress = 0.50886077f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion2.ogg", FMOD_2D);
    progress = 0.50970465f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion3.ogg", FMOD_2D);
    progress = 0.51054853f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion4.ogg", FMOD_2D);
    progress = 0.5113924f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion5.ogg", FMOD_2D);
    progress = 0.5122363f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion6.ogg", FMOD_2D);
    progress = 0.5130802f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion7.ogg", FMOD_2D);
    progress = 0.51392406f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion8.ogg", FMOD_2D);
    progress = 0.51476794f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion9.ogg", FMOD_2D);
    progress = 0.5156118f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion10.ogg", FMOD_2D);
    progress = 0.5164557f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion11.ogg", FMOD_2D);
    progress = 0.5172996f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion12.ogg", FMOD_2D);
    progress = 0.5181435f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion13.ogg", FMOD_2D);
    progress = 0.51898736f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion14.ogg", FMOD_2D);
    progress = 0.51983124f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion15.ogg", FMOD_2D);
    progress = 0.5206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion16.ogg", FMOD_2D);
    progress = 0.521519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion17.ogg", FMOD_2D);
    progress = 0.5223629f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion18.ogg", FMOD_2D);
    progress = 0.5232068f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion19.ogg", FMOD_2D);
    progress = 0.52405065f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion20.ogg", FMOD_2D);
    progress = 0.52489454f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion21.ogg", FMOD_2D);
    progress = 0.5257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion22.ogg", FMOD_2D);
    progress = 0.5265823f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion23.ogg", FMOD_2D);
    progress = 0.5274262f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion24.ogg", FMOD_2D);
    progress = 0.52827007f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion25.ogg", FMOD_2D);
    progress = 0.52911395f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion26.ogg", FMOD_2D);
    progress = 0.52995783f;
    // SFX\ROOM\INTRO\GUARD
    progress = 0.5308017f;
    // SFX\ROOM\INTRO\GUARD\BALCONY
    progress = 0.5316456f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/Alert1.ogg", FMOD_3D);
    progress = 0.5324895f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/Alert2.ogg", FMOD_3D);
    progress = 0.53333336f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/OhSh.ogg", FMOD_3D);
    progress = 0.53417724f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/WTF1.ogg", FMOD_3D);
    progress = 0.5350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/WTF2.ogg", FMOD_3D);
    progress = 0.53586495f;
    // SFX\ROOM\INTRO\GUARD\ULGRIN
    progress = 0.53670883f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/BeforeDoorOpen.ogg", FMOD_3D);
    progress = 0.5375527f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/CellGas1.ogg", FMOD_3D);
    progress = 0.5383966f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/CellGas2.ogg", FMOD_3D);
    progress = 0.5392405f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/Escort1.ogg", FMOD_3D);
    progress = 0.54008436f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/Escort2.ogg", FMOD_3D);
    progress = 0.54092824f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone1.ogg", FMOD_3D);
    progress = 0.5417721f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone2.ogg", FMOD_3D);
    progress = 0.542616f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone3.ogg", FMOD_3D);
    progress = 0.5434599f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone4.ogg", FMOD_3D);
    progress = 0.5443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone5.ogg", FMOD_3D);
    progress = 0.54514766f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortKill1.ogg", FMOD_3D);
    progress = 0.54599154f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortKill2.ogg", FMOD_3D);
    progress = 0.5468354f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortPissedOff1.ogg", FMOD_3D);
    progress = 0.5476793f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortPissedOff2.ogg", FMOD_3D);
    progress = 0.5485232f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRefuse1.ogg", FMOD_3D);
    progress = 0.5493671f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRefuse2.ogg", FMOD_3D);
    progress = 0.55021095f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRun.ogg", FMOD_3D);
    progress = 0.55105484f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortTerminated.ogg", FMOD_3D);
    progress = 0.5518987f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCell.ogg", FMOD_3D);
    progress = 0.5527426f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCellRefuse1.ogg", FMOD_3D);
    progress = 0.5535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCellRefuse2.ogg", FMOD_3D);
    progress = 0.55443037f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/OhAndByTheWay.ogg", FMOD_3D);
    progress = 0.55527425f;
    // SFX\ROOM\INTRO\GUARD
    progress = 0.55611813f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation1a.ogg", FMOD_3D);
    progress = 0.556962f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation1b.ogg", FMOD_3D);
    progress = 0.5578059f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation2a.ogg", FMOD_3D);
    progress = 0.5586498f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation2b.ogg", FMOD_3D);
    progress = 0.55949366f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation3a.ogg", FMOD_3D);
    progress = 0.56033754f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation3b.ogg", FMOD_3D);
    progress = 0.5611814f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation4a.ogg", FMOD_3D);
    progress = 0.5620253f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation4b.ogg", FMOD_3D);
    progress = 0.5628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation5a.ogg", FMOD_3D);
    progress = 0.5637131f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation5b.ogg", FMOD_3D);
    progress = 0.56455696f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music1.ogg", FMOD_3D);
    progress = 0.56540084f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music2.ogg", FMOD_3D);
    progress = 0.5662447f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music3.ogg", FMOD_3D);
    progress = 0.5670886f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music4.ogg", FMOD_3D);
    progress = 0.5679325f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music5.ogg", FMOD_3D);
    progress = 0.56877637f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/PlayerEscape.ogg", FMOD_3D);
    progress = 0.56962025f;
    // SFX\ROOM\INTRO\PA
    progress = 0.57046413f;
    // SFX\ROOM\INTRO\PA\1
    progress = 0.571308f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/1/Attention1.ogg", FMOD_2D);
    progress = 0.5721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/1/Attention2.ogg", FMOD_2D);
    progress = 0.5729958f;
    // SFX\ROOM\INTRO\PA\2
    progress = 0.57383966f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew0.ogg", FMOD_2D);
    progress = 0.57468355f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew1.ogg", FMOD_2D);
    progress = 0.5755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew2.ogg", FMOD_2D);
    progress = 0.5763713f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew3.ogg", FMOD_2D);
    progress = 0.5772152f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew4.ogg", FMOD_2D);
    progress = 0.5780591f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew5.ogg", FMOD_2D);
    progress = 0.57890296f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist0.ogg", FMOD_2D);
    progress = 0.57974684f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist1.ogg", FMOD_2D);
    progress = 0.5805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist2.ogg", FMOD_2D);
    progress = 0.5814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist3.ogg", FMOD_2D);
    progress = 0.5822785f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist4.ogg", FMOD_2D);
    progress = 0.5831224f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist5.ogg", FMOD_2D);
    progress = 0.58396626f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist6.ogg", FMOD_2D);
    progress = 0.58481014f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist7.ogg", FMOD_2D);
    progress = 0.585654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist8.ogg", FMOD_2D);
    progress = 0.5864979f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist8.ogg", FMOD_2D);
    progress = 0.5873418f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist9.ogg", FMOD_2D);
    progress = 0.58818567f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist10.ogg", FMOD_2D);
    progress = 0.58902955f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist11.ogg", FMOD_2D);
    progress = 0.58987343f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist12.ogg", FMOD_2D);
    progress = 0.5907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist13.ogg", FMOD_2D);
    progress = 0.5915612f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist14.ogg", FMOD_2D);
    progress = 0.5924051f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist15.ogg", FMOD_2D);
    progress = 0.59324896f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist16.ogg", FMOD_2D);
    progress = 0.59409285f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist17.ogg", FMOD_2D);
    progress = 0.5949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist18.ogg", FMOD_2D);
    progress = 0.5957806f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist19.ogg", FMOD_2D);
    progress = 0.5966245f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security0.ogg", FMOD_2D);
    progress = 0.5974684f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security1.ogg", FMOD_2D);
    progress = 0.59831226f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security2.ogg", FMOD_2D);
    progress = 0.59915614f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security3.ogg", FMOD_2D);
    progress = 0.6f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security4.ogg", FMOD_2D);
    progress = 0.6008439f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security5.ogg", FMOD_2D);
    progress = 0.6016878f;
    // SFX\ROOM\INTRO\PA\3
    progress = 0.6025317f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/CallOnline.ogg", FMOD_2D);
    progress = 0.60337555f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Crew0.ogg", FMOD_2D);
    progress = 0.60421944f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Report0.ogg", FMOD_2D);
    progress = 0.6050633f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Report1.ogg", FMOD_2D);
    progress = 0.6059072f;
    // SFX\ROOM\INTRO\PA\4
    progress = 0.6067511f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew0.ogg", FMOD_2D);
    progress = 0.6075949f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew1.ogg", FMOD_2D);
    progress = 0.6084388f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew2.ogg", FMOD_2D);
    progress = 0.6092827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew3.ogg", FMOD_2D);
    progress = 0.61012655f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew4.ogg", FMOD_2D);
    progress = 0.61097044f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew5.ogg", FMOD_2D);
    progress = 0.6118143f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew6.ogg", FMOD_2D);
    progress = 0.6126582f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist0.ogg", FMOD_2D);
    progress = 0.6135021f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist1.ogg", FMOD_2D);
    progress = 0.61434597f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist2.ogg", FMOD_2D);
    progress = 0.61518985f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist3.ogg", FMOD_2D);
    progress = 0.61603373f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist4.ogg", FMOD_2D);
    progress = 0.6168776f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist5.ogg", FMOD_2D);
    progress = 0.6177215f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist6.ogg", FMOD_2D);
    progress = 0.6185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist7.ogg", FMOD_2D);
    progress = 0.61940926f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security0.ogg", FMOD_2D);
    progress = 0.62025315f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security1.ogg", FMOD_2D);
    progress = 0.621097f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security2.ogg", FMOD_2D);
    progress = 0.6219409f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security3.ogg", FMOD_2D);
    progress = 0.6227848f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security4.ogg", FMOD_2D);
    progress = 0.6236287f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security5.ogg", FMOD_2D);
    progress = 0.62447256f;
    // SFX\ROOM\INTRO\PA\5
    progress = 0.62531644f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew1.ogg", FMOD_2D);
    progress = 0.6261603f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew2.ogg", FMOD_2D);
    progress = 0.6270042f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew3.ogg", FMOD_2D);
    progress = 0.6278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew4.ogg", FMOD_2D);
    progress = 0.628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew5.ogg", FMOD_2D);
    progress = 0.62953585f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew6.ogg", FMOD_2D);
    progress = 0.63037974f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Scientist0.ogg", FMOD_2D);
    progress = 0.6312236f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security0.ogg", FMOD_2D);
    progress = 0.6320675f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security1.ogg", FMOD_2D);
    progress = 0.6329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security2.ogg", FMOD_2D);
    progress = 0.63375527f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew0.ogg", FMOD_2D);
    progress = 0.63459915f;
    // SFX\ROOM\INTRO\PA\NUMBERS
    progress = 0.63544303f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/1.ogg", FMOD_2D);
    progress = 0.6362869f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/2.ogg", FMOD_2D);
    progress = 0.6371308f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/3.ogg", FMOD_2D);
    progress = 0.6379747f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/4.ogg", FMOD_2D);
    progress = 0.63881856f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/5.ogg", FMOD_2D);
    progress = 0.63966244f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/6.ogg", FMOD_2D);
    progress = 0.6405063f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/7.ogg", FMOD_2D);
    progress = 0.6413502f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/8.ogg", FMOD_2D);
    progress = 0.6421941f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/9.ogg", FMOD_2D);
    progress = 0.643038f;
    // SFX\ROOM\INTRO\PA\SCRIPTED
    progress = 0.64388186f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement1.ogg", FMOD_2D);
    progress = 0.64472574f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement2.ogg", FMOD_2D);
    progress = 0.6455696f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement3.ogg", FMOD_2D);
    progress = 0.6464135f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement4.ogg", FMOD_2D);
    progress = 0.6472574f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement5.ogg", FMOD_2D);
    progress = 0.6481013f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement6.ogg", FMOD_2D);
    progress = 0.64894515f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement7.ogg", FMOD_2D);
    progress = 0.64978904f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted1.ogg", FMOD_2D);
    progress = 0.6506329f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted2.ogg", FMOD_2D);
    progress = 0.6514768f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted3.ogg", FMOD_2D);
    progress = 0.6523207f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted4.ogg", FMOD_2D);
    progress = 0.65316457f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted5.ogg", FMOD_2D);
    progress = 0.65400845f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted6.ogg", FMOD_2D);
    progress = 0.65485233f;
    // SFX\ROOM\INTRO\PA
    progress = 0.6556962f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Off.ogg", FMOD_2D);
    progress = 0.6565401f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/On.ogg", FMOD_2D);
    progress = 0.657384f;
    // SFX\ROOM\INTRO\SCIENTIST
    progress = 0.65822786f;
    // SFX\ROOM\INTRO\SCIENTIST\FRANKLIN
    progress = 0.65907174f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Approach173.ogg", FMOD_2D);
    progress = 0.6599156f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/EnterChamber.ogg", FMOD_2D);
    progress = 0.6607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Problem.ogg", FMOD_2D);
    progress = 0.6616034f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse1.ogg", FMOD_2D);
    progress = 0.6624473f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse2.ogg", FMOD_2D);
    progress = 0.66329116f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse3.ogg", FMOD_2D);
    progress = 0.66413504f;
    // SFX\ROOM\INTRO\SCIENTIST
    progress = 0.6649789f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Conversation.ogg", FMOD_2D);
    progress = 0.6658228f;
    // SFX\ROOM\INTRO\VEHICLE
    progress = 0.6666667f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Vehicle/VehicleIdle.ogg", FMOD_3D);
    progress = 0.66751057f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Vehicle/VehicleMove.ogg", FMOD_3D);
    progress = 0.66835445f;
    // SFX\ROOM\INTRO
    progress = 0.66919833f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/173Chamber.ogg", FMOD_2D);
    progress = 0.6700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/173Vent.ogg", FMOD_2D);
    progress = 0.6708861f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang1.ogg", FMOD_2D);
    progress = 0.67173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang2.ogg", FMOD_2D);
    progress = 0.67257386f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang3.ogg", FMOD_2D);
    progress = 0.67341775f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Ew1.ogg", FMOD_2D);
    progress = 0.6742616f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Ew2.ogg", FMOD_2D);
    progress = 0.6751055f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Horror.ogg", FMOD_2D);
    progress = 0.6759494f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light1.ogg", FMOD_2D);
    progress = 0.6767933f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light2.ogg", FMOD_2D);
    progress = 0.67763716f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light3.ogg", FMOD_2D);
    progress = 0.67848104f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/See173.ogg", FMOD_2D);
    progress = 0.67932487f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/WhatThe.ogg", FMOD_3D);
    progress = 0.68016875f;
    // SFX\ROOM\POCKETDIMENSION
    progress = 0.68101263f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Enter.ogg", FMOD_2D);
    progress = 0.6818565f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Exit.ogg", FMOD_2D);
    progress = 0.6827004f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Explosion.ogg", FMOD_2D);
    progress = 0.6835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Impact.ogg", FMOD_2D);
    progress = 0.68438816f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Kneel.ogg", FMOD_2D);
    progress = 0.68523204f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/PrisonVoices.ogg", FMOD_2D);
    progress = 0.6860759f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Rumble.ogg", FMOD_2D);
    progress = 0.6869198f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Screech.ogg", FMOD_2D);
    progress = 0.6877637f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/TrenchPlane.ogg", FMOD_2D);
    progress = 0.6886076f;
    // SFX\ROOM\STOREROOM
    progress = 0.68945146f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Storeroom/Escape1.ogg", FMOD_3D);
    progress = 0.69029534f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Storeroom/Escape2.ogg", FMOD_3D);
    progress = 0.6911392f;
    // SFX\ROOM\TESLA
    progress = 0.6919831f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/Idle.ogg", FMOD_3D);
    progress = 0.692827f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/PowerUp.ogg", FMOD_3D);
    progress = 0.69367087f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/Shock.ogg", FMOD_3D);
    progress = 0.69451475f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/WindUp.ogg", FMOD_3D);
    progress = 0.69535863f;
    // SFX\ROOM
    progress = 0.6962025f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Blackout.ogg", FMOD_2D);
    progress = 0.6970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/LockroomSiren.ogg", FMOD_2D);
    progress = 0.6978903f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Room2ElevatorDeath.ogg", FMOD_2D);
    progress = 0.69873416f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Room2SL049Spawn.ogg", FMOD_2D);
    progress = 0.69957805f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Sinkhole.ogg", FMOD_2D);
    progress = 0.7004219f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/SinkholeFall.ogg", FMOD_2D);
    progress = 0.7012658f;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/TunnelBurst.ogg", FMOD_2D);
    progress = 0.7021097f;

    progress = 0.7029536f;
    // SFX\SCP
    progress = 0.70379746f;
    // SFX\SCP\008
    progress = 0.70464134f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/KillScientist0.ogg", FMOD_2D);
    progress = 0.7054852f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/KillScientist1.ogg", FMOD_2D);
    progress = 0.7063291f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices0.ogg", FMOD_2D);
    progress = 0.707173f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices1.ogg", FMOD_2D);
    progress = 0.7080169f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices2.ogg", FMOD_2D);
    progress = 0.70886075f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices3.ogg", FMOD_2D);
    progress = 0.70970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices4.ogg", FMOD_2D);
    progress = 0.7105485f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices5.ogg", FMOD_2D);
    progress = 0.7113924f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices6.ogg", FMOD_2D);
    progress = 0.7122363f;
    // SFX\SCP\008_1
    progress = 0.71308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008_1/Breath.ogg", FMOD_3D);
    progress = 0.71392405f;
    // SFX\SCP\009
    progress = 0.71476793f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/009/IceCracking.ogg", FMOD_3D);
    progress = 0.7156118f;
    // SFX\SCP\012
    progress = 0.7164557f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech1.ogg", FMOD_2D);
    progress = 0.7172996f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech2.ogg", FMOD_2D);
    progress = 0.71814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech3.ogg", FMOD_2D);
    progress = 0.71898735f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech4.ogg", FMOD_2D);
    progress = 0.7198312f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech5.ogg", FMOD_2D);
    progress = 0.7206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech6.ogg", FMOD_2D);
    progress = 0.721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech7.ogg", FMOD_2D);
    progress = 0.7223629f;
    // SFX\SCP\035
    progress = 0.72320676f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Closet1.ogg", FMOD_3D);
    progress = 0.72405064f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Closet2.ogg", FMOD_3D);
    progress = 0.7248945f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Escape.ogg", FMOD_3D);
    progress = 0.7257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Gased1.ogg", FMOD_3D);
    progress = 0.7265823f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Gased2.ogg", FMOD_3D);
    progress = 0.7274262f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedCloset.ogg", FMOD_3D);
    progress = 0.72827005f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedEscape.ogg", FMOD_3D);
    progress = 0.72911394f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedKilled1.ogg", FMOD_3D);
    progress = 0.7299578f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedKilled2.ogg", FMOD_3D);
    progress = 0.7308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedStop1.ogg", FMOD_3D);
    progress = 0.7316456f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedStop2.ogg", FMOD_3D);
    progress = 0.73248947f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GetUp.ogg", FMOD_2D);
    progress = 0.73333335f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Help1.ogg", FMOD_3D);
    progress = 0.73417723f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Help2.ogg", FMOD_3D);
    progress = 0.7350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle1.ogg", FMOD_3D);
    progress = 0.735865f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle2.ogg", FMOD_3D);
    progress = 0.7367089f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle3.ogg", FMOD_3D);
    progress = 0.73755276f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle4.ogg", FMOD_3D);
    progress = 0.73839664f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle5.ogg", FMOD_3D);
    progress = 0.7392405f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle6.ogg", FMOD_3D);
    progress = 0.7400844f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle7.ogg", FMOD_3D);
    progress = 0.7409283f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/KilledEscape.ogg", FMOD_3D);
    progress = 0.7417722f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/KilledGetUp.ogg", FMOD_2D);
    progress = 0.74261606f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/RadioHelp1.ogg", FMOD_2D);
    progress = 0.74345994f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/RadioHelp2.ogg", FMOD_2D);
    progress = 0.7443038f;
    // SFX\SCP\049
    progress = 0.7451477f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/714Equipped.ogg", FMOD_3D);
    progress = 0.7459916f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/DetectedInChamber.ogg", FMOD_3D);
    progress = 0.7468355f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Kidnap1.ogg", FMOD_3D);
    progress = 0.74767935f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Kidnap2.ogg", FMOD_3D);
    progress = 0.74852324f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Room2SL1.ogg", FMOD_3D);
    progress = 0.7493671f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Room2SL2.ogg", FMOD_3D);
    progress = 0.75021094f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching1.ogg", FMOD_3D);
    progress = 0.7510548f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching2.ogg", FMOD_3D);
    progress = 0.7518987f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching3.ogg", FMOD_3D);
    progress = 0.7527426f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching4.ogg", FMOD_3D);
    progress = 0.7535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching5.ogg", FMOD_3D);
    progress = 0.75443035f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching6.ogg", FMOD_3D);
    progress = 0.75527424f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching7.ogg", FMOD_3D);
    progress = 0.7561181f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted1.ogg", FMOD_3D);
    progress = 0.756962f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted2.ogg", FMOD_3D);
    progress = 0.7578059f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted3.ogg", FMOD_3D);
    progress = 0.75864977f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted4.ogg", FMOD_3D);
    progress = 0.75949365f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted5.ogg", FMOD_3D);
    progress = 0.76033753f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted6.ogg", FMOD_3D);
    progress = 0.7611814f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted7.ogg", FMOD_3D);
    progress = 0.7620253f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step1.ogg", FMOD_3D);
    progress = 0.7628692f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step2.ogg", FMOD_3D);
    progress = 0.76371306f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step3.ogg", FMOD_3D);
    progress = 0.76455694f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/TakeOffHazmat.ogg", FMOD_3D);
    progress = 0.7654008f;
    // SFX\SCP\049_2
    progress = 0.7662447f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049_2/Breath.ogg", FMOD_3D);
    progress = 0.7670886f;
    // SFX\SCP\066
    progress = 0.7679325f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Beethoven.ogg", FMOD_2D);
    progress = 0.76877636f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric1.ogg", FMOD_3D);
    progress = 0.76962024f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric2.ogg", FMOD_3D);
    progress = 0.7704641f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric3.ogg", FMOD_3D);
    progress = 0.771308f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes1.ogg", FMOD_3D);
    progress = 0.7721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes2.ogg", FMOD_3D);
    progress = 0.77299577f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes4.ogg", FMOD_3D);
    progress = 0.77383965f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes5.ogg", FMOD_3D);
    progress = 0.77468354f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes6.ogg", FMOD_3D);
    progress = 0.7755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Rolling.ogg", FMOD_3D);
    progress = 0.7763713f;
    // SFX\SCP\079
    progress = 0.7772152f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast1.ogg", FMOD_2D);
    progress = 0.77805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast2.ogg", FMOD_2D);
    progress = 0.77890295f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast3.ogg", FMOD_2D);
    progress = 0.77974683f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast4.ogg", FMOD_2D);
    progress = 0.7805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast5.ogg", FMOD_2D);
    progress = 0.7814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast6.ogg", FMOD_2D);
    progress = 0.7822785f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast7.ogg", FMOD_2D);
    progress = 0.78312236f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast8.ogg", FMOD_2D);
    progress = 0.78396624f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/GateB.ogg", FMOD_2D);
    progress = 0.7848101f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Refuse.ogg", FMOD_3D);
    progress = 0.785654f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Speech.ogg", FMOD_3D);
    progress = 0.7864979f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/TestroomWarning.ogg", FMOD_2D);
    progress = 0.7873418f;
    // SFX\SCP\096
    progress = 0.78818566f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/ElevatorSlam.ogg", FMOD_2D);
    progress = 0.78902954f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/Scream.ogg", FMOD_3D);
    progress = 0.7898734f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/Triggered.ogg", FMOD_2D);
    progress = 0.7907173f;
    // SFX\SCP\106
    progress = 0.7915612f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Breathing.ogg", FMOD_3D);
    progress = 0.79240507f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion1.ogg", FMOD_3D);
    progress = 0.79324895f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion2.ogg", FMOD_3D);
    progress = 0.79409283f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion3.ogg", FMOD_3D);
    progress = 0.7949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay0.ogg", FMOD_3D);
    progress = 0.7957806f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay2.ogg", FMOD_3D);
    progress = 0.7966245f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay3.ogg", FMOD_3D);
    progress = 0.79746836f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Laugh.ogg", FMOD_2D);
    progress = 0.79831225f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Laugh2.ogg", FMOD_2D);
    progress = 0.7991561f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay1.ogg", FMOD_3D);
    progress = 0.8f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay2.ogg", FMOD_3D);
    progress = 0.8008439f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay3.ogg", FMOD_3D);
    progress = 0.8016878f;
    // SFX\SCP\109
    progress = 0.80253166f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/109/Ahh.ogg", FMOD_2D);
    progress = 0.80337554f;
    // SFX\SCP\173
    progress = 0.8042194f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap1.ogg", FMOD_2D);
    progress = 0.8050633f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap2.ogg", FMOD_2D);
    progress = 0.8059072f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap3.ogg", FMOD_2D);
    progress = 0.8067511f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle1.ogg", FMOD_3D);
    progress = 0.80759495f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle2.ogg", FMOD_3D);
    progress = 0.80843884f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle3.ogg", FMOD_3D);
    progress = 0.8092827f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/StoneDrag.ogg", FMOD_3D);
    progress = 0.8101266f;
    // SFX\SCP\198
    progress = 0.8109705f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/198/Shock.ogg", FMOD_2D);
    progress = 0.81181437f;
    // SFX\SCP\205
    progress = 0.81265825f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/205/Enter.ogg", FMOD_2D);
    progress = 0.81350213f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/205/Horror.ogg", FMOD_2D);
    progress = 0.814346f;
    // SFX\SCP\215
    progress = 0.8151899f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/215/Whisper.ogg", FMOD_2D);
    progress = 0.8160338f;
    // SFX\SCP\294
    progress = 0.81687766f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ahh.ogg", FMOD_2D);
    progress = 0.81772155f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Burn.ogg", FMOD_2D);
    progress = 0.8185654f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Coin_Drop.ogg", FMOD_3D);
    progress = 0.8194093f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Cough.ogg", FMOD_2D);
    progress = 0.8202532f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense0.ogg", FMOD_3D);
    progress = 0.8210971f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense1.ogg", FMOD_3D);
    progress = 0.8219409f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense2.ogg", FMOD_3D);
    progress = 0.8227848f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense3.ogg", FMOD_3D);
    progress = 0.82362866f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ew1.ogg", FMOD_2D);
    progress = 0.82447255f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ew2.ogg", FMOD_2D);
    progress = 0.8253164f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/OutOfRange.ogg", FMOD_3D);
    progress = 0.8261603f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Retch1.ogg", FMOD_2D);
    progress = 0.8270042f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Retch2.ogg", FMOD_2D);
    progress = 0.8278481f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Slurp.ogg", FMOD_2D);
    progress = 0.82869196f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Spit.ogg", FMOD_2D);
    progress = 0.82953584f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Vomit.ogg", FMOD_2D);
    progress = 0.8303797f;
    // SFX\SCP\372
    progress = 0.8312236f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle0.ogg", FMOD_2D);
    progress = 0.8320675f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle1.ogg", FMOD_2D);
    progress = 0.8329114f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle2.ogg", FMOD_2D);
    progress = 0.83375525f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle3.ogg", FMOD_2D);
    progress = 0.83459914f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle4.ogg", FMOD_2D);
    progress = 0.835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle5.ogg", FMOD_2D);
    progress = 0.8362869f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle6.ogg", FMOD_2D);
    progress = 0.8371308f;
    // SFX\SCP\427
    progress = 0.83797467f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/427/Effect.ogg", FMOD_2D);
    progress = 0.83881855f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/427/Transform.ogg", FMOD_2D);
    progress = 0.83966243f;
    // SFX\SCP\457
    progress = 0.8405063f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/457/FireLoop.ogg", FMOD_3D);
    progress = 0.8413502f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/457/Sighting.ogg", FMOD_2D);
    progress = 0.8421941f;
    // SFX\SCP\513
    progress = 0.84303796f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/914Refine.ogg", FMOD_3D);
    progress = 0.84388185f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell1.ogg", FMOD_2D);
    progress = 0.8447257f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell2.ogg", FMOD_2D);
    progress = 0.8455696f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell3.ogg", FMOD_2D);
    progress = 0.8464135f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell4.ogg", FMOD_2D);
    progress = 0.8472574f;
    // SFX\SCP\682
    progress = 0.84810126f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/682/Roar.ogg", FMOD_2D);
    progress = 0.84894514f;
    // SFX\SCP\789
    progress = 0.849789f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/789/butt.ogg", FMOD_3D);
    progress = 0.8506329f;
    // SFX\SCP\860
    progress = 0.8514768f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer0.ogg", FMOD_2D);
    progress = 0.8523207f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer1.ogg", FMOD_2D);
    progress = 0.85316455f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer2.ogg", FMOD_2D);
    progress = 0.85400844f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer3.ogg", FMOD_2D);
    progress = 0.8548523f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer4.ogg", FMOD_2D);
    progress = 0.8556962f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer5.ogg", FMOD_2D);
    progress = 0.8565401f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Chase1.ogg", FMOD_2D);
    progress = 0.85738397f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Chase2.ogg", FMOD_2D);
    progress = 0.85822785f;
    // SFX\SCP\914
    progress = 0.85907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/DoorClose.ogg", FMOD_3D);
    progress = 0.8599156f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/DoorOpen.ogg", FMOD_3D);
    progress = 0.8607595f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/PlayerDeath.ogg", FMOD_2D);
    progress = 0.8616034f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/PlayerUse.ogg", FMOD_2D);
    progress = 0.86244726f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/Refining.ogg", FMOD_3D);
    progress = 0.86329114f;
    // SFX\SCP\939
    progress = 0.864135f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert1.ogg", FMOD_3D);
    progress = 0.8649789f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert2.ogg", FMOD_3D);
    progress = 0.8658228f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert3.ogg", FMOD_3D);
    progress = 0.8666667f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack1.ogg", FMOD_3D);
    progress = 0.86751056f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack2.ogg", FMOD_3D);
    progress = 0.86835444f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack3.ogg", FMOD_3D);
    progress = 0.8691983f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure1.ogg", FMOD_3D);
    progress = 0.8700422f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure2.ogg", FMOD_3D);
    progress = 0.8708861f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure3.ogg", FMOD_3D);
    progress = 0.87172997f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure4.ogg", FMOD_3D);
    progress = 0.87257385f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure5.ogg", FMOD_3D);
    progress = 0.87341774f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure6.ogg", FMOD_3D);
    progress = 0.8742616f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure7.ogg", FMOD_3D);
    progress = 0.8751055f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure8.ogg", FMOD_3D);
    progress = 0.8759494f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure9.ogg", FMOD_3D);
    progress = 0.87679327f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure10.ogg", FMOD_3D);
    progress = 0.87763715f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert1.ogg", FMOD_3D);
    progress = 0.87848103f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert2.ogg", FMOD_3D);
    progress = 0.8793249f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert3.ogg", FMOD_3D);
    progress = 0.8801688f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack1.ogg", FMOD_3D);
    progress = 0.8810127f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack2.ogg", FMOD_3D);
    progress = 0.88185656f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack3.ogg", FMOD_3D);
    progress = 0.88270044f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure1.ogg", FMOD_3D);
    progress = 0.8835443f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure2.ogg", FMOD_3D);
    progress = 0.8843882f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure3.ogg", FMOD_3D);
    progress = 0.8852321f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure4.ogg", FMOD_3D);
    progress = 0.886076f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure5.ogg", FMOD_3D);
    progress = 0.88691986f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure6.ogg", FMOD_3D);
    progress = 0.88776374f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure7.ogg", FMOD_3D);
    progress = 0.8886076f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure8.ogg", FMOD_3D);
    progress = 0.8894515f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure9.ogg", FMOD_3D);
    progress = 0.8902954f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure10.ogg", FMOD_3D);
    progress = 0.89113927f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert1.ogg", FMOD_3D);
    progress = 0.89198315f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert2.ogg", FMOD_3D);
    progress = 0.89282703f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert3.ogg", FMOD_3D);
    progress = 0.89367086f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack1.ogg", FMOD_3D);
    progress = 0.89451474f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack2.ogg", FMOD_3D);
    progress = 0.8953586f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack3.ogg", FMOD_3D);
    progress = 0.8962025f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure1.ogg", FMOD_3D);
    progress = 0.8970464f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure2.ogg", FMOD_3D);
    progress = 0.89789027f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure3.ogg", FMOD_3D);
    progress = 0.89873415f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure4.ogg", FMOD_3D);
    progress = 0.89957803f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure5.ogg", FMOD_3D);
    progress = 0.9004219f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure6.ogg", FMOD_3D);
    progress = 0.9012658f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure7.ogg", FMOD_3D);
    progress = 0.9021097f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure8.ogg", FMOD_3D);
    progress = 0.90295357f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure9.ogg", FMOD_3D);
    progress = 0.90379745f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure10.ogg", FMOD_3D);
    progress = 0.90464133f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure11.ogg", FMOD_3D);
    progress = 0.9054852f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/Attack.ogg", FMOD_2D);
    progress = 0.9063291f;
    // SFX\SCP\966
    progress = 0.907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo1.ogg", FMOD_2D);
    progress = 0.90801686f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo2.ogg", FMOD_2D);
    progress = 0.90886074f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo3.ogg", FMOD_2D);
    progress = 0.9097046f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle1.ogg", FMOD_2D);
    progress = 0.9105485f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle2.ogg", FMOD_2D);
    progress = 0.9113924f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle3.ogg", FMOD_2D);
    progress = 0.9122363f;
    // SFX\SCP\970
    progress = 0.91308016f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/970/Corpse.ogg", FMOD_2D);
    progress = 0.91392404f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/970/FCVENY.ogg", FMOD_2D);
    progress = 0.9147679f;
    // SFX\SCP\990
    progress = 0.9156118f;
    /// ALREADY LOADED BY LOADING SCREEN AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm1.ogg", FMOD_2D);
    progress = 0.9164557f;
    /// ALREADY LOADED BY LOADING SCREEN AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm2.ogg", FMOD_2D);
    progress = 0.91729957f;
    // SFX\SCP\1033RU
    progress = 0.91814345f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage0.ogg", FMOD_2D);
    progress = 0.91898733f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage1.ogg", FMOD_2D);
    progress = 0.9198312f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage2.ogg", FMOD_2D);
    progress = 0.9206751f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage3.ogg", FMOD_2D);
    progress = 0.921519f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/SCPDeath.ogg", FMOD_2D);
    progress = 0.92236286f;
    // SFX\SCP\1048A
    progress = 0.92320675f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1048A/Growth.ogg", FMOD_2D);
    progress = 0.9240506f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1048A/Shriek.ogg", FMOD_3D);
    progress = 0.9248945f;
    // SFX\SCP\1079
    progress = 0.9257384f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1079/BubbleSizz0.ogg", FMOD_2D);
    progress = 0.9265823f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1079/BubbleSizz1.ogg", FMOD_2D);
    progress = 0.92742616f;
    // SFX\SCP\1123
    progress = 0.92827004f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Ambient.ogg", FMOD_2D);
    progress = 0.9291139f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Gunshot.ogg", FMOD_3D);
    progress = 0.9299578f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Horror.ogg", FMOD_2D);
    progress = 0.9308017f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer1.ogg", FMOD_3D);
    progress = 0.9316456f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer2.ogg", FMOD_3D);
    progress = 0.93248945f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer3.ogg", FMOD_3D);
    progress = 0.93333334f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Touch.ogg", FMOD_2D);
    progress = 0.9341772f;
    // SFX\SCP\1162
    progress = 0.9350211f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange1.ogg", FMOD_3D);
    progress = 0.935865f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange2.ogg", FMOD_3D);
    progress = 0.93670887f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange3.ogg", FMOD_3D);
    progress = 0.93755275f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange4.ogg", FMOD_3D);
    progress = 0.93839663f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange0.ogg", FMOD_3D);
    progress = 0.9392405f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange1.ogg", FMOD_3D);
    progress = 0.9400844f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange2.ogg", FMOD_3D);
    progress = 0.9409283f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange3.ogg", FMOD_3D);
    progress = 0.94177216f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange4.ogg", FMOD_3D);
    progress = 0.94261605f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer1.ogg", FMOD_2D);
    progress = 0.9434599f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer2.ogg", FMOD_2D);
    progress = 0.9443038f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer3.ogg", FMOD_2D);
    progress = 0.9451477f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer4.ogg", FMOD_2D);
    progress = 0.9459916f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer5.ogg", FMOD_2D);
    progress = 0.94683546f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer6.ogg", FMOD_2D);
    progress = 0.94767934f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer7.ogg", FMOD_2D);
    progress = 0.9485232f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer8.ogg", FMOD_2D);
    progress = 0.9493671f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer9.ogg", FMOD_2D);
    progress = 0.950211f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer10.ogg", FMOD_2D);
    progress = 0.9510549f;
    // SFX\SCP\1499
    progress = 0.95189875f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Enter.ogg", FMOD_2D);
    progress = 0.95274264f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Exit.ogg", FMOD_2D);
    progress = 0.9535865f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle1.ogg", FMOD_2D);
    progress = 0.9544304f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle2.ogg", FMOD_2D);
    progress = 0.9552743f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle3.ogg", FMOD_2D);
    progress = 0.95611817f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle4.ogg", FMOD_2D);
    progress = 0.95696205f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Triggered.ogg", FMOD_2D);
    progress = 0.95780593f;
    // SFX\SCP\Joke
    progress = 0.9586498f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/789J.ogg", FMOD_2D);
    progress = 0.9594937f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/Quack.ogg", FMOD_3D);
    progress = 0.9603376f;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/Saxophone.ogg", FMOD_3D);
    progress = 0.96118146f;

    progress = 0.96202534f;
    // SFX\Step
    progress = 0.9628692f;
    // SFX\Step\SCP
    progress = 0.9637131f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP1.ogg", FMOD_3D);
    progress = 0.96455693f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP2.ogg", FMOD_3D);
    progress = 0.9654008f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP3.ogg", FMOD_3D);
    progress = 0.9662447f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP4.ogg", FMOD_3D);
    progress = 0.9670886f;
    // SFX\Step
    progress = 0.96793246f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run1.ogg", FMOD_2D);
    progress = 0.96877635f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run2.ogg", FMOD_2D);
    progress = 0.9696202f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run3.ogg", FMOD_2D);
    progress = 0.9704641f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run4.ogg", FMOD_2D);
    progress = 0.971308f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run5.ogg", FMOD_2D);
    progress = 0.9721519f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run6.ogg", FMOD_2D);
    progress = 0.97299576f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run7.ogg", FMOD_2D);
    progress = 0.97383964f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run8.ogg", FMOD_2D);
    progress = 0.9746835f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal1.ogg", FMOD_2D);
    progress = 0.9755274f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal2.ogg", FMOD_2D);
    progress = 0.9763713f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal3.ogg", FMOD_2D);
    progress = 0.9772152f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal4.ogg", FMOD_2D);
    progress = 0.97805905f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal5.ogg", FMOD_2D);
    progress = 0.97890294f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal6.ogg", FMOD_2D);
    progress = 0.9797468f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal7.ogg", FMOD_2D);
    progress = 0.9805907f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal8.ogg", FMOD_2D);
    progress = 0.9814346f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step1.ogg", FMOD_2D);
    progress = 0.98227847f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step2.ogg", FMOD_2D);
    progress = 0.98312235f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step3.ogg", FMOD_2D);
    progress = 0.98396623f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step4.ogg", FMOD_2D);
    progress = 0.9848101f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step5.ogg", FMOD_2D);
    progress = 0.985654f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step6.ogg", FMOD_2D);
    progress = 0.9864979f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step7.ogg", FMOD_2D);
    progress = 0.98734176f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step8.ogg", FMOD_2D);
    progress = 0.98818564f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest1.ogg", FMOD_2D);
    progress = 0.9890295f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest2.ogg", FMOD_2D);
    progress = 0.9898734f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest3.ogg", FMOD_2D);
    progress = 0.9907173f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal1.ogg", FMOD_2D);
    progress = 0.9915612f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal2.ogg", FMOD_2D);
    progress = 0.99240506f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal3.ogg", FMOD_2D);
    progress = 0.99324894f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal4.ogg", FMOD_2D);
    progress = 0.9940928f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal5.ogg", FMOD_2D);
    progress = 0.9949367f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal6.ogg", FMOD_2D);
    progress = 0.9957806f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal7.ogg", FMOD_2D);
    progress = 0.99662447f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal8.ogg", FMOD_2D);
    progress = 0.99746835f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD1.ogg", FMOD_2D);
    progress = 0.99831223f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD2.ogg", FMOD_2D);
    progress = 0.9991561f;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD3.ogg", FMOD_2D);
    progress = 1.0f;
}

float PreloadManager::ProcessPreload() {
    if (!preloadStarted) {
        std::thread(ProcessPreloadThread).detach();
        preloadStarted = true;
    }

    return progress;
}

enum LoadingScreenImagePosition {
    TopLeft,
    TopCenter,
    TopRight,
    CenterLeft,
    CenterCenter,
    CenterRight,
    BottomLeft,
    BottomCenter,
    BottomRight
};

bool disableBackground = false;
Util::Image::Image* loadingScreenBackgroundImage = nullptr;
Util::Image::Image* loadingScreenImage = nullptr;
LoadingScreenImagePosition loadingScreenImagePosition;
std::string title;
std::string currentText;
std::vector<std::string> text;

void PreloadManager::Init() {
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm1.ogg", FMOD_2D);
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm2.ogg", FMOD_2D);
    
    toml::parse_result parsedToml;
    try {
        parsedToml = toml::parse_file("Assets/LoadingScreens/LoadingScreens.ini");
    } catch (toml::ex::parse_error& error) {
        Util::Error::Exit(std::string(error.what()) + " " + std::to_string(error.source().begin.line));
    }

    std::vector<std::string> loadingScreenOptions;
    toml::array* loadingScreenOptionsArray = parsedToml["Config"]["LoadingScreens"].as_array();
    for (size_t i = 0; i < loadingScreenOptionsArray->size(); i++) {
        loadingScreenOptions.push_back(loadingScreenOptionsArray->get(i)->as_string()->get());
    }

    title = loadingScreenOptions.at(Util::Math::RandomInt(0, loadingScreenOptions.size() - 1));
    
    const std::string texture = parsedToml[title]["Texture"].value_exact<std::string>().value();
    const std::string alignX = parsedToml[title]["AlignX"].value_exact<std::string>().value();
    const std::string alignY = parsedToml[title]["AlignY"].value_exact<std::string>().value();

    if (alignY == "Top") {
        if (alignX == "Left") {
            loadingScreenImagePosition = TopLeft;
        } else if (alignX == "Center") {
            loadingScreenImagePosition = TopCenter;
        } else if (alignX == "Right") {
            loadingScreenImagePosition = TopRight;
        }
    } else if (alignY == "Center") {
        if (alignX == "Left") {
            loadingScreenImagePosition = CenterLeft;
        } else if (alignX == "Center") {
            loadingScreenImagePosition = CenterCenter;
        } else if (alignX == "Right") {
            loadingScreenImagePosition = CenterRight;
        }
    } else if (alignY == "Bottom") {
        if (alignX == "Left") {
            loadingScreenImagePosition = BottomLeft;
        } else if (alignX == "Center") {
            loadingScreenImagePosition = BottomCenter;
        } else if (alignX == "Right") {
            loadingScreenImagePosition = BottomRight;
        }
    }
    
    if (parsedToml[title]["DisableBackground"].is_boolean()) {
        disableBackground = parsedToml[title]["DisableBackground"].value_exact<bool>().value();
    }
    
    if (parsedToml[title]["Text1"].is_string()) {
        text.push_back(Localization::GetTranslatedKey("LoadingScreens", parsedToml[title]["Text1"].value_exact<std::string>().value()));
    }
    
    if (parsedToml[title]["Text2"].is_string()) {
        text.push_back(Localization::GetTranslatedKey("LoadingScreens", parsedToml[title]["Text2"].value_exact<std::string>().value()));
    }
    
    if (parsedToml[title]["Text3"].is_string()) {
        text.push_back(Localization::GetTranslatedKey("LoadingScreens", parsedToml[title]["Text3"].value_exact<std::string>().value()));
    }
    
    if (parsedToml[title]["Text4"].is_string()) {
        text.push_back(Localization::GetTranslatedKey("LoadingScreens", parsedToml[title]["Text4"].value_exact<std::string>().value()));
    }

    if (!disableBackground) {
        loadingScreenBackgroundImage = new Util::Image::Image;
        if (!LoadImageFromFile("Assets/LoadingScreens/loadingback.png", loadingScreenBackgroundImage)) {
            Util::Error::Exit("The texture \"Assets\\LoadingScreens\\loadingback.png\" failed to load. Ensure the file exists, or verify your game files.");
        }
    }

    loadingScreenImage = new Util::Image::Image;
    if (!LoadImageFromFile("Assets/LoadingScreens/" + texture, loadingScreenImage)) {
        Util::Error::Exit("The texture \"Assets\\LoadingScreens\\" + texture + "\" failed to load. Ensure the file exists, or verify your game files.");
    }

    if (title == "CWM") {
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "fineradio"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "burn"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "cannotcontrol"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "trust"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "question1"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "jorge"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "question2"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "midnight"));
        text.emplace_back(Localization::GetTranslatedKey("LoadingScreens", "alloylife"));
    }
}

bool cyclingTextStarted = false;

void cycleTextThread() {
    int time = 13000;
    if (title == "CWM") {
        time = 0;
    }
    
    cyclingTextStarted = true;
    while (cyclingTextStarted) {
        for (const std::string& string : text) {
            currentText = string;
            Sleep(time);
        }
    }
}

FMOD::Channel* cwm1Channel;

void PreloadManager::Render(GLFWwindow* window, GlobalGameState* gameState) {
    try {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        
        if (title == "CWM") {
            static bool cwmInitPlayed = false;
            if (!cwmInitPlayed) {
                cwmInitPlayed = true;

                cwm1Channel = AudioEngine::PlaySoundByName("Assets/SFX/SCP/990/cwm1.ogg", AudioEngine::GetChannelGroup("Game"));
            }

            static bool cwmFinalPlayed = false;
            if (!cwmFinalPlayed && progress == 1) {
                cwmFinalPlayed = true;

                if (AudioEngine::IsSoundPlaying(cwm1Channel)) {
                    AudioEngine::StopSound(cwm1Channel);
                }
                
                AudioEngine::PlaySoundByName("Assets/SFX/SCP/990/cwm2.ogg", AudioEngine::GetChannelGroup("Game"));
            }
        }

        // RENDER LOADING SCREEN IMAGE
        {
            int targetSize = height / 1.75f;
            ImVec2 position = ImVec2(0, 0);
            ImVec2 pivotPoint = ImVec2(0, 0);
            
            switch (loadingScreenImagePosition) {
                case TopLeft: {
                    position = ImVec2(0, 0);
                    pivotPoint = ImVec2(0, 0);
                    break;
                }
                case TopCenter: {
                    position = ImVec2((width / 2.0f), 0);
                    pivotPoint = ImVec2(0.5f, 0);
                    break;
                }
                case TopRight: {
                    position = ImVec2(width, 0);
                    pivotPoint = ImVec2(1, 0);
                    break;
                }
                case CenterLeft: {
                    position = ImVec2(0, height / 2.0f);
                    pivotPoint = ImVec2(0, 0.5f);
                    break;
                }
                case CenterCenter: {
                    position = ImVec2(width / 2.0f, height / 2.0f);
                    pivotPoint = ImVec2(0.5f, 0.5f);
                    break;
                }
                case CenterRight: {
                    position = ImVec2(width, height / 2.0f);
                    pivotPoint = ImVec2(1, 0.5f);
                    break;
                }
                case BottomLeft: {
                    position = ImVec2(0, height);
                    pivotPoint = ImVec2(0, 1);
                    break;
                }
                case BottomCenter: {
                    position = ImVec2(width / 2.0f, height);
                    pivotPoint = ImVec2(0.5, 1);
                    break;
                }
                case BottomRight: {
                    position = ImVec2(width, height);
                    pivotPoint = ImVec2(1, 1);
                    break;
                }
            }

            ImGui::SetNextWindowPos(position, 0, pivotPoint);
            ImGui::SetNextWindowSize(ImVec2(targetSize, targetSize));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## LOADINGSCREEN-IMAGE", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            ImGui::SetCursorPos(ImVec2(0, 0));
            ImGui::Image(reinterpret_cast<void*>(loadingScreenImage->TextureId), ImVec2(targetSize, targetSize));
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        }
        
        // RENDER BACKGROUND IMAGE
        if (!disableBackground && loadingScreenBackgroundImage) {
            int targetSize = height / 2;

            ImGui::SetNextWindowSize(ImVec2(targetSize, targetSize));
            ImGui::SetNextWindowPos(ImVec2(width / 2.0f, height / 2.0f), 0, ImVec2(0.5, 0.5));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## BACKGROUND-IMAGE", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            ImGui::SetCursorPos(ImVec2(0, 0));
            ImGui::Image(reinterpret_cast<void*>(loadingScreenBackgroundImage->TextureId), ImVec2(targetSize, targetSize));
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        // RENDER PROGRESS, TITLE, TEXT
        {
            ImVec2 targetSize = ImVec2(Util::Math::ClampMin(static_cast<float>(width) / 3.0f, 750.0f), Util::Math::ClampMin(static_cast<float>(height) / 1.5f, 600.0f));
            
            ImGui::SetNextWindowSize(targetSize);
            ImGui::SetNextWindowPos(ImVec2(width / 2.0f, height / 2.0f), 0, ImVec2(0.5, 0.5));
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::Begin("## PROGRESS-TITLE-TEXT", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.5f);
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 1));
            ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 1));
            ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.827f, 0, 0, 1));
            ImGui::SetCursorPosX(5);
            ImGui::ProgressBar(ProcessPreload(), ImVec2(targetSize.x - 10, 0));
            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();

            ImGui::Dummy(ImVec2(0, 50.0f));

            ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(1, 1, 1, 1));
            ImGui::PushStyleVar(ImGuiStyleVar_SeparatorTextAlign, ImVec2(0.5f, 0.5f));
            ImGui::PushFont(Localization::GetActiveLanguageCourierNewLarge());
            ImGui::SeparatorText(title.c_str());
            ImGui::PopFont();
            ImGui::PopStyleVar();
            ImGui::PopStyleColor();

            ImGui::Dummy(ImVec2(0, 20.0f));

            if (!cyclingTextStarted) {
                std::thread(cycleTextThread).detach();
            }

            if (!currentText.empty()) {
                ImGui::TextWrappedCentered(currentText.c_str());
            }
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        }

        // PRESS SPACE TO CONTINUE; PRELOAD COMPLETE
        if (progress >= 1) {
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
            ImGui::SetNextWindowSize(ImVec2(width, 30));
            ImGui::SetNextWindowPos(ImVec2(0, height - 50));
            ImGui::Begin("## PRELOAD-FINISHED", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            ImGui::TextCentered(Localization::GetTranslatedKey("LoadingScreens", "anykey").c_str());

            if (glfwGetKey(window, GLFW_KEY_SPACE)) {
                *gameState = GlobalGameState::MainMenu;

                cyclingTextStarted = false;

                AudioEngine::PlaySoundByName("Assets\\SFX\\Splash\\Button.ogg", AudioEngine::GetChannelGroup("Game"));
            }
            
            ImGui::End();
            ImGui::PopStyleColor(2);
        }
    } catch (...) {
        // IGNORE, GO TO NEXT FRAME
    }
}

void PreloadManager::Free() {
    if (!disableBackground) {
        delete loadingScreenBackgroundImage;
    }
    delete loadingScreenImage;
}