#include "Character.hpp"

Character::Character():
	_nbrMaterias(0)
{
	std::cout << "Character Default Constructor" << std::endl;
}

Character::Character(const std::string &name):
	_name(name), _nbrMaterias(0)
{
	for (int i = 0; i < NBR_SLOTS; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character Name Constructor" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character Default Destructor" << std::endl;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < NBR_SLOTS; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (src._inventory[i])
			this->_inventory[i] =  src._inventory[i]->clone();
	}
	this->_nbrMaterias = src._nbrMaterias;
	return (*this);
}

const std::string &Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (_nbrMaterias < NBR_SLOTS)
	{
		for (int i = 0; i < NBR_SLOTS; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				_nbrMaterias += 1;
				std::cout << "Materia equiped successfully to your inventory" << std::endl;
				return ;
			}
		}
	}
	else
		std::cout << this->_name << "'s inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < NBR_SLOTS)
	{
		_inventory[idx] = NULL;
		_nbrMaterias -= 1;
		std::cout << "Materia unequiped successfully to your inventory" << std::endl;
	}
	else
		std::cout << "Invalid Inventory Index Slot" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < NBR_SLOTS)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
		else
			std::cout << "Inventory Slot is Empty" << std::endl;
	}
	else
		std::cout << "Invalid Inventory Index Slot" << std::endl;
}

void	Character::showInventory(void) const
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << this->_name << "'s Inventory" << std::endl;
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (this->_inventory[i])
			std::cout << this->_inventory[i] << std::endl;
		else
			std::cout << "Empty Slot" << std::endl;
	}
	std::cout << "<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>" << std::endl;
}
