#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

#ifdef USE_DEBUG
#define PRINT_DEBUG(s)  printf ("%s: %s\n", __func__, s);
#else
#define PRINT_DEBUG(...)
#endif

#endif