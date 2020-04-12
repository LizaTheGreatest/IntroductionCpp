#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>

//--------------------------------#14---------------------------------


int nod(int, int);


int main()
{
    int x, y;
    scanf("%d%d", &x, &y);

    nod(x, y);

    printf("%d\n", nod(x, y));

    return 0;
}

int nod(int x, int y)
{
    if (!y) return x;
    return nod(y, x % y);
}

