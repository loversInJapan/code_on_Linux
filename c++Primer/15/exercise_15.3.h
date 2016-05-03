/*************************************************************************
	> File Name: exercise_15.3.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 24 Sep 2015 02:12:47 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price, size_t cnt):bookNo_(book),
    price_(sales_price),qty_(cnt){}
    string isbn() const {return bookNo_;}
    virtual double net_price() const { return qty_ * price_;}
    virtual ~Quote() = default;
private:
    string bookNo_;
protected:
    double price_;
    size_t qty_;
};

ostream &print_total(Quote &q)
{
    cout << q.isbn()  << "  " << q.net_price();
    return cout;
}
