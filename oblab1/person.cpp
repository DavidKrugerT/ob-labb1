#include "person.h"

/*perator overloading tar en fil till vänster och en strukt person till höger hämtar in p.
The class template basic_istream provides support for high level input operations on character streams.
The supported operations include formatted input (e.g. integer values or whitespace-separated characters and characters */

std::istream & operator>>(std::istream & in, person & p)
{
	std::string zip1, zip2, city1, city2;


	std::getline(in, p.name);
	std::getline(in, p.id);
	std::getline(in, p.address.street, ',');
	
	in.ignore();
	in >> zip1;
	in.ignore();
	in >> zip2;

	//om zip ett inte är tom eller om zip 2 är tom. p.address.zip string to int zip1 + zip2.
	if (!(zip1.empty() || zip2.empty()))
		p.address.zip = stoi(zip1 + zip2);

	in.ignore(2);

	in >> city1;

	in.ignore();

	if (in.peek() != ' ')
	{
		in >> city2;
	}
	else
	{
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Gör så att den ignorerar alla spaces efter stadsnamnen tills att det blir en ny rad.
	}
	if (city2.empty())
	{
		p.address.city = city1;
	}
	else {
		p.address.city = city1 + " " + city2;
	}
	return in;
}

std::vector<person> read_file(const std::string & filename)
{
	//skapar en vector med struct person och struct p.
	std::vector<person> ppl;
	person p;

	std::ifstream file(filename.c_str());
	if (file.is_open())
		while (file >> p)
			ppl.push_back(p);
	return ppl;

}

std::size_t find_in_names(const std::vector<person> persons, std::string name_part)
{
	std::size_t count = 0;
	name_part = toUpper(name_part);

	for (auto a : persons)
	{
		a.name = toUpper(a.name);

		if (a.name.find(name_part) != std::string::npos) // npos fortsätter tills det är slut "sista" positionen.
			++count;
	}
	return count;
}
//funtionen tar fram alla personer som bor i den sökta staden. skapar en temporär, 
//och pushbackar in det i en ny vektor 
std::vector<person> find_person_from_city(const std::vector<person>& haystack, std::string city)
{
	std::vector<person> personCity;
	city = toUpper(city);

	for (auto p : haystack)
	{
		auto tmp = p.address.city;
		tmp = toUpper(tmp);

		if (tmp == city)
			personCity.push_back(p);
	}
	return personCity;
}
//funktion som omvandlar alla små bokstäver till stora för att en sökning.
std::string toUpper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}
