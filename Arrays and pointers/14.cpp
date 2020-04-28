#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

//--------------------------------#14---------------------------------

void sortColumns(int**, int, int);




int main()
{
    int** matrix;
    int rows, columns;

    printf("Enter number of rows: ");
    rows = safeReadInt();

    printf("Enter number of columns ");
    columns = safeReadInt();

    createMatrix(&matrix, rows, columns);
    fillMatrix(matrix, rows, columns);

    viewMatrix(matrix, rows, columns);




    sortColumns(matrix, rows, columns);

    printf("\tMatrix with sorted columns\n\n");
    viewMatrix(matrix, rows, columns);



    return 0;
}


void sortColumns(int** matrix, int rows, int columns)
{
    int temp;
    for(int i = 0; i < columns; ++i)
    {

        for(int j = 0; j < rows - 1; ++j)
           {
                for(int k = j + 1; k < rows; ++k)
                    if(matrix[k][i] < matrix[j][i])
                    {
                        temp = matrix [j][i];
                        matrix[j][i] = matrix[k][i];
                        matrix[k][i] = temp;
                    }

           }
    }

}

