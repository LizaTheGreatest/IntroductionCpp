#include <stdio.h>
#include <stdlib.h>


//--------------------------------#12---------------------------------
void addElements(int*, int);
void viewMatrix(int*, int);
int minElement(int*, int);
int maxElement(int*, int);
void sortToMax(int*, int);
void sortToMin(int*, int);

int main()
{
    int size;
    int* matrix;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    matrix = (int*) malloc(size * sizeof (int));

    printf("Please, fill the matrix\n");

    addElements(matrix, size);

    viewMatrix(matrix, size);

    printf("Min element is [%d] = %d\n",minElement(matrix, size), matrix[minElement(matrix, size)]);
    printf("Max element is [%d] = %d\n", maxElement(matrix,size), matrix[maxElement(matrix, size)]);

    printf("Sorted from min to max\n");
    sortToMax(matrix, size);
    viewMatrix(matrix, size);
    printf("Sorted from max to min\n");
    sortToMin(matrix, size);
    viewMatrix(matrix, size);



    return 0;
}

void addElements(int* matrix, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = ", i);
        scanf("%d", &matrix[i]);

    }
}

void viewMatrix(int* matrix, int size)
{
    for(int i = 0; i < size; ++i)
        printf("%d\t", matrix[i]);
    printf("\n");
}

int minElement(int* matrix, int size)
{
    int index = 0;

    for(int i = 0; i < size; ++i)
        if(matrix[i] < matrix[index])
            index = i;

    return index;
}

int maxElement(int* matrix, int size)
{
    int index = 0;
    for(int i = 0; i < size; ++i)
        if(matrix[i] > matrix[index])
            index = i;

    return index;
}

void sortToMax(int* matrix, int size)
{
    int temp = 0;
    for(int i = 0; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            if(matrix[j] < matrix[i])
            {
                temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }

}

void sortToMin(int* matrix, int size)
{
    int temp = 0;
    for(int i = 0; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            if(matrix[j] > matrix [i])
            {
                temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }
}





