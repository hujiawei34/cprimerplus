#include <stdio.h>
void Temperatures(double fahrenheit);
void Temperature(double fahrenheit) {
  const double conversion_factor = 5.0 / 9.0;
  const double freezing_point = 32.0;
  double celsius = (fahrenheit - freezing_point) * conversion_factor;
  printf("%.3f 华氏温度等于 %.3f 摄氏度\n", fahrenheit, celsius);

  const double kelvin_offset = 273.16;
  double kelvin = celsius + kelvin_offset;
  printf("%.3f 摄氏度等于 %.3f 开氏温度\n", celsius, kelvin);
}
int main(void) {
  printf("input 华氏温度:");
  double fahrenheit;
  ;
  while (scanf("%lf", &fahrenheit) == 1) {
    Temperature(fahrenheit);
    printf("Enter next number for fahrenheit (none number to quit):");
  }
  printf("Done.\n");
  return 0;
}