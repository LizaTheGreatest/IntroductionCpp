#include "arrays.h"
#include "stdio.h"
#include <stdlib.h>


void sortAscending(int* array, int size, int left_border)
{
    for(int i = left_border; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            if(array[j] < array[i])
            {
               swap(array[i], array[j]);
            }
}


void sortDescending(int* array, int size, int left_border)
{
    for(int i = left_border; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            if(array[j] > array[i])
            {
                swap(array[i], array[j]);
            }
}

int minElement(int* array, int size, int left_border)
{
    int index = 0;

    for(int i = left_border; i < size; ++i)
        if(array[i] < array[index])
            index = i;

    return index;
}

int maxElement(int* array, int size, int left_border)
{
    int index = 0;

    for(int i = left_border; i < size; ++i)
        if(array[i] > array[index])
            index = i;

    return index;
}

void viewMatrix(int** matrix, const int rows, const int columns)
{
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
        {
            printf("[%d][%d] = %d; ", i, j, matrix[i][j]);
        }
    printf("\n\n");
}

void viewMatrix(int* matrix, const int size)
{
    for(int i = 0; i < size; ++i)
        printf("[%d] = %d; ", i, matrix[i]);
    printf("\n\n");
}

void createMatrix(int** matrix, int size)
{
    *matrix = (int*) malloc(size * sizeof (int));
}

void createMatrix(int*** matrix, int rows, int columns)
{

    *matrix = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; ++i)
        (*matrix)[i] = (int*) malloc(columns * sizeof (int));

}

void fillMatrix(int* matrix, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = ", i);

        matrix[i] = safeReadInt();
    }
}

void fillMatrix(int** matrix, int rows, int columns)
{
    for(int i = 0; i < rows; ++i)
    {
        printf("Enter %d numbers: ", columns);
        for(int j = 0; j < columns; ++j)

            matrix[i][j] = safeReadInt();

    }
}


int safeReadInt(const char* text)
{

    bool ok = false;
    int result;

    do
    {

        ok = scanf("%d", &result) == 1;
        flush_stdin();
        if(!ok)
        {
            printf("%s", text);
        }

    }
    while (!ok);
    return result;

}
void flush_stdin()
{
    char c;
    while ((c = getc(stdin)) != '\n' && c != EOF);
}

