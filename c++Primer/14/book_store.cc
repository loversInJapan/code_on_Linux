/*************************************************************************
	> File Name: book_store.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 07 Nov 2015 07:23:40 PM CST
 ************************************************************************/

#include <iostream>
#include "sale_data.h"
using namespace std;

int main()
{
    /*
    Sales_data total;
    if(cin >> total){
	Sales_data trans;
	while(cin >> trans){
	    if(total.isbn() == trans.isbn())
		total += trans;
	    else{
		cout << total << endl;
		total = trans;
	    }
	}
	cout << total << endl;
    }else{
	cerr << "no data?" << endl;
	return -1;
    }*/
    Sales_data a;
    a = "harry potter";
    cout << a << endl;
    return 0;
}
