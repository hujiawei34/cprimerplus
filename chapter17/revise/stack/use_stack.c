/**
 * @file use_stack.c use stack to simulator elevator
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief 使用stack模拟公司下班时，不同楼层员工乘坐电梯下班的情况
 * @version 0.1
 * @date 2026-01-30
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "stack.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_FLOOR 100 // 最高楼层,最低楼层1
typedef struct staff
{
    Item i;
    /* 目标楼层,简化实现，固定为1，*/
    int dest_floor;
    /* 当前所在楼层*/
    int current_floor;
} Staff;

char *int2string(unsigned int i) // i=123
{
    char *re = malloc(5 * sizeof(char));
    char temp[5];
    unsigned int left = i;
    if (i == 0)
    {
        re[0] = '0';
        re[1] = '\0';
        return re;
    }
    int index = 0;
    while (left != 0)
    {
        temp[index] = left % 10 + '0';
        left = left / 10;
        index++;
    }
    // index=3,temp=['3','2','1']
    int k;
    for (k = 0, index--; index >= 0; index--, k++)
    {
        re[k] = temp[index];
    }
    k++;
    re[k] = '\0';
    return re;
}
void initStaff(Staff *s, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        s[i].current_floor = rand() % 100;
        s[i].dest_floor = 1;
        s[i].i.age = rand() % 30 + 20;
        strcpy(s[i].i.dept, "dept");
        strcat(s[i].i.dept, int2string(i));
        strcpy(s[i].i.name, "name");
        strcat(s[i].i.name, int2string(i));
    }
}
void printStaff(Staff s)
{
    printf("%s age of %d from  %s is at %d floor go to %d floor\n ", s.i.name, s.i.age, s.i.dept, s.current_floor, s.dest_floor);
}
void showAllStaff(Staff *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printStaff(s[i]);
    }
}
int main(int argc, char const *argv[])
{
    Staff s[MAX_S];
    initStaff(s, MAX_S);
    showAllStaff(s, MAX_S);

    return 0;
}
