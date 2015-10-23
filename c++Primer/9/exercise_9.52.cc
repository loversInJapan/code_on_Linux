/*************************************************************************
	> File Name: exercise_9.52.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 20 Oct 2015 06:36:34 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;

//typedef 
union type
{
    double num;
    char ope;
};

struct stack_elem
{
    bool tag_of_num;
    type val;
    stack_elem()
    {
	tag_of_num = true;
	val.num = 0;
    }
    stack_elem(const double &num)
    {
	tag_of_num = true;
	val.num = num;
    }
    stack_elem(const char &ch)
    {
	tag_of_num = false;
	val.ope = ch;
    }
    /*stack_elem(const stack_elem &rhs)
    {
	tag_of_num = rhs.tag_of_num;
	if(tag_of_num)
	    val.num = rhs.val.num;
	else
	    val.ope = rhs.val.ope;
    }*/
};

//int Compute(const string &str)
//{
//    if(str == "")
//	return INT_MIN;
//    string src = str+'#';
//    stack<char> operate;
//    stack<char> num;
//    string numbers = "0123456789";
//    string operators = "()+-*/";
//}

double
calculate(const string &str)
{
    stack<stack_elem> stack_1, stack_2;
    string operators = "()+-*/";
    size_t index=0;
    while(str[index] != '#')
    {
        if(operators.find(str[index]) != string::npos)
	{
	    if(str[index] == '(')
		stack_1.push(stack_elem('('));
	    else if(str[index] == ')')
	    {
		while(stack_1.top().val.ope != '(')
		{
		    stack_2.push(stack_1.top());
		    stack_1.pop();
		}
		stack_1.pop();
	    }
	    else if(str[index] == '+' || str[index] == '-')
	    {
		while(!stack_1.empty() && stack_1.top().val.ope != '(')
		{
		    stack_2.push(stack_1.top());
		    stack_1.pop();
		}
		stack_1.push(stack_elem(str[index]));
	    }
	    else if(str[index] == '*' || str[index] == '/')
	    {
		while(!stack_1.empty() && (stack_1.top().val.ope == '*'|| 
			    stack_1.top().val.ope == '/'))
		{
		    stack_2.push(stack_1.top());
		    stack_1.pop();
		}
		stack_1.push(stack_elem(str[index]));
	    }
	    ++index;
	}
	else
	{
	    double num = stod(str.substr(index));
	    stack_2.push(stack_elem(num));
	    index = str.find_first_of(operators,index);
	    //cout << index << endl;
	    if(index == string::npos)
		break;
	}
    }
    while(!stack_1.empty())
    {
	stack_2.push(stack_elem(stack_1.top()));
	stack_1.pop();
    }
    while(!stack_2.empty())
    {
	stack_1.push(stack_2.top());
	stack_2.pop();
    }
    while(!stack_1.empty())
    {
	auto cur = stack_1.top();
	//if(cur.tag_of_num)
	  //  cout << cur.val.num << " ";
	//else
	  //  cout << cur.val.ope << " ";
	if(cur.tag_of_num)
	{
	    stack_2.push(cur);
	    cout << cur.val.num << " ";
	}
	else
	{
	    cout << cur.val.ope << " ";
	    char ch = cur.val.ope;
	    auto v1 = stack_2.top().val.num;
	    stack_2.pop();
	    auto v2 = stack_2.top().val.num;
	    stack_2.pop();
	    switch(ch)
	    {
	    case '+':
		v2 += v1;
		break;
	    case '-':
		v2 -= v1;
		break;
	    case '*':
		v2 *= v1;
		break;
	    case '/':
		v2 /= v1;
		break;
	    }
	    stack_2.push(stack_elem(v2));
	}
	stack_1.pop();
    }
    cout << endl;
    return stack_2.top().val.num;
}

int main()
{
    //cout << endl;
    cout << calculate("30+4*2-(15.6/3)#") << endl;
    return 0;
}
