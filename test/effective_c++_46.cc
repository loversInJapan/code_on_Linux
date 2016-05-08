#include <iostream>
using namespace std;

template <typename T>
class Rational
{
public:
	Rational(T numerator=0, T denominator=1):numerator_(numerator),denominator_(denominator)
	{}
	T numerator() const {return numerator_;}
	T denominator() const {return denominator_;}
friend
	const Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		return Rational(lhs.numerator()*rhs.numerator(), lhs.denominator()*rhs.denominator());
	}
private:
	T numerator_;
	T denominator_;
};

template <typename T>
ostream& operator<<(ostream& os, const Rational<T> &rhs)
{
	os << rhs.numerator() << "/" << rhs.denominator();
	return os;
}

/*
template <typename T>
const Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs)
{
	return Rational<T>(lhs.numerator()*rhs.numerator(), lhs.denominator()*rhs.denominator());
}
*/
int main()
{
	Rational<int> lhs(3,5);
//	cout <<  lhs.numerator() << endl;
	Rational<int> rhs(3,7);
	Rational<int> res = lhs*rhs;
	cout << res << endl;
	res = rhs * 2;
	cout << res << endl;
	Rational<double> dlhs(2.3,1.2);
	Rational<double> drhs(4.3,7.2);
	cout << dlhs * drhs << endl;
	return 0;
}

