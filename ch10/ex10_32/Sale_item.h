#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using naemspace std;

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

int main(int argc, char const *argv[])
{
	vector<Sale_item> v;
	istream_iterator<Sale_item> in_iter(cin), eof;
	ostream_iterator<Sale_item> out_iter(cout, "\n");

	while(in_iter != eof)
	{
		v.push_back(*in_iter++);
	}

	sort(v.begin(), v.end(), compare_isbn);

	
	return 0;
}

bool compare_isbn(const Sale_item &item1, const Sale_item &item2)
{
	return item1.get_isbn().size() < item2.get_isbn().size();
}