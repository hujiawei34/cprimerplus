#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 4096
#define FILENAME_LEN 40
void append(FILE *fp_s, FILE *fp_t);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s source_filename1 [source_filename2] ... target_filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *target_filename = argv[argc - 1];
    FILE *fp_t;
    if ((fp_t = fopen(target_filename, "a+")) == NULL)
    {
        fprintf(stderr, "can not write to %s\n", target_filename);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc - 1; i++)
    {
        char *source_filename = argv[i];
        FILE *fp_s;
        if ((fp_s = fopen(source_filename, "r")) == NULL)
        {
            fprintf(stderr, "can not read file:%s\n", source_filename);
            exit(EXIT_FAILURE);
        }
        append(fp_s, fp_t);
        printf("appended:%s\n", source_filename);
    }
    return 0;
}
void append(FILE *fp_s, FILE *fp_t)
{
    int bytes;
    static char buff[BUFFSIZE];
    if ((bytes = fread(buff, sizeof(char), BUFFSIZE, fp_s)) > 0)
        fwrite(buff, sizeof(char), bytes, fp_t);
}