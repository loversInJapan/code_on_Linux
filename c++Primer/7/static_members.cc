/*************************************************************************
	> File Name: static_members.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 12 Sep 2015 12:57:02 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
class Account
{
public:
    static double rate(){return intereste_rate_;}
    static void rate(double r){intereste_rate_ = r;}
    static int get_num(){return num_;}
private:
    static double InitRate(){ double r; cin >> r; return r;}
    static double intereste_rate_;
    static constexpr int num_ = 20;
};

//double Account::intereste_rate_ = 0.23;
double Account::intereste_rate_ = Account::InitRate();
constexpr int Account::num_ ;

int main()
{
    double cur_rate = Account::rate();
    cout << cur_rate << endl;
    Account::get_num();

    return 0;
}
