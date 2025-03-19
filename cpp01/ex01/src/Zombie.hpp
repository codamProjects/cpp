
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void	announce(void) const;
	void	setName(std::string const name);

private:
	std::string _name;
};

Zombie	*zombieHorde(int n, std::string name);

#endif
