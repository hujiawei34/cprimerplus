#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define slen 10
#define boy_num 19
struct boy {
  int n;
  char fname[slen];
  char lname[slen];
  int up_time;  // 上场数
  int hit_time; // 击中数
  int run_time; // 走垒数
  int rbi;      // 打点
  double sb;    // 安打率=击中数/ 上场次数
};
void show_boys(struct boy boys[boy_num], int n) {
  printf("n fname lname up_time hit_time run_time rbi sb\n");
  for (int i = 0; i < n; i++) {
    printf("%d %s %s %d %d %d %d %.2f\n", boys[i].n, boys[i].fname,
           boys[i].lname, boys[i].up_time, boys[i].hit_time, boys[i].run_time,
           boys[i].rbi, boys[i].sb);
  }
}
struct boy add_boy(struct boy b1, struct boy b2) {
  struct boy b3;
  b3.n = b1.n;
  strcpy(b3.fname, b1.fname);
  strcpy(b3.lname, b1.lname);
  b3.up_time = b1.up_time + b2.up_time;
  b3.hit_time = b1.hit_time + b2.hit_time;
  b3.run_time = b1.run_time + b2.run_time;
  b3.rbi = b1.rbi + b2.rbi;
  b3.sb = (double)b3.hit_time / (double)b3.up_time;
  return b3;
}
int main(int argc, char *argv[]) {
  FILE *fp = fopen("6.txt", "r");
  struct boy boys[boy_num];
  memset(boys, 0, sizeof(boys));
  struct boy b;
  int status = fscanf(fp, "%d %s %s %d %d %d %d\n", &b.n, b.fname, b.lname,
                      &b.up_time, &b.hit_time, &b.run_time, &b.rbi);
  b.sb = (double)b.hit_time / (double)b.up_time;
  int count = 0;
  while (status == 7 && !feof(fp)) {
    int i;
    int found = 0;
    for (i = 0; i < count; i++) {
      if (boys[i].n == b.n) {
        boys[i] = add_boy(boys[i], b);
        found = 1;
        break;
      }
    }
    if (!found && count < boy_num) {
      boys[count] = b;
      count++;
    }
    status = fscanf(fp, "%d %s %s %d %d %d %d\n", &b.n, b.fname, b.lname,
                    &b.up_time, &b.hit_time, &b.run_time, &b.rbi);
    b.sb = (double)b.hit_time / (double)b.up_time;
  }

  show_boys(boys, count);
  return 0;
}