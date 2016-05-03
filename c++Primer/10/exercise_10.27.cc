/*************************************************************************
	> File Name: exercise_10.27.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 23 Oct 2015 07:59:04 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vec = {1,1,2,2,3,4,5,5,6};
    list<int> lst;
    auto back_in = back_inserter(lst);
    unique_copy(vec.cbegin(),vec.cend(),back_in);
    ostream_iterator<int> out_it(cout," ");
    //for_each(lst.begin(),lst.end(),out_it);
    for(auto print : lst)
	*out_it++ = print;
	//cout << print << " ";
    cout << endl;
    copy(lst.cbegin(),lst.cend(),out_it);
    cout << endl;
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in,eof,0) << endl;
    return 0;
}
