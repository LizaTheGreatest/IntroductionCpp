#include <stdio.h>

//--------------------------------#11---------------------------------

void newValues(int&, int&, int&);

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    newValues(a, b, c);
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);

    return 0;
}

void newValues(int& a, int& b, int& c)
{
    int tempA = a;
    int tempB = b;
    a = a + b + c - a * a;
    b = tempA * tempA + b * b - c * c;
    c = tempA * tempB * c;

}

