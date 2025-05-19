/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:53:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/19 14:33:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#ifndef DATA_HPP
# define DATA_HPP

# include "Serializer.hpp"

typedef struct s_data
{
	int	id;
	float	number;
	double	test_double;
	char	c;
	std::string name;
}	t_data;

#endif /* DATA_HPP */
