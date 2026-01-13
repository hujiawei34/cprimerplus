#include <stdio.h>
#define MIN -1000
#define MAX 1000
int record_n(void)
{
    printf("enter a number btween %d~%d:", MIN, MAX);
    int n;
    int status = scanf("%d", &n);
    while (getchar() != '\n')
        ;

    while (status != 1 || n < MIN || n > MAX)
    {
        printf("invalid number,enter a number btween %d~%d:", MIN, MAX);
        while (getchar() != '\n')
            ;
        status = scanf("%d", &n);
    }
    printf("your number is %d,i will keep it secrect!\n", n);
    return n;
}
char get_choice(int guess)
{
    printf("i guess the number is %d\n", guess);
    printf("is it right(inpout y/n)?:");
    char choice = getchar();
    while (getchar() != '\n')
        ;
    while (choice != 'y' && choice != 'n')
    {
        printf("invalid choice,input y or n.\n");
        choice = getchar();
        while (getchar() != '\n')
            ;
    }
    return choice;
}
char get_judge(int guess)
{
    printf("tell me is %d bigger or smaller?(input b/s):", guess);
    char choice = getchar();
    while (getchar() != '\n')
        ;
    while (choice != 'b' && choice != 's')
    {
        printf("invalid choice,input b or s.\n");
        choice = getchar();
        while (getchar() != '\n')
            ;
    }
    return choice;
}
int main(void)
{
    int right = record_n();
    int max = MAX;
    int min = MIN;
    int guess = (max - min) / 2;
    char choice = get_choice(guess);

    while (choice != 'y')
    {
        int judge = get_judge(guess);
        switch (judge)
        {
        case 'b':
            max = guess;
            break;
        case 's':
            min = guess;
            break;
        }
        printf("max=%d,min=%d\n", max, min);
        guess = min + (max - min) / 2;
        choice = get_choice(guess);
    }
    printf("your record num is %d,i guessed number is %d!", right, guess);

    return 0;
}