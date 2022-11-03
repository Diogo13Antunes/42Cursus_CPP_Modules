#include "../includes/PhoneBook.hpp"

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
