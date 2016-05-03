/*************************************************************************
	> File Name: exercise_7.40.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 10 Sep 2015 08:01:52 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
class Employee
{
public:

    Employee(string nam, string sec, string sex, unsigned age, unsigned No):
	name_(nam),sector_(sec),sex_(sex),age_(age),No_(No){}
    Employee(){}
    Employee(string nam):name_(nam){}
    Employee(string nam, unsigned num):name_(nam),No_(num){}
private:
    string name_;
    string sector_;
    unsigned age_=0;
    string sex_;
    unsigned No_=0;
};

int main()
{
    return 0;
}
