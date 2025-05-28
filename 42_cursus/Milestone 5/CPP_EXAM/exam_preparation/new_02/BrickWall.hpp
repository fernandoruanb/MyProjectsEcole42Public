/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:35:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/28 20:38:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class ATarget;

class BrickWall: public ATarget
{
	private:
		BrickWall& operator=(const BrickWall &other);
	public:
		BrickWall(void);
		~BrickWall(void);
		BrickWall(const BrickWall &other);
		ATarget* clone(void) const;
};

#endif /* BRICKWALL_HPP */
