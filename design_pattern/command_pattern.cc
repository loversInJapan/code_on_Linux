/*************************************************************************
	> File Name: command_pattern.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 10 Nov 2015 07:17:24 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define SAFE_DELETE(p) if(p){delete p; p = nullptr;}

class Receiver{
public:
    void Action()
    {
	cout << "Action" << endl;
    }
};

class Command{
public:
    virtual void Excute()=0;
    virtual ~Command(){}
protected:
    Receiver* rp;
};

class ConcreteCommand : public Command{
public:
    ConcreteCommand(Receiver* p)// : Command(p){}
    {
	rp = p;
    }
    void Excute()
    {
	rp->Action();
    }
};

class Invoker{
public:
    Invoker(Command* p) : cmm_ptr_(p) {}
    void Invoke()
    {
	cmm_ptr_->Excute();
    }
private:
    Command* cmm_ptr_;
};

int main()
{
    Receiver* rec_ptr = new Receiver();
    Command* com_ptr = new ConcreteCommand(rec_ptr);
    Invoker* inv_ptr = new Invoker(com_ptr);
    inv_ptr->Invoke();
    SAFE_DELETE(inv_ptr);
    SAFE_DELETE(com_ptr);
    SAFE_DELETE(rec_ptr);
    return 0;
}
