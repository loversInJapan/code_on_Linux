/*************************************************************************
	> File Name: exercise_16.1.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 26 Nov 2015 04:19:37 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SalesData{
    friend bool operator<(const SalesData&, const SalesData&);
private:
    string bookNo_;
    double price_ = 0.0;
    size_t sz_ = 0;
public:
    SalesData() = default;
    SalesData(const string& s, double p, size_t n) : bookNo_(s), price_(p), sz_(n){}
    SalesData(const string& s) : bookNo_(s){}
};

inline
bool operator<(const SalesData& lhs, const SalesData& rhs)
{
    return lhs.bookNo_ < rhs.bookNo_;
}

template <typename T>
int compare(const T& v1, const T& v2)
{
    if(v1 < v2)
	return -1;
    else
	return 1;
}

int main()
{
    int i1 = 2, i2 = 4;
    cout << compare(i1,i2) << endl;
    string s1 = {"abc"}, s2 = {"abcd"};
    cout << compare(s1, s2) << endl;
    vector<int> v1 = {2,3,4}, v2 = {1,2,3,4,5};
    cout << compare(v1,v2) << endl;
    SalesData sd1, sd2;
    cout << compare(sd1,sd2) << endl;

    return 0;
}
