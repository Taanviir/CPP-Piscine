#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal& copy);

	AAnimal& operator=(const AAnimal& copy);

	std::string getType(void) const;
	void setType(const std::string& newType);
	virtual void makeSound(void) const;

protected:
	std::string type;
};

#endif // AANIMAL_HPP
