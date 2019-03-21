---
layout: post
title:  "Data Structure Basis"
date:   2019-03-19 08:40:00 +0800
---

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

Based on 《[Cracking the Coding Interview][ctci]》. This blog mostly comes from *IX - Interview Questions*.

---
# 1. Hash Tables #

通过hash(key)获得hash code，然后对哈希表的长度取余，获得index。由于可能有冲突，每个index对应一个链表。

* Lookup time: $$O(1)$$，worst case$$O(n)$$

* Space: 需要allocate一个大的数组

* 处理冲突的方法：

    + 链表：最常用

    + Binary Search Tree：用于一些很特殊的数据分布

    + Open Addressing With -
        - Linear Probing：会造成集聚（clustering）
        - Quadratic Probing
        - Double Hashing：用第二个hash算法
    
---
# 2. Linked Lists #

注意最好把nodes通过一个类（或者结构）包装起来，这样如果有其他objects指向这个链表，当链表的head node改变的时候，只需要改变包装类（结构）中指向head node的指针，而不需要影响其他objects。 

* Runner Technique：遍历链表时可以同时用两个步幅不同的指针，可用在很多链表问题中。 

    * e.g. a1->a2->...->an->b1->b2->...->bn需要改成a1->b1->a2->b2->...->an->bn. 

        可以让p1步幅为1，p2步幅为2.
    
    * e.g. 找到链表中倒数第k个node.
        
        可以让p1在p2前第k个。

* e.g. 只给定在链表中的一个node，要删除这个node.
    
    设这个node为a，把a的下一个node复制到a，然后删除下一个node。

* 单向/双向链表

---
# 3. Stacks & Queues #

通常需要支持push，pop，peak（查看最顶元素），isEmpty。

* e.g. 设计一个除了push，pop，还可以返回最小值的stack. 要求$$O(1)$$.

    让每一个node记录在它下面（包括它）的所有数的最小值。这样，即使最小值被pop了，也不需要重新遍历stack，保证了$$O(1)$$。

* e.g. 只使用一个temporary stack（不使用其他结构，如数组），实现stack的排序。

    假设s1是原始stack，s2是tempo stack，每次s1 pop出一个a，暂存在变量里，从s2里不断pop元素到s1中，直到找到适合a的位置，push进s2。对s1的所有元素都进行这样的操作直到empty。这样保证s2始终有序。

---
# 4. Trees & Graphs #

## Trees

* **Binary Search Tree**（BST,二叉搜索树）

    对所有节点$$n$$，$$left \; descendents \leq n < right \; descendents$$. 

* Balanced Tree

    不完美，但足够保证插入和查找有$$O(\log{n})$$的时间复杂度。

    + **Red-Black Tree**（BST的一种）

        - RULES

            - 不能连续两个红节点

            - 任何给定节点，它的所有到叶节点的路径上，黑节点数量相等

        - 保证路径长度最长/最短的比例在2之内。以此保证**插入、查找和删除的时间$$O(\log{n})$$**。

        - 按照BST插入新节点后，首先设为红色，然后改变颜色解决冲突。    

    + **AVL Tree**（BST的一种）

        - RULES

            - 每个节点记录左右子树高度

            - 左子树和右子树高度相差不超过1

        - 插入新节点后左/右旋转解决冲突。

        - 保证**插入、查找和删除的时间$$O(\log{n})$$**。

* 二叉树的中序、先序、后序遍历

    使用递归实现（[递归和迭代][some-address-of-my-blog]）。

* 最小堆[Min-Heap]&最大堆[Max-Heap]

    + 是完全二叉树（只能缺右下角的叶节点）。

    + 插入后Bubble Up。**插入、取出最小值的时间复杂度$$O(\log{n})$$**。

## Graphs

* 图的表示方法：

    + 邻接表[Adjacency List]

        使用Graph类，以及Node类来表示。也可以只使用Node类，然后通过Node的数组存储。后者更紧凑，但没有那么干净，通常更倾向于使用前者。

    + 邻接矩阵[Adjacency Matrices]

* 图的搜索方法

    + **Depth-First Search**（DFS)

        一般在需要遍历时使用，较简单。每个Node使用visited来标记是否被访问过。

        ```C++
        void search(Node root) {
            if (root == null) return;
            visit(root);
            root.visited = true;
            for each (Node n in root.adjacent) {
                if (n.visited == false) {
                    search(n);
                }
            }
        }
        ```

    + **Breadth-First Search**（BFS)

        一般在搜索路径的时候使用。注意使用队列来实现，每个Node使用marked来标记是否进入队列，然后按队列顺序访问。把一个节点r的相邻节点全部enqueue之后，再从队列中dequeue来访问。

        ```C++
        void search(Node root) {
            Queue queue = new Queue();
            root.marked = true;
            queue.enqueue(root);    // Add to the end of queue

            while (!queue.isEmpty()) {
                Node r = queue.dequeue();   // Remove from teh front of the queue
                visit(r);
                foreach (Node n in r.adjacent) {
                    if (n.marked == false) {
                        n.marked = true;
                        queue.enqueue(n);
                    }
                }
            }
        }
        ```

* 加权图的搜索方法：Dijkstra's Algorithm


[ctci]: http://www.crackingthecodinginterview.com/