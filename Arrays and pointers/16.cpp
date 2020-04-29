#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


//--------------------------------#16---------------------------------
void sum(int*, int);

int main()
{
    int rows, columns;
    int** matrix;
    printf("Enter rows number: ");
    rows = safeReadInt();
    printf("Enter columns number: ");
    columns = safeReadInt();

    createMatrix(&matrix, rows, columns);
    fillMatrix(matrix, rows, columns);
    viewMatrix(matrix, rows, columns);


    int* row;
    createMatrix(&row, rows);

    bool noZero = true;
    for(int i = 0; i < rows; ++i)
    {
        row = matrix[i];
        for(int j = 0; j < columns; ++j)
        {
            if(!row[j])
            {
                noZero = false;
                break;
            }

        }
        if(noZero)
            sum(row, columns);

    }

    return 0;
}


void sum(int* row, int rows)
{
    int sum = 0;
    for(int i = 0; i < rows; ++i)
        sum += row[i];
    printf("Sum is %d\n", sum);
}

