
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const FragTrap& fragtrap);
	FragTrap& operator=(const FragTrap& fragtrap);
	FragTrap(std::string const& name);
	~FragTrap();

	void	highFivesGuys(void);

private:
	FragTrap();

};

#endif