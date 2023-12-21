#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);

	WrongAnimal& operator=(const WrongAnimal& copy);

	std::string getType(void) const;

	virtual void makeSound(void) const;

protected:
	std::string _type;
};

#endif // WRONGANIMAL_HPP
