/*************************************************************************
	> File Name: sale_data.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 07 Nov 2015 06:38:04 PM CST
 ************************************************************************/

#ifndef SALE_DATA_H_
#define SALE_DATA_H_

#include <string>
#include <iostream>

class Sales_data{
    friend std::ostream &operator<<(std::ostream&, const Sales_data&);
    friend std::istream &operator>>(std::istream&, Sales_data &);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : book_no_(s){}
    Sales_data(const std::string &s, unsigned n, double p) :
	book_no_(s), units_sold_(n), revenue_(p*n) {}
    Sales_data(std::istream&);
    std::string isbn() const {return book_no_;}
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const Sales_data&);
private:
    double avg_price() const;
    std::string book_no_;
    unsigned units_sold_ = 0;
    double revenue_ = 0;
};

inline
bool CompareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() && 
	lhs.units_sold_ == rhs.units_sold_ && 
	lhs.revenue_ == lhs.revenue_;
}

inline 
bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream&, const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data &);
Sales_data operator+(const Sales_data&, const Sales_data&);

Sales_data add(const Sales_data&, const Sales_data&);
#endif
