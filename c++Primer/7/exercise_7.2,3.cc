/*************************************************************************
	> File Name: exercise_7.2,3.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 11:33:37 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include "Sales_item.h"
using namespace std;
class Sale_data
{
public:
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
    if(cin >> total.book_no >> total.units_sold >> total.revenue)
    {
	Sale_data next;
	while(cin >> next.book_no >> next.units_sold >> next.revenue)
	{
	    if(total.isbn() == next.isbn())
	    	total.combine(next);
	    else
	    {
		cout << total.book_no << " " << total.units_sold << " " << total.revenue << endl;
		total.book_no = next.book_no;
		total.units_sold = next.units_sold;
		total.revenue = next.revenue;
	    }
	}
	cout << total.book_no << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
	cerr << "no data?" << endl;
	return -1;
    }
    return 0;
}
