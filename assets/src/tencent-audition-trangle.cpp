/*
三元组
小Q定义了一种特殊的三元组叫做三角形三元组:
对于一个有序的三元组(a, b, c), 如果a, b, c都是正整数, 并且a, b, c三边构成一个三角形, 就称(a, b, c)为三角形三元组。
例如(1, 2, 3)不是三角形三元组, 而(3, 4, 5)和(3, 5, 4)是不同的三角形三元组。
小Q现在给出三个正整数X, Y, Z, 希望你能求出一共有多少个三角形三元组(a, b, c)满足1 <= a <= X, 1 <= b <= Y, 1 <= c <= Z.
输入描述
输入包括三个正整数X, Y, Z(1 <= X, Y, Z <= 109), 以空格分割。
输出描述
输出一个正整数, 满足条件的三元组数量, 因为答案可能很大, 输出对于1000000007取模的答案。
示例1
输入
2 3 3
输出
9
*/

#include "pch.h"
#include <iostream>

using namespace std;

int Min(int x, int y)
{
	return x < y ? x : y;
}

int Max(int x, int y)
{
	return x > y ? x : y;
}

int Abs(int x)
{
	return x > 0 ? x : -x;
}

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

/*  第一个想法：本来想排序，但是感觉很麻烦（并不）。以x为变化点，
	分为X = 1，X = 2，……，X = |Y - Z|和X = |Y - Z| + 1，……，X = X两部分讨论
	很麻烦，不好理解，很容易出错，自己也没搞明白（太紧张了）。
	答案是错的，也许能调对，但是太麻烦，而且想到了第二种 */
long findTotal(int x, int y, int z)
{
	long total = 0;

	int minYZ = Min(y, z), maxYZ = Max(y, z), i;

	for (i = 1; i <= Abs(y - z) + 1 && i <= x; i++)
	{
		total += (minYZ - i + 1) * (2 * i - 1);
		total += (i - 1) * i;
	}

	if (i == x)
	{
		return total;
	}

	for (; i <= x; i++)
	{
		total += minYZ * (i - 1);
	}

	return total;
}

/*  第二种想法：先用swap手动模拟冒泡排序，把xyz按从小到大排好
	对于(x, y)的任意排列，第三条边的可能取值范围为：
	[|x - y| + 1, x + y - 1]。
	由于z最大，所以左边界一定能取到；而右边界受z最大值的限制。
	最后实现只需要两重循环和一行计算……	*/
long findTotal2(int x, int y, int z)
{
	// make sure x <= y <= z
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);

	long total = 0;

	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			total += Min(i + j - 1, z) - (Abs(i - j) + 1) + 1;
		}
	}

	return total;
}

int main() {

	int X, Y, Z;

	while (true)
	{
		cin >> X >> Y >> Z;

		long total = findTotal2(X, Y, Z);
		
		cout << total << endl;
	}

	return 0;
}