#include "Array1D.h"

int Array1D_init(ItemType*& a, int n) {
	a = new ItemType[n];
	if (!a) {
		printf(MEMORY_ALLOCATION_ERROR);
		return 0;
	}

	return 1;
}

void Array1D_free(ItemType*& a, int& n) {
	if (a)
		delete[] a;
}

int Array1D_random(ItemType*& a, int& n) {
	if (a)
		Array1D_free(a, n);

	EnterNumber(n, NUMBEROFITEM_MSG, POSITIVE);

	if (!Array1D_init(a, n))
		return 0;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = MIN + rand() % (MAX - MIN + 1);

	return 1;
}

int Array1D_scan(ItemType*& a, int& n) {
	if (a)
		Array1D_free(a, n);

	EnterNumber(n, NUMBEROFITEM_MSG, POSITIVE);

	if (!Array1D_init(a, n))
		return 0;

	for (int i = 0; i < n; i++) {
		ItemType_scan(a[i], TextFormat("Nhap a[%d]: ", i));
	}

	return 1;
}

void Array1D_print(ItemType* a, int n) {
	if (!a) {
		printf(ARRAY1D_EMPTY);
		return;
	}

	printf(ARRAY1D_PRINT_MSG);

	for (int i = 0; i < n; i++)
		ItemType_print(a[i]);
	printf("\n");
}

int Array1D_readFromFile(ItemType*& a, int& n, const char* filename) {
	if (a)
		Array1D_free(a, n);

	FILE* f = fopen(filename, "r");
	if (!f) {
		printf("Khong the mo file %s\n", filename);
		return 0;
	}

	if (!fscanf(f, "%d", &n))
		n = -1;
	if (n <= 0) {
		printf("So luong phan tu khong hop le!\n");
		fclose(f);
		return 0;
	}

	if (!Array1D_init(a, n)) {
		fclose(f);
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (!fscanf(f, "%d", &a[i])) {
			printf("Du lieu trong file khong hop le!\n");
			Array1D_free(a, n);
			fclose(f);
			return 0;
		}

	fclose(f);
	return 1;
}

int Array1D_writeToFile(ItemType* a, int n, const char* filename) {
	if (!a) {
		printf(ARRAY1D_EMPTY);
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
	printCenter("ARRAY 1D", 45, ' ');
	printf("\n=============================================\n");
	printf("1. Nhap mang tu ban phim\n");
	printf("2. Xuat mang\n");
	printf("3. Tao mang ngau nhien\n");
	printf("4. Doc mang tu file\n");
	printf("5. Ghi mang ra file\n");
	printf("0. Thoat\n");
	printf("=============================================\n");
}