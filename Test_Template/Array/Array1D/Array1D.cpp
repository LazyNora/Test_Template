#include "Array1D.h"

int Array1D_random(ItemType*& a, int& n) {
	if (a)
		delete[] a;

	EnterNumber(n, NUMBEROFITEM_MSG, POSITIVE);

	a = new ItemType[n];
	if (!a) {
		printf(MEMORY_ALLOCATION_ERROR);
		return 0;
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = MIN + rand() % (MAX - MIN + 1);

	return 1;
}

int Array1D_scan(ItemType*& a, int& n) {
	if (a)
		delete[] a;

	EnterNumber(n, NUMBEROFITEM_MSG, POSITIVE);

	a = new ItemType[n];
	if (!a) {
		printf(MEMORY_ALLOCATION_ERROR);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		EnterNumber(a[i], TextFormat("Nhap a[%d]: ", i), INTERGER);
	}

	return 1;
}

void Array1D_print(ItemType* a, int n) {
	if (!a) {
		printf(ARRAY_EMPTY);
		return;
	}

	printf(ARRAY_PRINT_MSG);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int Array1D_readFromFile(ItemType*& a, int& n, const char* filename) {
	if (a)
		delete[] a;

	FILE* f = fopen(filename, "r");
	if (!f) {
		printf("Khong the mo file %s\n", filename);
		return 0;
	}

	if (!fscanf(f, "%d", &n))
		n = -1;
	Flush();
	if (n <= 0) {
		printf("So luong phan tu khong hop le!\n");
		fclose(f);
		return 0;
	}

	a = new ItemType[n];
	if (!a) {
		printf(MEMORY_ALLOCATION_ERROR);
		fclose(f);
		return 0;
	}

	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);

	fclose(f);
	return 1;
}

int Array1D_writeToFile(ItemType* a, int n, const char* filename) {
	if (!a) {
		printf(ARRAY_EMPTY);
		return 0;
	}

	FILE* f = fopen(filename, "w");
	if (!f) {
		printf("Khong the mo file %s\n", filename);
		return 0;
	}

	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(f, "%d ", a[i]);

	fclose(f);
	return 1;
}

void Array1D_menu() {
	printf("=============================================\n");
	printf("1. Nhap mang tu ban phim\n");
	printf("2. Xuat mang\n");
	printf("3. Tao mang ngau nhien\n");
	printf("4. Doc mang tu file\n");
	printf("5. Ghi mang ra file\n");
	printf("0. Thoat\n");
	printf("=============================================\n");
}