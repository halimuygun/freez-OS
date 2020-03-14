#ifndef LANGUAGE_H
#define LANGUAGE_H

#if   LANGUAGE_CHOICE == "tr" // Turkish
  #include "language_tr.h"
#elif LANGUAGE_CHOICE == "en" // English
  #include "language_en.h"
#endif

#endif