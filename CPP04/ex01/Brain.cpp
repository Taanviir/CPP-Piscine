#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "BIG BRAIN IDEA";
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this == &copy)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}