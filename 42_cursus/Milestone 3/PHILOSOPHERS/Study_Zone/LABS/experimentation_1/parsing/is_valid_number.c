/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:12:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/11 18:15:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_number(const char *s)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		if (!ft_isdigit(s[index]))
			return (0);
		index++;
	}
	return (1);
}
