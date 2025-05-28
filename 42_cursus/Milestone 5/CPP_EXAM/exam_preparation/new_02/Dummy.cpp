/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:03:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:05:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void): ATarget("Target Practice Dummy") {}

Dummy::~Dummy(void) {}

Dummy::Dummy(const Dummy& target): ATarget(target.getType()) {}

ATarget* clone(void) const
{
	return new Dummy(*this);
}
