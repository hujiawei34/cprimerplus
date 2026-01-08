/* 复习题 1 2 3  */
#include <stdio.h>
int main(void) {
  // 1.
  // a.
  int result;
  result = (2 + 3) * 6;//30
  printf("%d\n", result);
  //b.
  result=(12+6)/2*3;//27
  printf("%d\n", result);
  //c.
  int y,x;
  y=x=(2+3)/4;//1
  printf("%d\n", y);
  printf("%d\n", x);
  //d.
  result=3+2*(x=7/2);//9
  printf("%d\n", result);


  //2.
  //a.
  x=(int)3.8+3.3;//6;
  printf("%d\n", x);

  //b.
  x=(2+3)*10.5;//52
  printf("%d\n", x);

  //c.
  x=3/5*22.0;//0
  printf("%d\n", x);

  //d.
  x=22.0*3/5;//13
  printf("%d\n", x);


  //3.
  //a.
  printf("%.2f\n",30.0/4.0*5.0);//7.5*5=37.50
  //b.
  printf("%.2f\n",30.0/(4.0*5.0));// 30/20=1.50
  //c.
  printf("%d\n",30/4*5);//7*5=35
  //d.
  printf("%d\n",30*5/4);//150/4=37
  //e.
  printf("%f\n",30/4.0*5);//7.5*5=37
  //f.
  printf("%f\n",30/4*5.0);//7*5.0=35.0=35


  return 0;
}