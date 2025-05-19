/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:40:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/19 11:46:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(void)
{
	std::cout << "Base constructor called" << std::endl;
}

Base::~Base(void)
{
	std::cout << "Base Destructor called" << std::endl;
}
