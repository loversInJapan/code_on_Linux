/*************************************************************************
	> File Name: exercise_7.4,5.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 11:51:44 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name_ = "";
    string address_ = "";
public:
    Person() = default;
    Person(const string &name_str, const string &add_str):name_(name_str),address_(add_str){}
    Person& NameAHuman();
    Person& WriteDownAnAddress();
    string ShowMeTheName()const{return name_;}
    string ShowMeTheAddress()const{return address_;}
};

Person& Person::NameAHuman()
{getline(cin,name_);return *this;}

Person& Person::WriteDownAnAddress()
{getline(cin,address_);return *this;}

int main()
{
    Person Leno("Andrew Adams", "Hawaii, USA");
    //Leno.NameAHuman();
    //Leno.WriteDownAnAddress();
    cout << Leno.ShowMeTheName() << '\n' << Leno.ShowMeTheAddress() << endl;

    return 0;
}
