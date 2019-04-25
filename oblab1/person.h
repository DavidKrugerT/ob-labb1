#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cctype>


struct location {
	std::string street;
	std::string city;
	int	zip;
};

struct person {
	std::string name;
	std::string id;
	location address;
};


//inströmsoperator för personer.
std::istream & operator>>(std::istream  & in, person & p);

std::vector<person> read_file(const std::string & filname);

//Ger antalet namn som stämmer med den givna sökningen.
std::size_t find_in_names(const std::vector<person> persons, std::string name_part);

//Ger en lista på antalet personer som bor på den givna staden.
std::vector<person> find_person_from_city(const std::vector<person> & haystack, std::string city);

// tar in en sträng och spottar ut en ny med endast stora bokstäver.
std::string toUpper(std::string str);

#endif // !PERSON_H
