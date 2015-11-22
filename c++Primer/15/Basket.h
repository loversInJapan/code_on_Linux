/*************************************************************************
	> File Name: Basket.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 20 Nov 2015 08:18:45 PM CST
 ************************************************************************/

#ifndef BASKET_H_
#define BASKET_H_

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Quote.h"

class Basket{
public:
    void add_item(const std::shared_ptr<Quote>& sale)
    {items.insert(sale);}
    void add_item(const Quote& sale)
    {items.insert(std::shared_ptr<Quote>(sale.clone()));}
    double total_receipt(std::ostream&) const;
    void display(std::ostream&)const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
	    const std::shared_ptr<Quote> &rhs)
    {return lhs->isbn() < rhs->isbn();}
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif
