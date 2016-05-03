/*************************************************************************
	> File Name: Basket_main.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 20 Nov 2015 08:56:22 PM CST
 ************************************************************************/

#include <iostream>
#include "Basket.h"
using namespace std;

int main()
{
    Basket sale;
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(make_shared<Bulk_quote>("345",45,4,0.2));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("345", 45, 3, 0.2)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("345", 45, 3, 0.2)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("345", 45, 3, 0.2)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("345", 45, 3, 0.2)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("456", 55, 2, 0.25)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("456", 55, 2, 0.25)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("456", 55, 2, 0.25)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("456", 55, 2, 0.25)));
    sale.add_item(shared_ptr<Bulk_quote>(new Bulk_quote("456", 55, 2, 0.25)));

    sale.total_receipt(cout);
}
