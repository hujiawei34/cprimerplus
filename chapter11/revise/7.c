#include <stdio.h>
#include <string.h>
#define M1 "How are ya,sweetie?"
char M2[40]="Beat the clock.";
char *M3="chat";

int main(void)
{
    char words[80];
    printf(M1);//How are ya,sweetie?
    puts(M1);//How are ya,sweetie?\n
    puts(M2);//Beat the clock.\n
    puts(M2+1);//eat the clock.\n
    strcpy(words,M2);
    strcat(words," Win a toy");//Beat the clock. Win a toy
    puts(words);//Beat the clock. Win a toy\n
    words[4]='\0';
    puts(words);//Beat\n
    while(*M3)
        puts(M3++);
    /**
     * chat
     * hat
     * at
     * t
     */

     puts(--M3);//t
     puts(--M3);//at
     M3=M1;
     puts(M3);//How are ya,sweetie?\n
     

    return 0;
}