#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal {
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal& copy);

	AAnimal& operator=(const AAnimal& copy);

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;

protected:
	std::string type;
};

#endif // ANIMAL_HPP
