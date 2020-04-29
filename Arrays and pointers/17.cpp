#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

//--------------------------------#17---------------------------------
void getFirstIndex(int**, int*, int*, int, int);
void getLastIndex(int**, int*, int*, int, int);

int main()
{
    int rows, columns;
    int** matrix;

    int x1, y1, x2, y2;
    int multipl = 1;


    printf("Enter number of rows: ");
    rows = safeReadInt();

    printf("Enter number of columns: ");
    columns = safeReadInt();

    createMatrix(&matrix, rows, columns);
    fillMatrix(matrix, rows, columns);
    viewMatrix(matrix, rows, columns);


    getFirstIndex(matrix, &x1, &y1, rows, columns);
    getLastIndex(matrix, &x2, &y2, rows, columns);

    printf("%d %d\n", x1, y1);
    printf("%d %d\n", x2, y2);

    int first_i, last_i;
    int first_j;

    if(y1 == columns - 1)
    {
        first_i = x1 + 1;
        first_j = 0;
    }
    else
    {
        first_i = x1;
        first_j = y1 + 1;
    }

    if(y2 == 0)
    {
        last_i = x2 - 1;

    }

    else
    {
        last_i = x2;

    }

    bool t = true;
    for(int i = first_i; i <= last_i; ++i)
    {
        if(!t) break;
        for(int j = first_j; j < columns; ++j)
        {
            if(j == y2 && i == x2)
            {
                t = false;
                break;

            }

            if(j == columns - 1)
                first_j = 0;

            multipl *= matrix[i][j];
        }

    }

    printf("%d\n", multipl);


    return 0;
}

void getFirstIndex(int** matrix, int* x1, int* y1, int rows, int columns)
{
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
        {
            if(matrix[i][j] < 0)
            {
                *x1 = i;
                *y1 = j;
                return;
            }
        }
}

void getLastIndex(int** matrix, int* x2, int* y2, int rows, int columns)
{
    for(int i = rows - 1; i >= 0; --i)
        for(int j = columns - 1; j >= 0; --j)
        {
            if(matrix[i][j] < 0)
            {
                *x2 = i;
                *y2 = j;
                return;
            }
        }
}

