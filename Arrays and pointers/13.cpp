#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


//--------------------------------#13---------------------------------

void findMinMaxSum(int** matrix, int rows, int columns, int* min, int* max, int* sum);
int main()
{
    int** matrix;
    int rows, columns;
    int min, max, sum;

    printf("Enter matrix number of rows: ");
    rows = safeReadInt();

    printf("Enter matrix number of columns: ");
    columns = safeReadInt();

    createMatrix(&matrix, rows, columns);
    fillMatrix(matrix, rows, columns);

    viewMatrix(matrix, rows, columns);


    findMinMaxSum(matrix, rows, columns, &min, &max, &sum);

    printf("\nSum is %d\nMinimum is %d\nMaximum is %d\n", sum, min, max);

    return 0;
}


void findMinMaxSum(int** matrix, int rows, int columns, int* min, int* max, int* sum)
{
    *min = matrix[1][0];
    *max = matrix[0][1];
    *sum = 0;
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
        {
            if(j < i)
            {
                if(matrix[i][j] < *min)
                    *min = matrix[i][j];
            }
            else if(j > i)
            {
                if(matrix[i][j] > *max)
                    *max = matrix[i][j];
            }
            else *sum += matrix[i][j];
        }
}

