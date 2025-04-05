/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:52:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 20:52:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

void	Account::displayAccountsInfos(void)
{
	std::cout << "Accounts: " << getNbAccounts() << std::endl;
	std::cout << "Total: " << getTotalAmount() << std::endl;
	std::cout << "Deposits: " << getNbDeposits() << std::endl;
	std::cout << "Withdrawals: " << getNbWithdrawals() << std::endl;
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
