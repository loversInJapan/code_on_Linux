/*************************************************************************
	> File Name: exercise_13.34,36.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 16 Nov 2015 09:17:11 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

class Message;
//class Folder
class Folder{
public:
    void add_msg(Message* msg);
    void remove_msg(Message* msg);
    void Show() const;
private:
    set<Message*> msgs_;
};

void Folder::add_msg(Message* msg)
{
    msgs_.insert(msg);
}

void Folder::remove_msg(Message* msg)
{
    msgs_.erase(msg);
}

//class Message
class Message{
    friend class Folder;
public:
    explicit Message(const string& s = "") : contents_(s)
    {}
    Message(const Message& msg);
    Message& operator=(const Message& msg);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    string contents_;
    set<Folder*> folders_;
    void add_to_folders(const Message&);
    void remove_from_folders();
};

void Message::save(Folder& f)
{
    folders_.insert(&f);
    f.add_msg(this);
}

void Message::remove(Folder& f)
{
    folders_.erase(&f);
    f.remove_msg(this);
}

void Message::add_to_folders(const Message& msg)
{
    for(auto f : msg.folders_)
	f->add_msg(this);
}

void Message::remove_from_folders()
{
    for(auto f : folders_)
	f->remove_msg(this);
}

Message::Message(const Message& msg)
{
    contents_ = msg.contents_;
    folders_ = msg.folders_;
    add_to_folders(msg);
}

Message::~Message()
{
    remove_from_folders();
}

Message& Message::operator=(const Message& msg)
{
    remove_from_folders();
    contents_ = msg.contents_;
    folders_ = msg.folders_;
    add_to_folders(msg);
    return *this;
}

void Folder::Show() const
{
    for(auto f : msgs_)
	cout << f->contents_ << endl;
}

int main()
{
    Folder f1;
    Message m1("hello");
    m1.save(f1);
    Message m2("world!");
    m2.save(f1);
    Message m3("new");
    m3.save(f1);
    Message m4("happy");
    m4.save(f1);
    Message m5("sun");
    m5.save(f1);
    f1.Show();

    return 0;
}

