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
void show_menu(void){
    puts("==============================");
    printf("v: view all books\n");
    printf("a: add a book\n");
    printf("d: delete a book\n");
    printf("u: update a book\n");
    printf("q: quit\n");
    printf("Please enter your choice:");
}
char get_choice(void){
    char ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while (strchr("vadaqu", ch) == NULL)
    {
        printf("Please enter a v, a, d, u, or q:");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    }
    return ch;
}
void view_books(struct book library[], int count){
    if (count == 0)
    {
        puts("No books in the library.");
    }
    else
    {
        puts("==========================");
        puts("number title author value");
        for (int i = 0; i < count; i++)
        {
            printf("%d %s %s: %.2f\n", i, library[i].title, library[i].author, library[i].value);
        }
        puts("==========================");
    }
}
void add_book(struct book library[], int *count){
    if (*count == MAXBKS-1)
    {
        fputs("The library is full.", stderr);
        return;
    }
    puts("Please enter the book title.");
    s_gets(library[*count].title, MAXTITL);
    puts("Please enter the author.");
    s_gets(library[*count].author, MAXAUTL);
    puts("Please enter the value.");
    scanf("%f", &library[*count].value);
    while (getchar() != '\n')
        continue;
    FILE *fp=fopen("book.dat","a+b");
    fwrite(&library[*count], sizeof(struct book), 1, fp);
    fclose(fp);
    (*count)++;
}
void delete_book(struct book library[], int *count){
    int index;
    puts("Please enter the book number to delete.");
    scanf("%d", &index);
    while (getchar() != '\n')
        continue;
    if (index < 0 || index >= *count)
    {
        fputs("Invalid book number.", stderr);
        return;
    }
    for (int i = index; i < *count - 1; i++)
    {
        library[i] = library[i + 1];
    }
    (*count)--;
    FILE *fp=fopen("book.dat","w+b");
    fwrite(library, sizeof(struct book), *count, fp);
    fclose(fp);
}
void update_book(struct book library[], int count){
    int index;
    puts("Please enter the book number to update.");
    scanf("%d", &index);
    while (getchar() != '\n')
        continue;
    if (index < 0 || index >= count)
    {
        fputs("Invalid book number.", stderr);
        return;
    }
    puts("Please enter the new title.");
    s_gets(library[index].title, MAXTITL);
    puts("Please enter the new author.");
    s_gets(library[index].author, MAXAUTL);
    puts("Please enter the new value.");
    scanf("%f", &library[index].value);
    while (getchar() != '\n')
        continue;
    FILE *fp=fopen("book.dat","w+b");
    fwrite(library, sizeof(struct book), count, fp);
    fclose(fp);
}
int main(int argc, char *argv[])
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "r")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        count++;
    }
    filecount = count;
    show_menu();
    char ch = get_choice();
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'v':
            view_books(library, count);
            break;
        case 'a':
            add_book(library, &count);
            break;
        case 'd':
            delete_book(library, &count);
            break;
        case 'u':
            update_book(library, count);
            break;
        default:
            break;
        }
        show_menu();
        ch = get_choice();
    }
    puts("Bye.");
    fclose(pbooks);

    return 0;
}