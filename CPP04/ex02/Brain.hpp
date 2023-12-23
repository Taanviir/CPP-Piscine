#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain& copy);

	Brain& operator=(const Brain& copy);

protected:
	std::string _ideas[100];
};

#endif // BRAIN_HPP
