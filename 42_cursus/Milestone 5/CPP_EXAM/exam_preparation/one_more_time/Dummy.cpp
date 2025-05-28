/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:11:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 11:20:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void): ATarget("Target Practice Dummy") {}

Dummy::~Dummy(void) {}

Dummy::Dummy(const Dummy &other) {}

ATarget*	Dummy::clone(void) const
{
	return new Dummy(*this);
}
