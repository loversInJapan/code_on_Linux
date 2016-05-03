/*************************************************************************
	> File Name: exercise_18.28.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 07 Nov 2015 09:58:22 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct Base{
    void bar(int val)
    {
        cout << "call bar(int) of Base, ival of Base is " <<  ival << endl;
    }
protected:
    int ival = 0;
};

struct Derived1 : virtual public Base{
    void bar(char ch)
    {
        cout << "call bar(char) of Derived1, cval of Derived1 is " << cval << endl;
    }
    void foo(char ch)
    {
        cout << "call foo(char) of Derived1, cval if Derived1 is " << cval << endl;
    }
protected:
    char cval = 0;
};

struct Derived2 : public virtual Base{
    void foo(int i)
    {
        cout << "call foo(int) of Derived2, ival of Derived2 is " << ival
        << " and the cval is " << cval << endl;
    }
protected:
    int ival = 0;
    char cval = 0;
};

class VMI : public Derived2, public Derived1{
public:
    void Call()
    {
        Base::ival = 999;
        Derived1::cval = 'Z';
        //Derived2::foo(-1);
        Base::bar('@');
    }
};

int main()
{
    VMI ins;
    //ins.Call();
    ins.Base::bar('a');
    ins.Derived1::foo('b');

    return 0;
}
