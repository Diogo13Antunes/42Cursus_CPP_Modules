#include "Replacer.hpp"

static int	existFile(std::string fileName);

Replacer::Replacer()
{

}

Replacer::~Replacer()
{

}

void	Replacer::makeReplace(void)
{
	std::string	oldFileText;
	std::string	newFileText;
	std::string	str1 = getString1();
	std::string	str2 = getString2();
	char		buff;
	int			i = 0;
	int			find = 0;

	while (oldFile.read(&buff, 1))
		oldFileText += buff;

	while (1)
	{
		find = oldFileText.find(str1, i);
		if (find == -1)
			break ;
		newFileText += oldFileText.substr(i, find - i);
		i = find + (int)str1.length();
		newFileText += str2;
	}
	newFileText += oldFileText.substr(i, find);
	newFile << newFileText;
}

void	Replacer::createNewFile(void)
{
	newFileName += fileName;
	newFileName += ".replace";
	newFile.open(newFileName.c_str(), std::ios::out);
}

int	Replacer::setFile(std::string newFile)
{
	if (existFile(newFile))
	{
		fileName = newFile;
		oldFile.open(newFile.c_str());
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

void	Replacer::setString1(std::string str1)
{
	string1 = str1;
}

std::string	Replacer::getString1(void) const
{
	return (string1);
}

void	Replacer::setString2(std::string str2)
{
	string2 = str2;
}

std::string	Replacer::getString2(void) const
{
	return (string2);
}

static int	existFile(std::string fileName)
{
	std::fstream	newFile;
	newFile.open(fileName.c_str());
	if (newFile)
	{
		newFile.close();
		return (EXIST);
	}
	else
	{
		newFile.close();
		Terminal::write("Error: File does not exist\n");
		return (NOT_EXIST);
	}
}
