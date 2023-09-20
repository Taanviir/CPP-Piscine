#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
}

Account::Account(void) {
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
}

Account::~Account(void) {
	return;
}

void Account::displayAccountsInfos(void) {
	std::cout << "Total number of accounts: " << _nbAccounts << std::endl;
	std::cout << "Total amount accross all accounts: " << _totalAmount << std::endl;
}

void Account::makeDeposit(int deposit) {
	std::cout << "Making deposit of " << deposit << std::endl;
	_totalAmount += deposit;
	_nbDeposits++;
	return;
}

bool Account::makeWithdrawal(int withdrawal) {
	std::cout << "Making withdrawal of " << withdrawal << std::endl;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	return false;
}

int Account::checkAmount(void) const {
	std::cout << "Available amount in this account: " << this->_amount << std::endl;
	return 0;
}

void Account::displayStatus(void) const {
	std::cout << "DISPLAY STATUS " << std::endl;
	return;
}