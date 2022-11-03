#include "../includes/PhoneBook.hpp"

static void	printElement(Contact person, int index);

void	PhoneBook::createContact()
{
	int	actualContact;

	if (nbrContact == 8)
		actualContact = oldestContact;
	else
		actualContact = nbrContact;
	std::cout << "--------------- ADD ---------------" << std::endl;
	contacts[actualContact].setFirstName();
	contacts[actualContact].setLastName();
	contacts[actualContact].setNickname();
	contacts[actualContact].setPhoneNumber();
	contacts[actualContact].setSecret();
	std::cout << "\nContact added Seccessfully\n" << std::endl;
	if (nbrContact == 8)
	{
		if (oldestContact < 7)
			oldestContact++;
		else
			oldestContact = 0;
	}
	nbrContact += 1;
}

void	PhoneBook::searchContact() const
{
	int i = 0;

	while (i < nbrContact)
	{
		printElement(contacts[i], i + 1);
		i++;
	}
}

static void	printElement(Contact person, int index)
{
	std::cout
		<< std::setw(10)
		<< index
		<< std::left
		<< std::setw(10)
		<< " | "
		<< std::left
		<< person.getFisrtName()
		<< std::setw(10)
		<< " | "
		<< std::left
		<< person.getLastName()
		<< std::setw(10)
		<< " | "
		<< std::left
		<< person.getNickname()
		<< std::setw(10)
		<< " | "
		<< std::endl;
}
