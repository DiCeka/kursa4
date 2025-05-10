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

cell** ArrCreate2D_cell(int rows, int cols)
{
    cell** a = new cell* [rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new cell[cols];
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

void ArrOutput2D_cells(cell** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j].texturetype << " ";
        }
        cout << "\n";
    }
}
