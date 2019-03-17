---
layout: post
title:  "Linear Algebra[1] - Linear Transformations and Matrices"
date:   2019-03-16 20:50:50 +0800
---

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

Based on a great series that introduce linear algebra [Essence of linear algebra - 3blue1brown][youtube-linear]. This blog covers [ch3][youtube-ch3], [ch4][youtube-ch4] and [ch5][youtube-ch5].

# What is Linear Transformation
A **transformation** is basically a **function** that takes an input vector to generate some output vector. In our imagination, the vector is moved smoothly to a new position. So we call it a transformation instead of a function.

![image1](../../../assets/img/LA_1_1.png)

To understand the transformation as a whole, we might think of every vectors in the space conceptualized as single points.

![image2](../../../assets/img/LA_1_2.gif)

The effect of various transformation is beautiful. Although, as we can imagine, arbitrary transformation can look pretty complicated.

![image3](../../../assets/img/LA_1_3.gif)

Luckily linear transformaiton limits itself to a special type of transformation, ones that are easier to understand. Visually, a **linear transformation** has two properties:
1. All lines remain lines.
2. Origin remain fixed.

In general, we can think of linear transformations as keeping grid lines *parallel* and *evenly spaced*.

![image4](../../../assets/img/LA_1_4.gif "Not a linear transformation")

# How to describe linear transformation
As it turns out, you only need to record where the two basis vectors, $$\vec{i}$$ and $$\vec{j}$$, land. Because every vector that started off as a certatin combination of $$\vec{i}$$ and $$\vec{j}$$, will ends up with that same linear combination of where those two vectors landed.

![image5](../../../assets/img/LA_1_5.png)

As a result, **a 2D linear transformation is completely described by just 4 numbers**: the two coordinates for where $$\vec{i}$$ lands, and the two coordinates for where $$\vec{j}$$ lands. And it's common to package these coordinates into a 2-by-2 grid of numbers, called a $$2\times2 \; Matrix$$, where you can interpret the columns as the two special vectors where $$\vec{i}$$ and $$\vec{j}$$ each land.

![image6](../../../assets/img/LA_1_6.gif)

Now we can think about these columns as the transformed versions of the basis vectors, and the results of transformations as the appropriate linear combination of those vectors.

![image7](../../../assets/img/LA_1_7.png)

A special case is that, when the vectors that $$\vec{i}$$ and $$\vec{j}$$ land on are **linearly dependent**, which means that one is a scaled version of the other. It means that the linear transformation squishes all of 2D space onto the line where those two vectors sit, also known as the one-dimensional span of those two linearly dependent vectors.

![image8](../../../assets/img/LA_1_8.gif)

# Push it further
## Matrix multiplication as composition
The composition of two transformations can be represented by single transformation, which captures the overall effect of applying those two actions successively. This new matrix is called the **product** of the original two matrices. 

![image9](../../../assets/img/LA_1_9.gif)

Always remember, the multiplying two matrices like this has the geometric meaning of applying one transformation then another. But one thing that's kinda weird here, is that this has reading from right to left.

![image10](../../../assets/img/LA_1_10.png)

Applying the method mentioned above of finding where $$\vec{i}$$ and $$\vec{i}$$ each land, we could figure out the multiplied matrix.

![image11](../../../assets/img/LA_1_11.gif)

Notice, there's a lot of symbols here, and it's common to be taught this formula as something to memorize along with a certain algorithmic process to kind of help remember it. 

![image12](../../../assets/img/LA_1_12.png)

But before memorizing that process, just get in the habit of thinking about what matrix multiplication relly represents: applying one transformation after another. This will give you a much betterh conceptual framework that makes the properties of matrix multiplication much easier to understand.

## 3-dimensional matrix
In 3D spaces, it's nothing different to 2D spaces but there's one more basis vector on the z-axis, $$\vec{k}$$. 

# Conclusion
Every time you see a matrix, you can interpret it as a certain transformation of space. Once you really digest this idea, you're in a great position to understand linear algebra deeply. Almost all of the topics coming up will become easier to understand once you start thinking about matrices as transformations of space.

[youtube-linear]: https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab
[youtube-ch3]: https://youtu.be/kYB8IZa5AuE
[youtube-ch4]: https://youtu.be/XkY2DOUCWMU
[youtube-ch5]: https://youtu.be/rHLEWRxRGiM