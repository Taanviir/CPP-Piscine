#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (command != "EXIT")
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		// validate output
		if (command == "ADD")
			phonebook.add();
		// else if (command == "SEARCH")
		// else print message and continue
		std::cout << "You have entered " << command << std::endl;
	}
	return (0);
}