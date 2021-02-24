// This function file is about thermal measurement.

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Arduino.h"
#include "Configuration.h"

double readAVGTemperature(int ADC_PIN) {
  double val = 0;
  for (int i = 0; i < 20; i++) {
    val += analogRead(ADC_PIN);
    delay(1);
  }

  val = val / 20; // AVG
  return val;
}

//double Termistor(int tRead) {
//  double temp;
//  //sicaklik = log(((12000000 / analogOkuma) - 4800));
//  temp = log(((10230000 / tRead) - 5000));
//  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
//  temp = temp - 273.15;
//  return temp;
//}

double calculateThermistor(double ADC) { //Steinhart-Hart
  double V_NTC = (VCC * ADC) / 1023;
  double R_NTC = (RS_THERMISTOR * V_NTC) / (VCC - V_NTC);
  R_NTC = log(R_NTC);
  R_NTC = R_NTC * THERMISTOR_TOLERANCE;
  double Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * R_NTC * R_NTC )) * R_NTC );
  Temp = Temp - 273.15;
  return Temp;
}

//    double readThermistorTable() {
//
//    }


void checkTemperatureLimit(String AREA) {
  int PIN, LIMIT;

  if (AREA == "REFR")
  {
    PIN = (int)SN_REFR_TEMP;
    LIMIT = REFR_LIMIT_TEMP;
  }
  else if (AREA == "FREZ")
  {
    PIN = (int)SN_FREZ_TEMP;
    LIMIT = FREZ_LIMIT_TEMP;
  }

  double TMP = calculateThermistor(readAVGTemperature(PIN));

  if (TMP >= LIMIT)  {
    CRITICAL_TEMP += 1;
    digitalWrite(LED_TEMPLIMIT, HIGH);
  }
  else
    digitalWrite(LED_TEMPLIMIT, LOW);

  if (TMP < LIMIT) {
    CRITICAL_TEMP = 0;
    digitalWrite(LED_COOL, HIGH);
  }
  else
    digitalWrite(LED_COOL, LOW);

}


#endif
