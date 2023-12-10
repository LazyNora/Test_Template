#ifndef DEFAULT_H_
#define DEFAULT_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "Config.h"

#define INTERGER [](int x) { return true; }
#define POSITIVE [](int x) { return x > 0; }
#define RANGE(X,Y) [](int x) { return x >= X && x <= Y; }

#define STR(X) #X
#define STR2(X) STR(X)

void Flush();
void EnterNumber(int& x, const char* msg = INTERGER_MSG, bool (*check)(int) = INTERGER);
const char* TextFormat(const char* format, ...);
void printCenter(const char* str, int width = 0, char fill = ' ');

#endif // !DEFAULT_H_