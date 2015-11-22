/*************************************************************************
	> File Name: Quote.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 20 Nov 2015 08:00:40 PM CST
 ************************************************************************/

#include "Quote.h"
#include <iostream>
using std::ostream; using std::endl; using std::cout;

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::min;

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n
	<< " total due: " << ret << endl;
    return ret;
}

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= qty_)
	return cnt * (1-discount_) * price_;
    else
	return cnt * price_;
}
