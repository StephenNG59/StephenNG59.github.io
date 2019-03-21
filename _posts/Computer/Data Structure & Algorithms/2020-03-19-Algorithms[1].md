---
layout: post
title:  "Algorithms Basis"
date:   2019-03-19 18:40:00 +0800
---

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

---

# 递归[Recursive] 和迭代[Iteration]

## 递归

自己调用自己。分为递推和回归两个阶段。递归在栈中存储中间结果，占用空间，如果递归太深容易造成Stack Overflow；另外大量函数调用带来时间开销。

常见用途包括反转字符串，计算斐波那契数列，快速排序，树遍历。

## 迭代

A不停调用B。利用变量的原值不断推算出变量的新值。效率高，没有什么额外开销；代码不如递归简洁。

* 参考[递归和迭代的区别、联系、优缺点][add1]

---

# 排序算法

## 快速排序[Quick Sort]

时间平均$$O(n \log{n})$$，最差$$O(n^2)$$。空间$$O(n \log{n})$$。

* 快排经典实现：

    1. 指定左、右边界，划定pivot。

    2. 两个指针分别从左右往中间靠，找到左侧比pivot大的，和右侧比pivot小的，这两个直接进行交换。最后结果是pivot左侧都比它小，右侧都比它大。

    3. 把左右边界分别设置为左侧、右侧，递归调用。

## 归并排序[Merge Sort]

时间平均和最差$$O(n \log{n})$$。空间depends on实现方法：$$O(n)$$/$$O(1)$$。

分成两半，分别对两半进行MergeSort排序，然后merge。

---

# 搜索算法

## 二分查找

用于有序数组。

[add1]: https://blog.csdn.net/laoyang360/article/details/7855860