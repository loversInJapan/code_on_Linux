/*************************************************************************
	> File Name: exercise_7.21.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 04 Sep 2015 12:41:30 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include "Sales_item.h"
using namespace std;
class Sale_data
{
    friend istream &read(istream &, Sale_data &);
    friend ostream &print(ostream &, Sale_data &);
    friend Sale_data &combine(const Sale_data &);
private:
    string book_no;
    unsigned int units_sold = 0;
    double sold_price = 0.0;
    double revenue = 0.0;
public:
    Sale_data& combine(const Sale_data &rhs);
    string isbn() const {return book_no;}
};

istream& read(istream &is, Sale_data &item)
{
    double price;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os, Sale_data &item)
{
    os << item.book_no << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sale_data& Sale_data::combine(const Sale_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sale_data total;
    if(read(cin,total))
    {
	Sale_data next;
	while(read(cin, next))
	{
	    if(total.isbn() == next.isbn())
	    	total.combine(next);
	    else
	    {
		print(cout, total);
		total = next;
	    }
	}
	print(cout, total);
    }
    else
    {
	cerr << "no data?" << endl;
	return -1;
    }
    return 0;
}
