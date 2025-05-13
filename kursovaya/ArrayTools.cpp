#pragma once
#include "ArrayTools.h"


int** ArrCreate2D_int(int rows, int cols)
{
    int** a = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
    }

    return a;
}

cell** ArrCreate2D_cell()
{
    int mx = 0;
    for (int i = 0; i < 11; i++)
    {
        if (mx < LvlSizes[i]) mx = LvlSizes[i];
    }
    cell** a = new cell* [mx]; // тут был numHcells, дальше везде numWcells

    for (int i = 0; i < mx; i++)
    {
        a[i] = new cell[mx];
    }

    return a;
}

void ArrDelete2D_cell(cell** a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void ArrDelete2D_int(int** a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void ArrOutput2D_cells(cell** a, int data)
{

    for (int i = 0; i < numHcells; i++)
    {
        for (int j = 0; j < numWcells; j++)
        {
            switch (data)
            {
            case 1: cout << a[i][j].texturetype << " "; break;
            case 2: cout << a[i][j].rotation << " "; break;
            case 3: cout << a[i][j].IsActive << " "; break;
            case 4: cout << a[i][j].ways[0] << " "; break;
            }
        }
        cout << "\n";
    }
}
