
#include<iostream>
#include<time.h>
#include "Account.hpp"

// INIT ATTRB
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// CONSTUCTOR
Account::Account(int initial_deposit) {
	this->_accountIndex = Account::getNbAccounts();
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

// DESTRUCTOR
Account::~Account() {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << Account::checkAmount()
	<< ";closed" << std::endl;
}

// GETTERS
int	Account::getNbAccounts(void) {
	return(_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return(_totalAmount);
}

int	Account::getNbDeposits(void) {
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return(_totalNbWithdrawals);
}

// FUNCTIONS
void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount()
	<< ";deposit:" << deposit << ";amount:" << Account::checkAmount() + deposit
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (this->_amount < withdrawal) {
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount()
		<< ";withdrawal:refused" << std::endl;
		return(false);
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount()
	<< ";withdrawal:" << withdrawal << ";amount:" << Account::checkAmount() - withdrawal
	<< ";nb_withdrawals:1" << std::endl;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const {
	return(this->_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << Account::checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t	structure;
	tm		*currentTime;
	char	limitChar[16];

	time(&structure);
	currentTime = localtime(&structure);
	std::strftime(limitChar, 16, "%Y%m%d_%H%M%S", currentTime);
	std::cout << '[' << limitChar << ']';
}
