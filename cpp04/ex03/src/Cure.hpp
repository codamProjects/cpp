
#ifndef	CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& src);
	Cure& operator=(const Cure& src);
	~Cure() override;

	AMateria*	clone() const override;
	void	use(ICharacter& target) override;

};

#endif