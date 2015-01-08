#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
public:
	friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, unsigned u, double p): bookNo(s), units_sold(u), revenue(p*u) {}
    Sales_data(std::istream &is) { read(is, *this); }
    
    // member function
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
	double avg_price() const { return units_sold ? revenue/units_sold : 0; }
	std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

#endif