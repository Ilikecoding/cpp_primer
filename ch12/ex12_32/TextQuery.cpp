#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream &is)
{
	std::string line;
	while(std::getline(is, line))
	{
		file.push_back(line);
		int n = file.size() - 1;
		std::istringstream in(line);
		std::string word;
		while(in >> word)
		{
			auto &lines = word_map[word];
			if(!lines)
			{
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &s) const
{
	std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto it = word_map.find(s);
	if(it == word_map.end())
	{
		return QueryResult(s, nodata, file);
	}
	else
	{
		return QueryResult(s, it->second, file);
	}
}