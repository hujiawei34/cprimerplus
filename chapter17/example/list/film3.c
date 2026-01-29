/**
 * @file film3.c
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 与list.c 一起编译
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "../../../my.h"
void showmovies(Item item);

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            ;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title(empty line to stop):");

    }
    if(ListIsEmpty(&movies))
    {
        printf("No data entered. ");
    }else{
        printf("Here is the movie list:\n");
        Traverse(&movies,showmovies);
    }
    printf("You entered %d movies.\n",ListItemCount(&movies));
    EmptyTheList(&movies);
    printf("Bye!");
    return 0;
}
void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n",item.title,item.rating);
}
