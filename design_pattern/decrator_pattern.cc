/*************************************************************************
	> File Name: decrator_pattern.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 10 Nov 2015 12:35:46 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

//class Person
class Person{
public:
    Person() = default;
    Person(const string& name) : name_(name) {}
    virtual ~Person(){}
    virtual ostream& Show(ostream &os)
    {
	os << "good looking " << name_;
	return os;
    }
    //virtual void Decorate(shared_ptr<Person> sp) {}
private:
    string name_;
};
//class Finery
class Finery : public Person{
public:
    Finery() = default;
    Finery(shared_ptr<Person> sp) : sp_(sp) {}
    virtual ~Finery(){}
    void Decorate(shared_ptr<Person> sp) 
    {
	sp_ = sp;
    }
    ostream& Show(ostream& os) override
    {
	if(sp_ != nullptr)
	{
	    sp_->Show(os);
	}
	return os;
    }
protected:
    shared_ptr<Person> sp_;
};
//class Tshirts
class Tshirts : public Finery{
public:
    Tshirts(shared_ptr<Person> sp) : Finery(sp){}
    ostream& Show(ostream& os) override
    {
	//os << "T shirts ";
	AddDecorate(os);
	sp_->Show(os);
	//AddDecorate(os);
	return os;
    }
private:
    ostream& AddDecorate(ostream& os)
    {
	os << "T-shirt ";
	return os;
    }
};
//class Sneaker
class Sneaker : public Finery{
public:
    Sneaker(shared_ptr<Person> sp) : Finery(sp){}
    ostream& Show(ostream& os) override
    {
	//os << "NIKE-AIR-FORCE-1 ";
	AddDecorate(os);
	sp_->Show(os);
	//AddDecorate(os);
	return os;
    }
private:
    ostream& AddDecorate(ostream& os)
    {
	//os << "T-shirt";
	os << "NIKE-AIR-FORCE-1 ";
	return os;
    }
};

int main()
{
    shared_ptr<Person> boy = shared_ptr<Person>(new Person("Mike"));
    shared_ptr<Person> wear = shared_ptr<Person>(new Tshirts(boy));
    shared_ptr<Person> shoe = shared_ptr<Person>(new Sneaker(wear));

    //wear->Decorate(boy);
    //shoe->Decorate(wear);
    shoe->Show(cout) << endl;
    return 0;
}
