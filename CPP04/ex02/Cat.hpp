#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal {
public:
	Cat();
	~Cat();
	Cat(const Cat& copy);

	Cat& operator=(const Cat& copy);

	void makeSound(void) const;

private:
	Brain* _brains;
};

#endif // CAT_HPP
