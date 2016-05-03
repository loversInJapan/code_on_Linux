/*************************************************************************
	> File Name: find_one_single_number.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 05 Oct 2015 10:51:10 PM PDT
 ************************************************************************/

#include <iostream>
#define ON(n,i) (n & (1<<i))
using namespace std;

void FindSingle(int *arr, int size)
{
    int tmp1, tmp2, cnt1, cnt2;
    for(int i = 0; i < 31; ++i)
    {
	tmp1 = tmp2 = cnt1 = cnt2 = 0;
	for(int j = 0; j < size; ++j)
	{
	    if(ON(arr[j],i))
	    {
		tmp1 ^= arr[j];
		++cnt1;
	    }
	    else
	    {
		tmp2 ^= arr[j];
		++cnt2;
	    }
	}
	if(cnt1 % 2)
	{
	    if(0 == tmp2)
		continue;
	    else
	    {
		cout << tmp1 << endl;
		break;
	    }
	}
	else
	{
	    if(0 == tmp1)
		continue;
	    else
	    {
		cout << tmp2 << endl;
		break;
	    }
	}
    }
}

int main()
{
    int arr[] = {1,2,2,1,3,4,5,4,5,3,13,18,90,90,81,78,81};
    FindSingle(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
