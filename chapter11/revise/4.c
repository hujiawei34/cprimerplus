#include <stdio.h>
#include <string.h>
int main(void)
{
    char goldwyn[40]="art of it all ";
    char samuel[40]="I read p";
    const char * quote="the way through.";

    strcat(goldwyn,quote);//art of it all the way through.
    strcat(samuel,goldwyn);
    puts(samuel);
    //I read part of it all the way through.
    return 0;
}