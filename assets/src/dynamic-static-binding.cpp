// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

class A
{
public:
	virtual void about() { std::cout << " -A- " << std::endl; }

	void about1() { std::cout << " -A1- " << std::endl; }
};

class B : public A
{
public:
	void about() { std::cout << " -B- " << std::endl; }

	void about2() { std::cout << " -B2- " << std::endl; }
};

class C : public A
{
//public:
//	void about() { std::cout << " -C- " << std::endl; }
};


int main()
{
	A *pa = new A();
	A *pb = new B();		// pb's static binding: A, dynamic binding: B.
	C *pc = new C();

	pa = pb;				// pa's dynamic type becomes pb's dynamic type.

	pa->about();			// -B- : 
	pa->about1();			// -A1-
	pb->about1();			// -A1-
	/*pb->about2();*/		// fails compilation: pb's static type doesn't have about2().
	pb->about();			// -B- : virtual function is dynamic binding, related to pb's dynamic type.
	pc->about();			// -A- : can't find about() in C, so refer to its base class A.

	std::cin.get();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
