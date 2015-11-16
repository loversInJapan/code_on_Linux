/*************************************************************************
	> File Name: exercise_14.38.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 12 Nov 2015 09:56:22 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SizeCmp{
public:
    SizeCmp(size_t n) : sz_(n){}
    bool operator()(const string& s)
    {
	if(s.size() == sz_)
	{
	    ++cnt_;
	    return true;
	}else
	    return false;
    }
    ostream& Count(ostream& os, int i)
    {
	os << "size of " << i << " show " << cnt_ << (cnt_ < 2 ? " time" : " times");
	return os;
    }
private:
    size_t sz_;
    size_t cnt_=0;
};

int main()
{
    vector<string> vec = {"a","the","an","apple","banana","programmin","design","computer"};
    size_t cnt = 0;
    for(int i=1; i<=10; ++i)
    {
	SizeCmp sc = for_each(vec.begin(),vec.end(),SizeCmp(i));
	sc.Count(cout, i) << '\n';
    }
    return 0;
}
