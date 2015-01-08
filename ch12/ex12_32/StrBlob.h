#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <memory>
#include <string>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
    
	StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il): 
	    data(std::make_shared<std::vector<std::string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

	void push_back(const std::string &s) { data->push_back(s); }
	void pop_back();

    std::string& front();
    const std::string& front() const;

    std::string& back();
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

#endif