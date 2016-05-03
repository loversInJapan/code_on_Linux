/*************************************************************************
	> File Name: tell_seek.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 21时54分34秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
    fstream fs(argv[1], fstream::ate | fstream::out | fstream::in);
    if(!fs){
        cout << "open file failed" << endl;
        return EXIT_FAILURE;
    }

    auto end_mark = fs.tellg();
    string line;
    fs.seekg(0, fstream::beg);
    auto read_mark = fs.tellg();
    unsigned cnt = 0;
    while(fs && read_mark != end_mark && getline(fs,line)){
        cnt += line.size() + 1;
        read_mark = fs.tellg();
        fs.seekp(0, fstream::end);
        fs << cnt;
        if(read_mark != end_mark)
            fs << " ";
        //fs.seekg(read_mark);
        //fs.seekg(cnt, fstream::beg);
        fs.seekg(read_mark);
    }
    fs.seekp(0,fstream::end);
    fs << "\n";
    return 0;
}
