#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	// AAnimal a; --> this does not work due to AAnimal being an Abstract class

	return 0;
}
