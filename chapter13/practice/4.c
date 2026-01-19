#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename1 filename2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++)
    {
        FILE *fp;
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "can not read file:%s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("\n==========%s========\n", argv[i]);
        char ch;
        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        printf("\n====================\n");
    }
    puts("Done!");

    return 0;
}