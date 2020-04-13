#include <stdio.h>

//--------------------------------#3---------------------------------
bool isPrime(int);
int main()
{
    int left, right;
    printf("Enter borders: ");
    scanf("%d%d", &left, &right);
    for(int i = left; i <= right; i++)
    {
        if(isPrime(i)) printf("%d ", i);
    }
    return 0;
}

bool isPrime(int x)
{
    if(x == 1) return false;
    if(!(x % 2)) return x == 2;
    for(int i = 3; i < x / 2; i += 2)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
