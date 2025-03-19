
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const FragTrap& fragtrap);
	FragTrap& operator=(const FragTrap& fragtrap);
	FragTrap(std::string const& name);
	~FragTrap();

	void	highFivesGuys(void);

protected:
	int				_FThp = 100;
	int				_FTep = 100;
	unsigned int	_FTad = 30;

private:
	FragTrap();

};

#endif