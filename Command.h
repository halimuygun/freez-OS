// This function file is about thermal measurement.

#ifndef COMMAND_H
#define COMMAND_H

#include "Configuration.h"

bool MINUTE = false;

void getTimeStamp() {
  int HR = SECOND / 3600;
  int MN = (SECOND % 3600) / 60;
  int SC = (SECOND % 3600) % 60;
  TIME_STAMP = String(HR) + ":" + String(MN) + ":" + String(SC);

  delay(1000);
}

void timeLoop() {
  getTimeStamp();

  // Every second jobs here

  
  if ((SECOND % 60) == 0)
    MINUTE = true;
  
  // Every minute jobs here
  if (MINUTE)
  {
    
    MINUTE = false;
  }

  // Next second
  SECOND += 1;
}

#endif
