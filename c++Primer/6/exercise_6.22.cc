/*************************************************************************
	> File Name: exercise_6.22.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 15 Aug 2015 02:18:12 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
void exchange_pointers(int** a, int** b)
{
    int* temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int a = 2, b = 4;
    int *pa = &a, *pb = &b;
    cout << pa << endl;
    cout << pb << endl;
    exchange_pointers(&pa, &pb);
    cout << pa << endl;
    cout << pb << endl;
    return 0;
}
