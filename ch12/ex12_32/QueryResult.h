#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <string>
#include <set>
#include <memory>
#include "TextQuery.h"

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);

	QueryResult(const std::string &s,
		        std::shared_ptr<std::set<TextQuery::line_no>> l,
		        StrBlob sb):
	key(s), lines(l), file(sb) {}

private:
	std::string key;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
    StrBlob file;
};

#endif