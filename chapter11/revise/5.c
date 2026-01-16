#include <stdio.h>
char *pr(char *str) {
  char *pc;

  pc = str;
  while (*pc)
    putchar(*pc++);
  do {
    putchar(*--pc);
  } while (pc - str);
  return (pc);
}
int main(void) {
  char *x = pr("Ho Ho Ho!");
  /**a. will print
  Ho Ho Ho!!oH oH oH
   */
  // b.x是char *类型，指向字符串的第一个字符
  // c.x的值是字符串的第一个字符的地址
  // d.表达式*--pc是先将pc减1，再解引用，即指向字符串的最后一个字符，与--*pc不同，--*pc是先解引用，再减1，即指向字符串的最后一个字符，再用字符-1得到字符的ASCII码值
  // e.如果使用*--pc，会先将pc减1，再解引用，即指向字符串的最后一个字符，再用字符-1得到字符的ASCII码值，再用ASCII码值-1得到字符的ASCII码值，再用ASCII码值-1得到字符的ASCII码值，...，直到得到字符的ASCII码值为0，即空字符'\0'
  // f.两个while循环用来测试字符串正向打印和逆向打印
  // g.如果pr()函数的参数是空字符串，while循环不会进入，do循环执行一次，函数返回空指针
  //    pr("");
  // h.

  return 0;
}