#include "person.h"

void printmenu();

int main() {
	
	auto lista = read_file("names.txt");
	system("chcp 1252");
	setlocale(LC_ALL, "SE");
	std::vector<person> personList;
	std::string input, searchName, searchCity;
	int choice = 0;

	bool programOn = true;

	do
	{
		system("CLS");
		printmenu();
		std::getline(std::cin, input);

		if (input.size() == 1)
			choice = input[0] - '0';
		else
			choice = -1;
		switch (choice) {
		case 1:
			system("CLS");
			std::cout << "Skriv in det du önskar söka: " << '\n';
			std::getline(std::cin, searchName);
			std::cout << "Antalet hittade personer: " << find_in_names(lista, searchName) << '\n';
			system("PAUSE");
			break;
		case 2:
			system("CLS");
			std::cout << "Skriv in stad du önskar hitta personer i: " << '\n';
			std::getline(std::cin, searchCity);
			personList = find_person_from_city(lista, searchCity);
			for (auto a : personList)
				std::cout << a.name << '\n';
			system("PAUSE");
			break;
		case 3:
			programOn = false;
			break;
		default:
			std::cout << "Du har inte valt något av de givna alternativen. " << '\n';
		}


	} while (programOn);
	return	0; //exit status, returning 0 means the program worked fine.
}

void printmenu()
{
	std::cout << "Vad vill du söka efter? " << '\n';
	std::cout << "1. Sök del av personnamn" << '\n';
	std::cout << "2. Sök städer" << '\n';
	std::cout << "3. Avlsuta" << '\n';
}
