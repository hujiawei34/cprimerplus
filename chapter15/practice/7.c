/*
 * 题目 7: 使用 unsigned long 和按位运算符管理结构体信息
 * 
 * 对比分析：位字段 vs 按位运算
 * 
 * 位字段方式（如 chapter15/practice/6.c）：
 *   struct fonts {
 *       unsigned int id : 8;
 *       unsigned int align : 2;
 *       ...
 *   };
 *   优点：代码简洁，易于理解
 *   缺点：C 标准未明确规定位字段的对齐和打包方式，不同编译器产生不同内存布局
 *        无法保证二进制数据格式跨平台一致
 * 
 * 按位运算方式（本文件）：
 *   unsigned long font;
 *   font |= (id & 0xFF) << ID_POS;
 *   优点：精确控制每一位，跨平台保证一致，可靠且可预测
 *   缺点：代码相对复杂，需要手动管理位位置和掩码
 * 
 * 使用场景对比：
 * ┌─────────────────────┬──────────────┬──────────────┐
 * │      方面          │   位字段     │   按位运算   │
 * ├─────────────────────┼──────────────┼──────────────┤
 * │ 代码简洁度          │      ✓       │      ✗       │
 * │ 可移植性            │      ✗       │      ✓       │
 * │ 网络/文件格式       │      ✗       │      ✓       │
 * │ 跨平台一致性        │      ✗       │      ✓       │
 * │ 实际工作中使用比例  │     10%      │     90%      │
 * └─────────────────────┴──────────────┴──────────────┘
 * 
 * 必须使用按位运算的场景：
 * 1. 网络协议 - IP报头、TCP报头等有严格位定义，必须跨平台一致
 *    例如：IP version(4位) | IHL(4位) | DSCP(6位) | ECN(2位)
 * 2. 文件格式 - ZIP、PNG、ELF 等二进制文件格式
 * 3. 硬件通信 - 与单片机、FPGA 通信时需要精确的寄存器位控制
 * 4. 序列化/反序列化 - 数据跨架构（x86 ↔ ARM）传输
 * 5. 性能关键代码 - 避免编译器自动对齐导致的额外开销
 * 
 * 结论：学过位字段后知道"为什么不用"，才能理解工业代码为什么都用按位运算。
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// 位位置定义
#define ID_POS 0        // ID 占 8 位（0-7）
#define SIZE_POS 8      // SIZE 占 7 位（8-14）
#define ALIGN_POS 15    // ALIGN 占 2 位（15-16）
#define BOLD_POS 17     // BOLD 占 1 位（17）
#define ITALIC_POS 18   // ITALIC 占 1 位（18）
#define UNDERLINE_POS 19 // UNDERLINE 占 1 位（19）

// 掩码定义
#define ID_MASK (0xFFL << ID_POS)
#define SIZE_MASK (0x7FL << SIZE_POS)
#define ALIGN_MASK (0x3L << ALIGN_POS)
#define BOLD_MASK (0x1L << BOLD_POS)
#define ITALIC_MASK (0x1L << ITALIC_POS)
#define UNDERLINE_MASK (0x1L << UNDERLINE_POS)

enum alignment_enum {
    left, center, right
};

char *alignment[] = {
    "left",
    "center",
    "right"
};

char *turn[] = {
    "off",
    "on"
};

// 获取字段值
unsigned char get_id(unsigned long font)
{
    return (font >> ID_POS) & 0xFF;
}

unsigned char get_size(unsigned long font)
{
    return (font >> SIZE_POS) & 0x7F;
}

unsigned char get_align(unsigned long font)
{
    return (font >> ALIGN_POS) & 0x3;
}

unsigned char get_bold(unsigned long font)
{
    return (font >> BOLD_POS) & 0x1;
}

unsigned char get_italic(unsigned long font)
{
    return (font >> ITALIC_POS) & 0x1;
}

unsigned char get_underline(unsigned long font)
{
    return (font >> UNDERLINE_POS) & 0x1;
}

// 设置字段值
void set_field_id(unsigned long *font, unsigned char id)
{
    *font &= ~ID_MASK;
    *font |= (id & 0xFF) << ID_POS;
}

void set_field_size(unsigned long *font, unsigned char size)
{
    *font &= ~SIZE_MASK;
    *font |= (size & 0x7F) << SIZE_POS;
}

void set_field_align(unsigned long *font, unsigned char align)
{
    *font &= ~ALIGN_MASK;
    *font |= (align & 0x3) << ALIGN_POS;
}

void set_field_bold(unsigned long *font, unsigned char bold)
{
    *font &= ~BOLD_MASK;
    *font |= (bold & 0x1) << BOLD_POS;
}

void set_field_italic(unsigned long *font, unsigned char italic)
{
    *font &= ~ITALIC_MASK;
    *font |= (italic & 0x1) << ITALIC_POS;
}

void set_field_underline(unsigned long *font, unsigned char underline)
{
    *font &= ~UNDERLINE_MASK;
    *font |= (underline & 0x1) << UNDERLINE_POS;
}

// 初始化
unsigned long init_font()
{
    unsigned long font = 0;
    set_field_id(&font, 1);
    set_field_size(&font, 12);
    set_field_align(&font, left);
    set_field_bold(&font, 0);
    set_field_italic(&font, 0);
    set_field_underline(&font, 0);
    return font;
}

void show(unsigned long font)
{
    printf(" ID  SIZE  ALIGNMENT  B    I    U\n");
    printf("%3d  %3d   %-8s  %-4s %-4s %-4s\n",
           get_id(font),
           get_size(font),
           alignment[get_align(font)],
           turn[get_bold(font)],
           turn[get_italic(font)],
           turn[get_underline(font)]);
}
void showmenu(void)
{
    printf("f)change font\t");
    printf("s)change size\t");
    printf("a)change alignment\n");
    printf("b)toggle bold\t");
    printf("i)toggle italic\t");
    printf("u)toggle underline\n");
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
void set_size(unsigned long *font)
{
    printf("Enter font size(0-127):");
    int size;
    scanf("%d", &size);
    while (getchar() != '\n')
        ;
    set_field_size(font, size & 0x7F);
}

void set_font(unsigned long *font)
{
    printf("Enter font id(0-255):");
    int id;
    scanf("%d", &id);
    while (getchar() != '\n')
        ;
    set_field_id(font, id & 0xFF);
}

void set_align(unsigned long *font)
{
    printf("l)left\tc)center\tr)right\n");
    char c = getchar();
    while (getchar() != '\n')
        ;

    switch (c)
    {
    case 'l':
        set_field_align(font, left);
        break;
    case 'c':
        set_field_align(font, center);
        break;
    case 'r':
        set_field_align(font, right);
        break;
    default:
        break;
    }
}
int main(int argc, char *argv[])
{
    unsigned long my_font = init_font();
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
            set_field_bold(&my_font, !get_bold(my_font));
            break;
        case 'i':
            set_field_italic(&my_font, !get_italic(my_font));
            break;
        case 'u':
            set_field_underline(&my_font, !get_underline(my_font));
            break;
        default:
            printf("unknow choice\n");
        }
        show(my_font);
        showmenu();
        ch = get_choice();
    }
    puts("Bye!");

    return 0;
}