#pragma once
#include "Structs.h"
#include "iostream"
#include <iomanip>
#include "Constants.h"
using namespace std;


int** ArrCreate2D_int(int rows, int cols);

cell** ArrCreate2D_cell();

void ArrDelete2D_cell(cell** a, int m);

void ArrDelete2D_int(int** a, int m);

void ArrOutput2D_cells(cell** a, int data = 1);