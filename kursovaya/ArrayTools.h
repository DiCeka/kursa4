#pragma once
#include "Structs.h"
#include "iostream"
#include <iomanip>
#include "Constants.h"
#include "Logic.h"
using namespace std;


int** ArrCreate2D_int(int rows, int cols);

cell** ArrSimpleCreate2D_cell(int size);

cell** ArrCreate2D_cell();

SDL_Rect* ArrCreate1D_Rect(int size);

void ArrAddElement1D_Rect(SDL_Rect*& a, int& size, SDL_Rect elem);

void ArrDelElement1D_Rect(SDL_Rect*& a, int& size, SDL_Rect elem);

void ArrClear1D_Rect(SDL_Rect*& a, int& size);

void ArrDelete2D_cell(cell** a, int m);

void ArrDelete2D_int(int** a, int m);

void ArrOutput2D_cells(cell** a, int data = 1);

int* ArrCreate1D_int(int size);

void ArrAddElement1D_int(int*& a, int& size, int elem);

void ArrDelElement1D_int(int*& a, int& size, int elem);