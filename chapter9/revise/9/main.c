#include <stdio.h>
#include "9.h"
int main(void)
{
    print_choice();
    int choice;
    choice = get_choice(1, 4);
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            printf("%s done!\n", OPTION_NAME1);
            break;
        case 2:
            printf("%s done!\n", OPTION_NAME2);
            break;
        case 3:
            printf("%s done!\n", OPTION_NAME3);
            break;
        }
        print_choice();
        choice = get_choice(1, 4);
        printf("choice=%d\n",choice);

    }
    return 0;
}