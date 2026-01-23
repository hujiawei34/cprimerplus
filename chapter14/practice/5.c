#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CSIZE 4
struct name {
  char fname[20];
  char lname[20];
};
struct student {
  struct name name;
  double grade[3];
  double average;
};
void s_gets_fp(char *s, int n, FILE *fp) {
  char *ret_val;
  int i = 0;
  ret_val = fgets(s, n, fp);
  if (ret_val) {
    char *find = strchr(s, '\n');
    if (find)
      *find = '\0';
    else
      while (getc(fp) != '\n' && !feof(fp))
        continue;
  }
}
double get_class_avg(struct student s[], int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += s[i].average;
  }
  return sum / n;
}
int main(int argc, char *argv[]) {
  struct student s[CSIZE];
  FILE *fp = fopen("students.txt", "r");
  for (int i = 0; i < CSIZE; i++) {
    printf("input student %d name:", i + 1);
    s_gets_fp(s[i].name.fname, 20, fp);
    printf("input student %d last name:", i + 1);
    s_gets_fp(s[i].name.lname, 20, fp);
    printf("input student %d 3 grades:", i + 1);
    for (int j = 0; j < 3; j++) {
      fscanf(fp, "%lf", &s[i].grade[j]);
      while (getc(fp) != '\n' && !feof(fp))
        continue;
    }
    s[i].average = (s[i].grade[0] + s[i].grade[1] + s[i].grade[2]) / 3;
  }
  puts("");

  for (int i = 0; i < CSIZE; i++) {
    printf("%s, %s average:%.2f\n", s[i].name.lname, s[i].name.fname,
           s[i].average);
  }
  printf("class average:%.2f\n", get_class_avg(s, CSIZE));
  return 0;
}