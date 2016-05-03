/*************************************************************************
	> File Name: exercise_8.13.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 16 Sep 2015 11:03:06 PM PDT
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfor
{
    string name_;
    vector<string> phones_;
};

bool valid_phone_num(const string& phone_num)
{
    for(const auto &ch : phone_num)
	if(!(ch <= 57 && ch >= 48))
	    return false;
    return true;
}

int main()
{
    vector<PersonInfor> infors;
    string line, word;
    ifstream ifio("raw_infor.txt");
    while(getline(ifio, line))
    {
	istringstream isio(line);
	PersonInfor tmp_infor;
	isio >> tmp_infor.name_;
	while(isio >> word)
	    tmp_infor.phones_.push_back(word);
	infors.push_back(tmp_infor);
    }

    for(const auto &output : infors)
    {
	ostringstream formatted, bad_nums;
	for(const auto &num : output.phones_)
	{
	    if(!valid_phone_num(num))
		bad_nums << num << " ";
	    else
		formatted << num << " ";
	}
	if(bad_nums.str().empty())
	    cout << "good input: " << '\n' << output.name_ << " "
		<< formatted.str() << endl;
	else
	    cerr << "wrong input: " << '\n' << output.name_ << " "
		<< "invalid phones: "<< bad_nums.str() << endl;
    }

    return 0;
}
