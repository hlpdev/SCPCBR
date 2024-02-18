#include "PreloadManager.h"

#include <thread>
#include <Windows.h>
#include <toml.hpp>

#include "../AudioEngine/AudioEngine.h"
#include "../Localization/Localization.h"
#include "../Util/Util.h"
#include "imgui/imgui.h"
#include "..\Dependencies\include\imgui\imgui_custom.h"

bool preloadStarted = false;
float progress = 0;

void ProcessPreloadThread() {
        // SFX\ALARM
    progress = 0.00084388186;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm.ogg", FMOD_2D);
    progress = 0.0016877637;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2.ogg", FMOD_2D);
    progress = 0.0025316456;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_1.ogg", FMOD_2D);
    progress = 0.0033755274;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_2.ogg", FMOD_2D);
    progress = 0.004219409;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_3.ogg", FMOD_2D);
    progress = 0.005063291;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_4.ogg", FMOD_2D);
    progress = 0.005907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_5.ogg", FMOD_2D);
    progress = 0.006751055;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_6.ogg", FMOD_2D);
    progress = 0.0075949365;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_7.ogg", FMOD_2D);
    progress = 0.008438818;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_8.ogg", FMOD_2D);
    progress = 0.009282701;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_9.ogg", FMOD_2D);
    progress = 0.010126582;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_10.ogg", FMOD_2D);
    progress = 0.010970464;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm2_11.ogg", FMOD_2D);
    progress = 0.011814346;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm3.ogg", FMOD_2D);
    progress = 0.012658228;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm4.ogg", FMOD_3D);
    progress = 0.01350211;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm5.ogg", FMOD_3D);
    progress = 0.014345991;
    AudioEngine::LoadSoundByName("Assets/SFX/Alarm/Alarm6.ogg", FMOD_3D);
    progress = 0.015189873;

    progress = 0.016033756;
    // SFX\AMBIENT
    progress = 0.016877636;
    // SFX\AMBIENT\FOREST
    progress = 0.017721519;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient1.ogg", FMOD_2D);
    progress = 0.018565401;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient2.ogg", FMOD_2D);
    progress = 0.019409282;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient3.ogg", FMOD_2D);
    progress = 0.020253165;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient4.ogg", FMOD_2D);
    progress = 0.021097047;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient5.ogg", FMOD_2D);
    progress = 0.021940928;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient6.ogg", FMOD_2D);
    progress = 0.02278481;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient7.ogg", FMOD_2D);
    progress = 0.023628691;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient8.ogg", FMOD_2D);
    progress = 0.024472574;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient9.ogg", FMOD_2D);
    progress = 0.025316456;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient10.ogg", FMOD_2D);
    progress = 0.026160337;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient11.ogg", FMOD_2D);
    progress = 0.02700422;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient12.ogg", FMOD_2D);
    progress = 0.027848102;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Forest/Ambient13.ogg", FMOD_2D);
    progress = 0.028691983;
    // SFX\AMBIENT\GENERAL
    progress = 0.029535865;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient1.ogg", FMOD_2D);
    progress = 0.030379746;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient2.ogg", FMOD_2D);
    progress = 0.031223629;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient3.ogg", FMOD_2D);
    progress = 0.03206751;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient4.ogg", FMOD_2D);
    progress = 0.032911394;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient5.ogg", FMOD_2D);
    progress = 0.033755273;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient6.ogg", FMOD_2D);
    progress = 0.034599155;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient7.ogg", FMOD_2D);
    progress = 0.035443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient8.ogg", FMOD_2D);
    progress = 0.03628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient9.ogg", FMOD_2D);
    progress = 0.037130803;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient10.ogg", FMOD_2D);
    progress = 0.03797468;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient11.ogg", FMOD_2D);
    progress = 0.038818564;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient12.ogg", FMOD_2D);
    progress = 0.039662447;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/General/Ambient13.ogg", FMOD_2D);
    progress = 0.04050633;
    // SFX\AMBIENT\PRE-BREACH
    progress = 0.041350212;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient1.ogg", FMOD_2D);
    progress = 0.042194095;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient2.ogg", FMOD_2D);
    progress = 0.043037973;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient3.ogg", FMOD_2D);
    progress = 0.043881856;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient4.ogg", FMOD_2D);
    progress = 0.04472574;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Pre-breach/Ambient5.ogg", FMOD_2D);
    progress = 0.04556962;
    // SFX\AMBIENT\ROOM AMBIENCE
    progress = 0.046413504;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/895.ogg", FMOD_2D);
    progress = 0.047257382;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Drip.ogg", FMOD_2D);
    progress = 0.048101265;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Drips.ogg", FMOD_2D);
    progress = 0.048945148;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Fan.ogg", FMOD_2D);
    progress = 0.04978903;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FanOff.ogg", FMOD_2D);
    progress = 0.050632913;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FanOn.ogg", FMOD_2D);
    progress = 0.05147679;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Feuer.ogg", FMOD_2D);
    progress = 0.052320674;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/FuelPump.ogg", FMOD_2D);
    progress = 0.053164557;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/LowDrone.ogg", FMOD_2D);
    progress = 0.05400844;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Pulsing.ogg", FMOD_2D);
    progress = 0.05485232;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Servers1.ogg", FMOD_2D);
    progress = 0.055696204;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Room ambience/Ventilation.ogg", FMOD_2D);
    progress = 0.056540083;
    // SFX\AMBIENT\ZONE1
    progress = 0.057383966;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient1.ogg", FMOD_2D);
    progress = 0.05822785;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient2.ogg", FMOD_2D);
    progress = 0.05907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient3.ogg", FMOD_2D);
    progress = 0.059915613;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient4.ogg", FMOD_2D);
    progress = 0.060759492;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient5.ogg", FMOD_2D);
    progress = 0.061603375;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient6.ogg", FMOD_2D);
    progress = 0.062447257;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient7.ogg", FMOD_2D);
    progress = 0.06329114;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient8.ogg", FMOD_2D);
    progress = 0.06413502;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient9.ogg", FMOD_2D);
    progress = 0.064978905;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient10.ogg", FMOD_2D);
    progress = 0.06582279;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient11.ogg", FMOD_2D);
    progress = 0.06666667;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient12.ogg", FMOD_2D);
    progress = 0.067510545;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient13.ogg", FMOD_2D);
    progress = 0.06835443;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient14.ogg", FMOD_2D);
    progress = 0.06919831;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient15.ogg", FMOD_2D);
    progress = 0.07004219;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient16.ogg", FMOD_2D);
    progress = 0.070886075;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient17.ogg", FMOD_2D);
    progress = 0.07172996;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient18.ogg", FMOD_2D);
    progress = 0.07257384;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient19.ogg", FMOD_2D);
    progress = 0.07341772;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient20.ogg", FMOD_2D);
    progress = 0.074261606;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient21.ogg", FMOD_2D);
    progress = 0.07510549;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient22.ogg", FMOD_2D);
    progress = 0.07594936;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient23.ogg", FMOD_2D);
    progress = 0.076793246;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient24.ogg", FMOD_2D);
    progress = 0.07763713;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone1/Ambient25.ogg", FMOD_2D);
    progress = 0.07848101;
    // SFX\AMBIENT\ZONE2
    progress = 0.07932489;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient1.ogg", FMOD_2D);
    progress = 0.080168776;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient2.ogg", FMOD_2D);
    progress = 0.08101266;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient3.ogg", FMOD_2D);
    progress = 0.08185654;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient4.ogg", FMOD_2D);
    progress = 0.082700424;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient5.ogg", FMOD_2D);
    progress = 0.08354431;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient6.ogg", FMOD_2D);
    progress = 0.08438819;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient7.ogg", FMOD_2D);
    progress = 0.085232064;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient8.ogg", FMOD_2D);
    progress = 0.08607595;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient9.ogg", FMOD_2D);
    progress = 0.08691983;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient10.ogg", FMOD_2D);
    progress = 0.08776371;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient11.ogg", FMOD_2D);
    progress = 0.088607594;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient12.ogg", FMOD_2D);
    progress = 0.08945148;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient13.ogg", FMOD_2D);
    progress = 0.09029536;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient14.ogg", FMOD_2D);
    progress = 0.09113924;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient15.ogg", FMOD_2D);
    progress = 0.091983125;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient16.ogg", FMOD_2D);
    progress = 0.09282701;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient17.ogg", FMOD_2D);
    progress = 0.09367089;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient18.ogg", FMOD_2D);
    progress = 0.094514765;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient19.ogg", FMOD_2D);
    progress = 0.09535865;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient20.ogg", FMOD_2D);
    progress = 0.09620253;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient21.ogg", FMOD_2D);
    progress = 0.09704641;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient22.ogg", FMOD_2D);
    progress = 0.097890295;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient23.ogg", FMOD_2D);
    progress = 0.09873418;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone2/Ambient24.ogg", FMOD_2D);
    progress = 0.09957806;
    // SFX\AMBIENT\ZONE3
    progress = 0.10042194;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient1.ogg", FMOD_2D);
    progress = 0.101265825;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient2.ogg", FMOD_2D);
    progress = 0.10210971;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient3.ogg", FMOD_2D);
    progress = 0.10295358;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient4.ogg", FMOD_2D);
    progress = 0.103797466;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient5.ogg", FMOD_2D);
    progress = 0.10464135;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient6.ogg", FMOD_2D);
    progress = 0.10548523;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient7.ogg", FMOD_2D);
    progress = 0.10632911;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient8.ogg", FMOD_2D);
    progress = 0.107172996;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient9.ogg", FMOD_2D);
    progress = 0.10801688;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient10.ogg", FMOD_2D);
    progress = 0.10886076;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient11.ogg", FMOD_2D);
    progress = 0.10970464;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient12.ogg", FMOD_2D);
    progress = 0.110548526;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient13.ogg", FMOD_2D);
    progress = 0.11139241;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient14.ogg", FMOD_2D);
    progress = 0.11223628;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient15.ogg", FMOD_2D);
    progress = 0.11308017;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient16.ogg", FMOD_2D);
    progress = 0.11392405;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient17.ogg", FMOD_2D);
    progress = 0.11476793;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient18.ogg", FMOD_2D);
    progress = 0.115611814;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient19.ogg", FMOD_2D);
    progress = 0.1164557;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient20.ogg", FMOD_2D);
    progress = 0.11729958;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient21.ogg", FMOD_2D);
    progress = 0.11814346;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient22.ogg", FMOD_2D);
    progress = 0.118987344;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient23.ogg", FMOD_2D);
    progress = 0.11983123;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/Zone3/Ambient24.ogg", FMOD_2D);
    progress = 0.1206751;
    // SFX\AMBIENT
    progress = 0.121518984;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/ToZone2.ogg", FMOD_2D);
    progress = 0.12236287;
    AudioEngine::LoadSoundByName("Assets/SFX/Ambient/ToZone3.ogg", FMOD_2D);
    progress = 0.12320675;

    progress = 0.12405063;
    // SFX\CHARACTER
    progress = 0.124894515;
    // SFX\CHARACTER\APACHE
    progress = 0.1257384;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Crash1.ogg", FMOD_2D);
    progress = 0.12658228;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Crash2.ogg", FMOD_2D);
    progress = 0.12742616;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Apache/Propeller.ogg", FMOD_3D);
    progress = 0.12827004;
    // SFX\CHARACTER\D9341
    progress = 0.12911393;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip0.ogg", FMOD_3D);
    progress = 0.12995781;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip1.ogg", FMOD_3D);
    progress = 0.1308017;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip2.ogg", FMOD_3D);
    progress = 0.13164558;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip3.ogg", FMOD_3D);
    progress = 0.13248946;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip4.ogg", FMOD_3D);
    progress = 0.13333334;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/BloodDrip5.ogg", FMOD_3D);
    progress = 0.13417721;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath0.ogg", FMOD_2D);
    progress = 0.13502109;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath0gas.ogg", FMOD_2D);
    progress = 0.13586497;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath1.ogg", FMOD_2D);
    progress = 0.13670886;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath1gas.ogg", FMOD_2D);
    progress = 0.13755274;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath2.ogg", FMOD_2D);
    progress = 0.13839662;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath2gas.ogg", FMOD_2D);
    progress = 0.1392405;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath3.ogg", FMOD_2D);
    progress = 0.14008439;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath3gas.ogg", FMOD_2D);
    progress = 0.14092827;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath4.ogg", FMOD_2D);
    progress = 0.14177215;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Breath4gas.ogg", FMOD_2D);
    progress = 0.14261603;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough1.ogg", FMOD_2D);
    progress = 0.14345992;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough2.ogg", FMOD_2D);
    progress = 0.1443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Cough3.ogg", FMOD_2D);
    progress = 0.14514768;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Crouch.ogg", FMOD_2D);
    progress = 0.14599156;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage1.ogg", FMOD_2D);
    progress = 0.14683545;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage2.ogg", FMOD_2D);
    progress = 0.14767933;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage3.ogg", FMOD_2D);
    progress = 0.14852321;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage4.ogg", FMOD_2D);
    progress = 0.1493671;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage5.ogg", FMOD_2D);
    progress = 0.15021098;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage6.ogg", FMOD_2D);
    progress = 0.15105486;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage7.ogg", FMOD_2D);
    progress = 0.15189873;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage8.ogg", FMOD_2D);
    progress = 0.15274261;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage9.ogg", FMOD_2D);
    progress = 0.15358649;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Damage10.ogg", FMOD_2D);
    progress = 0.15443037;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/Heartbeat.ogg", FMOD_2D);
    progress = 0.15527426;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/D9341/RelaxedBreathGas.ogg", FMOD_2D);
    progress = 0.15611814;
    // SFX\CHARACTER\GUARD
    progress = 0.15696202;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom1.ogg", FMOD_3D);
    progress = 0.1578059;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom2.ogg", FMOD_3D);
    progress = 0.15864979;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/096ServerRoom3.ogg", FMOD_3D);
    progress = 0.15949367;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/SuicideGuard1.ogg", FMOD_3D);
    progress = 0.16033755;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Guard/SuicideGuard2.ogg", FMOD_3D);
    progress = 0.16118143;
    // SFX\CHARACTER\JANITOR
    progress = 0.16202532;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Janitor/106Abduct.ogg", FMOD_3D);
    progress = 0.1628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Janitor/Idle.ogg", FMOD_3D);
    progress = 0.16371308;
    // SFX\CHARACTER\LURESUBJECT
    progress = 0.16455697;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/106Bait.ogg", FMOD_2D);
    progress = 0.16540085;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle1.ogg", FMOD_2D);
    progress = 0.16624473;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle2.ogg", FMOD_2D);
    progress = 0.16708861;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle3.ogg", FMOD_2D);
    progress = 0.1679325;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle4.ogg", FMOD_2D);
    progress = 0.16877638;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle5.ogg", FMOD_2D);
    progress = 0.16962026;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Idle6.ogg", FMOD_2D);
    progress = 0.17046413;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/LureSubject/Sniffling.ogg", FMOD_2D);
    progress = 0.17130801;
    // SFX\CHARACTER\MTF
    progress = 0.1721519;
    // SFX\CHARACTER\MTF\049
    progress = 0.17299578;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Player0492_1.ogg", FMOD_3D);
    progress = 0.17383966;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Player0492_2.ogg", FMOD_3D);
    progress = 0.17468354;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted1.ogg", FMOD_3D);
    progress = 0.17552742;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted2.ogg", FMOD_3D);
    progress = 0.1763713;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted3.ogg", FMOD_3D);
    progress = 0.17721519;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted4.ogg", FMOD_3D);
    progress = 0.17805907;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/049/Spotted5.ogg", FMOD_3D);
    progress = 0.17890295;
    // SFX\CHARACTER\MTF\096
    progress = 0.17974684;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/096/Spotted1.ogg", FMOD_3D);
    progress = 0.18059072;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/096/Spotted2.ogg", FMOD_3D);
    progress = 0.1814346;
    // SFX\CHARACTER\MTF\106
    progress = 0.18227848;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted1.ogg", FMOD_3D);
    progress = 0.18312237;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted2.ogg", FMOD_3D);
    progress = 0.18396625;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted3.ogg", FMOD_3D);
    progress = 0.18481013;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted4.ogg", FMOD_3D);
    progress = 0.18565401;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/106/Spotted5.ogg", FMOD_3D);
    progress = 0.1864979;
    // SFX\CHARACTER\MTF\173
    progress = 0.18734178;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/BLINKING.ogg", FMOD_3D);
    progress = 0.18818565;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box1.ogg", FMOD_3D);
    progress = 0.18902953;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box2.ogg", FMOD_3D);
    progress = 0.18987341;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Box3.ogg", FMOD_3D);
    progress = 0.1907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont1.ogg", FMOD_3D);
    progress = 0.19156118;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont2.ogg", FMOD_3D);
    progress = 0.19240506;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont3.ogg", FMOD_3D);
    progress = 0.19324894;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Cont4.ogg", FMOD_3D);
    progress = 0.19409283;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted1.ogg", FMOD_3D);
    progress = 0.19493671;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted2.ogg", FMOD_3D);
    progress = 0.19578059;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/173/Spotted3.ogg", FMOD_3D);
    progress = 0.19662447;
    // SFX\CHARACTER\MTF
    progress = 0.19746836;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Announc.ogg", FMOD_2D);
    progress = 0.19831224;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Announc173Contain.ogg", FMOD_2D);
    progress = 0.19915612;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncAfter1.ogg", FMOD_2D);
    progress = 0.2;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncAfter2.ogg", FMOD_2D);
    progress = 0.20084389;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraCheck.ogg", FMOD_2D);
    progress = 0.20168777;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraFound1.ogg", FMOD_2D);
    progress = 0.20253165;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraFound2.ogg", FMOD_2D);
    progress = 0.20337553;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/AnnouncCameraNoFound.ogg", FMOD_2D);
    progress = 0.20421942;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Beep.ogg", FMOD_3D);
    progress = 0.2050633;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Breath.ogg", FMOD_3D);
    progress = 0.20590717;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD1.ogg", FMOD_3D);
    progress = 0.20675105;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD2.ogg", FMOD_3D);
    progress = 0.20759493;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD3.ogg", FMOD_3D);
    progress = 0.20843881;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ClassD4.ogg", FMOD_3D);
    progress = 0.2092827;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB1.ogg", FMOD_3D);
    progress = 0.21012658;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB2.ogg", FMOD_3D);
    progress = 0.21097046;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB3.ogg", FMOD_3D);
    progress = 0.21181434;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/GateB4.ogg", FMOD_3D);
    progress = 0.21265823;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random1.ogg", FMOD_3D);
    progress = 0.21350211;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random2.ogg", FMOD_3D);
    progress = 0.21434599;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random3.ogg", FMOD_3D);
    progress = 0.21518987;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random4.ogg", FMOD_3D);
    progress = 0.21603376;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random5.ogg", FMOD_3D);
    progress = 0.21687764;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random6.ogg", FMOD_3D);
    progress = 0.21772152;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Random7.ogg", FMOD_3D);
    progress = 0.2185654;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching1.ogg", FMOD_3D);
    progress = 0.21940929;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching2.ogg", FMOD_3D);
    progress = 0.22025317;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching3.ogg", FMOD_3D);
    progress = 0.22109705;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching4.ogg", FMOD_3D);
    progress = 0.22194093;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching5.ogg", FMOD_3D);
    progress = 0.22278482;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Searching6.ogg", FMOD_3D);
    progress = 0.22362868;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step1.ogg", FMOD_3D);
    progress = 0.22447257;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step2.ogg", FMOD_3D);
    progress = 0.22531645;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Step3.ogg", FMOD_3D);
    progress = 0.22616033;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop1.ogg", FMOD_3D);
    progress = 0.22700422;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop2.ogg", FMOD_3D);
    progress = 0.2278481;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop3.ogg", FMOD_3D);
    progress = 0.22869198;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop4.ogg", FMOD_3D);
    progress = 0.22953586;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop5.ogg", FMOD_3D);
    progress = 0.23037975;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Stop6.ogg", FMOD_3D);
    progress = 0.23122363;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost1.ogg", FMOD_3D);
    progress = 0.23206751;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost2.ogg", FMOD_3D);
    progress = 0.2329114;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/TargetLost3.ogg", FMOD_3D);
    progress = 0.23375528;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated1.ogg", FMOD_3D);
    progress = 0.23459916;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated2.ogg", FMOD_3D);
    progress = 0.23544304;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated3.ogg", FMOD_3D);
    progress = 0.23628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Targetterminated4.ogg", FMOD_3D);
    progress = 0.2371308;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla0.ogg", FMOD_3D);
    progress = 0.23797469;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla1.ogg", FMOD_2D);
    progress = 0.23881857;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla2.ogg", FMOD_2D);
    progress = 0.23966245;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/Tesla3.ogg", FMOD_2D);
    progress = 0.24050634;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs1.ogg", FMOD_3D);
    progress = 0.2413502;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs2.ogg", FMOD_3D);
    progress = 0.24219409;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs3.ogg", FMOD_3D);
    progress = 0.24303797;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs4.ogg", FMOD_3D);
    progress = 0.24388185;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs5.ogg", FMOD_3D);
    progress = 0.24472573;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThereHeIs6.ogg", FMOD_3D);
    progress = 0.24556962;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc1.ogg", FMOD_2D);
    progress = 0.2464135;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc2.ogg", FMOD_2D);
    progress = 0.24725738;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnounc3.ogg", FMOD_2D);
    progress = 0.24810126;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnouncFinal.ogg", FMOD_2D);
    progress = 0.24894515;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF/ThreatAnnouncPossession.ogg", FMOD_2D);
    progress = 0.24978903;
    // SFX\CHARACTER\MTF2
    progress = 0.2506329;
    // SFX\CHARACTER\MTF2\049
    progress = 0.2514768;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/049/Player0492_1.ogg", FMOD_3D);
    progress = 0.25232068;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/049/Player0492_2.ogg", FMOD_3D);
    progress = 0.25316456;
    // SFX\CHARACTER\MTF2\096
    progress = 0.25400844;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/096/Spotted1.ogg", FMOD_3D);
    progress = 0.25485232;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/096/Spotted2.ogg", FMOD_3D);
    progress = 0.2556962;
    // SFX\CHARACTER\MTF2\106
    progress = 0.2565401;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted1.ogg", FMOD_3D);
    progress = 0.25738397;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted2.ogg", FMOD_3D);
    progress = 0.25822785;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted3.ogg", FMOD_3D);
    progress = 0.25907174;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted4.ogg", FMOD_3D);
    progress = 0.25991562;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted5.ogg", FMOD_3D);
    progress = 0.2607595;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/106/Spotted6.ogg", FMOD_3D);
    progress = 0.2616034;
    // SFX\CHARACTER\MTF2\173
    progress = 0.26244727;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING1.ogg", FMOD_3D);
    progress = 0.26329115;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING2.ogg", FMOD_3D);
    progress = 0.26413503;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING3.ogg", FMOD_3D);
    progress = 0.26497892;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/BLINKING4.ogg", FMOD_3D);
    progress = 0.2658228;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box1.ogg", FMOD_3D);
    progress = 0.26666668;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box2.ogg", FMOD_3D);
    progress = 0.26751056;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box3.ogg", FMOD_3D);
    progress = 0.26835442;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Box4.ogg", FMOD_3D);
    progress = 0.2691983;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont1.ogg", FMOD_3D);
    progress = 0.27004218;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont2.ogg", FMOD_3D);
    progress = 0.27088606;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont3.ogg", FMOD_3D);
    progress = 0.27172995;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont4.ogg", FMOD_3D);
    progress = 0.27257383;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont5.ogg", FMOD_3D);
    progress = 0.2734177;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Cont6.ogg", FMOD_3D);
    progress = 0.2742616;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted1.ogg", FMOD_3D);
    progress = 0.27510548;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted2.ogg", FMOD_3D);
    progress = 0.27594936;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted3.ogg", FMOD_3D);
    progress = 0.27679324;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/173/Spotted4.ogg", FMOD_3D);
    progress = 0.27763712;
    // SFX\CHARACTER\MTF2
    progress = 0.278481;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Announc.ogg", FMOD_2D);
    progress = 0.2793249;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Beep.ogg", FMOD_3D);
    progress = 0.28016877;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ClassD1.ogg", FMOD_3D);
    progress = 0.28101265;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ClassD2.ogg", FMOD_3D);
    progress = 0.28185654;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Random1.ogg", FMOD_3D);
    progress = 0.28270042;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Random2.ogg", FMOD_3D);
    progress = 0.2835443;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching1.ogg", FMOD_3D);
    progress = 0.28438818;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching2.ogg", FMOD_3D);
    progress = 0.28523207;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching3.ogg", FMOD_3D);
    progress = 0.28607595;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching4.ogg", FMOD_3D);
    progress = 0.28691983;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching5.ogg", FMOD_3D);
    progress = 0.2877637;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Searching6.ogg", FMOD_3D);
    progress = 0.2886076;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop1.ogg", FMOD_3D);
    progress = 0.28945148;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop2.ogg", FMOD_3D);
    progress = 0.29029536;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop3.ogg", FMOD_3D);
    progress = 0.29113925;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop4.ogg", FMOD_3D);
    progress = 0.29198313;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop5.ogg", FMOD_3D);
    progress = 0.292827;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Stop6.ogg", FMOD_3D);
    progress = 0.2936709;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost1.ogg", FMOD_3D);
    progress = 0.29451478;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost2.ogg", FMOD_3D);
    progress = 0.29535866;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost3.ogg", FMOD_3D);
    progress = 0.29620254;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/TargetLost4.ogg", FMOD_3D);
    progress = 0.29704642;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated1.ogg", FMOD_3D);
    progress = 0.2978903;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated2.ogg", FMOD_3D);
    progress = 0.2987342;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated3.ogg", FMOD_3D);
    progress = 0.29957807;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated4.ogg", FMOD_3D);
    progress = 0.30042195;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Targetterminated5.ogg", FMOD_3D);
    progress = 0.30126584;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/Tesla0.ogg", FMOD_3D);
    progress = 0.30210972;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs1.ogg", FMOD_3D);
    progress = 0.3029536;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs2.ogg", FMOD_3D);
    progress = 0.30379745;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs3.ogg", FMOD_3D);
    progress = 0.30464134;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs4.ogg", FMOD_3D);
    progress = 0.30548522;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs5.ogg", FMOD_3D);
    progress = 0.3063291;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/MTF2/ThereHeIs6.ogg", FMOD_3D);
    progress = 0.30717298;
    // SFX\CHARACTER\SCIENTIST
    progress = 0.30801687;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/EmilyScream.ogg", FMOD_2D);
    progress = 0.30886075;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/Radio0.ogg", FMOD_3D);
    progress = 0.30970463;
    AudioEngine::LoadSoundByName("Assets/SFX/Character/Scientist/Radio1.ogg", FMOD_3D);
    progress = 0.3105485;

    progress = 0.3113924;
    // SFX\DOOR
    progress = 0.31223628;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/1123DoorOpen.ogg", FMOD_3D);
    progress = 0.31308016;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Airlock.ogg", FMOD_3D);
    progress = 0.31392404;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose.ogg", FMOD_3D);
    progress = 0.31476793;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose1.ogg", FMOD_3D);
    progress = 0.3156118;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorClose2.ogg", FMOD_3D);
    progress = 0.3164557;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen.ogg", FMOD_3D);
    progress = 0.31729957;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen1.ogg", FMOD_3D);
    progress = 0.31814346;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/BigDoorOpen2.ogg", FMOD_3D);
    progress = 0.31898734;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close1.ogg", FMOD_3D);
    progress = 0.31983122;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close2.ogg", FMOD_3D);
    progress = 0.3206751;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Close3.ogg", FMOD_3D);
    progress = 0.321519;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open1.ogg", FMOD_3D);
    progress = 0.32236287;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open1_dist.ogg", FMOD_2D);
    progress = 0.32320675;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open2.ogg", FMOD_3D);
    progress = 0.32405064;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/Door2Open3.ogg", FMOD_3D);
    progress = 0.32489452;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorCheckpoint.ogg", FMOD_3D);
    progress = 0.3257384;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose1.ogg", FMOD_3D);
    progress = 0.32658228;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose2.ogg", FMOD_3D);
    progress = 0.32742617;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose3.ogg", FMOD_3D);
    progress = 0.32827005;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorClose079.ogg", FMOD_3D);
    progress = 0.32911393;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorError.ogg", FMOD_3D);
    progress = 0.3299578;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen1.ogg", FMOD_3D);
    progress = 0.3308017;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen2.ogg", FMOD_3D);
    progress = 0.33164558;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen3.ogg", FMOD_3D);
    progress = 0.33248946;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen079.ogg", FMOD_3D);
    progress = 0.33333334;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpen173.ogg", FMOD_3D);
    progress = 0.33417723;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpenFast1.ogg", FMOD_3D);
    progress = 0.3350211;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorOpenFast2.ogg", FMOD_3D);
    progress = 0.335865;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/DoorSparks.ogg", FMOD_3D);
    progress = 0.33670887;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose1.ogg", FMOD_3D);
    progress = 0.33755276;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose2.ogg", FMOD_3D);
    progress = 0.33839664;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorClose3.ogg", FMOD_3D);
    progress = 0.33924052;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen1.ogg", FMOD_3D);
    progress = 0.34008437;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen2.ogg", FMOD_3D);
    progress = 0.34092826;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/ElevatorOpen3.ogg", FMOD_3D);
    progress = 0.34177214;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/EndroomDoor.ogg", FMOD_2D);
    progress = 0.34261602;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorBudge.ogg", FMOD_3D);
    progress = 0.3434599;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorClose.ogg", FMOD_3D);
    progress = 0.3443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Door/WoodenDoorOpen.ogg", FMOD_3D);
    progress = 0.34514767;

    progress = 0.34599155;
    // SFX\ENDING
    progress = 0.34683543;
    // SFX\ENDING\GATEA
    progress = 0.34767932;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/106Escape.ogg", FMOD_3D);
    progress = 0.3485232;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/106Retreat.ogg", FMOD_3D);
    progress = 0.34936708;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Bell1.ogg", FMOD_2D);
    progress = 0.35021096;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Bell2.ogg", FMOD_2D);
    progress = 0.35105485;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/CI.ogg", FMOD_3D);
    progress = 0.35189873;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/EndingA1.ogg", FMOD_2D);
    progress = 0.3527426;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/EndingA2.ogg", FMOD_2D);
    progress = 0.3535865;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/Franklin.ogg", FMOD_2D);
    progress = 0.35443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/HIDTurret.ogg", FMOD_2D);
    progress = 0.35527426;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateA/STOPRIGHTTHERE.ogg", FMOD_2D);
    progress = 0.35611814;
    // SFX\ENDING\GATEB
    progress = 0.35696203;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/682Battle.ogg", FMOD_3D);
    progress = 0.3578059;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/AlphaWarheadsFail.ogg", FMOD_3D);
    progress = 0.3586498;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/DetonatingAlphaWarheads.ogg", FMOD_3D);
    progress = 0.35949367;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB1.ogg", FMOD_2D);
    progress = 0.36033756;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB2.ogg", FMOD_2D);
    progress = 0.36118144;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/EndingB3.ogg", FMOD_2D);
    progress = 0.36202532;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Gunshot.ogg", FMOD_2D);
    progress = 0.3628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Nuke1.ogg", FMOD_2D);
    progress = 0.3637131;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Nuke2.ogg", FMOD_2D);
    progress = 0.36455697;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/PlayerDetect.ogg", FMOD_3D);
    progress = 0.36540085;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/GateB/Siren.ogg", FMOD_2D);
    progress = 0.36624473;
    // SFX\ENDING
    progress = 0.36708862;
    AudioEngine::LoadSoundByName("Assets/SFX/Ending/MenuBreath.ogg", FMOD_2D);
    progress = 0.3679325;

    progress = 0.36877638;
    // SFX\GENERAL
    progress = 0.36962026;
    // SFX\GENERAL\ELEVATOR
    progress = 0.37046415;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Elevator/Beep.ogg", FMOD_3D);
    progress = 0.37130803;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Elevator/Moving.ogg", FMOD_3D);
    progress = 0.3721519;
    // SFX\GENERAL
    progress = 0.3729958;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BodyFall.ogg", FMOD_3D);
    progress = 0.37383968;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BulletHit.ogg", FMOD_2D);
    progress = 0.37468356;
    AudioEngine::LoadSoundByName("Assets/SFX/General/BulletMiss.ogg", FMOD_2D);
    progress = 0.3755274;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Camera.ogg", FMOD_3D);
    progress = 0.3763713;
    AudioEngine::LoadSoundByName("Assets/SFX/General/GeneratorOn.ogg", FMOD_2D);
    progress = 0.37721518;
    AudioEngine::LoadSoundByName("Assets/SFX/General/GlassBreak.ogg", FMOD_3D);
    progress = 0.37805906;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot.ogg", FMOD_3D);
    progress = 0.37890294;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot2.ogg", FMOD_3D);
    progress = 0.37974682;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Gunshot3.ogg", FMOD_3D);
    progress = 0.3805907;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Hiss.ogg", FMOD_3D);
    progress = 0.3814346;
    AudioEngine::LoadSoundByName("Assets/SFX/General/LightSwitch.ogg", FMOD_2D);
    progress = 0.38227847;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Save1.ogg", FMOD_2D);
    progress = 0.38312235;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Save2.ogg", FMOD_3D);
    progress = 0.38396624;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Slash1.ogg", FMOD_3D);
    progress = 0.38481012;
    AudioEngine::LoadSoundByName("Assets/SFX/General/Slash2.ogg", FMOD_3D);
    progress = 0.385654;

    progress = 0.38649788;
    // SFX\HORROR
    progress = 0.38734177;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror0.ogg", FMOD_2D);
    progress = 0.38818565;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror1.ogg", FMOD_2D);
    progress = 0.38902953;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror2.ogg", FMOD_2D);
    progress = 0.38987342;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror3.ogg", FMOD_2D);
    progress = 0.3907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror4.ogg", FMOD_2D);
    progress = 0.39156118;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror5.ogg", FMOD_2D);
    progress = 0.39240506;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror6.ogg", FMOD_2D);
    progress = 0.39324895;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror7.ogg", FMOD_2D);
    progress = 0.39409283;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror8.ogg", FMOD_2D);
    progress = 0.3949367;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror9.ogg", FMOD_2D);
    progress = 0.3957806;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror10.ogg", FMOD_2D);
    progress = 0.39662448;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror11.ogg", FMOD_2D);
    progress = 0.39746836;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror12.ogg", FMOD_2D);
    progress = 0.39831224;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror13.ogg", FMOD_2D);
    progress = 0.39915612;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror14.ogg", FMOD_2D);
    progress = 0.4;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror15.ogg", FMOD_2D);
    progress = 0.4008439;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror16.ogg", FMOD_2D);
    progress = 0.40168777;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror17.ogg", FMOD_2D);
    progress = 0.40253165;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror18.ogg", FMOD_2D);
    progress = 0.40337554;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror19.ogg", FMOD_2D);
    progress = 0.40421942;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror20.ogg", FMOD_2D);
    progress = 0.4050633;
    AudioEngine::LoadSoundByName("Assets/SFX/Horror/Horror21.ogg", FMOD_2D);
    progress = 0.40590718;

    progress = 0.40675107;
    // SFX\INTERACT
    progress = 0.40759495;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/Button.ogg", FMOD_3D);
    progress = 0.40843883;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/Button2.ogg", FMOD_3D);
    progress = 0.4092827;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/KeycardUse1.ogg", FMOD_3D);
    progress = 0.4101266;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/KeycardUse2.ogg", FMOD_3D);
    progress = 0.41097045;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/LeverFlip.ogg", FMOD_3D);
    progress = 0.41181433;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/NVGUse0.ogg", FMOD_3D);
    progress = 0.4126582;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/NVGUse1.ogg", FMOD_3D);
    progress = 0.4135021;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem0.ogg", FMOD_3D);
    progress = 0.41434598;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem1.ogg", FMOD_3D);
    progress = 0.41518986;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem2.ogg", FMOD_3D);
    progress = 0.41603374;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem3.ogg", FMOD_3D);
    progress = 0.41687763;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem4.ogg", FMOD_3D);
    progress = 0.4177215;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/PickItem5.ogg", FMOD_3D);
    progress = 0.4185654;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/ScannerUse1.ogg", FMOD_3D);
    progress = 0.41940928;
    AudioEngine::LoadSoundByName("Assets/SFX/Interact/ScannerUse2.ogg", FMOD_3D);
    progress = 0.42025316;

    progress = 0.42109704;
    // SFX\MUSIC
    progress = 0.42194092;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/049Chase.ogg", FMOD_2D);
    progress = 0.4227848;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096.ogg", FMOD_2D);
    progress = 0.4236287;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096Angered.ogg", FMOD_2D);
    progress = 0.42447257;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/096Chase.ogg", FMOD_2D);
    progress = 0.42531645;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/106Chase.ogg", FMOD_2D);
    progress = 0.42616034;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/650Chase.ogg", FMOD_2D);
    progress = 0.42700422;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/860_2Chase.ogg", FMOD_2D);
    progress = 0.4278481;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Credits.ogg", FMOD_2D);
    progress = 0.42869198;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Dimension1499.ogg", FMOD_2D);
    progress = 0.42953587;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Dimension1499Danger.ogg", FMOD_2D);
    progress = 0.43037975;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Ending.ogg", FMOD_2D);
    progress = 0.43122363;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/EntranceZone.ogg", FMOD_2D);
    progress = 0.4320675;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Forest.ogg", FMOD_2D);
    progress = 0.4329114;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateA.ogg", FMOD_2D);
    progress = 0.43375528;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateB1.ogg", FMOD_2D);
    progress = 0.43459916;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/GateB2.ogg", FMOD_2D);
    progress = 0.43544304;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HaveMercyOnMe(Choir).ogg", FMOD_2D);
    progress = 0.43628693;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HaveMercyOnMe(NoChoir).ogg", FMOD_2D);
    progress = 0.4371308;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/HeavyContainment.ogg", FMOD_2D);
    progress = 0.4379747;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Intro.ogg", FMOD_2D);
    progress = 0.43881857;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Menu.ogg", FMOD_2D);
    progress = 0.43966246;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/MenuBackup.ogg", FMOD_2D);
    progress = 0.44050634;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/PD.ogg", FMOD_2D);
    progress = 0.44135022;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/PDTrench.ogg", FMOD_2D);
    progress = 0.4421941;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room2Tunnel.ogg", FMOD_2D);
    progress = 0.443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room3Storage.ogg", FMOD_2D);
    progress = 0.44388187;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room012.ogg", FMOD_2D);
    progress = 0.44472575;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room012Golgotha.ogg", FMOD_2D);
    progress = 0.44556963;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room035.ogg", FMOD_2D);
    progress = 0.44641352;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room049.ogg", FMOD_2D);
    progress = 0.44725737;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room079.ogg", FMOD_2D);
    progress = 0.44810125;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room106.ogg", FMOD_2D);
    progress = 0.44894513;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room205.ogg", FMOD_2D);
    progress = 0.44978902;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room409.ogg", FMOD_2D);
    progress = 0.4506329;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room457.ogg", FMOD_2D);
    progress = 0.45147678;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room914.ogg", FMOD_2D);
    progress = 0.45232067;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Room1123.ogg", FMOD_2D);
    progress = 0.45316455;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/SaveMeFrom.ogg", FMOD_2D);
    progress = 0.45400843;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/The Dread.ogg", FMOD_2D);
    progress = 0.4548523;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using178.ogg", FMOD_2D);
    progress = 0.4556962;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using215.ogg", FMOD_2D);
    progress = 0.45654008;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using420J.ogg", FMOD_2D);
    progress = 0.45738396;
    AudioEngine::LoadSoundByName("Assets/SFX/Music/Using1033RU.ogg", FMOD_2D);
    progress = 0.45822784;

    progress = 0.45907173;
    // SFX\RADIO
    progress = 0.4599156;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Buzz.ogg", FMOD_2D);
    progress = 0.4607595;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter1.ogg", FMOD_2D);
    progress = 0.46160337;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter2.ogg", FMOD_2D);
    progress = 0.46244726;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter3.ogg", FMOD_2D);
    progress = 0.46329114;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Chatter4.ogg", FMOD_2D);
    progress = 0.46413502;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin1.ogg", FMOD_2D);
    progress = 0.4649789;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin2.ogg", FMOD_2D);
    progress = 0.4658228;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin3.ogg", FMOD_2D);
    progress = 0.46666667;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Franklin4.ogg", FMOD_2D);
    progress = 0.46751055;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/OhGod.ogg", FMOD_2D);
    progress = 0.46835443;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/RadioAlarm.ogg", FMOD_2D);
    progress = 0.46919832;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/RadioAlarm2.ogg", FMOD_2D);
    progress = 0.4700422;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio0.ogg", FMOD_2D);
    progress = 0.47088608;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio1.ogg", FMOD_2D);
    progress = 0.47172996;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio2.ogg", FMOD_2D);
    progress = 0.47257385;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio3.ogg", FMOD_2D);
    progress = 0.47341773;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio4.ogg", FMOD_2D);
    progress = 0.4742616;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio5.ogg", FMOD_2D);
    progress = 0.4751055;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio6.ogg", FMOD_2D);
    progress = 0.47594938;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio7.ogg", FMOD_2D);
    progress = 0.47679326;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/SCPRadio8.ogg", FMOD_2D);
    progress = 0.47763714;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Squelch.ogg", FMOD_2D);
    progress = 0.47848102;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Static.ogg", FMOD_2D);
    progress = 0.4793249;
    AudioEngine::LoadSoundByName("Assets/SFX/Radio/Static895.ogg", FMOD_2D);
    progress = 0.4801688;

    progress = 0.48101267;
    // SFX\ROOM
    progress = 0.48185655;
    // SFX\ROOM\035CHAMBER
    progress = 0.4827004;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/InProximity.ogg", FMOD_2D);
    progress = 0.4835443;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleAttack1.ogg", FMOD_2D);
    progress = 0.48438817;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleAttack2.ogg", FMOD_2D);
    progress = 0.48523206;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleIdle.ogg", FMOD_2D);
    progress = 0.48607594;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/TentacleSpawn.ogg", FMOD_2D);
    progress = 0.48691982;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/Whispers1.ogg", FMOD_2D);
    progress = 0.4877637;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/035Chamber/Whispers2.ogg", FMOD_2D);
    progress = 0.4886076;
    // SFX\ROOM\096CHAMBER
    progress = 0.48945147;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/096Chamber/096ChamberEvent.ogg", FMOD_2D);
    progress = 0.49029535;
    // SFX\ROOM\106CHAMBER
    progress = 0.49113923;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/FemurBreaker.ogg", FMOD_2D);
    progress = 0.49198312;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/MagnetDown.ogg", FMOD_3D);
    progress = 0.492827;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/106Chamber/MagnetUp.ogg", FMOD_3D);
    progress = 0.49367088;
    // SFX\ROOM\457CHAMBER
    progress = 0.49451476;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/457Chamber/Drips.ogg", FMOD_2D);
    progress = 0.49535865;
    // SFX\ROOM\895CHAMBER
    progress = 0.49620253;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle1.ogg", FMOD_3D);
    progress = 0.4970464;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle2.ogg", FMOD_3D);
    progress = 0.4978903;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardIdle3.ogg", FMOD_3D);
    progress = 0.49873418;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardRadio.ogg", FMOD_3D);
    progress = 0.49957806;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream1.ogg", FMOD_3D);
    progress = 0.50042194;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream2.ogg", FMOD_3D);
    progress = 0.5012658;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/GuardScream3.ogg", FMOD_3D);
    progress = 0.5021097;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/895Chamber/NVG.ogg", FMOD_2D);
    progress = 0.5029536;
    // SFX\ROOM\INTRO
    progress = 0.5037975;
    // SFX\ROOM\INTRO\CLASSD
    progress = 0.50464135;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/Breen.ogg", FMOD_3D);
    progress = 0.50548524;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/DontLikeThis.ogg", FMOD_3D);
    progress = 0.5063291;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/ClassD/Gasp.ogg", FMOD_3D);
    progress = 0.507173;
    // SFX\ROOM\INTRO\COMMOTION
    progress = 0.5080169;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion1.ogg", FMOD_2D);
    progress = 0.50886077;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion2.ogg", FMOD_2D);
    progress = 0.50970465;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion3.ogg", FMOD_2D);
    progress = 0.51054853;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion4.ogg", FMOD_2D);
    progress = 0.5113924;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion5.ogg", FMOD_2D);
    progress = 0.5122363;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion6.ogg", FMOD_2D);
    progress = 0.5130802;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion7.ogg", FMOD_2D);
    progress = 0.51392406;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion8.ogg", FMOD_2D);
    progress = 0.51476794;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion9.ogg", FMOD_2D);
    progress = 0.5156118;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion10.ogg", FMOD_2D);
    progress = 0.5164557;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion11.ogg", FMOD_2D);
    progress = 0.5172996;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion12.ogg", FMOD_2D);
    progress = 0.5181435;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion13.ogg", FMOD_2D);
    progress = 0.51898736;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion14.ogg", FMOD_2D);
    progress = 0.51983124;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion15.ogg", FMOD_2D);
    progress = 0.5206751;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion16.ogg", FMOD_2D);
    progress = 0.521519;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion17.ogg", FMOD_2D);
    progress = 0.5223629;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion18.ogg", FMOD_2D);
    progress = 0.5232068;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion19.ogg", FMOD_2D);
    progress = 0.52405065;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion20.ogg", FMOD_2D);
    progress = 0.52489454;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion21.ogg", FMOD_2D);
    progress = 0.5257384;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion22.ogg", FMOD_2D);
    progress = 0.5265823;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion23.ogg", FMOD_2D);
    progress = 0.5274262;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion24.ogg", FMOD_2D);
    progress = 0.52827007;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion25.ogg", FMOD_2D);
    progress = 0.52911395;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Commotion/Commotion26.ogg", FMOD_2D);
    progress = 0.52995783;
    // SFX\ROOM\INTRO\GUARD
    progress = 0.5308017;
    // SFX\ROOM\INTRO\GUARD\BALCONY
    progress = 0.5316456;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/Alert1.ogg", FMOD_3D);
    progress = 0.5324895;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/Alert2.ogg", FMOD_3D);
    progress = 0.53333336;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/OhSh.ogg", FMOD_3D);
    progress = 0.53417724;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/WTF1.ogg", FMOD_3D);
    progress = 0.5350211;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Balcony/WTF2.ogg", FMOD_3D);
    progress = 0.53586495;
    // SFX\ROOM\INTRO\GUARD\ULGRIN
    progress = 0.53670883;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/BeforeDoorOpen.ogg", FMOD_3D);
    progress = 0.5375527;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/CellGas1.ogg", FMOD_3D);
    progress = 0.5383966;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/CellGas2.ogg", FMOD_3D);
    progress = 0.5392405;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/Escort1.ogg", FMOD_3D);
    progress = 0.54008436;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/Escort2.ogg", FMOD_3D);
    progress = 0.54092824;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone1.ogg", FMOD_3D);
    progress = 0.5417721;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone2.ogg", FMOD_3D);
    progress = 0.542616;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone3.ogg", FMOD_3D);
    progress = 0.5434599;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone4.ogg", FMOD_3D);
    progress = 0.5443038;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortDone5.ogg", FMOD_3D);
    progress = 0.54514766;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortKill1.ogg", FMOD_3D);
    progress = 0.54599154;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortKill2.ogg", FMOD_3D);
    progress = 0.5468354;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortPissedOff1.ogg", FMOD_3D);
    progress = 0.5476793;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortPissedOff2.ogg", FMOD_3D);
    progress = 0.5485232;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRefuse1.ogg", FMOD_3D);
    progress = 0.5493671;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRefuse2.ogg", FMOD_3D);
    progress = 0.55021095;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortRun.ogg", FMOD_3D);
    progress = 0.55105484;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/EscortTerminated.ogg", FMOD_3D);
    progress = 0.5518987;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCell.ogg", FMOD_3D);
    progress = 0.5527426;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCellRefuse1.ogg", FMOD_3D);
    progress = 0.5535865;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/ExitCellRefuse2.ogg", FMOD_3D);
    progress = 0.55443037;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Ulgrin/OhAndByTheWay.ogg", FMOD_3D);
    progress = 0.55527425;
    // SFX\ROOM\INTRO\GUARD
    progress = 0.55611813;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation1a.ogg", FMOD_3D);
    progress = 0.556962;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation1b.ogg", FMOD_3D);
    progress = 0.5578059;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation2a.ogg", FMOD_3D);
    progress = 0.5586498;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation2b.ogg", FMOD_3D);
    progress = 0.55949366;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation3a.ogg", FMOD_3D);
    progress = 0.56033754;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation3b.ogg", FMOD_3D);
    progress = 0.5611814;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation4a.ogg", FMOD_3D);
    progress = 0.5620253;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation4b.ogg", FMOD_3D);
    progress = 0.5628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation5a.ogg", FMOD_3D);
    progress = 0.5637131;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Conversation5b.ogg", FMOD_3D);
    progress = 0.56455696;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music1.ogg", FMOD_3D);
    progress = 0.56540084;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music2.ogg", FMOD_3D);
    progress = 0.5662447;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music3.ogg", FMOD_3D);
    progress = 0.5670886;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music4.ogg", FMOD_3D);
    progress = 0.5679325;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/Music5.ogg", FMOD_3D);
    progress = 0.56877637;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Guard/PlayerEscape.ogg", FMOD_3D);
    progress = 0.56962025;
    // SFX\ROOM\INTRO\PA
    progress = 0.57046413;
    // SFX\ROOM\INTRO\PA\1
    progress = 0.571308;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/1/Attention1.ogg", FMOD_2D);
    progress = 0.5721519;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/1/Attention2.ogg", FMOD_2D);
    progress = 0.5729958;
    // SFX\ROOM\INTRO\PA\2
    progress = 0.57383966;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew0.ogg", FMOD_2D);
    progress = 0.57468355;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew1.ogg", FMOD_2D);
    progress = 0.5755274;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew2.ogg", FMOD_2D);
    progress = 0.5763713;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew3.ogg", FMOD_2D);
    progress = 0.5772152;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew4.ogg", FMOD_2D);
    progress = 0.5780591;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Crew5.ogg", FMOD_2D);
    progress = 0.57890296;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist0.ogg", FMOD_2D);
    progress = 0.57974684;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist1.ogg", FMOD_2D);
    progress = 0.5805907;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist2.ogg", FMOD_2D);
    progress = 0.5814346;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist3.ogg", FMOD_2D);
    progress = 0.5822785;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist4.ogg", FMOD_2D);
    progress = 0.5831224;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist5.ogg", FMOD_2D);
    progress = 0.58396626;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist6.ogg", FMOD_2D);
    progress = 0.58481014;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist7.ogg", FMOD_2D);
    progress = 0.585654;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist8.ogg", FMOD_2D);
    progress = 0.5864979;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist8.ogg", FMOD_2D);
    progress = 0.5873418;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist9.ogg", FMOD_2D);
    progress = 0.58818567;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist10.ogg", FMOD_2D);
    progress = 0.58902955;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist11.ogg", FMOD_2D);
    progress = 0.58987343;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist12.ogg", FMOD_2D);
    progress = 0.5907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist13.ogg", FMOD_2D);
    progress = 0.5915612;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist14.ogg", FMOD_2D);
    progress = 0.5924051;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist15.ogg", FMOD_2D);
    progress = 0.59324896;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist16.ogg", FMOD_2D);
    progress = 0.59409285;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist17.ogg", FMOD_2D);
    progress = 0.5949367;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist18.ogg", FMOD_2D);
    progress = 0.5957806;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Scientist19.ogg", FMOD_2D);
    progress = 0.5966245;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security0.ogg", FMOD_2D);
    progress = 0.5974684;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security1.ogg", FMOD_2D);
    progress = 0.59831226;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security2.ogg", FMOD_2D);
    progress = 0.59915614;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security3.ogg", FMOD_2D);
    progress = 0.6;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security4.ogg", FMOD_2D);
    progress = 0.6008439;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/2/Security5.ogg", FMOD_2D);
    progress = 0.6016878;
    // SFX\ROOM\INTRO\PA\3
    progress = 0.6025317;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/CallOnline.ogg", FMOD_2D);
    progress = 0.60337555;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Crew0.ogg", FMOD_2D);
    progress = 0.60421944;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Report0.ogg", FMOD_2D);
    progress = 0.6050633;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/3/Report1.ogg", FMOD_2D);
    progress = 0.6059072;
    // SFX\ROOM\INTRO\PA\4
    progress = 0.6067511;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew0.ogg", FMOD_2D);
    progress = 0.6075949;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew1.ogg", FMOD_2D);
    progress = 0.6084388;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew2.ogg", FMOD_2D);
    progress = 0.6092827;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew3.ogg", FMOD_2D);
    progress = 0.61012655;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew4.ogg", FMOD_2D);
    progress = 0.61097044;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew5.ogg", FMOD_2D);
    progress = 0.6118143;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Crew6.ogg", FMOD_2D);
    progress = 0.6126582;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist0.ogg", FMOD_2D);
    progress = 0.6135021;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist1.ogg", FMOD_2D);
    progress = 0.61434597;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist2.ogg", FMOD_2D);
    progress = 0.61518985;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist3.ogg", FMOD_2D);
    progress = 0.61603373;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist4.ogg", FMOD_2D);
    progress = 0.6168776;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist5.ogg", FMOD_2D);
    progress = 0.6177215;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist6.ogg", FMOD_2D);
    progress = 0.6185654;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Scientist7.ogg", FMOD_2D);
    progress = 0.61940926;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security0.ogg", FMOD_2D);
    progress = 0.62025315;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security1.ogg", FMOD_2D);
    progress = 0.621097;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security2.ogg", FMOD_2D);
    progress = 0.6219409;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security3.ogg", FMOD_2D);
    progress = 0.6227848;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security4.ogg", FMOD_2D);
    progress = 0.6236287;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/4/Security5.ogg", FMOD_2D);
    progress = 0.62447256;
    // SFX\ROOM\INTRO\PA\5
    progress = 0.62531644;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew1.ogg", FMOD_2D);
    progress = 0.6261603;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew2.ogg", FMOD_2D);
    progress = 0.6270042;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew3.ogg", FMOD_2D);
    progress = 0.6278481;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew4.ogg", FMOD_2D);
    progress = 0.628692;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew5.ogg", FMOD_2D);
    progress = 0.62953585;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew6.ogg", FMOD_2D);
    progress = 0.63037974;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Scientist0.ogg", FMOD_2D);
    progress = 0.6312236;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security0.ogg", FMOD_2D);
    progress = 0.6320675;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security1.ogg", FMOD_2D);
    progress = 0.6329114;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Security2.ogg", FMOD_2D);
    progress = 0.63375527;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/5/Crew0.ogg", FMOD_2D);
    progress = 0.63459915;
    // SFX\ROOM\INTRO\PA\NUMBERS
    progress = 0.63544303;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/1.ogg", FMOD_2D);
    progress = 0.6362869;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/2.ogg", FMOD_2D);
    progress = 0.6371308;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/3.ogg", FMOD_2D);
    progress = 0.6379747;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/4.ogg", FMOD_2D);
    progress = 0.63881856;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/5.ogg", FMOD_2D);
    progress = 0.63966244;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/6.ogg", FMOD_2D);
    progress = 0.6405063;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/7.ogg", FMOD_2D);
    progress = 0.6413502;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/8.ogg", FMOD_2D);
    progress = 0.6421941;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Numbers/9.ogg", FMOD_2D);
    progress = 0.643038;
    // SFX\ROOM\INTRO\PA\SCRIPTED
    progress = 0.64388186;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement1.ogg", FMOD_2D);
    progress = 0.64472574;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement2.ogg", FMOD_2D);
    progress = 0.6455696;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement3.ogg", FMOD_2D);
    progress = 0.6464135;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement4.ogg", FMOD_2D);
    progress = 0.6472574;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement5.ogg", FMOD_2D);
    progress = 0.6481013;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement6.ogg", FMOD_2D);
    progress = 0.64894515;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Announcement7.ogg", FMOD_2D);
    progress = 0.64978904;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted1.ogg", FMOD_2D);
    progress = 0.6506329;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted2.ogg", FMOD_2D);
    progress = 0.6514768;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted3.ogg", FMOD_2D);
    progress = 0.6523207;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted4.ogg", FMOD_2D);
    progress = 0.65316457;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted5.ogg", FMOD_2D);
    progress = 0.65400845;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Scripted/Scripted6.ogg", FMOD_2D);
    progress = 0.65485233;
    // SFX\ROOM\INTRO\PA
    progress = 0.6556962;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/Off.ogg", FMOD_2D);
    progress = 0.6565401;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/PA/On.ogg", FMOD_2D);
    progress = 0.657384;
    // SFX\ROOM\INTRO\SCIENTIST
    progress = 0.65822786;
    // SFX\ROOM\INTRO\SCIENTIST\FRANKLIN
    progress = 0.65907174;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Approach173.ogg", FMOD_2D);
    progress = 0.6599156;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/EnterChamber.ogg", FMOD_2D);
    progress = 0.6607595;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Problem.ogg", FMOD_2D);
    progress = 0.6616034;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse1.ogg", FMOD_2D);
    progress = 0.6624473;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse2.ogg", FMOD_2D);
    progress = 0.66329116;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Franklin/Refuse3.ogg", FMOD_2D);
    progress = 0.66413504;
    // SFX\ROOM\INTRO\SCIENTIST
    progress = 0.6649789;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Scientist/Conversation.ogg", FMOD_2D);
    progress = 0.6658228;
    // SFX\ROOM\INTRO\VEHICLE
    progress = 0.6666667;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Vehicle/VehicleIdle.ogg", FMOD_3D);
    progress = 0.66751057;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Vehicle/VehicleMove.ogg", FMOD_3D);
    progress = 0.66835445;
    // SFX\ROOM\INTRO
    progress = 0.66919833;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/173Chamber.ogg", FMOD_2D);
    progress = 0.6700422;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/173Vent.ogg", FMOD_2D);
    progress = 0.6708861;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang1.ogg", FMOD_2D);
    progress = 0.67173;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang2.ogg", FMOD_2D);
    progress = 0.67257386;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Bang3.ogg", FMOD_2D);
    progress = 0.67341775;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Ew1.ogg", FMOD_2D);
    progress = 0.6742616;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Ew2.ogg", FMOD_2D);
    progress = 0.6751055;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Horror.ogg", FMOD_2D);
    progress = 0.6759494;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light1.ogg", FMOD_2D);
    progress = 0.6767933;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light2.ogg", FMOD_2D);
    progress = 0.67763716;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/Light3.ogg", FMOD_2D);
    progress = 0.67848104;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/See173.ogg", FMOD_2D);
    progress = 0.67932487;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Intro/WhatThe.ogg", FMOD_3D);
    progress = 0.68016875;
    // SFX\ROOM\POCKETDIMENSION
    progress = 0.68101263;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Enter.ogg", FMOD_2D);
    progress = 0.6818565;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Exit.ogg", FMOD_2D);
    progress = 0.6827004;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Explosion.ogg", FMOD_2D);
    progress = 0.6835443;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Impact.ogg", FMOD_2D);
    progress = 0.68438816;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Kneel.ogg", FMOD_2D);
    progress = 0.68523204;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/PrisonVoices.ogg", FMOD_2D);
    progress = 0.6860759;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Rumble.ogg", FMOD_2D);
    progress = 0.6869198;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/Screech.ogg", FMOD_2D);
    progress = 0.6877637;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/PocketDimension/TrenchPlane.ogg", FMOD_2D);
    progress = 0.6886076;
    // SFX\ROOM\STOREROOM
    progress = 0.68945146;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Storeroom/Escape1.ogg", FMOD_3D);
    progress = 0.69029534;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Storeroom/Escape2.ogg", FMOD_3D);
    progress = 0.6911392;
    // SFX\ROOM\TESLA
    progress = 0.6919831;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/Idle.ogg", FMOD_3D);
    progress = 0.692827;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/PowerUp.ogg", FMOD_3D);
    progress = 0.69367087;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/Shock.ogg", FMOD_3D);
    progress = 0.69451475;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Tesla/WindUp.ogg", FMOD_3D);
    progress = 0.69535863;
    // SFX\ROOM
    progress = 0.6962025;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Blackout.ogg", FMOD_2D);
    progress = 0.6970464;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/LockroomSiren.ogg", FMOD_2D);
    progress = 0.6978903;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Room2ElevatorDeath.ogg", FMOD_2D);
    progress = 0.69873416;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Room2SL049Spawn.ogg", FMOD_2D);
    progress = 0.69957805;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/Sinkhole.ogg", FMOD_2D);
    progress = 0.7004219;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/SinkholeFall.ogg", FMOD_2D);
    progress = 0.7012658;
    AudioEngine::LoadSoundByName("Assets/SFX/Room/TunnelBurst.ogg", FMOD_2D);
    progress = 0.7021097;

    progress = 0.7029536;
    // SFX\SCP
    progress = 0.70379746;
    // SFX\SCP\008
    progress = 0.70464134;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/KillScientist0.ogg", FMOD_2D);
    progress = 0.7054852;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/KillScientist1.ogg", FMOD_2D);
    progress = 0.7063291;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices0.ogg", FMOD_2D);
    progress = 0.707173;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices1.ogg", FMOD_2D);
    progress = 0.7080169;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices2.ogg", FMOD_2D);
    progress = 0.70886075;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices3.ogg", FMOD_2D);
    progress = 0.70970464;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices4.ogg", FMOD_2D);
    progress = 0.7105485;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices5.ogg", FMOD_2D);
    progress = 0.7113924;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008/Voices6.ogg", FMOD_2D);
    progress = 0.7122363;
    // SFX\SCP\008_1
    progress = 0.71308017;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/008_1/Breath.ogg", FMOD_3D);
    progress = 0.71392405;
    // SFX\SCP\009
    progress = 0.71476793;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/009/IceCracking.ogg", FMOD_3D);
    progress = 0.7156118;
    // SFX\SCP\012
    progress = 0.7164557;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech1.ogg", FMOD_2D);
    progress = 0.7172996;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech2.ogg", FMOD_2D);
    progress = 0.71814346;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech3.ogg", FMOD_2D);
    progress = 0.71898735;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech4.ogg", FMOD_2D);
    progress = 0.7198312;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech5.ogg", FMOD_2D);
    progress = 0.7206751;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech6.ogg", FMOD_2D);
    progress = 0.721519;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/012/Speech7.ogg", FMOD_2D);
    progress = 0.7223629;
    // SFX\SCP\035
    progress = 0.72320676;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Closet1.ogg", FMOD_3D);
    progress = 0.72405064;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Closet2.ogg", FMOD_3D);
    progress = 0.7248945;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Escape.ogg", FMOD_3D);
    progress = 0.7257384;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Gased1.ogg", FMOD_3D);
    progress = 0.7265823;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Gased2.ogg", FMOD_3D);
    progress = 0.7274262;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedCloset.ogg", FMOD_3D);
    progress = 0.72827005;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedEscape.ogg", FMOD_3D);
    progress = 0.72911394;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedKilled1.ogg", FMOD_3D);
    progress = 0.7299578;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedKilled2.ogg", FMOD_3D);
    progress = 0.7308017;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedStop1.ogg", FMOD_3D);
    progress = 0.7316456;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GasedStop2.ogg", FMOD_3D);
    progress = 0.73248947;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/GetUp.ogg", FMOD_2D);
    progress = 0.73333335;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Help1.ogg", FMOD_3D);
    progress = 0.73417723;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Help2.ogg", FMOD_3D);
    progress = 0.7350211;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle1.ogg", FMOD_3D);
    progress = 0.735865;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle2.ogg", FMOD_3D);
    progress = 0.7367089;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle3.ogg", FMOD_3D);
    progress = 0.73755276;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle4.ogg", FMOD_3D);
    progress = 0.73839664;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle5.ogg", FMOD_3D);
    progress = 0.7392405;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle6.ogg", FMOD_3D);
    progress = 0.7400844;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/Idle7.ogg", FMOD_3D);
    progress = 0.7409283;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/KilledEscape.ogg", FMOD_3D);
    progress = 0.7417722;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/KilledGetUp.ogg", FMOD_2D);
    progress = 0.74261606;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/RadioHelp1.ogg", FMOD_2D);
    progress = 0.74345994;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/035/RadioHelp2.ogg", FMOD_2D);
    progress = 0.7443038;
    // SFX\SCP\049
    progress = 0.7451477;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/714Equipped.ogg", FMOD_3D);
    progress = 0.7459916;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/DetectedInChamber.ogg", FMOD_3D);
    progress = 0.7468355;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Kidnap1.ogg", FMOD_3D);
    progress = 0.74767935;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Kidnap2.ogg", FMOD_3D);
    progress = 0.74852324;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Room2SL1.ogg", FMOD_3D);
    progress = 0.7493671;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Room2SL2.ogg", FMOD_3D);
    progress = 0.75021094;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching1.ogg", FMOD_3D);
    progress = 0.7510548;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching2.ogg", FMOD_3D);
    progress = 0.7518987;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching3.ogg", FMOD_3D);
    progress = 0.7527426;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching4.ogg", FMOD_3D);
    progress = 0.7535865;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching5.ogg", FMOD_3D);
    progress = 0.75443035;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching6.ogg", FMOD_3D);
    progress = 0.75527424;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Searching7.ogg", FMOD_3D);
    progress = 0.7561181;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted1.ogg", FMOD_3D);
    progress = 0.756962;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted2.ogg", FMOD_3D);
    progress = 0.7578059;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted3.ogg", FMOD_3D);
    progress = 0.75864977;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted4.ogg", FMOD_3D);
    progress = 0.75949365;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted5.ogg", FMOD_3D);
    progress = 0.76033753;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted6.ogg", FMOD_3D);
    progress = 0.7611814;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Spotted7.ogg", FMOD_3D);
    progress = 0.7620253;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step1.ogg", FMOD_3D);
    progress = 0.7628692;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step2.ogg", FMOD_3D);
    progress = 0.76371306;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/Step3.ogg", FMOD_3D);
    progress = 0.76455694;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049/TakeOffHazmat.ogg", FMOD_3D);
    progress = 0.7654008;
    // SFX\SCP\049_2
    progress = 0.7662447;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/049_2/Breath.ogg", FMOD_3D);
    progress = 0.7670886;
    // SFX\SCP\066
    progress = 0.7679325;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Beethoven.ogg", FMOD_2D);
    progress = 0.76877636;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric1.ogg", FMOD_3D);
    progress = 0.76962024;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric2.ogg", FMOD_3D);
    progress = 0.7704641;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Eric3.ogg", FMOD_3D);
    progress = 0.771308;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes1.ogg", FMOD_3D);
    progress = 0.7721519;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes2.ogg", FMOD_3D);
    progress = 0.77299577;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes4.ogg", FMOD_3D);
    progress = 0.77383965;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes5.ogg", FMOD_3D);
    progress = 0.77468354;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Notes6.ogg", FMOD_3D);
    progress = 0.7755274;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/066/Rolling.ogg", FMOD_3D);
    progress = 0.7763713;
    // SFX\SCP\079
    progress = 0.7772152;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast1.ogg", FMOD_2D);
    progress = 0.77805907;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast2.ogg", FMOD_2D);
    progress = 0.77890295;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast3.ogg", FMOD_2D);
    progress = 0.77974683;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast4.ogg", FMOD_2D);
    progress = 0.7805907;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast5.ogg", FMOD_2D);
    progress = 0.7814346;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast6.ogg", FMOD_2D);
    progress = 0.7822785;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast7.ogg", FMOD_2D);
    progress = 0.78312236;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Broadcast8.ogg", FMOD_2D);
    progress = 0.78396624;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/GateB.ogg", FMOD_2D);
    progress = 0.7848101;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Refuse.ogg", FMOD_3D);
    progress = 0.785654;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/Speech.ogg", FMOD_3D);
    progress = 0.7864979;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/079/TestroomWarning.ogg", FMOD_2D);
    progress = 0.7873418;
    // SFX\SCP\096
    progress = 0.78818566;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/ElevatorSlam.ogg", FMOD_2D);
    progress = 0.78902954;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/Scream.ogg", FMOD_3D);
    progress = 0.7898734;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/096/Triggered.ogg", FMOD_2D);
    progress = 0.7907173;
    // SFX\SCP\106
    progress = 0.7915612;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Breathing.ogg", FMOD_3D);
    progress = 0.79240507;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion1.ogg", FMOD_3D);
    progress = 0.79324895;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion2.ogg", FMOD_3D);
    progress = 0.79409283;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Corrosion3.ogg", FMOD_3D);
    progress = 0.7949367;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay0.ogg", FMOD_3D);
    progress = 0.7957806;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay2.ogg", FMOD_3D);
    progress = 0.7966245;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Decay3.ogg", FMOD_3D);
    progress = 0.79746836;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Laugh.ogg", FMOD_2D);
    progress = 0.79831225;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/Laugh2.ogg", FMOD_2D);
    progress = 0.7991561;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay1.ogg", FMOD_3D);
    progress = 0.8;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay2.ogg", FMOD_3D);
    progress = 0.8008439;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/106/WallDecay3.ogg", FMOD_3D);
    progress = 0.8016878;
    // SFX\SCP\109
    progress = 0.80253166;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/109/Ahh.ogg", FMOD_2D);
    progress = 0.80337554;
    // SFX\SCP\173
    progress = 0.8042194;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap1.ogg", FMOD_2D);
    progress = 0.8050633;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap2.ogg", FMOD_2D);
    progress = 0.8059072;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/NeckSnap3.ogg", FMOD_2D);
    progress = 0.8067511;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle1.ogg", FMOD_3D);
    progress = 0.80759495;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle2.ogg", FMOD_3D);
    progress = 0.80843884;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/Rattle3.ogg", FMOD_3D);
    progress = 0.8092827;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/173/StoneDrag.ogg", FMOD_3D);
    progress = 0.8101266;
    // SFX\SCP\198
    progress = 0.8109705;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/198/Shock.ogg", FMOD_2D);
    progress = 0.81181437;
    // SFX\SCP\205
    progress = 0.81265825;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/205/Enter.ogg", FMOD_2D);
    progress = 0.81350213;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/205/Horror.ogg", FMOD_2D);
    progress = 0.814346;
    // SFX\SCP\215
    progress = 0.8151899;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/215/Whisper.ogg", FMOD_2D);
    progress = 0.8160338;
    // SFX\SCP\294
    progress = 0.81687766;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ahh.ogg", FMOD_2D);
    progress = 0.81772155;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Burn.ogg", FMOD_2D);
    progress = 0.8185654;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Coin_Drop.ogg", FMOD_3D);
    progress = 0.8194093;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Cough.ogg", FMOD_2D);
    progress = 0.8202532;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense0.ogg", FMOD_3D);
    progress = 0.8210971;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense1.ogg", FMOD_3D);
    progress = 0.8219409;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense2.ogg", FMOD_3D);
    progress = 0.8227848;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Dispense3.ogg", FMOD_3D);
    progress = 0.82362866;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ew1.ogg", FMOD_2D);
    progress = 0.82447255;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Ew2.ogg", FMOD_2D);
    progress = 0.8253164;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/OutOfRange.ogg", FMOD_3D);
    progress = 0.8261603;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Retch1.ogg", FMOD_2D);
    progress = 0.8270042;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Retch2.ogg", FMOD_2D);
    progress = 0.8278481;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Slurp.ogg", FMOD_2D);
    progress = 0.82869196;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Spit.ogg", FMOD_2D);
    progress = 0.82953584;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/294/Vomit.ogg", FMOD_2D);
    progress = 0.8303797;
    // SFX\SCP\372
    progress = 0.8312236;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle0.ogg", FMOD_2D);
    progress = 0.8320675;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle1.ogg", FMOD_2D);
    progress = 0.8329114;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle2.ogg", FMOD_2D);
    progress = 0.83375525;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle3.ogg", FMOD_2D);
    progress = 0.83459914;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle4.ogg", FMOD_2D);
    progress = 0.835443;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle5.ogg", FMOD_2D);
    progress = 0.8362869;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/372/Rustle6.ogg", FMOD_2D);
    progress = 0.8371308;
    // SFX\SCP\427
    progress = 0.83797467;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/427/Effect.ogg", FMOD_2D);
    progress = 0.83881855;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/427/Transform.ogg", FMOD_2D);
    progress = 0.83966243;
    // SFX\SCP\457
    progress = 0.8405063;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/457/FireLoop.ogg", FMOD_3D);
    progress = 0.8413502;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/457/Sighting.ogg", FMOD_2D);
    progress = 0.8421941;
    // SFX\SCP\513
    progress = 0.84303796;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/914Refine.ogg", FMOD_3D);
    progress = 0.84388185;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell1.ogg", FMOD_2D);
    progress = 0.8447257;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell2.ogg", FMOD_2D);
    progress = 0.8455696;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell3.ogg", FMOD_2D);
    progress = 0.8464135;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/513/Bell4.ogg", FMOD_2D);
    progress = 0.8472574;
    // SFX\SCP\682
    progress = 0.84810126;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/682/Roar.ogg", FMOD_2D);
    progress = 0.84894514;
    // SFX\SCP\789
    progress = 0.849789;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/789/butt.ogg", FMOD_3D);
    progress = 0.8506329;
    // SFX\SCP\860
    progress = 0.8514768;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer0.ogg", FMOD_2D);
    progress = 0.8523207;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer1.ogg", FMOD_2D);
    progress = 0.85316455;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer2.ogg", FMOD_2D);
    progress = 0.85400844;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer3.ogg", FMOD_2D);
    progress = 0.8548523;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer4.ogg", FMOD_2D);
    progress = 0.8556962;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Cancer5.ogg", FMOD_2D);
    progress = 0.8565401;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Chase1.ogg", FMOD_2D);
    progress = 0.85738397;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/860/Chase2.ogg", FMOD_2D);
    progress = 0.85822785;
    // SFX\SCP\914
    progress = 0.85907173;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/DoorClose.ogg", FMOD_3D);
    progress = 0.8599156;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/DoorOpen.ogg", FMOD_3D);
    progress = 0.8607595;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/PlayerDeath.ogg", FMOD_2D);
    progress = 0.8616034;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/PlayerUse.ogg", FMOD_2D);
    progress = 0.86244726;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/914/Refining.ogg", FMOD_3D);
    progress = 0.86329114;
    // SFX\SCP\939
    progress = 0.864135;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert1.ogg", FMOD_3D);
    progress = 0.8649789;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert2.ogg", FMOD_3D);
    progress = 0.8658228;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Alert3.ogg", FMOD_3D);
    progress = 0.8666667;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack1.ogg", FMOD_3D);
    progress = 0.86751056;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack2.ogg", FMOD_3D);
    progress = 0.86835444;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Attack3.ogg", FMOD_3D);
    progress = 0.8691983;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure1.ogg", FMOD_3D);
    progress = 0.8700422;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure2.ogg", FMOD_3D);
    progress = 0.8708861;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure3.ogg", FMOD_3D);
    progress = 0.87172997;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure4.ogg", FMOD_3D);
    progress = 0.87257385;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure5.ogg", FMOD_3D);
    progress = 0.87341774;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure6.ogg", FMOD_3D);
    progress = 0.8742616;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure7.ogg", FMOD_3D);
    progress = 0.8751055;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure8.ogg", FMOD_3D);
    progress = 0.8759494;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure9.ogg", FMOD_3D);
    progress = 0.87679327;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/0Lure10.ogg", FMOD_3D);
    progress = 0.87763715;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert1.ogg", FMOD_3D);
    progress = 0.87848103;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert2.ogg", FMOD_3D);
    progress = 0.8793249;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Alert3.ogg", FMOD_3D);
    progress = 0.8801688;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack1.ogg", FMOD_3D);
    progress = 0.8810127;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack2.ogg", FMOD_3D);
    progress = 0.88185656;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Attack3.ogg", FMOD_3D);
    progress = 0.88270044;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure1.ogg", FMOD_3D);
    progress = 0.8835443;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure2.ogg", FMOD_3D);
    progress = 0.8843882;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure3.ogg", FMOD_3D);
    progress = 0.8852321;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure4.ogg", FMOD_3D);
    progress = 0.886076;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure5.ogg", FMOD_3D);
    progress = 0.88691986;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure6.ogg", FMOD_3D);
    progress = 0.88776374;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure7.ogg", FMOD_3D);
    progress = 0.8886076;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure8.ogg", FMOD_3D);
    progress = 0.8894515;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure9.ogg", FMOD_3D);
    progress = 0.8902954;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/1Lure10.ogg", FMOD_3D);
    progress = 0.89113927;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert1.ogg", FMOD_3D);
    progress = 0.89198315;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert2.ogg", FMOD_3D);
    progress = 0.89282703;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Alert3.ogg", FMOD_3D);
    progress = 0.89367086;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack1.ogg", FMOD_3D);
    progress = 0.89451474;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack2.ogg", FMOD_3D);
    progress = 0.8953586;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Attack3.ogg", FMOD_3D);
    progress = 0.8962025;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure1.ogg", FMOD_3D);
    progress = 0.8970464;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure2.ogg", FMOD_3D);
    progress = 0.89789027;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure3.ogg", FMOD_3D);
    progress = 0.89873415;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure4.ogg", FMOD_3D);
    progress = 0.89957803;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure5.ogg", FMOD_3D);
    progress = 0.9004219;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure6.ogg", FMOD_3D);
    progress = 0.9012658;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure7.ogg", FMOD_3D);
    progress = 0.9021097;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure8.ogg", FMOD_3D);
    progress = 0.90295357;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure9.ogg", FMOD_3D);
    progress = 0.90379745;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure10.ogg", FMOD_3D);
    progress = 0.90464133;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/2Lure11.ogg", FMOD_3D);
    progress = 0.9054852;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/939/Attack.ogg", FMOD_2D);
    progress = 0.9063291;
    // SFX\SCP\966
    progress = 0.907173;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo1.ogg", FMOD_2D);
    progress = 0.90801686;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo2.ogg", FMOD_2D);
    progress = 0.90886074;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Echo3.ogg", FMOD_2D);
    progress = 0.9097046;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle1.ogg", FMOD_2D);
    progress = 0.9105485;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle2.ogg", FMOD_2D);
    progress = 0.9113924;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/966/Idle3.ogg", FMOD_2D);
    progress = 0.9122363;
    // SFX\SCP\970
    progress = 0.91308016;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/970/Corpse.ogg", FMOD_2D);
    progress = 0.91392404;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/970/FCVENY.ogg", FMOD_2D);
    progress = 0.9147679;
    // SFX\SCP\990
    progress = 0.9156118;
    /// ALREADY LOADED BY LOADING SCREEN AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm1.ogg", FMOD_2D);
    progress = 0.9164557;
    /// ALREADY LOADED BY LOADING SCREEN AudioEngine::LoadSoundByName("Assets/SFX/SCP/990/cwm2.ogg", FMOD_2D);
    progress = 0.91729957;
    // SFX\SCP\1033RU
    progress = 0.91814345;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage0.ogg", FMOD_2D);
    progress = 0.91898733;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage1.ogg", FMOD_2D);
    progress = 0.9198312;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage2.ogg", FMOD_2D);
    progress = 0.9206751;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/Damage3.ogg", FMOD_2D);
    progress = 0.921519;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1033RU/SCPDeath.ogg", FMOD_2D);
    progress = 0.92236286;
    // SFX\SCP\1048A
    progress = 0.92320675;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1048A/Growth.ogg", FMOD_2D);
    progress = 0.9240506;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1048A/Shriek.ogg", FMOD_3D);
    progress = 0.9248945;
    // SFX\SCP\1079
    progress = 0.9257384;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1079/BubbleSizz0.ogg", FMOD_2D);
    progress = 0.9265823;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1079/BubbleSizz1.ogg", FMOD_2D);
    progress = 0.92742616;
    // SFX\SCP\1123
    progress = 0.92827004;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Ambient.ogg", FMOD_2D);
    progress = 0.9291139;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Gunshot.ogg", FMOD_3D);
    progress = 0.9299578;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Horror.ogg", FMOD_2D);
    progress = 0.9308017;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer1.ogg", FMOD_3D);
    progress = 0.9316456;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer2.ogg", FMOD_3D);
    progress = 0.93248945;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Officer3.ogg", FMOD_3D);
    progress = 0.93333334;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1123/Touch.ogg", FMOD_2D);
    progress = 0.9341772;
    // SFX\SCP\1162
    progress = 0.9350211;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange1.ogg", FMOD_3D);
    progress = 0.935865;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange2.ogg", FMOD_3D);
    progress = 0.93670887;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange3.ogg", FMOD_3D);
    progress = 0.93755275;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/BodyHorrorExchange4.ogg", FMOD_3D);
    progress = 0.93839663;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange0.ogg", FMOD_3D);
    progress = 0.9392405;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange1.ogg", FMOD_3D);
    progress = 0.9400844;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange2.ogg", FMOD_3D);
    progress = 0.9409283;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange3.ogg", FMOD_3D);
    progress = 0.94177216;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/Exchange4.ogg", FMOD_3D);
    progress = 0.94261605;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer1.ogg", FMOD_2D);
    progress = 0.9434599;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer2.ogg", FMOD_2D);
    progress = 0.9443038;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer3.ogg", FMOD_2D);
    progress = 0.9451477;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer4.ogg", FMOD_2D);
    progress = 0.9459916;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer5.ogg", FMOD_2D);
    progress = 0.94683546;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer6.ogg", FMOD_2D);
    progress = 0.94767934;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer7.ogg", FMOD_2D);
    progress = 0.9485232;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer8.ogg", FMOD_2D);
    progress = 0.9493671;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer9.ogg", FMOD_2D);
    progress = 0.950211;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1162/NostalgiaCancer10.ogg", FMOD_2D);
    progress = 0.9510549;
    // SFX\SCP\1499
    progress = 0.95189875;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Enter.ogg", FMOD_2D);
    progress = 0.95274264;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Exit.ogg", FMOD_2D);
    progress = 0.9535865;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle1.ogg", FMOD_2D);
    progress = 0.9544304;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle2.ogg", FMOD_2D);
    progress = 0.9552743;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle3.ogg", FMOD_2D);
    progress = 0.95611817;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Idle4.ogg", FMOD_2D);
    progress = 0.95696205;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/1499/Triggered.ogg", FMOD_2D);
    progress = 0.95780593;
    // SFX\SCP\Joke
    progress = 0.9586498;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/789J.ogg", FMOD_2D);
    progress = 0.9594937;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/Quack.ogg", FMOD_3D);
    progress = 0.9603376;
    AudioEngine::LoadSoundByName("Assets/SFX/SCP/Joke/Saxophone.ogg", FMOD_3D);
    progress = 0.96118146;

    progress = 0.96202534;
    // SFX\Step
    progress = 0.9628692;
    // SFX\Step\SCP
    progress = 0.9637131;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP1.ogg", FMOD_3D);
    progress = 0.96455693;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP2.ogg", FMOD_3D);
    progress = 0.9654008;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP3.ogg", FMOD_3D);
    progress = 0.9662447;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/SCP/StepSCP4.ogg", FMOD_3D);
    progress = 0.9670886;
    // SFX\Step
    progress = 0.96793246;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run1.ogg", FMOD_2D);
    progress = 0.96877635;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run2.ogg", FMOD_2D);
    progress = 0.9696202;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run3.ogg", FMOD_2D);
    progress = 0.9704641;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run4.ogg", FMOD_2D);
    progress = 0.971308;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run5.ogg", FMOD_2D);
    progress = 0.9721519;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run6.ogg", FMOD_2D);
    progress = 0.97299576;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run7.ogg", FMOD_2D);
    progress = 0.97383964;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Run8.ogg", FMOD_2D);
    progress = 0.9746835;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal1.ogg", FMOD_2D);
    progress = 0.9755274;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal2.ogg", FMOD_2D);
    progress = 0.9763713;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal3.ogg", FMOD_2D);
    progress = 0.9772152;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal4.ogg", FMOD_2D);
    progress = 0.97805905;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal5.ogg", FMOD_2D);
    progress = 0.97890294;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal6.ogg", FMOD_2D);
    progress = 0.9797468;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal7.ogg", FMOD_2D);
    progress = 0.9805907;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/RunMetal8.ogg", FMOD_2D);
    progress = 0.9814346;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step1.ogg", FMOD_2D);
    progress = 0.98227847;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step2.ogg", FMOD_2D);
    progress = 0.98312235;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step3.ogg", FMOD_2D);
    progress = 0.98396623;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step4.ogg", FMOD_2D);
    progress = 0.9848101;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step5.ogg", FMOD_2D);
    progress = 0.985654;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step6.ogg", FMOD_2D);
    progress = 0.9864979;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step7.ogg", FMOD_2D);
    progress = 0.98734176;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/Step8.ogg", FMOD_2D);
    progress = 0.98818564;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest1.ogg", FMOD_2D);
    progress = 0.9890295;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest2.ogg", FMOD_2D);
    progress = 0.9898734;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepForest3.ogg", FMOD_2D);
    progress = 0.9907173;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal1.ogg", FMOD_2D);
    progress = 0.9915612;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal2.ogg", FMOD_2D);
    progress = 0.99240506;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal3.ogg", FMOD_2D);
    progress = 0.99324894;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal4.ogg", FMOD_2D);
    progress = 0.9940928;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal5.ogg", FMOD_2D);
    progress = 0.9949367;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal6.ogg", FMOD_2D);
    progress = 0.9957806;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal7.ogg", FMOD_2D);
    progress = 0.99662447;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepMetal8.ogg", FMOD_2D);
    progress = 0.99746835;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD1.ogg", FMOD_2D);
    progress = 0.99831223;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD2.ogg", FMOD_2D);
    progress = 0.9991561;
    AudioEngine::LoadSoundByName("Assets/SFX/Step/StepPD3.ogg", FMOD_2D);
    progress = 1;
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
std::string text1;
std::string text2;
std::string text3;
std::string text4;
int textAmount = 0;

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
    } else if (alignY == "Right") {
        if (alignX == "Left") {
            loadingScreenImagePosition = BottomLeft;
        } else if (alignX == "Center") {
            loadingScreenImagePosition = BottomLeft;
        } else if (alignX == "Right") {
            loadingScreenImagePosition = BottomRight;
        }
    }
    
    if (parsedToml[title]["DisableBackground"].is_boolean()) {
        disableBackground = parsedToml[title]["DisableBackground"].value_exact<bool>().value();
    }
    
    if (parsedToml[title]["Text1"].is_string()) {
        text1 = parsedToml[title]["Text1"].value_exact<std::string>().value();
        textAmount++;
    }
    
    if (parsedToml[title]["Text2"].is_string()) {
        text2 = parsedToml[title]["Text2"].value_exact<std::string>().value();
        textAmount++;
    }
    
    if (parsedToml[title]["Text3"].is_string()) {
        text3 = parsedToml[title]["Text3"].value_exact<std::string>().value();
        textAmount++;
    }
    
    if (parsedToml[title]["Text4"].is_string()) {
        text4 = parsedToml[title]["Text4"].value_exact<std::string>().value();
        textAmount++;
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
}

bool cyclingTextStarted = false;

void cycleTextThread() {
    cyclingTextStarted = true;
    while (cyclingTextStarted) {
        if (!text1.empty()) {
            currentText = text1;
            Sleep(13000);
        }
        if (!text2.empty()) {
            currentText = text2;
            Sleep(13000);
        }
        if (!text3.empty()) {
            currentText = text3;
            Sleep(13000);
        }
        if (!text4.empty()) {
            currentText = text4;
            Sleep(13000);
        }
    }
}

void PreloadManager::Render(GLFWwindow* window, GlobalGameState* gameState) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    // RENDER LOADING SCREEN IMAGE
    {
        int targetSize = height / 2.5f;

        ImVec2 targetPosition;
        
        switch (loadingScreenImagePosition) {
            case TopLeft: {
                targetPosition = ImVec2(0, 0);
                break;
            }
            case TopCenter: {
                targetPosition = ImVec2((width / 2.0f) - (targetSize / 2.0f), 0);
                break;
            }
            case TopRight: {
                targetPosition = ImVec2(width - targetSize, 0);
                break;
            }
            case CenterLeft: {
                targetPosition = ImVec2(0, (height / 2.0f) - (targetSize / 2.0f));
                break;
            }
            case CenterCenter: {
                targetPosition = ImVec2((width / 2.0f) - (targetSize / 2.0f), (height / 2.0f) - (targetSize / 2.0f));
                break;
            }
            case CenterRight: {
                targetPosition = ImVec2(width - targetSize, (height / 2.0f) - (targetSize / 2.0f));
                break;
            }
            case BottomLeft: {
                targetPosition = ImVec2(0, height - targetSize);
                break;
            }
            case BottomCenter: {
                targetPosition = ImVec2((width / 2.0f) - (targetSize / 2.0f), height - targetSize);
                break;
            }
            case BottomRight: {
                targetPosition = ImVec2(width - targetSize, height - targetSize);
                break;
            }
        }

        ImGui::SetNextWindowPos(targetPosition);
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
        ImGui::SetNextWindowPos(ImVec2((width / 2) - (targetSize / 2), (height / 2) - (targetSize / 2)));
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
        ImVec2 targetSize = ImVec2(Util::Math::ClampMin(width / 3, 750), Util::Math::ClampMax(height / 1.5f, 700.0f));
        
        ImGui::SetNextWindowSize(targetSize);
        ImGui::SetNextWindowPos(ImVec2((width / 2) - (targetSize.x / 2), (height / 2) - (targetSize.y / 2)));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::Begin("## BACKGROUND-IMAGE", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 1));
        ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.827f, 0, 0, 1));
        ImGui::SetCursorPosX(5);
        ImGui::ProgressBar(ProcessPreload(), ImVec2(targetSize.x - 10, 0));
        ImGui::PopStyleColor(2);
        ImGui::PopStyleVar();
        
        ImGui::Text("");
        ImGui::Text("");
        ImGui::Text("");
        ImGui::Text("");
        ImGui::Text("");
        ImGui::Text("");
        
        ImGui::PushFont(Localization::GetActiveLanguageCourierNewLarge());
        ImGui::TextCentered(title.c_str());
        ImGui::PopFont();

        ImGui::Text("");
        ImGui::Text("");

        if (!cyclingTextStarted) {
            std::thread(cycleTextThread).detach();
        }

        if (!currentText.empty()) {
            ImGui::TextWrappedCentered(Localization::GetTranslatedKey("LoadingScreens", currentText).c_str());
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
        }
        
        ImGui::End();
        ImGui::PopStyleColor(2);
    }
}

void PreloadManager::Free() {
    if (!disableBackground) {
        delete loadingScreenBackgroundImage;
    }
    delete loadingScreenImage;
}