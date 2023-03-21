// CPP program to find infix for
// a given postfix.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    return (x >= '0' && x <= '9');
}

// Get Infix for a given postfix
// expression
string getInfix(string exp)
{
	stack<string> s;

	for (int i=0; exp[i]!='\0'; i++)
	{
		// Push operands
		if (isOperand(exp[i]))
		{
		    string op(1, exp[i]);
		    s.push(op);
		}
		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push(op2 + exp[i] + op1);
		}
		std::cout << s << std::endl;
	}
	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

// Driver code
int main(int ac, char **av)
{
    if (ac != 2)
    {
        exit(EXIT_FAILURE);
    }
	string exp = av[1];
	cout << "Correct:     \'" <<getInfix(exp) << "\'" << endl;
	return 0;
}
