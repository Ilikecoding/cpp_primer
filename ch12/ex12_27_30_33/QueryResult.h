#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "TextQuery.h"

class QueryResult
{	
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);   // print the query result

	QueryResult(const std::string &s,                                // constructor
		std::shared_ptr<std::set<TextQuery::line_no>> l,
		std::shared_ptr<std::vector<std::string>> f):
	key(s), lines(l), file(f) {}

    std::set<TextQuery::line_no>::iterator begin() const 
    { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() const 
    { return lines->end(); }    
    std::shared_ptr<std::vector<std::string>> get_file() const 
    { return file; }

private:
	std::string key;                                         // the word to search
	std::shared_ptr<std::set<TextQuery::line_no>> lines;     // the word's set of line number
	std::shared_ptr<std::vector<std::string>> file;          // the text of the file  
};

#endif