#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LINELEN 256
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage %s 'a' 'filename'\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int ch = argv[1][0];
    FILE *fp;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "can not read %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    char line[LINELEN];

    while (fgets(line, LINELEN, fp) != NULL)
    {
        if (strchr(line, ch))
            fputs(line, stdout);
    }
    return 0;
}