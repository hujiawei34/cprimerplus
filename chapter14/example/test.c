#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
struct names{
    char first[20];
    char last[20];

};
struct person{
    int id;
    struct names name;
};
int main(int argc, char *argv[])
{
    struct person ted={1,{"ted","wilson"}};
    puts(ted.name.first);
    
    return 0;
}