/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:18:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/05 11:48:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	std::cout << std::endl;
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalNbDeposits++;
	_nbDeposits = _totalNbDeposits;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "We are creating a beautiful account..." << std::endl;
	std::cout << "Index of Account: " << _accountIndex << std::endl;
	std::cout << "-----------------------------" << std::endl;
	_nbAccounts++;
}

Account::~Account(void)
{
	std::cout << "-----------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "Destructor called, man! " << std::endl;
	std::cout << "I will destroy the Account!!!" << std::endl;
	std::cout << "Account Number:  " << _accountIndex << ";" << std::endl;
	std::cout << "Final amount: R$" << checkAmount() << ";" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void	Account:: makeDeposit(int deposit)
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "MAKING A DEPOSIT $$$ =D " << std::endl;
	_displayTimestamp();
	std::cout << "Account Number: " << _accountIndex << std::endl;
	std::cout << "Deposit: R$" << deposit << std::endl;
	std::cout << "Your last amount: R$" << checkAmount() << std::endl;
	std::cout << checkAmount() << " + " << deposit << " = " << "R$" << _amount + deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount = _amount;
	std::cout << "Your new amount: R$" << checkAmount() << std::endl;
	std::cout << "Total Deposits: " << _totalNbDeposits << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

bool	Account:: makeWithdrawal(int withdrawal)
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "MAKING A WITHDRAWAL $$$ D= " << std::endl;
	_displayTimestamp();
	std::cout << "Account Number: " << _accountIndex << std::endl;
	std::cout << "Your amount: R$" << checkAmount() << std::endl;
	std::cout << "Withdrawal: R$" << withdrawal << std::endl;
	if (checkAmount() < withdrawal)
	{
		std::cout << checkAmount() << " - " << withdrawal << " = " << _amount - withdrawal << std::endl;
		std::cout << "You don't have money to pay it, man!!!" << std::endl;
		std::cout << "withdrawal: refused!!!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "Withdrawal you paid: R$" << withdrawal << std::endl;
		std::cout << checkAmount() << " - " << withdrawal << " = " << "R$" << _amount - withdrawal << std::endl;
		_amount -= withdrawal;
		_totalAmount = _amount;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "New amount: " << checkAmount() << std::endl;
		std::cout << "Withdrawals: " << getNbWithdrawals() << std::endl;
		std::cout << "-----------------------------" << std::endl;
		return (true);
	}
}

Account::Account(void) {}

void	Account::displayStatus(void) const
{
	std::cout << "-----------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "Index: " << _accountIndex << std::endl;
	std::cout << "Amount: " << checkAmount() << std::endl;
	std::cout << "Deposits: " << getNbDeposits() << std::endl;
	std::cout << "Withdrawals: " << getNbWithdrawals() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	time = std::time(NULL);
	struct tm time_now = *std::localtime(&time);

	std::cout << std::endl;
	std::cout << "[" << std::setfill('0') << std::setw(2) << time_now.tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_mday;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_sec;
	std::cout << "]" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "-----------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "Accounts: " << getNbAccounts() << std::endl;
	std::cout << "Total: " << getTotalAmount() << std::endl;
	std::cout << "Deposits: " << getNbDeposits() << std::endl;
	std::cout << "Withdrawals: " << getNbWithdrawals() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

int	Account::getNbAccounts(void)
{
	return	(_nbAccounts);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
