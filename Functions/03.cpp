#include <stdio.h>

//--------------------------------#3---------------------------------

void swap1(int&, int&);
void swap2(int*, int*);

int main()
{
    int n, m;
    printf("Enter numbers: ");
    scanf("%d%d", &n, &m);
    swap1(n, m);
    printf("First swap by reference: %d %d\n", n, m);
    swap2(&n, &m);
    printf("Second swap by pointers: %d %d\n", n, m);

    return 0;
}

void swap1(int& n, int& m)
{
    n = n - m;
    m = m + n;
    n = m - n;
}
void swap2(int* n, int* m)
{
    int temp = *n;
    *n = *m;
    *m = temp;

}



