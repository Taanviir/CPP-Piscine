#include "PhoneBook.hpp"

/*
* things to fix:
* index of contacts need to be handled properly
*/

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (42)
	{
		std::cout << std::endl << "Enter a command (ADD, SEARCH, EXIT): ";
		if (std::getline(std::cin, command)) {
			if (command == "ADD") {
				phonebook.addContact();
			}
			else if (command == "SEARCH")
				phonebook.searchContact();
			else if (command == "EXIT")
				break;
			else
				std::cout << "Invalid command" << std::endl;
		} else {
			std::cout << "Invalid input" << std::endl;
			break;
		};
	}
	return (0);
}