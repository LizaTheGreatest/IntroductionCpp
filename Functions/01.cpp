#include <stdio.h>

//--------------------------------#1---------------------------------
int findMax(int, int, int);
int main()
{
    int x1, x2, x3, x4, x5;
    printf("Enter five numbers: ");
    scanf("%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);
    printf("max of x1x2x3: %d\n", findMax(x1, x2, x3));
    printf("max of x4x2x3: %d\n", findMax(x4, x2, x3));
    printf("max of x4x5x3: %d\n", findMax(x4, x5, x3));
    return 0;
}

int findMax(int a, int b, int c)
{
    int max = a;
    if(max < b)

        max = b;

    if(max < c)
        max = c;

    return max;
}
