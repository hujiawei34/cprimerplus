#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME_LEN 40
int main(void)
{
    char filename[FILENAME_LEN];
    puts("Enter the reduce filename:");
    scanf("%40s",filename);
    FILE * fp_s,*fp_t;
    if((fp_s=fopen(filename,"r"))==NULL)
    {
        fprintf(stderr,"can not read file:%s\n",filename);
        exit(EXIT_FAILURE);
    }
    filename[FILENAME_LEN-1]='\0';

    char target_filename[FILENAME_LEN-8];
    strncpy(target_filename,filename,FILENAME_LEN-8);
    strcat(target_filename,".origin");
    if((fp_t=fopen(target_filename,"w"))==NULL)
    {
        fprintf(stderr,"can not write to %s\n",target_filename);
        exit(EXIT_FAILURE);

    }
    char ch;
    int i=0;
    while((ch=getc(fp_s))!=EOF)
    {
        if(i++%3==0)
            putc(ch,fp_t);
    }
    fclose(fp_s);
    fclose(fp_t);

    return 0;
}