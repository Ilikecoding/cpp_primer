#ifndef Text_Query_H
#define Text_Query_H

#include "StrBlob.h"
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

class QueryResult;

class TextQuery
{
public:
	using line_no = StrBlob::size_type;

	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	StrBlob file;
	std::map<std::string, 
	        std::shared_ptr<std::set<line_no>>> word_map;
};

#endif