#ifndef LANGUAGE_H
#define LANGUAGE_H

//#include "Configuration.h"
#include "Language_en.h"
#include "Language_tr.h"

#if   LANGUAGE_SELECT == "tr" // Turkish
  #include "language_tr.h"
#elif LANGUAGE_SELECT == "en" // English
  #include "language_en.h"
#endif

#endif
