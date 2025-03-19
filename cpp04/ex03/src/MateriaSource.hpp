
#ifndef	MateriaSource_HPP
# define MateriaSource_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& src);
	MateriaSource& operator=(const MateriaSource& src);
	~MateriaSource() override;

	void		learnMateria(AMateria* m) override;
	AMateria*	createMateria(std::string const& type) override;

private:
	AMateria*	_list[4];
};

#endif