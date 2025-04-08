/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:18:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 11:58:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout << " index:" << _accountIndex << ";" << "amount:" << checkAmount() << ";" << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
	<< "amount:" << checkAmount() << ";"
	<< "closed" << std::endl;
}

void	Account:: makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account:: makeWithdrawal(int withdrawal)
{
	if (checkAmount() < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";";
		std::cout << "p_amount:" << checkAmount() << ";";
		std::cerr << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_displayTimestamp();
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << " index:" << _accountIndex << ";";
		std::cout << "p_amount:" << checkAmount() << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		std::cout << "amount:" << checkAmount() << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	time = std::time(NULL);
	struct tm time_now = *std::localtime(&time);

	std::cout << "[" << std::setfill('0') << std::setw(2) << time_now.tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time_now.tm_sec;
	std::cout << "]";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
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
