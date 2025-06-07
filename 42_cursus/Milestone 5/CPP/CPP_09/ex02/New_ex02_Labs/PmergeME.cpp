/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:20:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/07 14:20:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

void	sortHighVector(std::vector<unsigned int> &vectorHigh)
{
	std::vector<unsigned int>::iterator s = vectorHigh.begin();
	std::vector<unsigned int>::iterator e = vectorHigh.end();

	std::sort(s, e);
}

void	sortHighList(std::list<unsigned int> &listHigh)
{
	listHigh.sort();
}
