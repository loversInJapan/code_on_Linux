/*************************************************************************
	> File Name: singleton.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 30 Nov 2015 06:18:15 PM CST
 ************************************************************************/

#include <iostream>
#include <pthread.h>
#include <memory>
using namespace std;

//class Lock
class Lock{
public:
    Lock()
    {
	pthread_mutex_init(&mutex_,nullptr);
    }
    ~Lock()
    {
	pthread_mutex_destroy(&mutex_);
    }
    bool lock();
    bool unlock();
private:
    pthread_mutex_t mutex_;
};

bool Lock::lock() 
{
    auto ret = pthread_mutex_lock(&mutex_);
    return ret==0 ? true : false;
}

bool Lock::unlock()
{
    auto ret = pthread_mutex_unlock(&mutex_);
    return ret==0 ? true : false;
}

//class Singleton
class Singleton final{
public:
    static Lock mutex;
    static shared_ptr<Singleton> single_ptr;
    static shared_ptr<Singleton> getInstance();
    ~Singleton()
    {
	cout << "destroy a Singleton" << endl;
    }
private:
    Singleton()
    {
	cout << "initialize an Singleton" << endl;
    }
    Singleton& operator=(const Singleton&);
    Singleton& operator=(Singleton&&);
    Singleton(const Singleton&);
    Singleton(Singleton&&);
};

Lock Singleton::mutex;
shared_ptr<Singleton> Singleton::single_ptr;

shared_ptr<Singleton>
Singleton::getInstance()
{
    if(single_ptr == nullptr){
	mutex.lock();
	if(single_ptr == nullptr){
	    single_ptr.reset(new Singleton);
	    cout << "initialization successed" << endl;
	}
	else
	    cout << "initialization failed" << endl;
	mutex.unlock();
    }
    else
	cout << "initialization failed" << endl;
    return single_ptr;
}

void* threadFunc(void* arg)
{
    *((shared_ptr<Singleton>*)arg) = Singleton::getInstance();
    //arg = sp.get();
    pthread_exit(nullptr);
    //return nullptr;
}

int main()
{
    //auto p1 = Singleton::getInstance();
    //auto p2 = Singleton::getInstance();
    pthread_t pthid1, pthid2;
    shared_ptr<Singleton> p1, p2;
    pthread_create(&pthid1,NULL,threadFunc,(void*)(&p1));
    pthread_create(&pthid2,NULL,threadFunc,(void*)(&p2));
    pthread_join(pthid1,nullptr);
    pthread_join(pthid2,nullptr);
    if(p1 == p2 && p1 != nullptr && p2 != nullptr)
	cout << "same instance" << endl;
    return 0;
}
