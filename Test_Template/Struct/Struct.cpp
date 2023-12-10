#include "Struct.h"

void ItemStruct_print(ItemStruct x){
	printf(PRINT_FORMAT, x.str1, x.str2, x.str3, x.f, x.i);
}

void ItemStruct_scan(ItemStruct& x, const char* msg) {
	return;
}