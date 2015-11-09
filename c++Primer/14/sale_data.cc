/*************************************************************************
	> File Name: sale_data.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 07 Nov 2015 06:59:23 PM CST
 ************************************************************************/

#include <iostream>
#include "sale_data.h"
using namespace std;

Sales_data::Sales_data(istream &is)
{
    is >> *this;
}

double Sales_data::avg_price() const
{
    if(units_sold_)
	return revenue_ / units_sold_;
    else
	return 0;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    book_no_ = rhs.book_no_;
    units_sold_ = rhs.units_sold_;
    revenue_ = rhs.revenue_;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

istream &operator>>(istream &is, Sales_data &item)
{
    double price;
    is >> item.book_no_ >> item.units_sold_ >> price;
    if(is)
	item.revenue_ = item.units_sold_ * price;
    else
	item = Sales_data();
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.book_no_ << " " << item.units_sold_ << " "
	<< item.revenue_ << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}
