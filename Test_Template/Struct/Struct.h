#ifndef STRUCT_H_
#define STRUCT_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../Config.h"
#include "../Default.h"

#define STR1_LEN 15
#define STR2_LEN 10
#define STR3_LEN 5
#define FLOAT_LEN 7
#define INT_LEN 4
#define FLOAT_DECIMAL 2
#define BORDER "|"

#define PRINT_FORMAT BORDER " %-" STR2(STR1_LEN) "s " BORDER " %-" STR2(STR2_LEN) "s " BORDER " %-" STR2(STR3_LEN) "s " BORDER " %-" STR2(FLOAT_LEN) "." STR2(FLOAT_DECIMAL) "f " BORDER " %-" STR2(INT_LEN) "d " BORDER "\n"

struct ItemStruct {
	char str1[STR1_LEN];
	char str2[STR2_LEN];
	char str3[STR3_LEN];
	float f;
	int i;
};

//typedef ItemStruct ItemType;

void ItemStruct_scan(ItemStruct& x, const char* msg);
void ItemStruct_print(ItemStruct x);

#endif // !STRUCT_H_
