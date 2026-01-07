#include <stdio.h>
#define GALLON_TO_LITERS 3.785411784
int main(void)
{
    printf("输入旅行的里程公里数：");
    float kilometers;
    scanf("%f", &kilometers);
    printf("输入旅行的耗油量升数：");
    float liters;
    scanf("%f", &liters);
    printf("每百公里油耗数为：%.2f\n", liters / (kilometers / 100));
    const float MILES_TO_KILOMETERS = 1.609344;
    const float KILOMETERS_TO_MILES = 1.0 / MILES_TO_KILOMETERS;
    float miles = kilometers * KILOMETERS_TO_MILES;
    float gallons = liters / GALLON_TO_LITERS;
    printf("每加仑英里数为：%.2f\n", miles / gallons);
    return 0;
}