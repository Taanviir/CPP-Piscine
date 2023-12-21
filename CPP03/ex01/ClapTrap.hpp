#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap(std::string* name);
	ClapTrap(std::string name);

	ClapTrap& operator=(const ClapTrap& copy);

	virtual void attack(const std::string* target);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif