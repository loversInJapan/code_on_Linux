/*************************************************************************
	> File Name: regex.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月10日 星期四 14时33分59秒
 ************************************************************************/

#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r;
    try{
        r.assign(pattern);
    }catch(regex_error e){
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    smatch result;
    string test_str = "receipt freind theif receive";
    if(regex_search(test_str, result, r))
        cout << result.str() << endl;

    return 0;
}
