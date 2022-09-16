#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

inline void	Account::_displayTimestamp( void )
{
	std::cout<<"["<<time(0)<<"]";
}

inline int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

inline int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

inline int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

inline int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<" accounts:"<<getNbAccounts()
	<<";total:"<<getTotalAmount()
	<<";deposits:"<<getNbDeposits()
	<<";withdrawals:"<<getNbWithdrawals()
	<<std::endl;
}


Account::Account( int initial_deposit )
{
	static int i;
	this->_amount = initial_deposit;
	this->_accountIndex = i++;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout<<" index:"<<this->_accountIndex
	<<";amount:"<<this->_amount
	<<";created"<<std::endl;
}
Account::~Account( void )
{
	// [19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout
	<<" index:"<<this->_accountIndex
	<<";amount:"<<this->_amount
	<<";closed"<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
	<<" index:"<<this->_accountIndex
	<<";p_amount:"<<this->_amount
	<<";deposit:"<<deposit
	<<";amount"<<this->_amount + deposit
	<<";nb_deposits:"<<this->_nbDeposits
	<<std::endl;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= this->_amount)
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		_displayTimestamp();
		std::cout
		<<" index:"<<this->_accountIndex
		<<";p_amount:"<<this->_amount
		<<";withdrawal:"<<withdrawal
		<<";amount"<<this->_amount - withdrawal
		<<";nb_withdrawals:"<<this->_nbWithdrawals
		<<std::endl;
		this->_amount -= withdrawal;
		return true;
	}else{
		_displayTimestamp();
		std::cout
		<<" index:"<<this->_accountIndex
		<<";p_amount:"<<this->_amount
		<<";withdrawal:refused"
		<<std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<<" index:"<<this->_accountIndex
	<<";amount:"<<checkAmount()
	<<";deposits:"<<this->_nbDeposits
	<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

