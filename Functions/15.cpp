#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>

//--------------------------------#15---------------------------------

void ask(int, int, int*);


int main()
{
    srand(time(NULL));
    int number = 7 + rand()%(51);
    int left_border = 7;
    int right_border = 57;
    int user_answer = 0;




    while(true)
    {
        ask(left_border, right_border, &user_answer);
        if(user_answer >= number && user_answer < right_border)
        {
            if(user_answer == number)
            {
                printf("Congratulations!\n");
                break;
            }

            right_border = user_answer;

        }
        else if(user_answer < number && user_answer > left_border)
        {
            left_border = user_answer;
        }

    }

    return 0;
}

void ask(int left_border, int right_border, int* user_answer)
{

    printf("Enter the number in range [%d; %d]: ", left_border, right_border);
    scanf("%d", user_answer);
}

