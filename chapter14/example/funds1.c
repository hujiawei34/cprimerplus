#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define FUNDLEN 50
struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(double d1,double d2)
{
    return d1+d2;
}
int main(int argc, char *argv[])
{
    struct funds stan={
        "Garlic-Melon Bank",
        4032.27,
        "Luck's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of %.2f.\n",sum(stan.bankfund,stan.savefund));
    return 0;
}