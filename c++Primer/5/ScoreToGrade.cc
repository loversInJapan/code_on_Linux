/*************************************************************************
	> File Name: ScoreToGrade.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 08 Aug 2015 05:54:45 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    const vector<string> grade{"F","D","C","B","A","A++"};
    int my_score;
    cin >> my_score;
    string my_grade;
    if(my_score < 60)
	my_grade = grade[0];
    else
    {
	my_grade = grade[(my_score-50)/10];
	if(my_score%10 > 7)
	    my_grade+="+";
	else if(my_score%10 < 3)
	    my_grade+="-";
    }
    cout << "your grade is " << my_grade << endl;

    return 0;
}
