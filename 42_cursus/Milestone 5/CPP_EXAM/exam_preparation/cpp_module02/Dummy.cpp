/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:40:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 18:05:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void): ATarget("Target Practice Dummy") {}

Dummy::~Dummy(void) {}

Dummy::Dummy(const Dummy &other): ATarget(other.getType()) {}

ATarget* Dummy::clone(void) const
{
	return new Dummy(*this);
}
