#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string input("hello world 111 222");
	string output;
	istringstream iss(input);
	while(iss >> output){
		cout << output << endl;
	}
	return 0;
}
