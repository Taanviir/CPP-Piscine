#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal {
public:
	Dog();
	~Dog();
	Dog(const Dog& copy);

	Dog& operator=(const Dog& copy);

	void makeSound(void) const;

private:
	Brain* _brains;
};

#endif // DOG_HPP
