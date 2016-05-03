/*************************************************************************
	> File Name: exercise_14.44.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 12 Nov 2015 12:26:29 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

double Add(double a, double b)
{
    return a+b;
}

double Sub(double a, double b)
{
    return a-b;
}

auto Div = [] (double a, double b) {return a/b;};

auto Mul = [] (double a, double b) {return a*b;};

struct Mod{
    double operator()(int a, int b) const
    {
	return a%b;
    }
};

int main()
{
    map<string, function<double(double, double)>> binops;
    binops.insert({"+",Add});
    binops.insert({"-",Sub});
    binops.insert({"*",Mul});
    binops.insert({"/",Div});
    binops.insert({"%",Mod()});
    cout << binops["+"](10,3) << endl;
    cout << binops["-"](10,3) << endl;
    cout << binops["*"](10,3) << endl;
    cout << binops["/"](10,3) << endl;
    cout << binops["%"](10,3) << endl;

    return 0;
}
