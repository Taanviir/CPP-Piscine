#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
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
				std::cout << "Error: Invalid command" << std::endl;
		} else {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF received, quitting program." << std::endl;
				return 1;
			}
			std::cout << "Error: Invalid input" << std::endl;
			break;
		};
	}
	return (0);
}