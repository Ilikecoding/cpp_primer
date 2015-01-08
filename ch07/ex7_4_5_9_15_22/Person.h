/*
Exercise 7.4: Write a class named Person that represents the name and
address of a person. Use a string to hold each of these elements.
Subsequent exercises will incrementally add features to this class.

Exercise 7.5: Provide operations in your Person class to return the name
and address. Should these functions be const? Explain your choice.

Exercise 7.9: Add operations to read and print Person objects to the code
you wrote for the exercises in § 7.1.2 (p. 260).

Exercise 7.15: Add appropriate constructors to your Person class.

Exercise 7.22: Update your Person class to hide its implementation.
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
    friend std::istream& read(std::istream &is, Person &person);
    friend std::ostream& print(std::ostream &os, const Person &person);
    
    Person() = default;
    Person(const std::string &n, const std::string &a): name(n), address(a) {}
    explicit Person(std::istream &is) { read(is, *this); }

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }

private:
	std::string name;
	std::string address;
};

std::istream& read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
	return is;
}

std::ostream& print(std::ostream &os, const Person &person)
{
	os << person.name << " " << person.address;
	return os;
}

#endif