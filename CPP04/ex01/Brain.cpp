#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "BIG BRAIN IDEA";
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain(const Brain& copy) {
	*this = copy;
	std::cout << "Brain Copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this == &copy) return *this;

	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}
	return *this;
}