/* 使用一个结构数组*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../my.h"
#define TSIZE 45
#define FMAX 5
struct film{
    char title[TSIZE];
    int rating;
};
int main(int argc, char *argv[])
{
    struct film movies[FMAX];
    int i=0;
    int j;

    puts("Enter first movie title:");
    while(i<FMAX && s_gets(movies[i].title,TSIZE)!=NULL && movies[i].title[0]!='\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i].rating);
        while(getchar() !='\n');
        puts("Enter next movie title(empty line to stop):");
    }
    if(i ==0){
        printf("No data entered. ");
    }else{
        printf("Here is the movie list:\n");
    }
    for(j=0;j<i;j++)
    {
        printf("Movie: %s Rating: %d\n",movies[i].title,movies[i].rating);
    }
    puts("Bye.");
    
    return 0;
}