/*************************************************************************
	> File Name: sales_data.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 19 Jul 2015 12:13:02 AM PDT
 ************************************************************************/

#include <iostream>
#include "sales_data.h"
using namespace std;

void Input(SalesData &rhs)
{
  double price=0.0;
  cin >> rhs.book_No >> rhs.units_sold >> price;
  rhs.revenue = rhs.units_sold * price;
}

int main(void)
{
  SalesData data1, data2;
  Input(data1);
  Input(data2);
  if(data1.book_No == data2.book_No)
  {
    unsigned total_sold = data1.units_sold + data2.units_sold;
    double total_revenue = data1.revenue + data2.revenue;
    cout << data1.book_No << " " << total_sold << " " << total_revenue << " ";
    if(total_sold == 0)
      cout << "(no sales)" << endl;
    else
      cout << total_revenue / total_sold << endl;
    return 0;
  }else
  {
    cout << "Data must refer to the same ISBN" << endl;
    return -1;
  }
}
