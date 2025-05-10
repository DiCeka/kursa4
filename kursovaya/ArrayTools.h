#pragma once
#include "Structs.h"
#include "iostream"
#include <iomanip>
using namespace std;


int** ArrCreate2D_int(int rows, int cols);

cell** ArrCreate2D_cell(int rows, int cols);

void ArrDelete2D_cell(cell** a, int m);

void ArrDelete2D_int(int** a, int m);

void ArrOutput2D_cells(cell** a, int rows, int cols);