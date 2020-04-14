#include <stdio.h>
#include <stdlib.h>


//--------------------------------#15---------------------------------
void addMatrix(int***, int, int);
void fillMatrix(int***, int, int);
void viewMatrix(int**, int, int);
void multiplication(int***, int**, int**, int, int, int);



int main()
{
      int n1, m1;
      int n2, m2;
      int** matrix_1;
      int** matrix_2;
      int** matrix_3;
      printf("Enter number of rows and columns: ");
      scanf("%d%d", &n1, &m1);
      n2 = m1;
      printf("Enter number of columns for second matrix: ");
      scanf("%d", &m2);

      addMatrix(&matrix_1, n1, m1);
      fillMatrix(&matrix_1, n1, m1);
      viewMatrix(matrix_1, n1, m1);

      addMatrix(&matrix_2, n2, m2);
      fillMatrix(&matrix_2, n2, m2);
      viewMatrix(matrix_2, n2, m2);

      addMatrix(&matrix_3, n1, m2);
      multiplication(&matrix_3, matrix_1, matrix_2, n1, m1, m2);
      viewMatrix(matrix_3, n1, m2);

      return 0;

}

void addMatrix(int*** matrix, int n, int m)
{

    *matrix = (int**) malloc(n * sizeof (int*));
    for(int i = 0; i < n; ++i)
        (*matrix)[i] = (int*) malloc(m * sizeof (int));

}


void fillMatrix(int*** matrix, int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        printf("Enter %d elements: ", m);
        for(int j = 0; j < m; ++j)
            scanf("%d", &(*matrix)[i][j]);
    }
}


void viewMatrix(int** matrix, int n, int m)
 {
    printf("\n\tMATRIX %d x %d\n\n", n, m);
     for(int i = 0; i < n; ++i)
     {
         for(int j = 0; j < m; ++j)
             printf("%d\t", matrix[i][j]);
         printf("\n\n");
     }
 }

void multiplication(int*** matrix_3, int** matrix_1, int** matrix_2, int n1, int m1, int m2)
{
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < m2; ++j)
        {
            int elem = 0;
            for (int k = 0; k < m1; ++k)
                elem += matrix_1[i][k] * matrix_2[k][j];
            (*matrix_3)[i][j] = elem;
        }

    }

}
