#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1)
        fp = stdin;
    else if (argc == 2)
        fp = fopen(argv[1], "r");
    else
    {
        fprintf(stderr, "Usage: %s [filename]", argv[0]);
        exit(EXIT_FAILURE);
    }
    double v;
    double sum;
    double n = 0;
    while (fscanf(fp, "%lf", &v) == 1)
    {
        sum += v;
        n++;
    }
    printf("avg=%g\n", sum / n);

    return 0;
}