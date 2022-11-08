#include "../includes/PhoneBook.hpp"

static void	printRowOfElements(Contact person, int index);
static void	printElement(std::string element);
static void	printContact(Contact cont);

void	PhoneBook::createContact()
{
	int	actualContact;

	if (nbrContact == 8)
		actualContact = oldestContact;
	else
		actualContact = nbrContact;
	Terminal::write("--------------- ADD ---------------\n");
	contacts[actualContact].setFirstName();
	contacts[actualContact].setLastName();
	contacts[actualContact].setNickname();
	contacts[actualContact].setPhoneNumber();
	contacts[actualContact].setSecret();
	Terminal::write("\nContact added Seccessfully\n");
	Terminal::wait_enter();
	if (nbrContact == 8)
	{
		if (oldestContact < 7)
			oldestContact++;
		else
			oldestContact = 0;
	}
	if (nbrContact < 8)
		nbrContact += 1;
}

void	PhoneBook::searchContact() const
{
	int			i = 0;
	int			specific_contact;
	std::string	opt;

	if (nbrContact == 0)
	{
		Terminal::write("There is no contacts in this PhoneBook!\n");
		return ;
	}
	Terminal::write("---------------------- SEARCH ----------------------\n");
	Terminal::write("     INDEX |   FIRST N. |    LAST N. |   NICKNAME |\n");
	while (i < nbrContact)
	{
		printRowOfElements(contacts[i], i + 1);
		i++;
	}
	Terminal::write("----------------------------------------------------\n");
	Terminal::write("If you want to see a specific contact insert the index.\nIf not insert 0\n");
	opt = Terminal::read("Contact: ");
	specific_contact = std::strtol(opt.c_str(), '\0', 10);
	if (specific_contact > 0 && specific_contact < 9)
		printContact(contacts[specific_contact - 1]);
	else
		return ;
}

static void	printContact(Contact cont)
{
	Terminal::clean();
	Terminal::write("----------------------------------------------------\n");
	Terminal::write("First Name:     ");
	Terminal::write(cont.getFisrtName());
	Terminal::write("\nLast Name:      ");
	Terminal::write(cont.getLastName());
	Terminal::write("\nNickname:       ");
	Terminal::write(cont.getNickname());
	Terminal::write("\nPhone Number:   ");
	Terminal::write(cont.getPhoneNumber());
	Terminal::write("\nSecret:         ");
	Terminal::write(cont.getSecret());
	Terminal::write("\n----------------------------------------------------\n");
	Terminal::wait_enter();
}

static void	printRowOfElements(Contact person, int index)
{
	std::cout << "         " << index << " | ";
	printElement(person.getFisrtName());
	std::cout << " | ";
	printElement(person.getLastName());
	std::cout << " | ";
	printElement(person.getNickname());
	std::cout << " | " << std::endl;
}

static void	printElement(std::string element)
{
	if (element.length() > 10)
		std::cout << element.substr(0, 9) << ".";
	else if (element.length() == 10)
		std:: cout << element;
	else
	{
		int elem_length = element.length();
		int nbr_spaces = 10 - elem_length;

		for (int i = 0; i < nbr_spaces; i++)
			std::cout << " ";
		std::cout << element;
	}
}
