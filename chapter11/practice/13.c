#include <stdio.h>
int main(int argc, char const *argv[]) {
  for (int i = argc; i >1; i--) {
      printf("%s ", argv[i-1]);
  }
//   for (int i = 1; i < argc; i++) {
//     printf("%s ", argv[i]);
//   }
  puts("");
  return 0;
}