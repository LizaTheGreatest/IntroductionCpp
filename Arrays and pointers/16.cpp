#include <stdio.h>
#include <stdlib.h>


//--------------------------------#16---------------------------------
void fillMatrix(int**, int, int);
void viewMatrix(int**, int, int);
void sum(int*, int);

int main()
{
    int n, m;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);
    int** matrix = (int**) malloc(n * sizeof (int*));
    for(int i = 0; i < n; ++i)
        matrix[i] = (int*) malloc(m * sizeof (int));

    fillMatrix(matrix, n, m);
    viewMatrix(matrix, n, m);

    int counter = 0;
    int* row = (int*) malloc(n * sizeof (int));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 0)
            {
                counter = 0;
                break;
            }
            counter++;
        }
        if(counter)
        {
            row = matrix[i];
            sum(row, m);
        }

    }




    return 0;
}

void fillMatrix(int** matrix, int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        printf("Enter %d elements: ", m);
        for(int j = 0; j < m; ++j)
            scanf("%d", &matrix[i][j]);

    }
}
 void viewMatrix(int** matrix, int n, int m)
 {

     for(int i = 0; i < n; ++i)
     {
         for(int j = 0; j < m; ++j)
             printf("%d\t", matrix[i][j]);
         printf("\n\n");
     }
 }
void sum(int* row, int n)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += row[i];
    printf("Sum is %d\n", sum);
}
