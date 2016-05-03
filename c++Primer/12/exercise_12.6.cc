/*************************************************************************
	> File Name: exercise_12.6.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 28 Oct 2015 02:29:47 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> *GetVector()
{
    return new vector<int>;
}

void InputVector(vector<int> *vec_ptr)
{
    for(int i = 0; i < 3; ++i){
	int val;
	cin >> val;
	vec_ptr->push_back(val);
    }
}

void PrintVector(vector<int> *vec_ptr)
{
    for(auto i : *vec_ptr)
	cout << i << " ";
}

int main()
{
    int val;
    printf("%d\n",val);
    auto *ptr = GetVector();
    InputVector(ptr);
    PrintVector(ptr);
    cout << endl;
    delete ptr;

    return 0;
}
