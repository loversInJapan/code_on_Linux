/*************************************************************************
	> File Name: Quote.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 20 Nov 2015 07:12:25 PM CST
 ************************************************************************/

#ifndef QUOTE_H_
#define QUOTE_H_

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

class Quote{
    friend std::istream& operator>>(std::istream&, Quote&);
    friend std::ostream& operator<<(std::ostream&, const Quote&);
public:
    Quote() = default;
    Quote(const std::string &book, double sale_prices):bookNo_(book), price_(sale_prices){}
    Quote(const Quote& rhs)
    {
	bookNo_ = rhs.bookNo_;
	price_ = rhs.price_;
    }
    Quote& operator=(const Quote& rhs)
    {
	bookNo_ = rhs.bookNo_;
	price_ = rhs.price_;
	return *this;
    }
    virtual ~Quote() = default;
    std::string isbn() const {return bookNo_;}
    virtual double net_price(std::size_t n) const
    {
	return n * price_;
    }
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
private:
    std::string bookNo_;
protected:
    double price_ = 0.0;
};

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
	Quote(book, price), qty_(qty), discount_(disc){}
    Disc_quote(const Disc_quote& rhs) : Quote(rhs){}
    double net_price(std::size_t)const = 0;
    std::pair<size_t, double> disc_policy() const
    {return {qty_,discount_};}
protected:
    std::size_t qty_ = 0;
    double discount_ = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
	: Disc_quote(book, p, qty, disc){}
    Bulk_quote(const Bulk_quote& rhs) : Disc_quote(rhs)
    {
	qty_ = rhs.qty_;
	discount_ = rhs.discount_;
    }
    Bulk_quote& operator=(const Bulk_quote& rhs)
    {
	Quote::operator=(rhs);
	qty_ = rhs.qty_;
	discount_ = rhs.discount_;
	return *this;
    }
    double net_price(std::size_t) const override;
    Bulk_quote* clone()const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
};

double print_total(std::ostream&, const Quote&, std::size_t);

#endif
