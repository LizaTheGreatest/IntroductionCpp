#include <stdio.h>

//--------------------------------#7---------------------------------

void divide(int, int);

int main()
{
    int x, y;
    printf("Enter x, y: ");
    scanf("%d%d", &x, &y);
    divide(x, y);
    return 0;
}

void divide(int x, int y)
{
    printf("%3.2lf\n", (double)x/y);
}





