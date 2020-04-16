#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//--------------------------------#16---------------------------------
void multiTable(int[10][10]);
void generateNumbers(int*, int*);
void printMultiplication(int, int);
void ask(int, int, int*);



int main()
{
    int table[10][10];
    for(int i = 0; i < 10; ++i)
        for(int j = 1; j < 10; ++j)
            table[i][j] = i * j;

    int a, b;
    int answer = 0;
    int attempts = 3;

    generateNumbers(&a, &b);

    while (attempts) {

        ask(a, b, &answer);
        if(answer == a * b)
        {
           printf("Congratulations!\n");
           break;
        }
        system(CLEAR);
        printf("That's not correct. Try again\n");
        attempts--;

    }
    if(!attempts)
    {
        multiTable(table);
        while (true)
        {

            ask(a, b, &answer);

            if(answer == a * b)
            {
               printf("Congratulations!\n");
               break;
            }
            system(CLEAR);
            multiTable(table);
            printf("No. Please, try again\n");

        }
    }

    return 0;
}

void generateNumbers(int* a, int* b)
{
    srand(time(NULL));
    *a = 1 + rand()%(9);
    *b = 1 + rand()%(9);
}
void multiTable(int array[10][10])
{
    for(int i = 1; i < 8; i += 3)
    {
        for(int j = 1; j < 10; ++j)
        {
            for(int k = i; k < i + 3; ++k)
            {
                printf("%d * %d = %d\t", k, j, array[k][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}
void ask(int a, int b, int* answer)
{
    printf("%d * %d = ", a, b);
    scanf("%d", answer);

}

