#include <stdio.h>

//--------------------------------#9---------------------------------

int reverse(int);

int main()
{

    int number;
    int reversed;
    printf("Enter number: ");
    scanf("%d", &number);
    reversed = reverse(number);
    printf("Reversed number is %d\n", reversed);
    return 0;
}

int reverse(int number)
{
    int temp = 0;
    while (number)
    {
        temp = temp * 10 + number % 10;
        number /= 10;
    }
    return temp;
}







