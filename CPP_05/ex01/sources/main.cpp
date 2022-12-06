#include <Bureaucrat.hpp>
#include <Form.hpp>

int main()
{
	try
	{
		Form a("Eval", 10, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
