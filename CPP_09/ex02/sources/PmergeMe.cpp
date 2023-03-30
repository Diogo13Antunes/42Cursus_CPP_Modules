#include <PmergeMe.hpp>


static bool			isValidData(char **data);
static bool			printErrorMsg(const char *error);
static int			strToInt(std::string str);
static bool			isDequeAlreadySorted(std::deque<int> *deq);
static bool			isVectorAlreadySorted(std::vector<int> *vec);

static void			sortVector(std::vector<int> *vec);
static void			sortDeque(std::deque<int> *deq);

static void			insertionDequeSort(std::deque<int> *deq, int begin, int end);
static void			insertionVectorSort(std::vector<int> *vec, int begin, int end);

static void			mergeVectorSort(std::vector<int> *vec, int begin, int mid, int end);
static void			mergeDequeSort(std::deque<int> *deq, int begin, int mid, int end);

static double		getDuration(clock_t begin, clock_t end);

PmergeMe::PmergeMe(void)
{
	//Default PmergeMe Constructor
}

PmergeMe::PmergeMe(char **args, int amountNbrs)
{
	//With Values PmergeMe Constructor
	this->_beginSetArguments = clock();
	this->_initialData = NULL;
	this->setArguments(args);
	this->_initialDataSize = amountNbrs;
	this->setVectorData();
	this->setDequeData();
	this->_endSetArguments = clock();
	this->_durationSetArguments = getDuration(this->_beginSetArguments, this->_endSetArguments);
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
		this->_initialData = args;
}

void	PmergeMe::setVectorData(void)
{
	size_t		i;
	std::string	temp;

	if (this->_initialData == NULL)
		return ;
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

	if (this->_initialData == NULL)
		return ;
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
		std::cout << this->_vectorData[i] << " ";
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
		std::cout << this->_dequeData[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::sort(void)
{
	this->_beginVector = clock();
	if (this->_vectorData.size() <= 0)
		printErrorMsg("Impossible to sort Vector is Empty");
	else if (isVectorAlreadySorted(&(this->_vectorData)))
		printErrorMsg("Impossible to sort Vector is already Sorted");
	else
		sortVector(&(this->_vectorData));
	this->_endVector = clock();
	this->_durationVector = getDuration(this->_beginVector, this->_endVector);
	this->_beginDeque = clock();
	if (this->_dequeData.size() <= 0)
		printErrorMsg("Impossible to sort Deque is Empty");
	else if (isDequeAlreadySorted(&(this->_dequeData)))
		printErrorMsg("Impossible to sort Deque is already Sorted");
	else
		sortDeque(&(this->_dequeData));
	this->_endDeque = clock();
	this->_durationDeque = getDuration(this->_beginDeque, this->_endDeque);
}

void	PmergeMe::printTimes(void)
{
	std::cout << "Vector Time: " << this->_durationSetArguments + this->_durationVector << " seconds" << std::endl;
	std::cout << "Deque Time:  " << this->_durationSetArguments + this->_durationDeque << " seconds" << std::endl;
}

static void	sortVector(std::vector<int> *vec)
{
	size_t	n = vec->size();
	size_t	begin;
	size_t	mid;
	size_t	end;

	for (size_t i = 1; i < n; i += DIV)
		insertionVectorSort(vec, i, std::min((i + DIV - 1), (n - 1)));

	for (size_t size = DIV; size < n; size *= 2)
	{
		for (begin = 1; begin < n; begin *= 2)
		{
			mid = begin + size - 1;
			end = std::min((begin + size * 2 - 1), (n - 1));
			if (mid < end)
				mergeVectorSort(vec, begin, mid, end);
		}
	}
}

static void	sortDeque(std::deque<int> *deq)
{
	size_t	n = deq->size();
	size_t	begin;
	size_t	mid;
	size_t	end;

	for (size_t i = 1; i < n; i += DIV)
		insertionDequeSort(deq, i, std::min((i + DIV - 1), (n - 1)));

	for (size_t size = DIV; size < n; size *= 2)
	{
		for (begin = 1; begin < n; begin *= 2)
		{
			mid = begin + size - 1;
			end = std::min((begin + size * 2 - 1), (n - 1));
			if (mid < end)
				mergeDequeSort(deq, begin, mid, end);
		}
	}
}

static void	insertionVectorSort(std::vector<int> *vec, int begin, int end)
{
	int	key = 0;
	int	j = 0;

	for (int i = begin; i <= end; i++)
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

static void	insertionDequeSort(std::deque<int> *deq, int begin, int end)
{
	int	key = 0;
	int	j = 0;

	for (int i = begin; i <= end; i++)
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

static void	mergeVectorSort(std::vector<int> *vec, int begin, int mid, int end)
{
	std::vector<int>	left((*vec).begin() + begin, (*vec).begin() + mid);
	std::vector<int>	right((*vec).begin() + mid, (*vec).begin() + end);
	size_t				i = 0;
	size_t				j = 0;
	size_t				k = begin;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			(*vec)[k] = left[i];
			i++;
		}
		else
		{
			(*vec)[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size())
	{
		(*vec)[k] = left[i];
		k++;
		i++;
	}
	while (j < right.size())
	{
		(*vec)[k] = right[j];
		k++;
		j++;
	}
}

static void	mergeDequeSort(std::deque<int> *deq, int begin, int mid, int end)
{
	std::deque<int>		left((*deq).begin() + begin, (*deq).begin() + mid);
	std::deque<int>		right((*deq).begin() + mid, (*deq).begin() + end);
	size_t				i = 0;
	size_t				j = 0;
	size_t				k = begin;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			(*deq)[k] = left[i];
			i++;
		}
		else
		{
			(*deq)[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size())
	{
		(*deq)[k] = left[i];
		k++;
		i++;
	}
	while (j < right.size())
	{
		(*deq)[k] = right[j];
		k++;
		j++;
	}
}

static bool	onlyHaveDigits(char *str);
static bool	existDuplicates(char **data);

static bool	isValidData(char **data)
{
	for (size_t	i = 1; data[i]; i++)
	{
		if (!onlyHaveDigits(data[i]))
			return (printErrorMsg("Ivalid provided Argumenta"));
	}
	if (existDuplicates(data))
		return (printErrorMsg("Duplicated numbers"));
	return (true);
}

static bool	existDuplicates(char **data)
{
	std::string	value;
	size_t		count = 0;

	for (size_t i = 1; data[i]; i++)
	{
		count = 0;
		value = data[i];
		for (size_t a = i + 1; data[a]; a++)
		{
			if (value.compare(data[a]) == 0)
				count++;
		}
		if (count != 0)
			return (true);
		value.clear();
	}
	return (false);
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

static double	getDuration(clock_t begin, clock_t end)
{
	return ((double)(end - begin) / CLOCKS_PER_SEC);
}
