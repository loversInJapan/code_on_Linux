/*************************************************************************
	> File Name: ecercise_17.39.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月15日 星期二 17时07分42秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::fstream;

int main(int argc, char** argv)
{
    fstream in_out(argv[1], fstream::ate | fstream::in | fstream::out);
    if(!in_out){
        cerr << "unable to open file!" << endl;
        return EXIT_FAILURE;
    }
    auto end_mark = in_out.tellg();
    in_out.seekg(0,fstream::beg);
    size_t cnt = 0;
    string line;
    while(in_out && in_out.tellg() != end_mark && getline(in_out, line)){
        cnt += line.size() + 1;
        auto mark = in_out.tellg();
        in_out.seekp(0, fstream::end);
        in_out << cnt;
        if(mark != end_mark)
            in_out << " ";
        in_out.seekg(mark);
    }
    in_out.seekp(0,fstream::end);
    in_out << "\n";
    return 0;
}

