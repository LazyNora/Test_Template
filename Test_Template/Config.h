#pragma once

#define OPTION_SELECT "Nhap lua chon cua ban: "
#define OPTION_EXIT "Thoat chuong trinh!\n"
#define OPTION_ERROR "Lua chon khong hop le!\n"
#define NUMBEROFITEM_MSG "Nhap so luong phan tu: "
#define INTERGER_MSG "Nhap so nguyen: "
#define POSITIVE_MSG "Nhap so nguyen duong: "
#define NUMBER_ERROR "Gia tri vua nhap khong hop le!\n"
#define ARRAY_EMPTY "Mang rong!\n"
#define ARRAY_FULL "Mang day!\n"
#define ARRAY_INDEX_ERROR "Chi so khong hop le!\n"
#define MEMORY_ALLOCATION_ERROR "Khong the cap phat bo nho!\n"
#define ARRAY_PRINT_MSG "Mang hien tai: "

#if defined(ARRAY1D)
#include "Array/Array1D/Array1D.h"
#define inputFile "input_Array1D.txt"
#define outputFile "output_Array1D.txt"
#define FUNC(X) Array1D ## _ ## X
#elif defined(ARRAY2D)
#include "Array/Array2D/Array2D.h"
#define inputFile "input_Array2D.txt"
#define outputFile "output_Array2D.txt"
#define FUNC(X) Array2D ## _ ## X
#elif defined(ARRAY_STRUCT)
#include "Array/ArrayStruct/ArrayStruct.h"
#define inputFile "input_ArrayStruct.txt"
#define outputFile "output_ArrayStruct.txt"
#define FUNC(X) ArrayStruct ## _ ## X
#endif // Library