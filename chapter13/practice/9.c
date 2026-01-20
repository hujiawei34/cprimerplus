/* addaword.c --使用fprintf(),fscanf(),rewind() 函数*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 41 //max of word len 
int main(void)
{
    FILE *fp;
    char word[MAX];
    int count = 0;
    int num;

    if((fp = fopen("words.txt","a+")) == NULL)
    {
        fprintf(stderr,"Can't open words.txt\n");
        exit(EXIT_FAILURE);
    }
    // 1. 确定当前的编号起始点
    rewind(fp);
    while (fscanf(fp, "%d %s", &num, word) == 2) {
        count = num;
    }

    printf("Enter words to add (press # to stop):\n");
    while(fscanf(stdin,"%40s",word) == 1 && word[0] != '#')
    {
        fprintf(fp,"%d %s\n", ++count, word);
    }
    rewind(fp);
    printf("The words in words.txt are:\n");
    while(fscanf(fp,"%d %s", &num, word) == 2)
    {
        printf("%d %s\n", num, word);
    }
    putc('\n',stdout);
    puts("Done.");
    fclose(fp);
    return 0;
}