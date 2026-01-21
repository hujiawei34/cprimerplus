#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../my.h"
#define MAXTITL 41
#define MAXAUTH 31
struct book {
    char title[MAXTITL];
    char author[MAXAUTH];
    float value;
};
int main(int argc, char *argv[])
{
    struct book library;
    printf("Enter title: ");
    s_gets(library.title, MAXTITL);
    printf("Enter author: ");
    s_gets(library.author, MAXAUTH);
    printf("Enter value: ");
    scanf("%f", &library.value);

    printf("Title: %s\n", library.title);
    printf("Author: %s\n", library.author);
    printf("Value: %.2f\n", library.value);
    puts("Done.");

    return 0;
}