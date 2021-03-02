// This function file is about thermal measurement.

#ifndef COMMAND_H
#define COMMAND_H

#include "Configuration.h"

bool MIN = false;

void getTimeStamp() {
  int HR = SECOND / 3600;
  int MN = (SECOND % 3600) / 60;
  int SC = (SECOND % 3600) % 60;
  TIME_STAMP = String(HR) + ":" + String(MN) + ":" + String(SC);

  delay(1000);
}

void sendSerial(String TEXT) {
  if (SERIAL_POST)
    Serial.println(TEXT);
}

void sendTelemetry() {

}

void resetSystem() {
  if (RESET_MODE == "on")
  {
    digitalWrite(PIN_RESET, HIGH);
    delay(500);
    digitalWrite(PIN_RESET, LOW);
    CRITICAL_TIME = 0;
  }
}

void timeLoop() {
  getTimeStamp();

  // Every second jobs here
  String SERIAL_DATA_TEXT = "[" + TIME_STAMP + "]  Refr Temp: " + String(ACTUAL_REFR_TEMP) + ", Critical Time: " + String(CRITICAL_TIME) + " sec";

  sendSerial(SERIAL_DATA_TEXT);
  sendTelemetry();

  if (CRITICAL_TIME > RESET_TIME)
    resetSystem();


  if ((SECOND % 60) == 0)
    MIN = true;

  if (MIN)
  {
    // Every minute jobs here



    // Next minute
    MINUTE += 1;
    MIN = false;
  }

  // Next second
  SECOND += 1;
}

#endif
