#ifndef CONST_STRBLOB_PTR_H
#define CONST_STRBLOB_PTR_H

#include "StrBlob.h"
#include <memory>
#include <vector>
#include <string>

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr(): curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) {}

    std::string& deref() const;
    ConstStrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>> 
	    check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

#endif