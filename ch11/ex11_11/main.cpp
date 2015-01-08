/*
Exercise 11.11: Redefine bookstore without using decltype.
Exercise 11.19: Define a variable that you initialize by calling begin() on
the multiset named bookstore from § 11.2.2 (p. 425). Write the
variable’s type without using auto or decltype.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Sale_item
{
public:
	Sale_item(const string &s, unsigned uni, double price): 
	    isbn(s), units_sold(uni), revenue(uni * price) { }

	string get_isbn() const { return isbn; }

	bool same_isbn(const Sale_item &item) const
	{
		return isbn == item.isbn;
	}

    istream &operator >>(istream &is)
    {
    	double price;
    	is >> isbn >> units_sold >> price;
    	return is;
    }
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

bool compare_isbn(const Sale_item &item1, const Sale_item &item2)
{
	return item1.get_isbn() < item2.get_isbn();
}

int main(int argc, char const *argv[])
{
	using compareType = bool(*)(const Sale_item &lhs, const Sale_item &rhs);
	multiset<Sale_item, compareType> bookstore1(compare_isbn);
	// multiset<Sale_item, decltype(compare_isbn)*> bookstore2(compare_isbn);
	return 0;
}