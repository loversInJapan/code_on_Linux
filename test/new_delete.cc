/*************************************************************************
	> File Name: new_delete.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 16 Oct 2015 10:33:35 PM PDT
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void * operator new(size_t un_size)
{
    printf("operator new standard 1 called\n");
    return malloc(un_size);
}

void * operator new(size_t un_size, int line, const char * ptr_func)
{
    printf("operator new standard 2 called, line: %d, func: %s\n", line, ptr_func);
    return malloc(un_size);
}

void * operator new[](size_t un_size)
{
    printf("operator new[] called\n");
    return malloc(un_size);
}

void operator delete(void *ptr_mem, size_t un_size)
{
    printf("delete standard: %u\n", un_size);
    free(ptr_mem);
}

void operator delete[](void * ptr_mem, size_t un_size)
{
    printf("delete[] standard: %u\n", un_size);
    free(ptr_mem);
}

class A
{
public:
    A(int a=0) : a_(a)
    {
        printf("constructor of class A called\n");
    }
    virtual ~A()
    {
	printf("~A()\n");
    }
    static void operator delete(void *ptr_mem, size_t un_size)
    {
	printf("delete in class A: %u\n", un_size);
	free(ptr_mem);
    }
    void operator delete[](void *ptr_mem, size_t un_size)
    {
	printf("delete[] in class A: %u\n", un_size);
	free(ptr_mem);
    }
private:
    int a_;
};

class B : public A
{
public:
    B()
    {
	printf("constructor of class B called\n");
    }
    ~B()
    {
	printf("~B()\n");
    }
    static void * operator new(size_t un_size, int line, const char* ptr_func)
    {
	printf("operator new in class B called, line: %d, file_B: %s, size: %u\n",line,ptr_func, un_size);
	return malloc(un_size);
    }
    int b;
    int bb;
};

int main()
{
    printf("size of A: %u\n", sizeof(A));
    printf("size of B: %u\n", sizeof(B));
    A *pa = new A(10);
    printf("$$$$\n");

    A *pb = new (__LINE__, __func__) B;
    printf("&&&&\n");

    A *sz_a = new A[10];
    printf("####\n");

    delete pa;
    printf("$$$$\n");

    delete pb;
    printf("&&&&\n");

    delete []sz_a;
    printf("####\n");

    char *pc = NULL;
    delete pc;

    return 0;
}
