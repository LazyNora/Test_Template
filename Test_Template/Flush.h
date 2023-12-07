#ifndef FLUSH_H_
#define FLUSH_H_

#include <stdio.h>

void flush();

#endif // !FLUSH_H_

#ifdef FLUSH_IMPLEMENTATION

void flush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

#endif // FLUSH_IMPLEMENTATION