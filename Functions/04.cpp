#include <stdio.h>

//--------------------------------#4---------------------------------

int factorial(int);

int main()
{
    int a, b, c;
    printf("Enter numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    int sum = factorial(a) + factorial(b) + factorial(c);
    printf("Sum of factorials is %d\n", sum);
    return 0;
}


int factorial(int x)
{
    if(x == 1 || !x)
        return 1;
    return x * factorial(x - 1);
}


