#include <stdio.h>
int main(void)
{
    float g, h;
    float tax, rate;//rate not initialized, will be set to 0.0
    g = 1e21;
    tax = rate * g;
    printf("g=%.2e\ntax=%.2e\nrate=%f", g, tax, rate);
    return 0;
}