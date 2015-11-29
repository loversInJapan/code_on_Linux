/*************************************************************************
	> File Name: exercise_16.12.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 29 Nov 2015 12:08:10 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename> class Blob;
template <typename> class BlobPtr;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

//template class Blob
template <typename T>
class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    Blob();
    Blob(initializer_list<T> li);
    template <typename It> Blob(It b, It e);
    Blob(T*, size_t);

    BlobPtr<T> begin() {return BlobPtr<T>(*this);}
    BlobPtr<T> end()
    {
	auto ret = BlobPtr<T>(*this, data_->size());
	return ret;
    }

    size_t size() const
    {
	return data_->size();
    }
    bool empty() const
    {
	return data_->empty();
    }

    void push_back(const T& t)
    {
	data_->push_back(t);
    }
    void push_back(T&& t)
    {
	data_->push_back(std::move(t));
    }
    void pop_back();

    T& front();
    T& back();
    T& at(size_t);
    const T& back() const;
    const T& front() const;
    const T& at(size_t) const;
    T& operator[](size_t);
    const T& operator[](size_t) const;
    void operator=(const Blob<T>& rhs)
    {
	data_ = rhs.data_;
    }
    void swap(Blob &b)
    {
	data_.swap(b.data_);
    }
private:
    shared_ptr<vector<T>> data_;
    void check(size_t i, const string& msg) const;
};

template <typename T>
Blob<T>::Blob(T* p, size_t n) : data_(make_shared<vector<T>>(p, p+n)){}

template <typename T>
Blob<T>::Blob() : data_(make_shared<vector<T>> ()) {}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data_(make_shared<vector<T>>(b, e))
{}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) :
    data_(make_shared<vector<T>>(il))
{}

template <typename T>
void Blob<T>::check(size_t i, const string& msg) const
{
    if(i >= data_->size())
	throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front()
{
    check(0,"front on empty Blob");
    return data_->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data_->back();
}

template <typename T>
T& Blob<T>::at(size_t i)
{
    check(i,"at out of range");
    return (*data_)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data_->pop_back();
}

template <typename T>
const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data_->front();
}

template <typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data_->back();
}

template <typename T>
const T& Blob<T>::at(size_t i) const
{
    check(i,"at out of range");
    return (*data_)[i];
}

template <typename T>
T& Blob<T>::operator[](size_t i)
{
    check(i,"[] out of range");
    return (*data_)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_t i) const
{
    check(i,"[] out of range");
    return (*data_)[i];
}

template <typename T>
ostream& operator<<(ostream& os, const Blob<T> a)
{
    os << "< ";
    for(size_t i=0; i < a.size(); ++i)
	os << a[i] << " ";
    os << " >";
    return os;
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    if(lhs.size() != rhs.size())
	return false;
    for(size_t i = 0; i < lhs.size(); ++i)
	if(lhs[i] != rhs[i])
	    return false;
    return true;
}

//template class BlobPtr
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr{
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr() : curr_(0){}
    BlobPtr(Blob<T>& a, size_t sz = 0) : wptr_(a.data_), curr_(sz){}
    T& operator[](size_t i)
    {
	auto p = check(i, "subscript out of range");
	return (*p)[i];
    }
    const T& operator[](size_t i) const
    {
	auto p = check(i, "subscript out of range");
	return (*p)[i];
    }
    T& operator*()const
    {
	auto p = check(curr_, "dereference past end");
	return (*p)[curr_];
    }
    T* operator->()const
    {
	return &this->operator*();
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    shared_ptr<vector<T>>
	check(size_t i, const string& msg) const;
    weak_ptr<vector<T>> wptr_;
    size_t curr_;
};

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.wptr_.lock().get() == rhs.wptr_.lock().get()
	&& lhs.curr_ == rhs.curr_;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(operator==(lhs, rhs));
}

template <typename T>
shared_ptr<vector<T>>
BlobPtr<T>::check(size_t i, const string& msg)const
{
    auto ret = wptr_.lock();
    if(!ret)
	throw runtime_error("unbound BlobPtr");
    if(i >= ret->size())
	throw out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr_, "increment past end of BlobPtr");
    ++curr_;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr_;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

int main()
{
    Blob<string> b1;
    cout << b1.size() << endl;
    {
	Blob<string> b2 = {"a","an","the"};
	b1 = b2;
	b2.push_back("about");
	cout << b1.size() << " " << b2.size() << endl;
    }
    cout << b1.size() << endl;
    for(auto p = b1.begin(); p != b1.end(); ++p)
	cout << *p << endl;
    return 0;
}
