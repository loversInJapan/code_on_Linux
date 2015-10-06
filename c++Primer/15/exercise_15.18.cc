/*************************************************************************
	> File Name: exercise_15.18.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 30 Sep 2015 01:42:11 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

class Base
{
public:
    void pun_men() {}
protected:
    int pro_mem;
private:
    char pri_mem;
};

struct PubDer : public Base
{
    int f() {return pro_mem;}
    void memfcn(Base &b) {b = *this;}
};

struct PriDer : private Base
{
    int f1() const {return pro_mem;}
    void memfcn(Base &b) {b = *this;}
};

struct ProDer : protected Base
{
    int f2() {return pro_mem;}
    void memfcn(Base &b) {b = *this;}
};

struct DFPub : public PubDer
{
    int use_base() {return pro_mem;}
    void memfcn(Base &b) {b = *this;}
};

/*struct DFPri : private PriDer
{
    int use_base() { return pro_mem;}
};*/

int main()
{
    PubDer d1;
    PriDer d2;
    ProDer d3;
    DFPub dd1;
    //DFPri dd2;
    Base *p = &dd1;

    return 0;
}
