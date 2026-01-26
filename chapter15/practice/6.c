#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define MASK_ID 0xff
#define MASK_SIZE 0x7f
struct fonts
{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int align : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};
enum alignment_enum {
    left,center,right
};
char *alignment[] = {
    "left",
    "center",
    "right"};
char *turn[] = {
    "off",
    "on"};
struct fonts init()
{
    struct fonts re;
    re.id = 1;
    re.size = 12;
    re.align = left;
    re.bold = 0;
    re.italic = 0;
    re.underline = 0;
    return re;
}
void show(struct fonts f)
{
    printf(" ID  SIZE  ALIGNMENT  B    I    U\n");
    printf("%3d  %3d   %-8s  %-4s %-4s %-4s\n",
           f.id,
           f.size,
           alignment[f.align],
           turn[f.bold],
           turn[f.italic],
           turn[f.underline]);
}
void showmenu(void)
{
    printf("f)change font\t");
    printf("s)change size\t");
    printf("a)change alignment\t\n");
    printf("b)toggle bold\t");
    printf("i)toggle italic\t");
    printf("u)toggle underline\t\n");
    printf("q)quit\n");
}
char get_choice(void)
{
    char ch;
    ch = getchar();
    while (getchar() != '\n')
        ;

    while (strchr("fsabiuq", ch) == NULL)
    {
        printf("invalid input:\n");
        ch = getchar();
        while (getchar() != '\n')
            ;
    }
    return ch;
}
void set_size(struct fonts *f)
{
    printf("Enter font size(0-127):");
    int size;
    scanf("%d", &size);
    while (getchar() != '\n')
        ;
    f->size = size & MASK_SIZE;
}
void set_font(struct fonts *f)
{
    printf("Enter font id(0-255):");
    int id;
    scanf("%d", &id);
    while (getchar() != '\n')
        ;

    f->id = id & MASK_ID;
}
void set_align(struct fonts *f)
{
    printf("l)left\tc)center\tr)right\n");
    char c=getchar();
    while(getchar()!='\n');
    
    switch (c)
    {
    case 'l':
        f->align=left;
        break;
    case 'c':
        f->align=center;
        break;
    case 'r':
        f->align=right;
        break;
    
    default:
        break;
    }
}
int main(int argc, char *argv[])
{
    struct fonts my_font = init();
    show(my_font);
    showmenu();
    char ch = get_choice();
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'f':
            set_font(&my_font);
            break;
        case 's':
            set_size(&my_font);
            break;
        case 'a':
            set_align(&my_font);
            break;
        case 'b':
            my_font.bold = !my_font.bold;
            break;
        case 'i':
            my_font.italic = !my_font.italic;
            break;
        case 'u':
            my_font.underline = !my_font.underline;
            break;
        default:
            printf("unknow choice\n");
        }
        show(my_font);
        showmenu();
        ch = get_choice();
    }

    return 0;
}