#include <stdio.h>
#include <conio.h>

#define ARRAY1D
#define DEFAULT_IMPLEMENTATION
#include "Default.h"
#include "Config.h"

int main(void) {
	ItemType* a = NULL;
	int n = 0;
	int option = 0;

	do
	{
		FUNC(menu)();
		printf(OPTION_SELECT);
		if (!scanf("%d", &option))
			option = -1;
		Flush;

		switch (option)
		{
		case 0:
			printf(OPTION_EXIT);
			break;
		case 1:
			if (!FUNC(scan)(a, n))
				printf("Nhap mang that bai!\n");
			else {
				printf("Nhap mang thanh cong!\n");
				FUNC(print)(a, n);
			}
			break;
		case 2:
			FUNC(print)(a, n);
			break;
		case 3:
			if (!FUNC(random)(a, n))
				printf("Tao mang that bai!\n");
			else {
				printf("Tao mang thanh cong!\n");
				FUNC(print)(a, n);
			}
			break;
		case 4:
			if (!FUNC(readFromFile)(a, n, inputFile))
				printf("Doc file that bai!\n");
			else {
				printf("Doc file thanh cong!\n");
				FUNC(print)(a, n);
			}
			break;
		case 5:
			if (!FUNC(writeToFile)(a, n, outputFile))
				printf("Ghi file that bai!\n");
			break;
		default:
			printf(OPTION_ERROR);
			break;
		}

		if (option != 0) {
			printf("Nhan phim bat ki de tiep tuc!\n\n");
			(void)getch();
		}

	} while (option != 0);

	(void)getch();
}