#ifndef ARRAY2D_H_
#define ARRAY2D_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <random>
#include <time.h>
#include "../../Config.h"
#include "../../Default.h"

#define MIN -99
#define MAX 99

//typedef int ItemType;
typedef ItemType* ArrayType;

int Array2D_init(ArrayType*& a, int m, int n);
void Array2D_free(ArrayType*& a, int& m, int& n);

int Array2D_random(ArrayType*& a, int& m, int& n);

int Array2D_scan(ArrayType*& a, int& m, int& n);
void Array2D_print(ArrayType* a, int m, int n);

int Array2D_readFromFile(ArrayType*& a, int& m, int& n, const char* filename);
int Array2D_writeToFile(ArrayType* a, int m, int n, const char* filename);

void Array2D_menu();

#endif // !ARRAY1D_H_
