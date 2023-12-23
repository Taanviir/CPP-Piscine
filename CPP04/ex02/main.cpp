#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// AAnimal a; --> this does not work due to AAnimal being an Abstract class

	// Pointers to AAnimal is fine as the object of AAnimal isn't being instantiated
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	delete dog;
	delete cat;

	return 0;
}
