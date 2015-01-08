#include "StrBlob.h"
#include "StrBlobPtr.h"

StrBlobPtr StrBlob::begin() 
{ 
	return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() 
{ 
	return StrBlobPtr(*this, data->size()); 
}

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