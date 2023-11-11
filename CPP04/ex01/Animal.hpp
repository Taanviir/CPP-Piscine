#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& copy);

	Animal& operator=(const Animal& copy);

	std::string getType(void) const;
	void setType(const std::string& newType);
	virtual void makeSound(void) const;

protected:
	std::string type;
};

#endif // ANIMAL_HPP
