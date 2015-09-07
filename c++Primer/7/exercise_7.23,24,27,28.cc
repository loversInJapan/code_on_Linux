/*************************************************************************
	> File Name: exercise_7.23,24.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 04 Sep 2015 05:13:10 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
typedef unsigned pos;

class Screen
{
private:
    pos cur_pos_ = 0;
    pos width_ = 0;
    pos height_ = 0;
    string content_;
public:
    Screen()=default;
    Screen(pos width, pos height):width_(width),height_(height)
    {
	content_ = {4,' '};
    }
    Screen(pos width, pos height, char c):width_(width),height_(height),content_(width_*height_,c){}
    Screen &MoveTo(pos wd, pos ht);
    Screen &MoveTo(pos wd, pos ht) const;
    char GetChar(pos wd, pos ht)const {return content_[wd*width_ + ht];}
    Screen &SetChar(char c);
    Screen &SetChar(pos wd, pos ht, char c);
    Screen& Display(ostream &os){DoDisplay(os); return *this;}
    const Screen& Display(ostream &os) const {DoDisplay(os); return *this;}
private:
    void DoDisplay(ostream &os) const {os << content_;}
};

inline
Screen &Screen::MoveTo(pos wd, pos ht)
{
    cur_pos_ = wd*width_ + ht;
    return *this;
}

inline
Screen &Screen::SetChar(char c)
{
    content_[cur_pos_] = c;
    return *this;
}

inline
Screen &Screen::SetChar(pos wd, pos ht, char c)
{
    content_[wd*width_ + ht] = c;
    return *this;
}

int main()
{
    pos width = 5, height = 5;
    Screen my_screen(width,height,'$');
    my_screen.SetChar(4,0,'#');
    my_screen.Display(cout);
    cout << endl;

    Screen my_screen_sec(5,5,'X');
    my_screen_sec.MoveTo(4,0).SetChar('#').Display(cout);
    cout << endl;
    my_screen_sec.Display(cout);
    cout << endl;

    const Screen blank(4,3,'@');
    blank.Display(cout);
    cout << endl;

    return 0;
}
