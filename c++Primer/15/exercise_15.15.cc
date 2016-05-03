/*************************************************************************
	> File Name: exercise_15.15.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 29 Sep 2015 01:22:01 AM PDT
 ************************************************************************/

#include "exercise_15.3.h"

class DiscQuote:public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const string &book, double price, size_t qyt, double disc)
	:Quote(book, price, qyt),discount_(disc) {}
    double net_price() const = 0;
protected:
    double discount_ = 0;
private:
    int quote_;
};

class BulkQuote:public DiscQuote
{
public:
    BulkQuote() = default;
    BulkQuote(const string &book, double price, size_t qyt, double disc):
	DiscQuote(book, price, qyt, disc) {}
    double net_price() const override;
    void set_disc(double disc)
    {
	DiscQuote::discount_ = disc;
    }
    void set_nothing(BulkQuote &rhs)
    {
	rhs.nothing = 11;
    }
    void print_nothing()
    {
	cout << nothing << endl;
    }
    /*void set_quote(int val)
    {
	quote_ = val;
    }
    void print_quote()
    {
	cout << quote_ << endl;
    }*/
private:
    int nothing;
   // discount_ = 0.2;
};

double BulkQuote::net_price() const
{
    return price_*(1-discount_)*qty_;
}

class CoverClass:public DiscQuote
{
public:
    CoverClass() = default;
    double net_price() const
    {
	cout << "cover" << endl;
	return 1.0;
    }
};

int main()
{
    BulkQuote disc_q("happy", 22, 2, 0.15);
    //disc_q.nothing = 12;
    BulkQuote *ptr = &disc_q;
    //disc_q.set_quote(100);
    BulkQuote disc2;
    disc2.set_nothing(disc_q);
    disc_q.print_nothing();
    //cout << ptr->DiscQuote::discount_ << endl;
    //double payment = disc_q.net_price();
    //cout << payment << endl;
    CoverClass co;

    return 0;
}
