/*************************************************************************
	> File Name: text_query.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 01 Nov 2015 10:35:56 AM CST
 ************************************************************************/

#include "text_query.h"

TextQuery::TextQuery(ifstream &ifs): 
    whole_file_sp(new vector<string>)
{
    //whole_file_sp = make_shared<vector<string>>;
    string text;
    line_no line = 1;
    while(getline(ifs, text)){
	whole_file_sp->push_back(text);
	istringstream iss(text);
	string word;
	while(iss >> word){
	    auto &set_sp = str_line_mp[word];
	    if(set_sp == nullptr)
		set_sp.reset(new set<line_no>);
	    set_sp->insert(line);
	}
	++line;
    }
}

QueryResult TextQuery::query(const string &target) const
{
    shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = str_line_mp.find(target);
    if(loc != str_line_mp.end())
	return QueryResult(target, whole_file_sp, loc->second);
    else	
        return QueryResult(target, whole_file_sp, nodata);
    //return res;
}

string make_plural(size_t val, const string src)
{
    return val > 1 ? string(src+"s") : src;
}

ostream& print(ostream &os, QueryResult qr)
{
    if(qr.set_sp->size() == 0)
	os << qr.found << " doesn't exit";
    else{
        os << "'" << qr.found  << "'" << " occurs " << qr.set_sp->size() 
	    << make_plural(qr.set_sp->size(), " time") << endl;
	for(auto num : *qr.set_sp)
	    os << "    " << "(line " << num << ") " <<
	    *(qr.vec_sp->begin() + num - 1) << endl;
    }
    return os;
}
