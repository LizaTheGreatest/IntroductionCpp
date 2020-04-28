#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


//--------------------------------#15---------------------------------
void multiplication(int**, int**, int**, int, int, int);



int main()
{
      int row1, col1;
      int row2, col2;
      int** matrix_1;
      int** matrix_2;
      int** matrix_3;
      printf("Enter number of rows for first matrix: ");
      row1 = safeReadInt();
      printf("Enter number of columns for first matrix: ");
      col1 = safeReadInt();
      row2 = col1;
      printf("Enter number of columns for second matrix: ");
      col2 = safeReadInt();


      printf("first matrix size: %d x %d\n", row1, col1);
      printf("Second matrix size: %d x %d\n", row2, col2);
      printf("Multiplicated matrix size: %d x %d\n", row1, col2);

      createMatrix(&matrix_1, row1, col1);
      fillMatrix(matrix_1, row1, col1);
      printf("\tFirst matrix\n\n");
      viewMatrix(matrix_1, row1, col1);

      createMatrix(&matrix_2, row2, col2);
      fillMatrix(matrix_2, row2, col2);
      printf("\tSecond matrix\n\n");
      viewMatrix(matrix_2, row2, col2);

      createMatrix(&matrix_3, row1, col2);
      multiplication(matrix_3, matrix_1, matrix_2, row1, col1, col2);
      printf("\tMiltiplicated matrix\n\n");
      viewMatrix(matrix_3, row1, col2);

      return 0;

}



void multiplication(int** matrix_3, int** matrix_1, int** matrix_2, int row1, int col1, int col2)
{
    for (int i = 0; i < row1; ++i)
    {
        for (int j = 0; j < col2; ++j)
        {
            int elem = 0;
            for (int k = 0; k < col1; ++k)
                elem += matrix_1[i][k] * matrix_2[k][j];
            matrix_3[i][j] = elem;
        }

    }

}

