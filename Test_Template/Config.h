#pragma once

#define SPACING 4
#define PRINT_FORMAT "%" STR2(SPACING) "d "

#define OPTION_SELECT "Nhap lua chon cua ban: "
#define OPTION_EXIT "Thoat chuong trinh!"
#define OPTION_ERROR "Lua chon khong hop le!\n"
#define NUMBEROFITEM_MSG "Nhap so luong phan tu: "
#define NUMBEROFROW_MSG "Nhap so luong hang: "
#define NUMBEROFCOLUMN_MSG "Nhap so luong cot: "
#define INTERGER_MSG "Nhap so nguyen: "
#define POSITIVE_MSG "Nhap so nguyen duong: "
#define NUMBER_ERROR "Gia tri vua nhap khong hop le!\n"
#define ARRAY1D_EMPTY "Mang rong!\n"
#define ARRAY1D_FULL "Mang day!\n"
#define ARRAY1D_INDEX_ERROR "Chi so khong hop le!\n"
#define MEMORY_ALLOCATION_ERROR "Khong the cap phat bo nho!\n"
#define ARRAY1D_PRINT_MSG "Mang hien tai: "

#define ARRAY2D_EMPTY "Ma tran rong!\n"
#define ARRAY2D_FULL "Ma tran day!\n"
#define ARRAY2D_INDEX_ERROR "Chi so khong hop le!\n"
#define ARRAY2D_PRINT_MSG "Ma tran hien tai:\n"

typedef int ItemType;
void ItemType_scan(ItemType& x, const char* msg = NULL);
void ItemType_print(ItemType x);

#if defined(ARRAY1D)
#include "Array/Array1D/Array1D.h"
#define inputFile "input_Array1D.txt"
#define outputFile "output_Array1D.txt"
#define FUNC(X) Array1D ## _ ## X
#define INIT ItemType* a = NULL; int n = 0;
#define ARRAY a, n
#elif defined(ARRAY2D)
#include "Array/Array2D/Array2D.h"
#define inputFile "input_Array2D.txt"
#define outputFile "output_Array2D.txt"
#define FUNC(X) Array2D ## _ ## X
#define INIT ItemType** a = NULL; int m = 0, n = 0;
#define ARRAY a, m, n
#endif // Library