#include "Default.h"

void EnterNumber(int& x, const char* msg, bool (*check)(int)) {
	bool flag = false;
	do
	{
		flag = false;
		printf(msg);
		if (!scanf("%d", &x))
			flag = true;
		Flush();
		if (flag || !check(x))
			printf(NUMBER_ERROR);
	} while (flag || !check(x));
}

void Flush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

const char* TextFormat(const char* format, ...) {
	static char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	return buffer;
}