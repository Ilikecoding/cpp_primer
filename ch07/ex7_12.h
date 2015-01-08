#ifndef EX7_12_H
#define EX7_12_H

/*
Exercise 7.12: Move the definition of the Sales_data constructor that
takes an istream into the body of the Sales_data class.
*/

#include <string>
#include <iostream>

struct Sales_data
{
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p): 
	    bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}

std::istream& read(std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

#endif