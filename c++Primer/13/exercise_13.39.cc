/*************************************************************************
	> File Name: exercise_13.39.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 16 Nov 2015 03:11:35 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <algorithm>
//#include <>
using namespace std;

class StrVec{
public:
    StrVec():elements_(nullptr),first_free_(nullptr),cap_(nullptr) {}
    StrVec(const StrVec& sv);
    StrVec(StrVec &&rhs) noexcept;
    StrVec& operator=(const StrVec& sv);
    StrVec& operator=(StrVec &&rhs)noexcept;
    ~StrVec();
    void push_back(const string& s);
    size_t size() const {return first_free_ - elements_;}
    size_t capacity() const {return cap_ - elements_;}
    string* begin() const {return elements_;}
    string* end() const {return first_free_;}
private:
    static std::allocator<string> alloc;
    void check_n_alloc()
    {
	if(size() == capacity())
	    reallocate();
    }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string* elements_;
    string* first_free_;
    string* cap_;
};

allocator<string> StrVec::alloc;

StrVec::StrVec(StrVec&& rhs)noexcept
{
    //free();
    elements_ = rhs.elements_;
    first_free_ = rhs.first_free_;
    cap_ = rhs.cap_;
    rhs.elements_ = nullptr;
    rhs.first_free_ = nullptr;
    rhs.cap_ = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs)noexcept
{
    if(this != &rhs){
	free();
	elements_ = rhs.elements_;
	first_free_ = rhs.first_free_;
	cap_ = rhs.cap_;
	elements_ = first_free_ = cap_ = nullptr;
    }
    return *this;
}

void StrVec::push_back(const string& s)
{
    check_n_alloc();
    StrVec::alloc.construct(first_free_++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = StrVec::alloc.allocate(e-b);
    return {data, uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
    if(elements_){
	for(auto p = elements_; p != first_free_;)
	    StrVec::alloc.destroy(p++);
	StrVec::alloc.deallocate(elements_, cap_-elements_);
    }
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2*size() : 1;
    auto new_data = StrVec::alloc.allocate(new_capacity);
    auto des = new_data;
    auto elem = elements_;
    while(elem != first_free_){
	StrVec::alloc.construct(des++, std::move(*elem++));
    }
    free();
    elements_ = new_data;
    first_free_ = des;
    cap_ = elements_ + new_capacity;
}

StrVec::~StrVec()
{
    free();
}

StrVec::StrVec(const StrVec& sv)
{
    auto p = alloc_n_copy(sv.begin(),sv.end());
    elements_ = p.first;
    first_free_ = cap_ = p.second;
}

StrVec& StrVec::operator=(const StrVec& sv)
{
    auto data = alloc_n_copy(sv.begin(),sv.end());
    free();
    elements_ = data.first;
    first_free_ = cap_ = data.second;
    return *this;
}

int main()
{
    return 0;
}

