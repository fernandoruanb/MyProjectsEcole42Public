/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:02:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 15:08:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void): ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall(void) {}

BrickWall::BrickWall(const BrickWall &other): ATarget(other.getType()) {}

ATarget* BrickWall::clone(void) const
{
	return new BrickWall(*this);
}
