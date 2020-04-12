#include <stdio.h>

//--------------------------------#9---------------------------------
bool isPerfect(int);
int main()
{
    for(int j = 2; j <= 1000; ++j)
    {
        if(isPerfect(j))
            printf("%d ", j);
    }
    printf("\n");
    return 0;
}

bool isPerfect(int number)
{
    int sum = 0;
    for(int i = 1; i <= number / 2; ++i)
    {
        if(!(number % i))
            sum += i;

    }
    if(sum == number) return true;
    return false;
}




