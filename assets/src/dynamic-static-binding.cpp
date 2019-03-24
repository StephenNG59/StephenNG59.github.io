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
