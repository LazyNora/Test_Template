#include "Array2D.h"

int Array2D_init(ArrayType*& a, int m, int n) {
	a = new ArrayType[m];
	if (!a) {
		printf(MEMORY_ALLOCATION_ERROR);
		return 0;
	}

	for (int i = 0; i < m; i++) {
		a[i] = new ItemType[n];
		if (!a[i]) {
			printf(MEMORY_ALLOCATION_ERROR);
			Array2D_free(a, m, n);
			return 0;
		}
	}

	return 1;
}

void Array2D_free(ArrayType*& a, int& m, int& n) {
	if (a) {
		for (int i = 0; i < m; i++)
			if (a[i])
				delete[] a[i];
		delete[] a;
	}
}

int Array2D_random(ArrayType*& a, int& m, int& n) {
	if (a)
		Array2D_free(a, m, n);

	EnterNumber(m, NUMBEROFROW_MSG, POSITIVE);
	EnterNumber(n, NUMBEROFCOLUMN_MSG, POSITIVE);

	if (!Array2D_init(a, m, n))
		return 0;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = MIN + rand() % (MAX - MIN + 1);

	return 1;
}

int Array2D_scan(ArrayType*& a, int& m, int& n) {
	if (a)
		Array2D_free(a, m, n);

	EnterNumber(m, NUMBEROFROW_MSG, POSITIVE);
	EnterNumber(n, NUMBEROFCOLUMN_MSG, POSITIVE);

	if (!Array2D_init(a, m, n))
		return 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ItemType_scan(a[i][j], TextFormat("Nhap a[%d][%d]: ", i, j));

	return 1;
}

void Array2D_print(ArrayType* a, int m, int n) {
	if (!a) {
		printf(ARRAY2D_EMPTY);
		return;
	}

	printf(ARRAY2D_PRINT_MSG);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			ItemType_print(a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int Array2D_readFromFile(ArrayType*& a, int& m, int& n, const char* filename) {
	if (a)
		Array2D_free(a, m, n);

	FILE* f = fopen(filename, "rt");
	if (!f) {
		printf("Khong the mo file %s\n", filename);
		return 0;
	}

	if (!fscanf(f, "%d", &m))
		m = -1;
	if (!fscanf(f, "%d", &n))
		n = -1;
	if (m <= 0 || n <= 0) {
		printf("So luong phan tu khong hop le!\n");
		fclose(f);
		return 0;
	}

	if (!Array2D_init(a, m, n))
		return 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!fscanf(f, "%d", &a[i][j])) {
				printf("Du lieu trong file khong hop le!\n");
				Array2D_free(a, m, n);
				fclose(f);
				return 0;
			}

	fclose(f);
	return 1;
}

int Array2D_writeToFile(ArrayType* a, int m, int n, const char* filename) {
	if (!a) {
		printf(ARRAY2D_EMPTY);
		return 0;
	}

	FILE* f = fopen(filename, "wt");
	if (!f) {
		printf("Khong the mo file %s\n", filename);
		return 0;
	}

	fprintf(f, "%d %d\n", m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			fprintf(f, "%d ", a[i][j]);
		fprintf(f, "\n");
	}

	fclose(f);
	return 1;
}

void Array2D_menu() {
	printCenter("ARRAY 2D", 45, ' ');
	printf("\n=============================================\n");
	printf("1. Nhap ma tran tu ban phim\n");
	printf("2. Xuat ma tran\n");
	printf("3. Tao ngau nhien ma tran\n");
	printf("4. Doc ma tran tu file\n");
	printf("5. Ghi ma tran vao file\n");
	printf("0. Thoat\n");
	printf("=============================================\n");
}