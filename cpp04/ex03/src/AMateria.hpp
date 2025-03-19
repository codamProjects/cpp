
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria(const AMateria& src);
	AMateria& operator=(const AMateria& src);
	AMateria(std::string const& type);
	virtual ~AMateria();

	std::string const&	getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	_type;
	AMateria();
};

#endif