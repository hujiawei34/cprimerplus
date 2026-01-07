#include <stdio.h>
int main(void)
{
    printf("input your download speed in Mbps: ");

    float speed_mbps;
    scanf("%f", &speed_mbps);
    printf("input your file size in MB: ");
    float size_mb;
    scanf("%f", &size_mb);

    float time_seconds = (size_mb * 8) / speed_mbps;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed_mbps, size_mb);
    printf("downloads in %.2f seconds.\n", time_seconds);
    return 0;
}