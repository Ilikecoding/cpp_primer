#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

std::istream& read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is; 
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	     << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}