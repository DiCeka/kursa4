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

cell** ArrSimpleCreate2D_cell(int size)
{
    cell** a = new cell* [size];
    for (int i = 0; i < size; i++)
    {
        a[i] = new cell[size];
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

SDL_Rect* ArrCreate1D_Rect(int size)
{
    SDL_Rect* a = new SDL_Rect[size];

    return a;
}

void ArrAddElement1D_Rect(SDL_Rect*& a, int& size, SDL_Rect elem)
{
    // Ищем такой же элемент
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (EqualRects(a[i], elem)) { ind = i;  break; }
    }
    if (ind == -1)
    {
        SDL_Rect* newarr = new SDL_Rect[size + 1];
        for (int i = 0; i < size; i++) newarr[i] = a[i];
        newarr[size] = elem;
        size++;
        delete[] a;
        a = newarr;
    }
}

void ArrDelElement1D_Rect(SDL_Rect*& a, int& size, SDL_Rect elem)
{
    // Ищем индекс элемента
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (EqualRects(a[i], elem)) { ind = i; }
    }

    if (ind != -1)
    {
        SDL_Rect* newarr = new SDL_Rect[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i < ind) newarr[i] = a[i];
            else if (i > ind) newarr[i] = a[i+1];
        }
        size--;
        delete[] a;
        a = newarr;
    }
}

void ArrClear1D_Rect(SDL_Rect*& a, int& size)
{
    SDL_Rect* newarr = new SDL_Rect[0];
    size = 0;
    delete[] a;
    a = newarr;
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
            case 2: cout << setw(3) << a[i][j].rotation << " "; break;
            case 3: cout << a[i][j].IsActive << " "; break;
            case 4: cout << a[i][j].ways[0] << " "; break;
            case 5: cout << a[i][j].IsAnimating << " "; break;
            }
        }
        cout << "\n";
    }
}

int* ArrCreate1D_int(int size)
{
    int* a = new int[size];

    return a;
}
void ArrAddElement1D_int(int*& a, int& size, int elem)
{
    // Ищем такой же элемент
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == elem) { ind = i;  break; }
    }
    if (ind == -1)
    {
        int* newarr = new int[size + 1];
        for (int i = 0; i < size; i++) newarr[i] = a[i];
        newarr[size] = elem;
        size++;
        delete[] a;
        a = newarr;
    }
}
void ArrDelElement1D_int(int*& a, int& size, int elem)
{
    // Ищем индекс элемента
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == elem) { ind = i; }
    }

    if (ind != -1)
    {
        int* newarr = new int[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i < ind) newarr[i] = a[i];
            else if (i > ind) newarr[i] = a[i + 1];
        }
        size--;
        delete[] a;
        a = newarr;
    }
}

SDL_Point* ArrCreate1D_Point(int size)
{
    SDL_Point* a = new SDL_Point[size];

    return a;
}
void ArrAddElement1D_Point(SDL_Point*& a, int& size, SDL_Point elem)
{
    // Ищем такой же элемент
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i].x == elem.x && a[i].y == elem.y) { ind = i;  break; }
    }
    if (ind == -1)
    {
        SDL_Point* newarr = new SDL_Point[size + 1];
        for (int i = 0; i < size; i++) newarr[i] = a[i];
        newarr[size] = elem;
        size++;
        delete[] a;
        a = newarr;
    }
}
void ArrDelElement1D_Point(SDL_Point*& a, int& size, SDL_Point elem)
{
    // Ищем индекс элемента
    int ind = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i].x == elem.x && a[i].y == elem.y) { ind = i; }
    }

    if (ind != -1)
    {
        SDL_Point* newarr = new SDL_Point[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i < ind) newarr[i] = a[i];
            else if (i > ind) newarr[i] = a[i + 1];
        }
        size--;
        delete[] a;
        a = newarr;
    }
}