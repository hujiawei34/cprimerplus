/**
 * @file petclub.c 使用二叉查找树
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "../../../my.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);

/**
 * @brief 主程序
 *
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return int 程序退出状态码
 *
 * 功能说明：
 * 1. 初始化宠物俱乐部树结构
 * 2. 循环显示菜单并处理用户选择
 * 3. 根据用户选择执行相应操作（添加、列出、查找、统计、删除）
 * 4. 用户选择退出时，删除所有节点并释放内存
 */
int main(int argc, char const *argv[])
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            addpet(&pets);
            break;
        case 'l':
            showpets(&pets);
            break;
        case 'f':
            findpet(&pets);
            break;
        case 'n':
            printf("%d pets in club\n",
                   TreeItemCount(&pets));
            break;
        case 'd':
            droppet(&pets);
            break;
        default:
            puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

/**
 * @brief 显示菜单并获取用户选择
 *
 * @return char 用户选择的字符（'a', 'l', 'n', 'f', 'd', 'q'）
 *
 * 功能说明：
 * 1. 显示宠物俱乐部菜单选项
 * 2. 读取用户输入
 * 3. 清除输入缓冲区中的剩余字符
 * 4. 验证输入是否有效
 * 5. 如果输入无效，提示用户重新输入
 * 6. 如果遇到 EOF，返回 'q'（退出）
 */
char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet       l) show list of pets");
    puts("n) number of pets  f) find pets");
    puts("d) delete a pet    q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        ch = tolower(ch);
        if (strchr("alnfdq", ch) == NULL)
        {
            puts("Please enter an a,l,n,f,d or q:");
        }
        else
        {
            break;
        }
    }
    if (ch == EOF)
    {
        ch = 'q';
    }
    return ch;
}

/**
 * @brief 添加宠物到俱乐部
 *
 * @param pt 指向树的指针
 *
 * 功能说明：
 * 1. 检查树是否已满
 * 2. 提示用户输入宠物名字和种类
 * 3. 将输入转换为大写（统一格式）
 * 4. 调用 AddItem() 将宠物添加到树中
 */
void addpet(Tree *pt)
{
    Item temp;
    if (TreeIsFull(pt))
    {
        puts("No rooms in the club!");
    }
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

/**
 * @brief 从俱乐部删除宠物
 *
 * @param pt 指向树的指针
 *
 * 功能说明：
 * 1. 检查树是否为空
 * 2. 提示用户输入要删除的宠物名字和种类
 * 3. 将输入转换为大写（统一格式）
 * 4. 调用 DeleteItem() 尝试删除宠物
 * 5. 显示删除结果（成功或失败）
 */
void droppet(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No enties!");
        return;
    }
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petkind);
    uppercase(temp.petname);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
    {
        printf("is dropped from the club.\n");
    }
    else
    {
        printf("is not a member.\n");
    }
}

/**
 * @brief 显示所有宠物
 *
 * @param pt 指向树的指针
 *
 * 功能说明：
 * 1. 检查树是否为空
 * 2. 如果不为空，使用 Traverse() 遍历树
 * 3. 对每个宠物调用 printitem() 函数显示信息
 * 4. 由于使用中序遍历，宠物会按字母顺序显示
 */
void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
    }
    else
    {
        Traverse(pt, printitem);
    }
}

/**
 * @brief 查找宠物
 *
 * @param pt 指向树的指针
 *
 * 功能说明：
 * 1. 检查树是否为空
 * 2. 提示用户输入要查找的宠物名字和种类
 * 3. 将输入转换为大写（统一格式）
 * 4. 调用 InTree() 检查宠物是否在俱乐部中
 * 5. 显示查找结果（是否为会员）
 */
void findpet(const Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No enties!");
        return;
    }
    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt))
    {
        printf("is a member.\n");
    }
    else
    {
        printf("is not a member.\n");
    }
}

/**
 * @brief 打印单个宠物项目
 *
 * @param item 要打印的宠物项目
 *
 * 功能说明：
 * 以格式化的方式显示宠物的名字和种类
 * 此函数作为回调函数传递给 Traverse()
 */
void printitem(Item item)
{
    printf("Pet: %-19s kind: %-19s\n", item.petname, item.petkind);
}

/**
 * @brief 将字符串转换为大写
 *
 * @param str 指向要转换的字符串的指针
 *
 * 功能说明：
 * 遍历字符串中的每个字符，使用 toupper() 将其转换为大写
 * 这样可以确保所有宠物名字和种类都以统一的大写格式存储
 * 便于比较和查找（不区分大小写）
 */
void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
