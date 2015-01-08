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
	Sales_data(std::string s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { std::cout << "1" << std::endl; }
    Sales_data(): Sales_data("", 0, 0.0) { std::cout << "2" << std::endl; }
    Sales_data(std::string s): Sales_data(s, 0, 0.0) { std::cout << "3" << std::endl; }
    Sales_data(std::istream &is): Sales_data() { std::cout << "4" << std::endl; read(is, *this); }
    
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