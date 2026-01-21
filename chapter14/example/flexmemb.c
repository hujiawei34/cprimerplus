#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
struct flex
{
    size_t count;
    double average;
    double score[]; // 伸缩型数组
};
void showFlex(const struct flex *p);

int main(int argc, char *argv[])
{
    struct flex *pf1, *pf2;
    int n = 5;
    int i;
    int tot = 0;
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for (i = 0; i < n; i++)
    {
        pf1->score[i] = 20.0 - i;
        tot += pf1->score[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);
    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;

    for (i = 0; i < n; i++)
    {
        pf2->score[i] = 20.0 - i / 2.0;
        tot += pf2->score[i];
    }
    pf2->average = tot / n;
    showFlex(pf2);
    return 0;
}
void showFlex(const struct flex *p)
{
    printf("count=%ld,score=", p->count);
    for (size_t i = 0; i < p->count; i++)
        printf("%g ", p->score[i]);
    printf(",average=%g\n", p->average);
}