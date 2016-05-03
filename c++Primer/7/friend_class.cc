/*************************************************************************
	> File Name: friend_class.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 06 Sep 2015 05:15:44 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned pos;

class Screen
{
    friend class Windom_msg;
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

class Windom_msg
{
private:
    vector<Screen> screens{Screen(3,3,'#'),Screen(3,3,'$')};
public:
    using screen_index = vector<Screen>::size_type;
    void ClearWindow(screen_index win_num)
    {
	Screen &s = screens[win_num];
	s.content_ = string(s.width_*s.height_ , ' ');
    }
    void ShowWindows()
    {
	for(auto temp : screens)
	{
	    temp.Display(cout);
	    cout << endl;
	}
    }
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
    Windom_msg my_windows;
    my_windows.ShowWindows();
    my_windows.ClearWindow(0);
    my_windows.ShowWindows();

    return 0;

}
