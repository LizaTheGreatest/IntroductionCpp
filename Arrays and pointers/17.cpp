#include <stdio.h>
#include <stdlib.h>


//--------------------------------#17---------------------------------
void getFirstIndex(int**, int*, int*, int, int);
void getLastIndex(int**, int*, int*, int, int);

int main()
{
    int n, m;
    int i1, j1, i2, j2;
    int multipl = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);

    int** matrix = (int**) malloc(n * sizeof (int*));
    for(int i = 0; i < n; ++i)
        matrix[i] = (int*) malloc(m * sizeof (int));

    for(int i = 0; i < n; ++i)
        {
            printf("Enter %d elements: ", m);
            for(int j = 0; j < m; ++j)
                scanf("%d", &matrix[i][j]);

        }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            printf("%d\t", matrix[i][j]);
        printf("\n\n");
    }

    getFirstIndex(matrix, &i1, &j1, n, m);
    getLastIndex(matrix, &i2, &j2, n, m);

    printf("%d %d\n", i1, j1);
    printf("%d %d\n", i2, j2);
    for(int i = i1; i < i2; ++i)
    {
        int j;
        if(i == i1)
            j = j1 + 1;
        else j = 0;
        int last;
        if(i == i2)
            last = j2;
        else last = m;
        for(; j < last; ++j)
            multipl *= matrix[i][j];

    }
    printf("%d\n", multipl);


    return 0;
}

void getFirstIndex(int** matrix, int* i1, int* j1, int n, int m)
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] < 0)
            {
                *i1 = i;
                *j1 = j;
                return;
            }
        }
}

void getLastIndex(int** matrix, int* i2, int* j2, int n, int m)
{
    for(int i = n - 1; i >= 0; --i)
        for(int j = m - 1; j >= 0; --j)
        {
            if(matrix[i][j] < 0)
            {
                *i2 = i;
                *j2 = j;
                return;
            }
        }
}
