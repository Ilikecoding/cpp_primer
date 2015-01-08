#include "QueryResult.h"

std::string make_plural(const std::string &word, int n)
{
	return n > 1 ? word + "s" : word;
}

std::ostream &print(std::ostream& os, const QueryResult &qr)
{
	os << qr.key << " occurs " << qr.lines->size() 
		<< make_plural(" time", qr.lines->size()) << "\n";

	// print lines that the key word appears
	for (const auto &num : *qr.lines)      
	{
		os << "(line " << num + 1 << ") " 
		    << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}