#include <stdio.h>

//--------------------------------#12---------------------------------

int fibonacciNumber(int);
int main()
{
    int n;
    printf("Enter index: ");
    scanf("%d", &n);
    printf("fibonacci number is %d\n", fibonacciNumber(n));

    return 0;
}

int fibonacciNumber(int index)
{
    if(!index || index == 1) return index;
    return fibonacciNumber(index - 1) + fibonacciNumber(index - 2);
}
