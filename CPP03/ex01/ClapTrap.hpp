#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif