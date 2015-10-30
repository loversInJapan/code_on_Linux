/*************************************************************************
	> File Name: exercise_12.14.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 28 Oct 2015 07:51:04 PM PDT
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct Destination
{
    Destination(){}
    string str = "baidu";
};

struct Connection
{
    Connection(){}
    string str = "connection";
};

Connection connect(Destination* des)
{
    Connection *con = new Connection();
    //con->str += des->str;
    cout << con->str  << des->str << endl;
    return *con;
}

void disconnect(Connection &con)
{
    cout << "disconnect" << con.str << endl;
}

void end_connection(Connection *p) {disconnect(*p);}

void Func(Destination *des)
{
    Connection c = connect(des);
    shared_ptr<Connection> p(&c,
	    [](Connection *p) {disconnect(*p);});
    cout << c.str << endl;
}

int main()
{
    Destination des;
    Func(&des);

    return 0;
}
