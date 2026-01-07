// talkback.c -- 演示与用户交互的简单程序
#include <stdio.h>
#include <string.h>
#define DENSITY 62.4 // 人体密度，单位为磅/立方英尺
int main(void)
{
    float weight, volume;
    int size, letters;
    char first_name[40]; // name数组可以容纳39个字符加一个结尾
    char second_name[40];

    printf("Hi! What's your first name and second name?\n");
    scanf("%s %s", first_name, second_name);
    printf("%s %s, what's your weight in pounds?\n", first_name, second_name);
    scanf("%f", &weight);
    size = sizeof(first_name);
    letters = strlen(first_name);
    volume = weight / DENSITY;
    printf("Well, %s %s, your volume is %.2f cubic feet.\n", first_name, second_name, volume);
    printf("Also, your first name has %d letters,\n"
           "and we have %d bytes to store it.\n",
           letters, size);
    return 0;
}