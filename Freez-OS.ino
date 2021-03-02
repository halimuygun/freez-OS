/*
   Freez-OS refrigerator firmware for Arduino IDE
   https://github.com/halimuygun/freez-OS

   @author Halim Uygun
   https://www.halimuygun.com

   Licensed under GPL-3.0
   https://opensource.org/licenses/GPL-3.0

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   Revision Date: March 13, 2020
   Version: 0.1.0
*/

#include "Arduino.h"
#include "Math.h"
#include "Configuration.h"
#include "Language.h"
#include "Command.h"
#include "Temperature.h"


void setup() {
  pinMode(PIN_FREZ_LAMP, OUTPUT);
  pinMode(PIN_REFR_LAMP, OUTPUT);
  pinMode(PIN_FREZ_FAN, OUTPUT);
  pinMode(PIN_REFR_FAN, OUTPUT);
  pinMode(PIN_FREZ_HEATER, OUTPUT);
  pinMode(PIN_REFR_HEATER, OUTPUT);
  pinMode(PIN_COMPRESSOR, OUTPUT);
  pinMode(PIN_COMPRESSOR_FAN, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);

  pinMode(LED_COOL, OUTPUT);
  pinMode(LED_TEMPLIMIT, OUTPUT);
  pinMode(LED_DEFROST, OUTPUT);

  pinMode((int)SN_FREZ_DOOR, INPUT);
  pinMode((int)SN_REFR_DOOR, INPUT);
  pinMode((int)SN_FREZ_TEMP, INPUT);
  pinMode((int)SN_REFR_TEMP, INPUT);
  pinMode((int)SN_FREZ_HEAT_TEMP, INPUT);
  pinMode((int)SN_REFR_HEAT_TEMP, INPUT);
  pinMode((int)SN_LIMIT_TEMP, INPUT);

  Serial.begin(SERIAL_BOUD_RATE);

  if(Serial) {
    sendSerial(TXT_STARTED);
  }  
}

void loop() {
  timeLoop();
  readTemperatures();
  checkTemperatureLimit();



  
}
