#include <stdio.h>

//--------------------------------#10---------------------------------

void init1(int&, int&);
void init2(int*, int*);

int main()
{

    int x, y;
    init1(x, y);
    init2(&x, &y);
    return 0;
}

void init1(int& x, int& y)
{
    printf("Enter x, y : ");
    scanf("%d%d", &x, &y);
    printf("x = %d, y = %d\n", x, y);

}

void init2(int* x, int* y)
{
    printf("Enter x, y : ");
    scanf("%d%d", x, y);
    printf("x = %d, y = %d\n", *x, *y);
}



