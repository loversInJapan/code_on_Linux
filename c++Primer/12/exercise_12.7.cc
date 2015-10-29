/*************************************************************************
	> File Name: exercise_12.7.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 28 Oct 2015 04:46:28 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;
shared_ptr<vector<int>> GetVector()
{
    return shared_ptr<vector<int>> (new vector<int>);
}

void InputVector(shared_ptr<vector<int>> vec_ptr)
{
    for(int i = 0; i < 3; ++i){
	int val;
	cin >> val;
	vec_ptr->push_back(val);
    }
}

void PrintVector(shared_ptr<vector<int>> vec_ptr)
{
    for(auto i : *vec_ptr)
	cout << i << " ";
}

int main()
{
    //int val;
    //printf("%d\n",val);
    auto ptr = GetVector();
    InputVector(ptr);
    PrintVector(ptr);
    cout << endl;
    auto sp = GetVector();
    ptr = sp;
    if(ptr.unique())
	cout << "true" << endl;
    cout << sp.use_count() << endl;
    //delete ptr;

    return 0;
}
