/*************************************************************************
	> File Name: Basket.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 20 Nov 2015 08:42:58 PM CST
 ************************************************************************/

#include <iostream>
#include "Quote.h"
#include "Basket.h"
#include <set>
#include <string>
using namespace std;

void Basket::display(ostream& os) const
{
    os << "Basket size: " << items.size() << endl;
    for(auto next_item = items.cbegin(); next_item != items.cend();
	    next_item = items.upper_bound(*next_item))
    {
	os << (*next_item)->isbn() << " occurs "
	   << items.count(*next_item) << " times"
	   << " for a price of"
	   << (*next_item)->net_price(items.count(*next_item))
	   << endl;
    }
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
	sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}
