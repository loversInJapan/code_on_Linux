/*************************************************************************
	> File Name: exercise_9.47.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 10 Oct 2015 01:22:22 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int NOTmain()
{
    string nums = "0123456789";
    string alphabet = "aAbBcCdDeEfFgGiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    string src = "ab2c3d7R4E6";
    int pos=0;
    while((pos = src.find_first_of(nums,pos)) != string::npos)
    {
	cout << src[pos] << " ";
	++pos;
    }
    cout << endl;
    pos = 0;
    while((pos = src.find_first_of(alphabet,pos)) != string::npos)
    {
	cout << src[pos] << " ";
	++pos;
    }
    cout << endl;

    return 0;
}

int main()
{
    string nums = "0123456789";
    string alphabet = "aAbBcCdDeEfFgGiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    string src = "ab2c3d7R4E6";
    int pos=0;
    while((pos = src.find_first_not_of(alphabet,pos)) != string::npos)
    {
	cout << src[pos] << " ";
	++pos;
    }
    cout << endl;
    pos = 0;
    while((pos = src.find_first_not_of(nums,pos)) != string::npos)
    {
	cout << src[pos] << " ";
	++pos;
    }
    cout << endl;

    return 0;
}
