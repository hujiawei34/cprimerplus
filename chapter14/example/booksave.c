/* 在文件中保存结构 中的内容*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../my.h"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(int argc, char *argv[])
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
        {
            puts("Current contents of book.data:");
        }
        printf("%s by %s: %.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.data file is full.", stderr);
        exit(2);
    }
    puts("please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            ;
        count++;
        if (count < MAXBKS)
        {
            puts("Next book titles");
        }
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s:%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
    {
        puts("No books?Too bad.\n");
    }
    puts("Bye.");
    fclose(pbooks);

    return 0;
}