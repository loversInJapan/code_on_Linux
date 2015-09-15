/*************************************************************************
	> File Name: exercise_7.53.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 11 Sep 2015 11:58:10 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
class Debug
{
public:
    constexpr Debug(bool b=true):hw_(b),io_(b),other_(b){}
    constexpr Debug(bool h, bool i, bool o):hw_(h),io_(i),other_(o){}
    constexpr bool any() const {return hw_ || io_ || other_;}
    void set_hw(bool h){hw_ = h;}
    void set_io(bool i){io_ = i;}
    void set_other(bool o){other_ = o;}
private:
    bool hw_;
    bool io_;
    bool other_;
};

int main()
{
    //constexpr 
    Debug io_sub(false, true, false);
    if(io_sub.any())
	cerr << "print appropriate error message" << endl;
    //constexpr
    Debug prod(true);
    if(prod.any())
	cerr << "print an error message" << endl;

    return 0;
}
