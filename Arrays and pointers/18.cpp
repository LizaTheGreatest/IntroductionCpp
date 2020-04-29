#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

//--------------------------------#18---------------------------------
//int findmin(int**, int, int);
int findmax(int**, int, int);
void specialElements(int**, int, int);

/*
 * for tests 2 1 2 1      2 6 9 3
 *           3 0 5 0      1 5 3 7
 *           4 1 7 1      2 1 5 9
*/

int main()
{

    int rows, columns;
    int** matrix;

    printf("Enter number of rows: ");
    rows = safeReadInt();

    printf("Enter number of columns: ");
    columns = safeReadInt();

    createMatrix(&matrix, rows, columns);
    fillMatrix(matrix, rows, columns);
    viewMatrix(matrix, rows, columns);



    specialElements(matrix, rows, columns);


    return 0;
}

//int findmin(int** matrix, int rowNumber, int m)
//{
//    int min = matrix[rowNumber][0];
//    for(int i = 0; i < m - 1; ++i)
//        if(matrix[rowNumber][i + 1] < matrix[rowNumber][i])
//            min = matrix[rowNumber][i + 1];

//    return min;
//}

int findmax(int** matrix, int colNumber, int n)
{
    int max = matrix[0][colNumber];
    for(int i = 0; i < n - 1; ++i)
        if(matrix[i + 1][colNumber] > matrix[i][colNumber])
            max = matrix[i + 1][colNumber];
    return max;
}

void specialElements(int** matrix, int n, int m)
{
    int* rowMins = (int*) malloc(n * sizeof (int));
    int* colMaxes = (int*) malloc(m * sizeof (int));
    for(int i = 0; i < n; ++i)

        rowMins[i] = matrix[i][minElement(matrix[i], m)];
    //        rowMins[i] = findmin(matrix, i, m);
    for (int i = 0; i < m; ++i)
        colMaxes[i] = findmax(matrix, i, n);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxes[j])
                printf("[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }

}

