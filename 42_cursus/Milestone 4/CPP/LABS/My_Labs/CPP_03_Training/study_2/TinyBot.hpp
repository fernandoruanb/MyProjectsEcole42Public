/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TinyBot.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:00:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 19:19:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINYBOT_HPP
# define TINYBOT_HPP

# include <iostream>

class	TinyBot
{
	protected:
		std::string	name;
		int	energy;
	public:
		TinyBot(std::string name);
		~TinyBot();
		TinyBot(const TinyBot &robot);
		TinyBot& operator=(const TinyBot &robot);
		void	announce(void) const;
		std::string	get_name(void) const;
		void	recharge_energy(void);
		void	show_status(void) const;
};
std::ostream& operator<<(std::ostream &out, const TinyBot &robot);

#endif /* TINYBOT_HPP */
