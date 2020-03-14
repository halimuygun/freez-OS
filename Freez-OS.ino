/*
 * Freez-OS refrigerator firmware for Arduino IDE
 * https://github.com/halimuygun/freez-OS
 * 
 * @author Halim Uygun
 * https://www.halimuygun.com 
 * 
 * Licensed under GPL-3.0
 * https://opensource.org/licenses/GPL-3.0
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * Revision Date: March 13, 2020
 * Version: 0.1.0
 */

#include <math.h>
#include "Language.h"
#include "Configuration.h"


#define led_blue 2
#define led_red 4
#define pin_reset 6

long sec = 0;
bool everymin = false;
String timeNow = "00:00:00";
int critical = 0;
///

double Termistor(int analogOkuma) {
  double sicaklik;
  sicaklik = log(((12000000 / analogOkuma) - 4800));
  sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik)) * sicaklik);
  sicaklik = sicaklik - 273.15;
  return sicaklik;
}

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(pin_reset, OUTPUT);

  if(SERIAL_POST == "ON")
    Serial.begin(9600);
}

void loop() {
  int hour = sec / 3600;
  int minute = (sec % 3600)/60;
  int second = (sec % 3600) % 60;
  timeNow = String(hour) + ":" + String(minute) + ":" + String(second);

  double extTemperature = Termistor(analogRead(A5));
  
  if (extTemperature >= 7)  {
    critical += 1;
    digitalWrite(led_red, HIGH);
  }
  else
    digitalWrite(led_red, LOW);

//  if ((extTemperature < 10) & (extTemperature > 6)) {
//    critical = 0;
//    digitalWrite(led_yellow, HIGH);
//  }
//  else
//    digitalWrite(led_yellow, LOW);

  if (extTemperature < 7) {
    critical = 0;
    //digitalWrite(led_reboot, LOW);
    digitalWrite(led_blue, HIGH);
  }
  else
    digitalWrite(led_blue, LOW);


  if (critical > 2400)
  {
      //Serial.println("Rebooting..");
      //digitalWrite(led_reboot, HIGH);
      digitalWrite(pin_reset, HIGH);
      delay(500);
      digitalWrite(pin_reset, LOW);
      critical = 0;
  }

  String dataString = "[" + timeNow + "]  Internal Temp: " + String(extTemperature);
  dataString +=  ", Critical Time: " + String(critical) + " sec";

  if (everymin)
  {
    everymin = false;
  }

  //Serial.println(dataString);
  
  sec += 1;
  //if ((sec % 60) == 0)
  //   everymin = true;
     
  delay(1000);
}
