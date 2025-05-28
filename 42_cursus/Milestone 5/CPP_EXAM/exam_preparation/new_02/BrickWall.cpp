/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:38:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:43:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void): ATarget("Inconspicuous Red-brick wall") {}

BrickWall::BrickWall(void) {}

BrickWall::BrickWall(const BrickWall &other): type(other.getType()) {}

ATarget*	clone(void) const
{
	return new BrickWall(*this);
}
