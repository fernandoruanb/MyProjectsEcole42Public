/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:58:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 14:02:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp" 

class ATarget;

class BrickWall: public ATarget
{
	private:
		BrickWall& operator=(const BrickWall& other);
	public:
		BrickWall(void);
		~BrickWall(void);
		BrickWall(const BrickWall &other);
		ATarget* clone(void) const;
};

#endif /* BRICKWALL_HPP */
