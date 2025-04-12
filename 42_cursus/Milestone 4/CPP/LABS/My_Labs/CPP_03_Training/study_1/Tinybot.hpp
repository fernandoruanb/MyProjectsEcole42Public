/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tinybot.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:59:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 17:54:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINYBOT_HPP
# define TINYBOT_HPP

# include <iostream>

class	TinyBot
{
	private:
		std::string	name;
		int	energy;
	public:
		TinyBot(std::string name);
		~TinyBot(void);
		TinyBot(const TinyBot &other);
		TinyBot& operator=(const TinyBot &other);
		void	show_status(void) const;
		void	recharge_energy(void);
		void	announce(void) const;
		std::string	get_name(void) const;
};
std::ostream& operator<<(std::ostream &out, const TinyBot &other);

#endif /* TINY_BOT */
