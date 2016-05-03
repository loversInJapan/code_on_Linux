/*************************************************************************
	> File Name: hash_map.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 26 Oct 2015 07:49:01 AM PDT
 ************************************************************************/

#include <iostream>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

int main()
{
    int n;
    hash_map<int, int> hm;
    cout << "n = " << n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        hm[i] = i+2;
    }
    for(hash_map<int,int>::iterator i = hm.begin(); i != hm.end(); ++i)
    {
	printf("%d",i->second);
    }
    printf("\n%d  %d\n",hm.size(),hm.bucket_count());
    return 0;
}
