#include <stdio.h>

//--------------------------------#6---------------------------------

int power(int, int);

int main()
{
    int x, n;
    int p;
    printf("Enter x, n: ");
    scanf("%d%d", &x, &n);
    p = power(x, n);
    printf("%d", p);


    return 0;
}

int power(int x, int n)
{
    int pow = 1;
    for(int i = 0; i < n; ++i)
        pow *= x;
    return pow;
}





