#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../my.h"
#define MAXTITL 41
#define MAXAUTH 31
#define MAXBKS 100
struct book {
    char title[MAXTITL];
    char author[MAXAUTH];
    float value;
};
int main(int argc, char *argv[])
{
    struct book library[MAXBKS];
    int count=0;
    int index;

    printf("Please enter the book title.\n");
    printf("Please [Enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        printf("Please enter the author.\n");
        s_gets(library[count].author, MAXAUTH);
        printf("Please enter the value.\n");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS - 1) {
            printf("Please enter the next book title.\n");
        }
        count++;
    }
    if (count>0)
    {
        printf("Here is your collection:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
    }else{
        printf("No books entered.\n");
    }

    puts("Done.");

    return 0;
}