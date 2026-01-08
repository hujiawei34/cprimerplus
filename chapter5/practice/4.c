#include <stdio.h>
int main(void) {
  printf("Enter a height in centimeters:");
  float cm_input;
  scanf("%f", &cm_input);
  const float CM_PER_INCH = 2.54;
  const int INCHES_PER_FOOT = 12;
  while (cm_input > 0) {
    float inches = cm_input / CM_PER_INCH;
    int feet = inches / INCHES_PER_FOOT;
    float left_inches = inches - feet * INCHES_PER_FOOT;
    int tmp = cm_input;
    float show_input_cm = tmp;
    printf("%.1f cm = %d feet, %.1f inches.\n", show_input_cm, feet, left_inches);
    printf("Enter a height in centimeters(<=0 to quit):");
    scanf("%f", &cm_input);
  }
  printf("bye\n");

  return 0;
}