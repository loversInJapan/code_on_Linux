/*************************************************************************
	> File Name: exercise_17.37.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 19时19分43秒
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    ifstream ifs;
    ifs.open(argv[1]);
    char str[1];
    const int LEN = 10;
    if(ifs.is_open())
        cout << "file is opened" << endl;

    while(ifs.getline(str,LEN,'6')){
        cout << ifs.gcount() << " ";
        cout << str << endl;
    }

    //ifs.getline(str,LEN,'\n');
    cout << str << endl;
    ifs.close();
    return 0;
}
