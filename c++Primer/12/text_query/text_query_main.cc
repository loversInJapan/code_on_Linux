/*************************************************************************
	> File Name: text_query_main.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 01 Nov 2015 11:48:51 AM CST
 ************************************************************************/

#include "text_query.h"

void RunQuery(ifstream &ifs)
{
    TextQuery tq(ifs);
    while(true)
    {
	cout << "please input a word to look for: ";
        string s;
	if(!(cin >> s))
	    break;
	print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream ifs("article.txt");
    RunQuery(ifs);

    return 0;
}
