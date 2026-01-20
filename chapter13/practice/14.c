
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
#include <math.h>
void init_mapper(char mapper[10]) {
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
void get_dimensions(FILE *fp, int *rows, int *cols) {
  char ch;
  int r = 0;
  int c = 0;
  int max_c = 0;
  bool in_line = false;

  rewind(fp);
  while ((ch = getc(fp)) != EOF) {
    if (isdigit(ch)) {
      c++;
      in_line = true;
    } else if (ch == '\n') {
      if (in_line) {
        r++;
        if (c > max_c) max_c = c;
        c = 0;
        in_line = false;
      }
    }
  }
  // 处理最后一行可能没有换行符的情况
  if (in_line) {
      r++;
      if (c > max_c) max_c = c;
  }
  
  *rows = r;
  *cols = max_c;
  rewind(fp);
}

void read_data(int rows, int cols, int list[rows][cols], FILE *fp) {
  char ch;
  int r = 0;
  int c = 0;
  
  memset(list, 0, sizeof(int) * rows * cols);
  rewind(fp);

  while ((ch = getc(fp)) != EOF) {
    if (isdigit(ch)) {
      if (r < rows && c < cols) {
        list[r][c++] = ch - '0'; // 直接转数字
      }
    } else if (ch == '\n') {
      r++;
      c = 0;
    }
  }
}
/**
 * @brief 显示二维数组的符号表示
 * 
 * 遍历二维数组，根据元素值从映射表中获取对应的符号，
 * 并按行打印到标准输出。
 * 
 * @param rows 数组的行数
 * @param cols 数组的列数
 * @param list 二维数组，存储要显示的数据
 * @param mapper 映射表，将数字映射为对应的符号
 */
void show_data(int rows, int cols, int list[rows][cols], char mapper[10]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", mapper[list[i][j]]);
    }
    printf("\n");
  }
}
/**
 * @brief 设置每个元素的平均值
 * 
 * 遍历二维数组，对每个元素，如果其上下左右四个方向的元素与它的绝对差都大于1，
 * 则将该元素的值设置为其四邻元素的平均值（四舍五入）。
 * 
 * @param rows 数组的行数
 * @param cols 数组的列数
 * @param list 二维数组，存储要处理的数据
 */
void set_avg(int rows, int cols, int list[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int v=list[i][j];
      int lv;//left value
      int rv;//right value
      int uv;//upper value
      int dv;//down value
      if (i == 0) uv = v;
      else uv = list[i - 1][j];

      if (i == rows - 1) dv = v;
      else dv = list[i + 1][j];

      if (j == 0) lv = v;
      else lv = list[i][j - 1];

      if (j == cols - 1) rv = v;
      else rv = list[i][j + 1];
      
      if (abs(v-lv) >1 && abs(v-rv) >1 && abs(v-uv) >1 && abs(v-dv) >1)
        list[i][j] = round((lv + rv + uv + dv) / 4.0);
    }
  }
}
int main(int argc, char *argv[]) {
  char *filename = "12.txt";
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }
  int ROW = 0, COL = 0;
  get_dimensions(fp, &ROW, &COL);
  // printf("ROW=%d, COL=%d\n", ROW, COL); // Debug if needed

  int list[ROW][COL];
  read_data(ROW, COL, list, fp);
  char mapper[10];
  init_mapper(mapper);
  set_avg(ROW, COL, list);
  show_data(ROW, COL, list, mapper);

  fclose(fp);
  return 0;
}