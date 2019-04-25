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


//instr�msoperator f�r personer.
std::istream & operator>>(std::istream  & in, person & p);

std::vector<person> read_file(const std::string & filname);

//Ger antalet namn som st�mmer med den givna s�kningen.
std::size_t find_in_names(const std::vector<person> persons, std::string name_part);

//Ger en lista p� antalet personer som bor p� den givna staden.
std::vector<person> find_person_from_city(const std::vector<person> & haystack, std::string city);

// tar in en str�ng och spottar ut en ny med endast stora bokst�ver.
std::string toUpper(std::string str);

#endif // !PERSON_H
