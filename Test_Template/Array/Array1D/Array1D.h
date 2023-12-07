#ifndef ARRAY1D_H_
#define ARRAY1D_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <random>
#include <time.h>
#include "../../Config.h"
#include "../../Default.h"

#define MIN -99
#define MAX 99

typedef int ItemType;

int Array1D_random(ItemType*& a, int& n);

int Array1D_scan(ItemType*& a, int& n);
void Array1D_print(ItemType* a, int n);

int Array1D_readFromFile(ItemType*& a, int& n, const char* filename);
int Array1D_writeToFile(ItemType* a, int n, const char* filename);

void Array1D_menu();

#endif // !ARRAY1D_H_
