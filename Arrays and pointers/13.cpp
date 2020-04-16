#include <stdio.h>
#include <stdlib.h>


//--------------------------------#13---------------------------------
void addMatrix(int***, int, int);
void fillMatrix(int***, int, int);
void viewMatrix(int**, int, int);
void findMinMaxSum(int**, int, int*, int*, int*);
int main()
{
    int** matrix;
    int n;
    int min, max, sum;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    addMatrix(&matrix, n, n);
    fillMatrix(&matrix, n, n);
    viewMatrix(matrix, n, n);

    findMinMaxSum(matrix, n, &min, &max, &sum);

    printf("\nSum is %d\nMinimum is %d\nMaximum is %d\n", sum, min, max);

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


void findMinMaxSum(int** matrix, int n, int* min, int* max, int* sum)
{
    *min = matrix[1][0];
    *max = matrix[0][1];
    *sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
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

