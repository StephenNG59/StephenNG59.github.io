---
layout: post
title:  "Algorithms Practical"
date:   2019-03-22 8:50:00 +0800
---

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

- [寻找两个有序数组的中位数](#%E5%AF%BB%E6%89%BE%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E4%BD%8D%E6%95%B0)
- [最长回文子串](#%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2)
- [回文数](#%E5%9B%9E%E6%96%87%E6%95%B0)


# 寻找两个有序数组的中位数

中位数将一个集合分成长度相等的两个子集，其中一个子集元素总是大于另一个子集的元素。先保证数量相等，然后调试划分的位置，使大小关系成立。

# 最长回文子串

"babad" --> "bab" or "aba"；"cbbd" --> "bb"

使用动态规划法，$$P(i,j)$$表示从$$i$$到$$j$$的子串是否为回文串，则

$$P(i,j) = (P(i+1, j-1)) \; and \; S_i = S_j)$$

先初始化一字母和二字母的回文串，然后找三字回文串……

时间$$O(n^2)$$，空间$$O(n^2)$$。

# 回文数

121 --> true；122 --> false；-121 --> false

只需反转后半部分的数字，然后比较它和前半部分是否相同。

