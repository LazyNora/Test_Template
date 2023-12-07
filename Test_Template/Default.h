#ifndef DEFAULT_H_
#define DEFAULT_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "Config.h"

#define INTERGER [](int x) { return true; }
#define POSITIVE [](int x) { return x > 0; }
#define RANGE(X,Y) [](int x) { return x >= X && x <= Y; }

void Flush();
void EnterNumber(int& x, const char* msg = INTERGER_MSG, bool (*check)(int) = INTERGER);
const char* TextFormat(const char* format, ...);

#endif // !DEFAULT_H_