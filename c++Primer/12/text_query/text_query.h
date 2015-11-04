/*************************************************************************
	> File Name: text_query.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 01 Nov 2015 09:45:17 AM CST
 ************************************************************************/

#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_

#include <vector>
#include <map>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>
using namespace std;
using line_no = size_t;

class QueryResult
{
    friend ostream& print(ostream &os, QueryResult qr);
public:
    QueryResult(string str, shared_ptr<vector<string>> text, shared_ptr<set<line_no>> line) :
	found(str), vec_sp(text), set_sp(line) {}
private:
    string found;
    shared_ptr<vector<string>> vec_sp;
    shared_ptr<set<line_no>> set_sp;
};

class TextQuery
{
public:
    TextQuery(ifstream &);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> whole_file_sp;
    map<string, shared_ptr<set<line_no>>> str_line_mp;
};

#endif
