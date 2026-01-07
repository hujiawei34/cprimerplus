#include <stdio.h>
#define B "booboo"
#define X 10
int main() {
    int age ,xp;
    char name[20];
    printf("Please enter your first name:\n");
    scanf("%s", name);
    printf("All right, %s, what is your age?\n", name);
    scanf("%d", &age);
    xp=age+X;
    printf("That's a %s! You must be at lease %d.\n", B, xp);

    return 0;
}