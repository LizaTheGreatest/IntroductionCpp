#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


//--------------------------------#12---------------------------------

int main()
{
    int size;
    int* matrix;

    printf("Enter the size of array: ");
    size = safeReadInt();

    createMatrix(&matrix, size);

    printf("Please, fill the matrix\n");

    fillMatrix(matrix, size);

    viewMatrix(matrix, size);

    printf("Min element is [%d] = %d\n",minElement(matrix, size), matrix[minElement(matrix, size)]);
    printf("Max element is [%d] = %d\n", maxElement(matrix,size), matrix[maxElement(matrix, size)]);

    printf("Sorted from min to max\n");
    sortAscending(matrix, size);
    viewMatrix(matrix, size);
    printf("Sorted from max to min\n");
    sortDescending(matrix, size);
    viewMatrix(matrix, size);



    return 0;
}







