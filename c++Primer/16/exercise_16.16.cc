/*************************************************************************
	> File Name: exercise_16.16.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 02 Dec 2015 10:37:54 AM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

template <typename T>
class Vec{
public:
    Vec():elements_(nullptr),first_free_(nullptr),cap_(nullptr)
    {}
    Vec(const Vec&);
    Vec& operator=(const Vec& );
    ~Vec();
    void push_back(const T&);
    size_t size() const
    {
	return first_free_ - elements_;
    }
    size_t capacity() const
    {
	return cap_ - elements_;
    }
    T* begin() const
    {
	return elements_;
    }
    T* end() const
    {
	return first_free_;
    }
private:
    static allocator<T> alloc_;
    void check_n_alloc()
    {
	if(size() == capacity())
	    reallocate();
    }
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T* elements_;
    T* first_free_;
    T* cap_;
};

template <typename T>
allocator<T> Vec<T>::alloc_;

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* beg, const T* end)
{
    auto data = alloc_.allocate(end - beg);
    return {data, uninitialized_copy(beg, end, data)};
}

template <typename T>
void Vec<T>::push_back(const T& v)
{
    check_n_alloc();
    alloc_.construct(first_free_++, v);
}

template <typename T>
void Vec<T>::free()
{
    if(elements_){
	for(auto p = first_free_; p != elements_;)
	    alloc_.destroy(--p);
	alloc_.deallocate(elements_,cap_ - elements_);
    }
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T>::Vec(const Vec<T>& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    elements_ = data.first;
    first_free_ = cap_ = data.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    auto data = alloc_n_copy(rhs.elements_, rhs.first_free_);
    free();
    elements_ = data.first;
    first_free_ = cap_ = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
    auto new_cap = size()>0 ? size() * 2 : 1;
    auto data = alloc_.allocate(new_cap);
    auto dest = data;
    auto src = elements_;
    for(size_t i = 0; i < size(); ++i)
	alloc_.construct(dest++, std::move(*src++));
    free();
    elements_ = data;
    first_free_ = dest;
    cap_ = elements_ + new_cap;
}

int main()
{
    Vec<string> sv;
    sv.push_back("lakers");
    sv.push_back("kobe");
    sv.push_back("76ers");
    Vec<string> sv2(sv);
    sv2.push_back("sucks");
    for(auto p = sv2.begin(); p != sv2.end(); ++p)
	cout << *p << " ";
    cout << endl;
    return 0;
}
