#include <stdio.h>
#include <stdlib.h>


//--------------------------------#14---------------------------------
void addMatrix(int***, int, int);
void fillMatrix(int***, int, int);
void viewMatrix(int**, int, int);
void sortColumns(int**, int, int);




int main()
{
    int** matrix;
    int n, m;

    printf("Enter numbers of rows and columns: ");
    scanf("%d%d", &n, &m);

    addMatrix(&matrix, n, m);
    fillMatrix(&matrix, n, m);
    viewMatrix(matrix, n, m);

    sortColumns(matrix, n, m);

    viewMatrix(matrix, n, m);



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

void sortColumns(int** matrix, int n, int m)
{
    int temp;
    for(int i = 0; i < m; ++i)
    {

        for(int j = 0; j < n - 1; ++j)
           {
                for(int k = j + 1; k < n; ++k)
                    if(matrix[k][i] < matrix[j][i])
                    {
                        temp = matrix [j][i];
                        matrix[j][i] = matrix[k][i];
                        matrix[k][i] = temp;
                    }

           }
    }

}
