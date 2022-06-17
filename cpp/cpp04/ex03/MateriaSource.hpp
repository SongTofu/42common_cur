#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*(_inventory[4]);
public:
	MateriaSource();
	MateriaSource(MateriaSource const& other);
	~MateriaSource();

	MateriaSource&	operator=(MateriaSource const& other);
	virtual void	learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const& type);
};

#endif