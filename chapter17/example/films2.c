/* 使用一个结构链表*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../my.h"
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};
int main(int argc, char *argv[])
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);

        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            ;
        puts("Enter next movie title(empty line to stop):");
        prev = current;
    }
    if (head == NULL)
    {
        printf("No data entered. ");
    }
    else
    {
        printf("Here is the movie list:\n");
    }
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
    current=head;
    while(current!=NULL)
    {
        struct film *temp = current->next;
        free(current);
        current = temp;
    }
    puts("Bye.");

    return 0;
}