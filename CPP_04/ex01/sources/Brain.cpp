#include <Brain.hpp>

Brain::Brain()
{
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Brain Copy Constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < NBR_IDEAS; i++)
	{
		if (src._ideas[i] != this->_ideas[i])
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain Copy Assignment" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Default Destructor" << std::endl;
}
