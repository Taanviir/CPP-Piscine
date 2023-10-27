#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

Account::Account(int initial_deposit) {
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_nbAccounts--;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	time_t now = time(NULL);
	struct tm *ltime = localtime(&now);
	std::cout << "["
		<< std::setfill('0') << std::setw(2) << ltime->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << ltime->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << ltime->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << ltime->tm_hour
		<< std::setfill('0') << std::setw(2) << ltime->tm_min
		<< std::setfill('0') << std::setw(2) << ltime->tm_sec << "] ";
}