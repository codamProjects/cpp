
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>
int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		AMateria* tmp2;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		me->use(1, *bob);
		me->unequip(1);
		me->use(1, *bob);
		tmp = src->createMateria("something else");
		me->equip(tmp);	
		me->use(1, *bob);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		IMateriaSource* src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		ICharacter* me2 = new Character("me");
		ICharacter* bob2 = new Character("bob");
		AMateria* tmp2;
		tmp2 = src2->createMateria("cure");
		me2->equip(tmp2);
		me2->use(0, *bob2);
		me2->unequip(0);

		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		tmp2 = src2->createMateria("ice");
		me2->equip(tmp2);
		me2->unequip(5);
		me2->use(4, *me2);
		me2->use(3, *me2);
		delete bob2;
		delete me2;
		delete src2;
	}
return 0;
}