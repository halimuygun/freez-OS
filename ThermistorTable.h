// This thermistortable file contains the thermistor resistance values.

#ifndef THERMISTORTABLE_H
#define THERMISTORTABLE_H

#include "Configuration.h"

////////////////////    5k NTC    ////////////////////

#if (THERMISTOR == 5) // 0 to 40 degrees C
const short thermtable_5[41] = {
    12949, // 0 degrees C
    12424, // 1 degrees C
    11924, // 2 degrees C
    11447, // 3 degrees C
    10993, // 4 degrees C
    10559, // 5 degrees C
    10146, // 6 degrees C
    9752,  // 7 degrees C
    9375   // 8 degrees C
};
#endif

////////////////////    10k NTC    ////////////////////

#if (THERMISTOR == 10) // 0 to 40 degrees C
const short thermtable_10[41] = {
    31732, // 0 degrees C
    29996, // 1 degrees C
    28365, // 2 degrees C
    26834, // 3 degrees C
    25395, // 4 degrees C
    
};
#endif





#endif
