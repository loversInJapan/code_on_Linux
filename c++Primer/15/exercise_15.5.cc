/*************************************************************************
	> File Name: exercise_15.5.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 24 Sep 2015 04:00:11 AM PDT
 ************************************************************************/

#include "exercise_15.3.h"

class Bulk_quote:public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string book, double p, size_t qty, double disc):Quote(book,p,qty),min_qty_(qty+1),discount_(disc){}
    double net_price()const override;
    //virtual ostream &print_total() const override;
private:
    double discount_;
    size_t min_qty_;
};

double Bulk_quote::net_price()const
{
    if(qty_ > min_qty_)
	return qty_ * (1-discount_) * price_;
    else
	return qty_ * price_;
}

/*ostream & Bulk_quote::print_total() const
{
    cout << isbn() <<  " " << min_qty_ << " " << discount_ << " " << price_;
    return cout;
}*/

int main()
{
    Quote init("abc-9001", 23.5, 5);
    print_total(init) << endl;
    Bulk_quote bq("aaa-10001", 35.5, 5, 0.2);
    print_total(bq) << endl;
    return 0;
}
