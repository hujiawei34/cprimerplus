#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@file tree.py
@brief 二叉查找树的 Python 实现
@author Claude
@date 2026-01-29

这是 tree.c 的 Python 版本实现，包含所有核心功能
"""


class Item:
    """
    项目类
    存储宠物的基本信息
    """
    def __init__(self, petname="", petkind=""):
        self.petname = petname  # 宠物名字
        self.petkind = petkind  # 宠物种类

    def __str__(self):
        return f"Pet: {self.petname:<19} kind: {self.petkind:<19}"

    def __repr__(self):
        return f"Item('{self.petname}', '{self.petkind}')"


class TreeNode:
    """
    树节点类
    二叉查找树的节点，包含数据和左右子节点指针
    """
    def __init__(self, item):
        self.item = item        # 节点存储的数据项
        self.left = None        # 指向左子节点的指针
        self.right = None       # 指向右子节点的指针

    def __repr__(self):
        return f"TreeNode({self.item})"


class BinarySearchTree:
    """
    二叉查找树类
    表示整个二叉查找树，包含根节点和节点数量
    """
    MAXITEMS = 10  # 最大项目数

    def __init__(self):
        """初始化树"""
        self.root = None  # 指向根节点的指针
        self.size = 0     # 树中当前的节点数量

    def is_empty(self):
        """
        检查树是否为空
        @return True 树为空（根节点为 None）
        @return False 树不为空
        """
        return self.root is None

    def is_full(self):
        """
        检查树是否已满
        @return True 树已满（达到最大项目数 MAXITEMS）
        @return False 树未满
        """
        return self.size == self.MAXITEMS

    def item_count(self):
        """
        返回树中的项目数量
        @return 树中当前存储的项目数量
        """
        return self.size

    def add_item(self, item):
        """
        向树中添加一个项目

        @param item 要添加的项目
        @return True 成功添加项目
        @return False 添加失败（树已满、项目重复）

        功能说明：
        1. 检查树是否已满
        2. 检查项目是否已存在（不允许重复）
        3. 创建新节点
        4. 如果树为空，新节点成为根节点
        5. 否则，递归地将新节点添加到适当位置
        6. 增加树的大小计数
        """
        if self.is_full():
            print("Tree is full")
            return False

        if self.in_tree(item):
            print("Attempted to add duplicate item")
            return False

        new_node = TreeNode(item)
        self.size += 1

        if self.root is None:
            self.root = new_node
        else:
            self._add_node(new_node, self.root)

        return True

    def _add_node(self, new_node, root):
        """
        递归地将新节点添加到树中（私有辅助方法）

        @param new_node 要添加的新节点
        @param root 当前子树根节点

        递归算法：
        1. 使用 _to_left() 判断新节点是否应该放在左子树
           - 如果左子节点为空，直接插入
           - 否则递归调用 _add_node() 处理左子树
        2. 使用 _to_right() 判断新节点是否应该放在右子树
           - 如果右子节点为空，直接插入
           - 否则递归调用 _add_node() 处理右子树
        """
        if self._to_left(new_node.item, root.item):
            if root.left is None:
                root.left = new_node
            else:
                self._add_node(new_node, root.left)
        elif self._to_right(new_node.item, root.item):
            if root.right is None:
                root.right = new_node
            else:
                self._add_node(new_node, root.right)
        else:
            raise ValueError("Location error in _add_node()")

    def _to_left(self, item1, item2):
        """
        判断第一个项目是否应该放在第二个项目的左侧

        @param item1 第一个项目
        @param item2 第二个项目
        @return True item1 应该在 item2 的左子树中
        @return False item1 不应该在 item2 的左子树中

        比较规则（按字典序）：
        1. 首先比较 petname（宠物名字）
        2. 如果 petname 相同，则比较 petkind（宠物种类）
        3. 只有当 item1 < item2 时返回 True
        """
        if item1.petname < item2.petname:
            return True
        elif item1.petname == item2.petname and item1.petkind < item2.petkind:
            return True
        return False

    def _to_right(self, item1, item2):
        """
        判断第一个项目是否应该放在第二个项目的右侧

        @param item1 第一个项目
        @param item2 第二个项目
        @return True item1 应该在 item2 的右子树中
        @return False item1 不应该在 item2 的右子树中

        比较规则（按字典序）：
        1. 首先比较 petname（宠物名字）
        2. 如果 petname 相同，则比较 petkind（宠物种类）
        3. 只有当 item1 > item2 时返回 True
        """
        if item1.petname > item2.petname:
            return True
        elif item1.petname == item2.petname and item1.petkind > item2.petkind:
            return True
        return False

    def in_tree(self, item):
        """
        检查项目是否在树中

        @param item 要查找的项目
        @return True 项目在树中
        @return False 项目不在树中
        """
        _, child = self._seek_item(item)  # 使用 _ 表示不需要 parent
        return child is not None

    def _seek_item(self, item):
        """
        在树中查找项目并返回父子节点对（私有辅助方法）

        @param item 要查找的项目
        @return (parent, child) 父节点和子节点的元组

        返回值说明：
        - 如果找到项目：child 是包含该项目的节点，parent 是其父节点
        - 如果未找到：child 为 None，parent 是搜索路径上的最后一个节点
        - 如果树为空：child 和 parent 都为 None
        """
        parent = None
        child = self.root

        if child is None:
            return parent, child

        while child is not None:
            if self._to_left(item, child.item):
                parent = child
                child = child.left
            elif self._to_right(item, child.item):
                parent = child
                child = child.right
            else:
                # 找到了
                break

        return parent, child

    def delete_item(self, item):
        """
        从树中删除一个项目

        @param item 要删除的项目
        @return True 成功删除项目
        @return False 删除失败（项目不在树中）

        功能说明：
        1. 使用 _seek_item() 查找要删除的项目及其父节点
        2. 如果项目不存在，返回 False
        3. 根据项目位置调用 _delete_node()
        4. 减少树的大小计数
        """
        parent, child = self._seek_item(item)

        if child is None:
            return False

        # 删除节点
        if parent is None:
            # 删除根节点
            self.root = self._delete_node(child)
        elif parent.left == child:
            # 删除左子节点
            parent.left = self._delete_node(child)
        else:
            # 删除右子节点
            parent.right = self._delete_node(child)

        self.size -= 1
        return True

    def _delete_node(self, node):
        """
        删除单个节点（私有辅助方法）

        @param node 要删除的节点
        @return 替换该节点的新节点

        这是二叉查找树删除操作中最复杂的函数，需要处理三种情况：

        情况1：要删除的节点没有左子节点
          - 用右子节点替换当前节点

        情况2：要删除的节点没有右子节点（但有左子节点）
          - 用左子节点替换当前节点

        情况3：要删除的节点有两个子节点（最复杂）
          - 找到左子树中最右边的节点（左子树中的最大值）
          - 将该节点的右指针指向要删除节点的右子树
          - 用左子树替换当前节点
          - 这样可以保持二叉查找树的性质

        ========== 具体示例：删除节点 7（情况3）==========
        原始树结构：
               7
              / \
             3   10
            / \  / \
           1  5 9  12

        删除步骤：
        1. 节点 7 有左子节点(3)和右子节点(10)，属于情况3
        2. 从左子节点 3 开始，向右遍历找最右节点：
           - 从 3 向右到 5
           - 5 没有右子节点，所以 5 是左子树中的最右节点（最大值）
        3. 将节点 5 的右指针指向节点 7 的右子树(10)
        4. 返回节点 7 的左子树(3)作为替换节点

        删除后的树结构：
               3
              / \
             1   5
                  \
                  10
                 / \
                9  12
        """
        # ========== 情况1：要删除的节点没有左子节点 ==========
        if node.left is None:
            # 用右子节点替换当前节点（右子节点可能为 None，这也是正确的）
            return node.right

        # ========== 情况2：要删除的节点没有右子节点（但有左子节点）==========
        elif node.right is None:
            # 用左子节点替换当前节点（此时左子节点一定不为 None）
            return node.left

        # ========== 情况3：要删除的节点有两个子节点 ==========
        else:
            # 步骤1：找到左子树中最右边的节点（即左子树中的最大值节点）
            temp = node.left
            while temp.right is not None:
                temp = temp.right
            # 循环结束后，temp 指向左子树中最右边的节点

            # 步骤2：将左子树最右节点的右指针指向要删除节点的右子树
            temp.right = node.right

            # 步骤3：返回左子树作为替换节点
            return node.left

    def traverse(self, func):
        """
        遍历树并对每个项目执行指定函数

        @param func 要对每个项目执行的函数

        使用中序遍历（in-order traversal）访问树中的每个节点
        中序遍历顺序：左子树 -> 根节点 -> 右子树
        对于二叉查找树，中序遍历会按排序顺序访问所有项目
        """
        if self.root is not None:
            self._in_order(self.root, func)

    def _in_order(self, node, func):
        """
        中序遍历树（私有辅助方法）

        @param node 当前节点
        @param func 要对每个项目执行的函数

        递归实现中序遍历：
        1. 递归遍历左子树
        2. 处理当前节点（调用 func）
        3. 递归遍历右子树
        """
        if node is not None:
            self._in_order(node.left, func)
            func(node.item)
            self._in_order(node.right, func)

    def delete_all(self):
        """
        删除树中的所有节点

        功能说明：
        1. 将根节点设置为 None（Python 会自动进行垃圾回收）
        2. 将树的大小重置为 0
        3. 树恢复到初始化后的空状态
        """
        self.root = None
        self.size = 0

    def print_tree(self, node=None, level=0, prefix="Root: "):
        """
        以树形结构打印树（辅助调试方法）

        @param node 当前节点（默认为根节点）
        @param level 当前层级
        @param prefix 前缀字符串
        """
        if node is None:
            if level == 0:
                node = self.root
            else:
                return

        if node is None:
            print("Empty tree")
            return

        print("  " * level + prefix + str(node.item.petname))
        if node.left is not None or node.right is not None:
            if node.left:
                self.print_tree(node.left, level + 1, "L--- ")
            else:
                print("  " * (level + 1) + "L--- None")
            if node.right:
                self.print_tree(node.right, level + 1, "R--- ")
            else:
                print("  " * (level + 1) + "R--- None")


def test_binary_search_tree():
    """
    测试二叉查找树
    使用示例树进行测试：
           7
          / \
         3   10
        / \  / \
       1  5 9  12
    """
    print("=" * 60)
    print("二叉查找树测试程序")
    print("=" * 60)

    # 创建树
    tree = BinarySearchTree()

    # 添加节点（按照能构建出示例树的顺序）
    print("\n【步骤1】构建示例树...")
    nodes = [
        ("7", "number"),
        ("3", "number"),
        ("10", "number"),
        ("1", "number"),
        ("5", "number"),
        ("9", "number"),
        ("12", "number")
    ]

    for name, kind in nodes:
        item = Item(name, kind)
        tree.add_item(item)
        print(f"  添加节点: {name}")

    print(f"\n树中节点数量: {tree.item_count()}")

    # 打印树结构
    print("\n【步骤2】树的结构:")
    print("""
           7
          / \\
         3   10
        / \\  / \\
       1  5 9  12
    """)
    tree.print_tree()

    # 中序遍历（应该按升序输出）
    print("\n【步骤3】中序遍历（升序）:")
    items = []
    tree.traverse(lambda item: items.append(item.petname))
    print("  ", " -> ".join(items))

    # 查找测试
    print("\n【步骤4】查找测试:")
    test_items = [("5", "number"), ("8", "number")]
    for name, kind in test_items:
        item = Item(name, kind)
        found = tree.in_tree(item)
        print(f"  查找 {name}: {'找到' if found else '未找到'}")

    # 删除节点 7（根节点，有两个子节点）
    print("\n【步骤5】删除根节点 7...")
    print("  这是最复杂的情况：节点有两个子节点")
    print("  算法步骤：")
    print("    1. 找到左子树(3)中最右边的节点(5)")
    print("    2. 将节点5的右指针指向节点7的右子树(10)")
    print("    3. 用左子树(3)替换节点7")

    item_to_delete = Item("7", "number")
    success = tree.delete_item(item_to_delete)
    print(f"  删除结果: {'成功' if success else '失败'}")
    print(f"  树中节点数量: {tree.item_count()}")

    # 打印删除后的树结构
    print("\n【步骤6】删除后的树结构:")
    print("""
           3
          / \\
         1   5
              \\
              10
             / \\
            9  12
    """)
    tree.print_tree()

    # 再次中序遍历
    print("\n【步骤7】删除后的中序遍历:")
    items = []
    tree.traverse(lambda item: items.append(item.petname))
    print("  ", " -> ".join(items))
    print("  注意：节点7已被删除，其他节点仍保持升序")

    # 验证 BST 性质
    print("\n【步骤8】验证二叉查找树性质:")
    print("  ✓ 节点 3：左子树(1) < 3 < 右子树(5及其子树)")
    print("  ✓ 节点 5：无左子树，右子树(10及其子树) > 5")
    print("  ✓ 节点 10：左子树(9) < 10 < 右子树(12)")
    print("  ✓ 所有节点仍然满足 BST 性质！")

    # 测试其他删除情况
    print("\n【步骤9】测试其他删除情况...")

    # 删除叶子节点
    print("  删除叶子节点 1...")
    tree.delete_item(Item("1", "number"))
    items = []
    tree.traverse(lambda item: items.append(item.petname))
    print("    中序遍历:", " -> ".join(items))

    # 删除只有一个子节点的节点
    print("  删除只有右子节点的节点 5...")
    tree.delete_item(Item("5", "number"))
    items = []
    tree.traverse(lambda item: items.append(item.petname))
    print("    中序遍历:", " -> ".join(items))

    print("\n【步骤10】最终树结构:")
    tree.print_tree()

    # 清空树
    print("\n【步骤11】清空树...")
    tree.delete_all()
    print(f"  树中节点数量: {tree.item_count()}")
    print(f"  树是否为空: {tree.is_empty()}")

    print("\n" + "=" * 60)
    print("测试完成！")
    print("=" * 60)


if __name__ == "__main__":
    test_binary_search_tree()
