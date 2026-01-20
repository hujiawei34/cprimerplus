
/*
| 数字 | 对应符号 | 验证依据（示例行）|
|------|----------|-------------------|
| 0    | 空格（无显示） | 第1行数字`0 0 9 0...`对应符号行`# *%##%*'`，0
位置为空格 | | 1    | `.`（句点） | 第3行数字`...5 8
1 9...`对应符号`*%.#%*~*'`，1 对应 `.` | | 2    | `'`（单引号） | 第1行数字`...5
2 0...`对应符号`...*'`，2 对应 `'` | | 3    | `:`（冒号） | 第10行数字`...9
3 9...`对应符号`...:...`，3 对应 `:` | | 4    | `~`（波浪号） | 第3行数字`...5
4 5...`对应符号`...~*'`，4 对应 `~` | | 5    | `*`（星号） | 第8行全 5
数字对应全 `*` 符号行，5 对应 `*` | | 6    | `=`（等号） | 第14行数字`...6 6
0...`对应符号`...==`，6 对应 `=` | | 7    | `+`（加号） | 第14行数字`...6 6
0...`对应符号`...==`，7 对应 `+` | | 8    | `%`（百分号） | 第9行全 8 数字对应全
`%` 符号行，8 对应 `%` | | 9    | `#`（井号） | 第10行全 9 数字对应全 `#`
符号行，9 对应 `#` |
*/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init_mapper(char mapper[10])
{
  mapper[0] = ' ';
  mapper[1] = '.';
  mapper[2] = '\'';
  mapper[3] = ':';
  mapper[4] = '~';
  mapper[5] = '*';
  mapper[6] = '=';
  mapper[7] = '+';
  mapper[8] = '%';
  mapper[9] = '#';
}
int main(int argc, char *argv[])
{
  char *filename = "12.txt";
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }
  char ch;
  int ROW=1,COL=1;
  while ((ch = getc(fp)) != EOF)
  {
    if (isdigit(ch))
    {
      COL++;
    }
    else if (ch == '\n')
    {
      COL = 0;
      ROW++;
    }
  }
  rewind(fp);

  int list[ROW][COL];
  memset(list, 0, sizeof(list));
  
  int row = 0;
  int col = 0;
  while ((ch = getc(fp)) != EOF)
  {
    if (isdigit(ch))
    {
      list[row][col++] = atoi(&ch);
    }
    else if (ch == '\n')
    {
      col = 0;
      row++;
    }
  }
  char mapper[10];
  init_mapper(mapper);

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      printf("%c ", mapper[list[i][j]]);
    }
    printf("\n");
  }
  fclose(fp);
  return 0;
}