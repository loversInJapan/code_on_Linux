/*************************************************************************
	> File Name: exercise_7.1.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 07:00:24 PM PDT
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
Sale_data& Sale_data::combine(const Sale_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
int main()
{
    Sale_data total;
    if(cin>>total.book_no && cin>>total.units_sold && cin>>total.sold_price)
    {
	Sale_data next_one;
	while(cin>>next_one.book_no && cin>>next_one.units_sold && cin>>next_one.sold_price)
	{
	   if(total.book_no == next_one.book_no)
	       total.units_sold+=next_one.units_sold;
	   else
	   {
	       cout << total.book_no << "  " << total.units_sold << "  "
		   << total.units_sold * total.sold_price << endl;
	       total.book_no = next_one.book_no;
	       total.units_sold = next_one.units_sold;
	       total.sold_price = next_one.sold_price;
	   }
	}
	cout << total.book_no << "  " << total.units_sold << "  " 
	<< total.sold_price*total.units_sold << endl;
    }
    else
    {
	cerr << "no data?" << endl;
	return -1;
    }
    return 0;
}
