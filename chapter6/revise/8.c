#include <stdio.h>
/**input is
 * Go west, young man!
 * output is
 * Go west, youn
 */
void func_a(void)
{
    char ch;

    scanf("%c", &ch);
    while (ch != 'g')
    {
        printf("%c", ch);
        scanf("%c", &ch);
    }
}
/**input is
 * Go west, young man!
 * output is
 * Hp!xd...
 */
void func_b(void)
{
    char ch;
    scanf("%c", &ch);
    while (ch != 'g')
    {
        printf("%c", ++ch);
        scanf("%c", &ch);
    }
}
/**input is
 * Go west, young man!
 * output is
 * Go west, young
 */
void func_c(void)
{
    char ch;
    do
    {
        scanf("%c", &ch);
        printf("%c", ch);
    } while (ch != 'g');
}
/**input is
 * Go west, young man!
 * output is
 * $o west, youn
 */
void func_d(void)
{
    char ch;
    scanf("%c", &ch);
    for (ch = '$'; ch != 'g'; scanf("%c", &ch))
        printf("%c", ch);
}
int main(void)
{
    func_d();
    return 0;
}