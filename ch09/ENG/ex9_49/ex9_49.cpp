/*----------------------------------------------------------------
ex9_49:
A letter has an ascender if, as with d or f, part of the 
letter extends above the middle of the line. A letter has 
a descender if, as with p or g, part of the letter extends 
below the line. Write a program that reads a file containing 
words and reports the longest word that contains neither 
ascenders nor descenders.
----------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream in("letter.txt");
    if(!in)
    {
    	cout << "Can not open the file." << endl;
    	return -1;
    }

    string word, longest_word;
    while(in >> word)
    {
    	if(word.find_first_not_of("aceimnorstuvwxz") == string::npos 
    		&& word.size() > longest_word.size())
    	{
    		longest_word = word;
    	}
    }

    cout << longest_word << endl;
    in.close();

	return 0;
}