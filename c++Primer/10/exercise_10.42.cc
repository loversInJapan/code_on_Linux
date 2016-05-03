/*************************************************************************
	> File Name: exercise_10.42.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 23 Oct 2015 11:59:49 PM PDT
 ************************************************************************/

#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
    list<int> lst = {1,1,2,2,3,3,4,4,5,5,5,5,5,6};
    lst.unique();//(lst.begin(),lst.end());
    for(auto out : lst)
	cout << out << " ";
    cout << endl;
    ifstream input("numbers.txt");
    ofstream output1("odd.txt");
    ofstream output2("even.txt");
    istream_iterator<int> if_iter(input), eof;
    ostream_iterator<int> odd_iter(output1, " "), even_iter(output2);
    while(if_iter != eof)
    {
	int val = *if_iter++;
	if(val % 2)
            *even_iter++ = val;
	else
	{
	    *odd_iter++ = val;
	    output2 << endl;
	}
    }
    return 0;
}
