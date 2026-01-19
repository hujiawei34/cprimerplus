#include <stdio.h>
static int mode;
static double distance;
static double fuel;
void show_info(void){
    if(mode==0)
        printf("Fuel consumption is %g liters per 100 km.\n",fuel/distance*100);
    else
        printf("Fuel consumption is %g miles per gallon.\n",distance/fuel);
}
void set_mode(int input_mode){
    extern int mode;
    if(input_mode>=0&&input_mode<=1)
        mode=input_mode;
    else
        printf("Invalid mode specified. Mode %d(%s) is used.\n",mode,mode==0?"metric":"US");
}
void get_info(){
    extern double distance;
    extern double fuel;
    printf("Enter distance traveled in %s: ",mode==0?"kilometers":"miles");
    scanf("%lf",&distance);
    printf("Enter fuel consumed in %s: ",mode==0?"liters":"gallons");
    scanf("%lf",&fuel);
}