/*
Exercise 12.2: Write your own version of the StrBlob class including the
const versions of front and back.
*/

#include <vector>
#include <memory>
#include <string>

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;

    // 构造函数
	StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il): 
	    data(std::make_shared<std::vector<std::string>>(il)) {}

    // 成员函数
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

	void push_back(const std::string &s) { data->push_back(s); }
	void pop_back();

    std::string& front();
    const std::string& front() const;

    std::string& back();
    const std::string& back() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
	if(data->size() <= i)
	{
		throw std::out_of_range(msg);
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();	
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

int main(int argc, char const *argv[])
{
	return 0;
}