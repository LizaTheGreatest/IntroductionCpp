#include <stdio.h>

//--------------------------------#13---------------------------------


int suma_cifr(int);


int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    printf("Sum is %d\n", suma_cifr(number));

    return 0;
}

int suma_cifr(int number)
{
    if(!number) return 0;
    return number % 10 + suma_cifr(number / 10);
}
