/*************************************************************************
	> File Name: sales_data.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 19 Jul 2015 12:06:10 AM PDT
 ************************************************************************/

#ifndef _SALES_DATA_H
#define _SALES_DATA_H
#include <string>

struct SalesData
{
  std::string book_No;
  double revenue=0.0;
  unsigned units_sold=0;
};

void Input(SalesData &);

#endif
