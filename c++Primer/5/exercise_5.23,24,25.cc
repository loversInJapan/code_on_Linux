/*************************************************************************
	> File Name: exercise_5.23,24,25.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 08 Aug 2015 11:45:22 PM PDT
 ************************************************************************/

#include <iostream>
#include <stdexcept>
using namespace std;
int main(void)
{
    int did;
    int dir;
    cin >> did;
    /*try
    {
	cin >> dir;
    }catch(int err)
    {
	;
    }*/
    cin >> dir;
    if(dir == 0)
	throw runtime_error("divisor can't be 0");
    double res = did/dir;
    cout << res << endl;
    return 0;
}
