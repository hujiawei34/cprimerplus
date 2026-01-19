/* addaword.c --使用fprintf(),fscanf(),rewind() 函数*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 41 //max of word len 
int main(void)
{
    FILE *fp;
    char word[MAX];
    if((fp = fopen("words.txt","a+")) == NULL)
    {
        fprintf(stderr,"Can't open words.txt\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter words to add (press # to stop):\n");
    while(fscanf(stdin,"%40s",word) == 1 && word[0] != '#')
    {
        fprintf(fp,"%s\n",word);
    }
    rewind(fp);
    printf("The words in words.txt are:\n");
    while(fscanf(fp,"%s",word) == 1)
    {
        printf("%s\n",word);
    }
    putc('\n',stdout);
    puts("Done.");
    fclose(fp);
    return 0;
}