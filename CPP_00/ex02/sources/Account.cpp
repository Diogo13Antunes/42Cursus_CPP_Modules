#include "Account.hpp"
#include <ctime>
#include <iostream>

# define WITHDRAWAL_REFUSED "refused"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts += 1;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int 	p_amount;
	bool	ret;

	p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		_totalAmount -= withdrawal;
		ret = true;
	}
	else
	{
		std::cout << "withdrawal:refused";
		ret = false;
	}
	std::cout << std::endl;
	return (ret);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t	current_time = time(NULL);
	tm		tm = *localtime(&current_time);

	std::cout << "[";
	std::cout << tm.tm_year + 1900 << tm.tm_mon + 1 << tm.tm_mday;
	std::cout << "_";
	std::cout << tm.tm_hour << tm.tm_min << tm.tm_sec;
	std::cout << "] ";
}

int		Account::getNbAccounts()
{
	return (_nbAccounts);
}

int		Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int		Account::getTotalAmount()
{
	return (_totalAmount);
}

int		Account::checkAmount() const
{
	return (_amount);
}
