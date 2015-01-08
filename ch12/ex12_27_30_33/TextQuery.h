#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);                               // constructor
	QueryResult query(const std::string&) const;             // save the result of query function as the class QueryResult

private:
	std::shared_ptr<std::vector<std::string>> file;          // the input file
	std::map<std::string, 
	        std::shared_ptr<std::set<line_no>>> word_map;    // each word's set of line number 
};

#endif