/**
 * @file tree.c tree.h 中函数实现
 * @author hujiawei (jiaweihu047@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-01-28
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/**
 * @brief 父子节点对结构体
 *
 * 用于 SeekItem() 函数的返回值，同时保存父节点和子节点的指针
 * 这样可以在删除操作中方便地访问要删除节点的父节点
 */
typedef struct pair
{
    Trnode *parent; // 指向父节点的指针
    Trnode *child;  // 指向子节点的指针
} Pair;

static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);

static void InOrder(const Trnode *root, void (*pfun)(Item item));

static Pair SeekItem(const Item *pi, const Tree *pt);

static void DeleteNode(Trnode **ppt);

static void DeleteAllNodes(Trnode *pt);

/**
 * @brief 初始化树
 *
 * @param pt 指向树的指针
 *
 * 将树的根节点设置为 NULL，大小设置为 0，创建一个空树
 */
void InitializeTree(Tree *pt)
{
    pt->root = NULL;
    pt->size = 0;
}
/**
 * @brief 检查树是否为空
 *
 * @param pt 指向树的指针
 * @return true 树为空（根节点为 NULL）
 * @return false 树不为空
 */
bool TreeIsEmpty(const Tree *pt)
{
    if (pt->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief 检查树是否已满
 *
 * @param pt 指向树的指针
 * @return true 树已满（达到最大项目数 MAXITEMS）
 * @return false 树未满
 */
bool TreeIsFull(const Tree *pt)
{
    if (pt->size == MAXITEMS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief 返回树中的项目数量
 *
 * @param pt 指向树的指针
 * @return int 树中当前存储的项目数量
 */
int TreeItemCount(const Tree *pt)
{
    return pt->size;
}

/**
 * @brief 向树中添加一个项目
 *
 * @param pi 指向要添加的项目的指针
 * @param pt 指向树的指针
 * @return true 成功添加项目
 * @return false 添加失败（树已满、项目重复或内存分配失败）
 *
 * 功能说明：
 * 1. 检查树是否已满
 * 2. 检查项目是否已存在（不允许重复）
 * 3. 创建新节点
 * 4. 如果树为空，新节点成为根节点
 * 5. 否则，递归地将新节点添加到适当位置
 * 6. 增加树的大小计数
 */
bool AddItem(const Item *pi, Tree *pt)
{
    Trnode *new_node;
    if (TreeIsFull(pt))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, pt).child != NULL)
    {
        fprintf(stderr, "Attemped to add duplicate item\n");
        return false;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    pt->size++;
    if (pt->root == NULL)
    {
        pt->root = new_node;
    }
    else
    {
        AddNode(new_node, pt->root);
    }
    return true;
}

/**
 * @brief 检查项目是否在树中
 *
 * @param pi 指向要查找的项目的指针
 * @param pt 指向树的指针
 * @return true 项目在树中
 * @return false 项目不在树中
 *
 * 通过调用 SeekItem() 查找项目，如果找到则返回 true
 */
bool InTree(const Item *pi, const Tree *pt)
{
    return (SeekItem(pi, pt).child == NULL) ? false : true;
}

/**
 * @brief 从树中删除一个项目
 *
 * @param pi 指向要删除的项目的指针
 * @param pt 指向树的指针
 * @return true 成功删除项目
 * @return false 删除失败（项目不在树中）
 *
 * 功能说明：
 * 1. 使用 SeekItem() 查找要删除的项目及其父节点
 * 2. 如果项目不存在，返回 false
 * 3. 根据项目位置调用 DeleteNode()：
 *    - 如果是根节点（无父节点），删除根节点
 *    - 如果是父节点的左子节点，删除左子节点
 *    - 如果是父节点的右子节点，删除右子节点
 * 4. 减少树的大小计数
 */
bool DeleteItem(const Item *pi, Tree *pt)
{
    Pair look;

    look = SeekItem(pi, pt);
    if (look.child == NULL)
    {
        return false;
    }
    if (look.parent == NULL)
    {
        DeleteNode(&pt->root);
    }
    else if (look.parent->left == look.child)
    {
        DeleteNode(&look.parent->left);
    }
    else
    {
        DeleteNode(&look.parent->right);
    }
    pt->size--;
    return true;
}

/**
 * @brief 遍历树并对每个项目执行指定函数
 *
 * @param pt 指向树的指针
 * @param pfun 指向函数的指针，该函数接受一个 Item 参数
 *
 * 使用中序遍历（in-order traversal）访问树中的每个节点
 * 中序遍历顺序：左子树 -> 根节点 -> 右子树
 * 对于二叉查找树，中序遍历会按排序顺序访问所有项目
 */
void Traverse(const Tree *pt, void (*pfun)(Item item))
{
    if (pt != NULL)
    {
        InOrder(pt->root, pfun);
    }
}

/**
 * @brief 删除树中的所有节点
 *
 * @param pt 指向树的指针
 *
 * 功能说明：
 * 1. 递归删除所有节点并释放内存
 * 2. 将根节点设置为 NULL
 * 3. 将树的大小重置为 0
 * 4. 树恢复到初始化后的空状态
 */
void DeleteAll(Tree *pt)
{
    if (pt != NULL)
    {
        DeleteAllNodes(pt->root);
    }
    pt->root = NULL;
    pt->size = 0;
}

/**
 * @brief 中序遍历树（静态辅助函数）
 *
 * @param root 指向当前节点的指针
 * @param pfun 指向要对每个项目执行的函数的指针
 *
 * 递归实现中序遍历：
 * 1. 递归遍历左子树
 * 2. 处理当前节点（调用 pfun）
 * 3. 递归遍历右子树
 *
 * 对于二叉查找树，这种遍历方式会按升序访问所有节点
 */
static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

/**
 * @brief 递归删除所有节点（静态辅助函数）
 *
 * @param root 指向当前节点的指针
 *
 * 使用后序遍历删除所有节点：
 * 1. 先保存右子树指针（因为删除当前节点后会丢失）
 * 2. 递归删除左子树
 * 3. 释放当前节点
 * 4. 递归删除右子树
 *
 * 这种顺序确保在删除父节点之前先删除所有子节点
 */
static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

/**
 * @brief 递归地将新节点添加到树中（静态辅助函数）
 *
 * @param new_node 指向要添加的新节点的指针
 * @param root 指向当前子树根节点的指针
 *
 * 递归算法：
 * 1. 使用 ToLeft() 判断新节点是否应该放在左子树
 *    - 如果左子节点为空，直接插入
 *    - 否则递归调用 AddNode() 处理左子树
 * 2. 使用 ToRight() 判断新节点是否应该放在右子树
 *    - 如果右子节点为空，直接插入
 *    - 否则递归调用 AddNode() 处理右子树
 * 3. 如果既不应该在左边也不应该在右边，说明出现错误
 *
 * 注意：调用此函数前应确保项目不重复
 */
static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            AddNode(new_node, root->left);
        }
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            AddNode(new_node, root->right);
        }
    }
    else
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

/**
 * @brief 判断第一个项目是否应该放在第二个项目的左侧（静态辅助函数）
 *
 * @param i1 指向第一个项目的指针
 * @param i2 指向第二个项目的指针
 * @return true i1 应该在 i2 的左子树中
 * @return false i1 不应该在 i2 的左子树中
 *
 * 比较规则（按字典序）：
 * 1. 首先比较 petname（宠物名字）
 * 2. 如果 petname 相同，则比较 petkind（宠物种类）
 * 3. 只有当 i1 < i2 时返回 true
 */
static bool ToLeft(const Item *i1, const Item *i2)
{
    int compl;
    if ((compl = strcmp(i1->petname, i2->petname)) < 0)
    {
        return true;
    }
    else if (compl == 0 && strcmp(i1->petkind, i2->petkind) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 判断第一个项目是否应该放在第二个项目的右侧（静态辅助函数）
 *
 * @param i1 指向第一个项目的指针
 * @param i2 指向第二个项目的指针
 * @return true i1 应该在 i2 的右子树中
 * @return false i1 不应该在 i2 的右子树中
 *
 * 比较规则（按字典序）：
 * 1. 首先比较 petname（宠物名字）
 * 2. 如果 petname 相同，则比较 petkind（宠物种类）
 * 3. 只有当 i1 > i2 时返回 true
 */
static bool ToRight(const Item *i1, const Item *i2)
{
    int compl;
    if ((compl = strcmp(i1->petname, i2->petname)) > 0)
    {
        return true;
    }
    else if (compl == 0 && strcmp(i1->petkind, i2->petkind) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 创建一个新的树节点（静态辅助函数）
 *
 * @param pi 指向要存储在节点中的项目的指针
 * @return Trnode* 指向新创建的节点的指针，如果内存分配失败则返回 NULL
 *
 * 功能说明：
 * 1. 为新节点分配内存
 * 2. 将项目数据复制到节点中
 * 3. 将左右子节点指针初始化为 NULL
 * 4. 返回新节点的指针
 */
static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;
    new_node = malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

/**
 * @brief 在树中查找项目并返回父子节点对（静态辅助函数）
 *
 * @param pi 指向要查找的项目的指针
 * @param pt 指向树的指针
 * @return Pair 包含父节点和子节点指针的结构体
 *
 * 返回值说明：
 * - 如果找到项目：look.child 指向包含该项目的节点，look.parent 指向其父节点
 * - 如果未找到：look.child 为 NULL，look.parent 指向搜索路径上的最后一个节点
 * - 如果树为空：look.child 和 look.parent 都为 NULL
 *
 * 查找算法：
 * 1. 从根节点开始
 * 2. 使用 ToLeft() 和 ToRight() 判断应该向左还是向右搜索
 * 3. 记录父节点，移动到相应的子节点
 * 4. 重复直到找到项目或到达叶节点
 *
 * 此函数用于 InTree()、AddItem() 和 DeleteItem()
 */
static Pair SeekItem(const Item *pi, const Tree *pt)
{
    Pair look;
    look.parent = NULL;
    look.child = pt->root;
    if (look.child == NULL)
    {
        return look;
    }
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            break;
        }
    }
    return look;
}

/**
 * @brief 删除单个节点（静态辅助函数）
 *
 * @param ptr 指向节点指针的指针（二级指针）
 *
 * 这是二叉查找树删除操作中最复杂的函数，需要处理三种情况：
 *
 * 情况1：要删除的节点没有左子节点
 *   - 用右子节点替换当前节点
 *   - 释放当前节点
 *
 * 情况2：要删除的节点没有右子节点（但有左子节点）
 *   - 用左子节点替换当前节点
 *   - 释放当前节点
 *
 * 情况3：要删除的节点有两个子节点（最复杂）
 *   - 找到左子树中最右边的节点（左子树中的最大值）
 *   - 将该节点的右指针指向要删除节点的右子树
 *   - 用左子树替换当前节点
 *   - 释放当前节点
 *   - 这样可以保持二叉查找树的性质
 *
 * 使用二级指针的原因：
 * 需要修改父节点中指向此节点的指针（可能是父节点的 left 或 right）
 *
 * ========== 具体示例：删除节点 7（情况3）==========
 * 原始树结构：
 *        7
 *       / \
 *      3   10
 *     / \  / \
 *    1  5 9  12
 *
 * 删除步骤：
 * 1. 节点 7 有左子节点(3)和右子节点(10)，属于情况3
 * 2. 从左子节点 3 开始，向右遍历找最右节点：
 *    - 从 3 向右到 5
 *    - 5 没有右子节点，所以 5 是左子树中的最右节点（最大值）
 * 3. 将节点 5 的右指针指向节点 7 的右子树(10)
 * 4. 用节点 7 的左子树(3)替换节点 7
 * 5. 释放节点 7
 *
 * 删除后的树结构：
 *        3
 *       / \
 *      1   5
 *           \
 *           10
 *          / \
 *         9  12
 *
 * 验证二叉查找树性质：
 * - 节点 3：左子树(1) < 3 < 右子树(5及其子树)  ✓
 * - 节点 5：无左子树，右子树(10及其子树) > 5   ✓
 * - 节点 10：左子树(9) < 10 < 右子树(12)       ✓
 * - 所有节点仍然满足 BST 性质！
 */
static void DeleteNode(Trnode **ptr)
{
    Trnode *temp; // 临时指针，用于保存要删除的节点或遍历节点

    // ========== 情况1：要删除的节点没有左子节点 ==========
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;              // 保存要删除的节点地址
        *ptr = (*ptr)->right;     // 用右子节点替换当前节点（右子节点可能为 NULL，这也是正确的）
        free(temp);               // 释放被删除节点的内存
    }
    // ========== 情况2：要删除的节点没有右子节点（但有左子节点）==========
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;              // 保存要删除的节点地址
        *ptr = (*ptr)->left;      // 用左子节点替换当前节点（此时左子节点一定不为 NULL）
        free(temp);               // 释放被删除节点的内存
    }
    // ========== 情况3：要删除的节点有两个子节点 ==========
    else
    {
        // 步骤1：找到左子树中最右边的节点（即左子树中的最大值节点）
        // 这个节点的值小于要删除节点的右子树中的所有值，大于左子树中的其他所有值
        for (temp = (*ptr)->left;      // 从左子节点开始
             temp->right != NULL;       // 只要还有右子节点就继续
             temp = temp->right)        // 向右移动
        {
            continue;                   // 循环体为空，只是遍历到最右边
        }
        // 循环结束后，temp 指向左子树中最右边的节点（该节点的 right 为 NULL）

        // 步骤2：将左子树最右节点的右指针指向要删除节点的右子树
        temp->right = (*ptr)->right;   // 连接右子树，保持所有节点都在树中

        // 步骤3：准备删除节点
        temp = *ptr;                   // 保存要删除的节点地址

        // 步骤4：用左子树替换当前节点
        // 关键理解：ptr 是指向"指向节点7的指针"的指针
        // 例如：如果删除根节点，ptr 指向 pt->root
        //      *ptr 就是 pt->root（指向节点7）
        //      (*ptr)->left 就是节点3的地址
        // 执行后：pt->root 从指向节点7 变为 指向节点3
        // 这样节点3就成为了新的根节点（或新的子树根）
        *ptr = (*ptr)->left;           // 左子树成为新的子树根

        // 步骤5：释放被删除节点的内存
        free(temp);                    // 释放原节点（节点7）

        // 结果：左子树的最右节点现在连接了原节点的右子树
        // 所有节点仍然满足二叉查找树的性质：
        // - 左子树的所有值 < 原节点的值 < 右子树的所有值
    }
}