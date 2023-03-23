#include <PmergeMe.hpp>


static bool			isValidData(char **data);
static bool			printErrorMsg(const char *error);
static int			strToInt(std::string str);
static std::string	intToStr(int nbr);
static bool			isDequeAlreadySorted(std::deque<int> *deq);
static bool			isVectorAlreadySorted(std::vector<int> *vec);

static void			sortVector(std::vector<int> *vec);
static void			sortDeque(std::deque<int> *deq);

static void			insertionDequeSort(std::deque<int> *deq);
static void			insertionVectorSort(std::vector<int> *vec);

PmergeMe::PmergeMe(void)
{
	//Default PmergeMe Constructor
}

PmergeMe::PmergeMe(char **args, int amountNbrs)
{
	//With Values PmergeMe Constructor
	this->_initialData = NULL;
	this->setArguments(args);
	this->_initialDataSize = amountNbrs;
	this->setVectorData();
	this->setDequeData();
	(void)intToStr(13);
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	//PmergeMe Copy Constructor
	*this = src;
}

PmergeMe::~PmergeMe(void)
{
	//Default PmergeMe Destructor
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	//PmergeMe Copy Assignment Operator
	this->_initialData = src._initialData;
	this->_initialDataSize = src._initialDataSize;
	this->_vectorData = src._vectorData;
	this->_dequeData = src._dequeData;
	return (*this);
}

void	PmergeMe::setArguments(char **args)
{
	if (isValidData(args))
	{
		this->_initialData = args;
		for (int i = 1; this->_initialData[i] != NULL; i++)
			std::cout << " [" << this->_initialData[i] << "]";
		std::cout << std::endl;
	}
}

void	PmergeMe::setVectorData(void)
{
	size_t		i;
	std::string	temp;

	this->_vectorData.resize(this->_initialDataSize);
	for (i = 0; i < this->_vectorData.size(); i++)
	{
		temp = this->_initialData[i + 1];
		this->_vectorData[i] = strToInt(temp);
		temp.clear();
	}
}

void	PmergeMe::setDequeData(void)
{
	size_t		i;
	std::string	temp;

	this->_dequeData.resize(this->_initialDataSize);
	for (i = 0; i < this->_dequeData.size(); i++)
	{
		temp = this->_initialData[i + 1];
		this->_dequeData[i] = strToInt(temp);
		temp.clear();
	}
}

void	PmergeMe::printVectorData(void)
{
	if (this->_vectorData.size() <= 0)
	{
		printErrorMsg("Impossible to print the Vector is Empty");
		return ;
	}
	for (size_t i = 0; i < this->_vectorData.size(); i++)
		std::cout << "[" << this->_vectorData[i] << "] ";
	std::cout << std::endl;
}

void	PmergeMe::printDequeData(void)
{
	if (this->_dequeData.size() <= 0)
	{
		printErrorMsg("Impossible to print the Deque is Empty");
		return ;
	}
	for (size_t i = 0; i < this->_dequeData.size(); i++)
		std::cout << "[" << this->_dequeData[i] << "] ";
	std::cout << std::endl;
}

void	PmergeMe::sort(void)
{
	if (this->_vectorData.size() <= 0)
		printErrorMsg("Impossible to sort Vector is Empty");
	else if (isVectorAlreadySorted(&(this->_vectorData)))
		printErrorMsg("Impossible to sort Vector is already Sorted");
	else
		sortVector(&(this->_vectorData));
	if (this->_dequeData.size() <= 0)
		printErrorMsg("Impossible to sort Deque is Empty");
	else if (isDequeAlreadySorted(&(this->_dequeData)))
		printErrorMsg("Impossible to sort Deque is already Sorted");
	else
		sortDeque(&(this->_dequeData));
}

static void	sortVector(std::vector<int> *vec)
{
	insertionVectorSort(vec);
}

static void	sortDeque(std::deque<int> *deq)
{
	insertionDequeSort(deq);
}

static void	insertionVectorSort(std::vector<int> *vec)
{
	int	key = 0;
	int	j = 0;
	int	len = vec->size();
	for (int i = 1; i < len; i++)
	{
		key = (*vec)[i];
		j = i - 1;
		while (j >= 0 && (*vec)[j] > key)
		{
			(*vec)[j + 1] = (*vec)[j];
			j--;
		}
		(*vec)[j + 1] = key;
	}
}

static void	insertionDequeSort(std::deque<int> *deq)
{
	int	key = 0;
	int	j = 0;
	int	len = deq->size();
	for (int i = 1; i < len; i++)
	{
		key = (*deq)[i];
		j = i - 1;
		while (j >= 0 && (*deq)[j] > key)
		{
			(*deq)[j + 1] = (*deq)[j];
			j--;
		}
		(*deq)[j + 1] = key;
	}
}

static bool	onlyHaveDigits(char *str);

static bool	isValidData(char **data)
{
	for (size_t	i = 1; data[i]; i++)
		if (!onlyHaveDigits(data[i]))
			return (printErrorMsg("Ivalid provided Argumenta"));
	return (true);
}

static bool	onlyHaveDigits(char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

static bool	printErrorMsg(const char *error)
{
	std::cerr << "Error: " << error << std::endl;
	return (false);
}

static int	strToInt(std::string str)
{
	std::stringstream	oss;
	int					nbr;

	oss << str;
	oss >> nbr;
	return (nbr);
}

static std::string	intToStr(int nbr)
{
	std::stringstream	oss;
	std::string			str;

	oss << nbr;
	oss >> str;
	return (str);
}

static bool	isVectorAlreadySorted(std::vector<int> *vec)
{
	for (size_t i = 0; i < (*vec).size() - 1; i++)
	{
		if ((*vec)[i] > (*vec)[i + 1])
			return (false);
	}
	return (true);
}

static bool	isDequeAlreadySorted(std::deque<int> *deq)
{
	for (size_t i = 0; i < (*deq).size() - 1; i++)
	{
		if ((*deq)[i] > (*deq)[i + 1])
			return (false);
	}
	return (true);
}
