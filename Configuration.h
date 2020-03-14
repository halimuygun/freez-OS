// This configuration file contains the basic settings.

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

////////////////////    Settings    ////////////////////
#define LANGUAGE_CHOICE         "tr"
#define SERIAL_POST             "on"
#define RESET_MODE              "on"

////////////////////    Setup Values    ////////////////////
// FREZ: FREEZER
// REFR: REFRIGERATOR

#define FREZ_SET_TEMP         -18
#define REFR_SET_TEMP           4

#define FREZ_LIMIT_TEMP       -16
#define REFR_LIMIT_TEMP         6

#define FREZ_HEAT_LIMIT_TEMP   50
#define REFR_HEAT_LIMIT_TEMP   50


////////////////////    Pins    ////////////////////
// Outputs
#define PIN_FREZ_LAMP           2
#define PIN_REFT_LAMP           3
#define PIN_FREZ_FAN            4
#define PIN_REFT_FAN            5
#define PIN_FREZ_HEATER         6
#define PIN_REFT_HEATER         7
#define PIN_COMPRESSOR          8
#define PIN_COMPRESSOR_FAN      9

// Leds
#define LED_COOL               10
#define LED_TEMPLIMIT          11
#define LED_DEFROST            12

// Sensors
#define SN_FREZ_DOOR           A0
#define SN_REFT_DOOR           A1
#define SN_FREZ_TEMP           A2
#define SN_REFT_TEMP           A3
#define SN_FREZ_HEAT_TEMP      A4
#define SN_REFT_HEAT_TEMP      A5
#define SN_X                   A6
#define SN_Y                   A7


#endif

