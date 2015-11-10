/*************************************************************************
	> File Name: strategy_partten.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 09 Nov 2015 03:49:53 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <memory>
using namespace std;
//class CashSuper
class CashSuper{
public:
    virtual ~CashSuper() {}
    virtual double acceptCash(double money) {return money;}
};

//class CashNormal
class CashNormal : public CashSuper{
public:
    double acceptCash(double money) override
    { return money;}
};

//class CashDiscount
class CashDiscount : public CashSuper{
public:
    CashDiscount() = default;
    CashDiscount(double dis) : discount_(dis) {}
    double acceptCash(double money) override 
    {
	return money * discount_;
    }
private:
    double discount_ = 0;
};

//class CashReturn
class CashReturn : public CashSuper{
public:
    CashReturn() = default;
    CashReturn(double condition, double cut) : cond_(condition), cut_(cut) {}
    double acceptCash(double money) override 
    {
	double sub = ((int)(money/cond_)) * cut_;
	return money - sub;
    }
private:
    double cond_ = 0;
    double cut_ = 0;
};

//class CashContext
class CashContext{
public:
    map<string, int> mp = {{"original", 1}, {"discount", 2}, {"return", 3}};
    CashContext(const string &s)
    {
	switch(mp[s]){
	    case 1:
		{
		    sp = shared_ptr<CashSuper>(new CashNormal());
		}
		break;
	    case 2:
		{
		double discount = 1;
		cout << "input discount: ";
		cin >> discount;
		sp = shared_ptr<CashSuper>(new CashDiscount(discount));
		}
		break;
	    case 3:
		{
		double condition = 0, cut = 0;
		cout << "input condition and cut:";
		cin >> condition >> cut;
		sp = shared_ptr<CashSuper>(new CashReturn(condition, cut));
		}
		break;
	    default:
		{
		    throw runtime_error("input error");
		}
	}
    }
    double GetResult(double money)
    {
	return sp->acceptCash(money);
    }
private:
    shared_ptr<CashSuper> sp;
};

int main()
{
    double total = 0;
    double price = 0;
    int amount = 0;
    string s;
    cout << "choose a strategy: a) original; b)discount; c)return" << endl;
    cout << "your choice? : ";
    cin >> s;
    CashContext count(s);
    cout << "price: ";
    cin >> price;
    cout << "amount: ";
    cin >> amount;
    total = price*amount;
    total = count.GetResult(total);
    cout << "total: " << total << endl;
    return 0;
}
