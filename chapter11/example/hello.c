/* hello.c -- 把命令行参数转换为数字*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, times;

  if (argc < 2 || (times = atoi(argv[1])) < 1)
    printf("Usage: %s positive-integer\n", argv[0]);
  else
    for (i = 1; i <= times; i++)
      printf("Hello world!\n");
  return 0;
}