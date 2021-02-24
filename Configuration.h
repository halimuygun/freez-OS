// This configuration file contains the basic settings.

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

////////////////////    Settings    ////////////////////
#define LANGUAGE_SELECT         "tr"
#define SERIAL_POST             "on"
#define TELEMETRY_POST          "off"
#define RESET_MODE              "on"
#define SERIAL_BOUD_RATE        9600
#define WIFI_AP                 "UYGUN 1.6Ghz"
#define WIFI_PASSWORD           "*NisA07:OmeR03*"
#define TOKEN                   "QXg6keBOlo2ZbqJueQYd"
#define THINGSBOARD_SERVER      "demo.thingsboard.io"
#define DATA_POST_DURATION      1000 //milisecond

////////////////////    Setup Values    ////////////////////
// FREZ: FREEZER
// REFR: REFRIGERATOR

#define FREZ_SET_TEMP         -18
#define REFR_SET_TEMP           4

#define FREZ_LIMIT_TEMP       -14
#define REFR_LIMIT_TEMP         8

#define FREZ_HEAT_LIMIT_TEMP   50
#define REFR_HEAT_LIMIT_TEMP   50

////////////////////    Technique Values    ////////////////////
#define THERMISTOR              5 // Ex: 5 is 5k
#define THERMISTOR_TOLERANCE    1
#define VCC                     5
#define RS_THERMISTOR           5000

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
#define SN_REFR_TEMP            "A5"
#define SN_FREZ_HEAT_TEMP       "A4"
#define SN_REFR_HEAT_TEMP       "A5"
#define SN_X                    "A6"
#define SN_Y                    "A7"

////////////////////    Global Values    ////////////////////
String  TIME_STAMP        =       "00:00:00";
String  SERIAL_DATA_TEXT  =       "";
int     ACTUAL_REFR_TEMP  =       0;
int     ACTUAL_FREZ_TEMP  =       0;
int     CRITICAL_TEMP     =       0;
long    SECOND            =       0;



#endif