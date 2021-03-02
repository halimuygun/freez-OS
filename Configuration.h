// This configuration file contains the basic settings.

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Language.h"

////////////////////    Settings    ////////////////////
#define LANGUAGE_SELECT         "tr"
#define SERIAL_POST             "on"
#define TELEMETRY_POST          "off"
#define RESET_MODE              "on"
#define SERIAL_BOUD_RATE        9600
#define WIFI_AP                 "***YOUR_SSID***"
#define WIFI_PASSWORD           "***WIFI_PASS***"
#define TOKEN                   "*****TOKEN*****"
#define MQTT_SERVER             "telemetry.mqtt.org"
#define DATA_POST_DURATION      1000 // Milisecond

////////////////////    Setup Values    ////////////////////
// FREZ: FREEZER
// REFR: REFRIGERATOR

#define FREZ_SET_TEMP          -16
#define REFR_SET_TEMP           4

#define FREZ_LIMIT_TEMP        -12
#define REFR_LIMIT_TEMP         8

#define FREZ_HEAT_LIMIT_TEMP    50
#define REFR_HEAT_LIMIT_TEMP    50

#define LIMIT_TEMP              8 // External sensor read temp
#define RESET_TIME              2700 // Minutes

////////////////////    Technique Values    ////////////////////
#define THERMISTOR              5 // Ex: 5 is 5k
#define THERMISTOR_TOLERANCE    1
#define VCC                     5 // 5 volt for arduino
#define RS_THERMISTOR           5000
#define THERMISTOR_MODE         "calc" // calc or table

////////////////////    Pins    ////////////////////
// Outputs
#define PIN_FREZ_LAMP           2
#define PIN_REFR_LAMP           3
#define PIN_FREZ_FAN            4
#define PIN_REFR_FAN            5
#define PIN_FREZ_HEATER         6
#define PIN_REFR_HEATER         7
#define PIN_COMPRESSOR          8
#define PIN_COMPRESSOR_FAN      9
#define PIN_RESET               6

// Leds
#define LED_COOL                2
#define LED_TEMPLIMIT           4
#define LED_DEFROST             12

// Sensors
#define SN_FREZ_DOOR            "A0"
#define SN_REFR_DOOR            "A1"
#define SN_FREZ_TEMP            "A2"
#define SN_REFR_TEMP            "A3"
#define SN_FREZ_HEAT_TEMP       "A4"
#define SN_REFR_HEAT_TEMP       "A6"
#define SN_LIMIT_TEMP           "A5"

////////////////////    Global Values    ////////////////////
String  TIME_STAMP              =   "00:00:00";
int     ACTUAL_FREZ_TEMP        =   0;
int     ACTUAL_REFR_TEMP        =   0;
int     ACTUAL_FREZ_HEAT_TEMP   =   0;
int     ACTUAL_REFR_HEAT_TEMP   =   0;
int     CRITICAL_TIME           =   0; // Minute
long    SECOND                  =   0;
long    MINUTE                  =   0;


#endif
