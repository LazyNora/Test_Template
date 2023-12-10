#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#define ARRAY1D
#define STRUCT
#include "Struct/Struct.h"
#include "Config.h"
#include "Default.h"

int main(void) {
	ItemStruct item = { "abc", "def", "ghi", 1.1f, 2 };
	ItemStruct_print(item);
	(void)getch();
}

//int main(void) {
//	int option = 0;
//	INIT;
//
//	do
//	{
//		FUNC(menu)();
//		printf(OPTION_SELECT);
//		if (!scanf("%d", &option))
//			option = -1;
//		Flush();
//
//		switch (option)
//		{
//		case 0:
//			printf(OPTION_EXIT);
//			break;
//		case 1:
//			if (!FUNC(scan)(ARRAY))
//				printf("Nhap that bai!\n");
//			else {
//				printf("Nhap thanh cong!\n");
//				FUNC(print)(ARRAY);
//			}
//			break;
//		case 2:
//			FUNC(print)(ARRAY);
//			break;
//		case 3:
//			if (!FUNC(random)(ARRAY))
//				printf("Tao that bai!\n");
//			else {
//				printf("Tao thanh cong!\n");
//				FUNC(print)(ARRAY);
//			}
//			break;
//		case 4:
//			if (!FUNC(readFromFile)(ARRAY, inputFile))
//				printf("Doc file that bai!\n");
//			else {
//				printf("Doc file thanh cong!\n");
//				FUNC(print)(ARRAY);
//			}
//			break;
//		case 5:
//			if (!FUNC(writeToFile)(ARRAY, outputFile))
//				printf("Ghi file that bai!\n");
//			break;
//		default:
//			printf(OPTION_ERROR);
//			break;
//		}
//
//		if (option != 0) {
//			printf("Nhan phim bat ki de tiep tuc!");
//			(void)getch();
//			printf("\n\n");
//		}
//
//	} while (option != 0);
//
//	FUNC(free)(ARRAY);
//	(void)getch();
//}