#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand()%77);
    }
    puts("");
    return 0;
}