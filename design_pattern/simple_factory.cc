/*************************************************************************
	> File Name: simple_factory.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 08 Nov 2015 09:48:58 PM CST
 ************************************************************************/

#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <memory>
using namespace std;

//*********class Operator************//
class Operator{
protected:
    double num_a_ = 0;
    double num_b_ = 0;
public:
    Operator() = default;
    Operator(double a, double b) : num_a_(a), num_b_(b) {}
    virtual ~Operator() {}
    double GetNumberA() const
    {
	return num_a_;
    }
    double GetNumberB() const
    {
	return num_b_;
    }
    void SetNumberA(double val)
    {
	num_a_ = val;
    }
    void SetNumberB(double val)
    {
	num_b_ = val;
    }
    virtual double GetResult() const
    {
	double result = 0;
	return result;
    }
};
//*********class Operator************//
//*********class OperatorAdd************//
class OperatorAdd : public Operator{
public:
    OperatorAdd() = default;
    ~OperatorAdd() {}
    double GetResult() const override
    {
	double result = 0;
	result = num_a_ + num_b_;
	return result;
    }
};
//*********class OperatorAdd************//
//*********class OperatorSub************//
class OperatorSub : public Operator{
public:
    OperatorSub() = default;
    ~OperatorSub() {}
    double GetResult() const override
    {
	return num_a_ - num_b_;
    }
};
//*********class OperatorSub************//
//*********class OperatorMul************//
class OperatorMul : public Operator{
public:
    OperatorMul() = default;
    ~OperatorMul() {}
    double GetResult() const override
    {
	return num_a_ * num_b_;
    }
};
//*********class OperatorMul************//
//*********class OperatorDiv************//
class OperatorDiv : public Operator{
public:
    OperatorDiv() = default;
    ~OperatorDiv() {}
    double GetResult() const override
    {
	double result = 0;
	if(num_b_ == 0)
	    throw runtime_error("0 being a divisor is not allowed");
	result = num_a_ / num_b_;
	return result;
    }
};
//*********class OperatorDiv************//
//********class OperatorFactory********//
class OperatorFactory{
public:
    shared_ptr<Operator> CreateOperator(const string& s);
    ~OperatorFactory()
    {
	//delete oper;
    }
private:
    //Operator* oper = nullptr;
    shared_ptr<Operator> oper;
};

shared_ptr<Operator> OperatorFactory::CreateOperator(const string& s)
{
    map<string,int> mp = {{"+",1},{"-",1},{"*",1},{"/",1}};
    switch(mp[s]){
	case 1:
	    oper = shared_ptr<Operator>(new OperatorAdd());
	    break;
	case 2:
	    oper = shared_ptr<Operator>(new OperatorSub());
	    break;
	case 3:
	    oper = shared_ptr<Operator>(new OperatorMul());
	    break;
	case 4:
	    oper = shared_ptr<Operator>(new OperatorDiv());
	    break;
	default:
	    ;
    }
    return oper;
}
//********class OperatorFactory********//
int main()
{
    OperatorFactory factory;
    auto op_ptr = factory.CreateOperator("+");
    op_ptr->SetNumberA(3);
    op_ptr->SetNumberB(6);
    cout << op_ptr->GetResult() << endl;
    return 0;
}
