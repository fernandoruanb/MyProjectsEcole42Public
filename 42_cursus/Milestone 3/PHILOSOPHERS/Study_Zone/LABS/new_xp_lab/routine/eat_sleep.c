/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:44:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 11:47:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat_sleep(t_philo *ph, int flag)
{
	long	start;

	start = get_time(ph);
	if (flag == 0)
	{
		while ((get_time(ph) - start) < ph->t_eat * 1000)
		{
			if (die(ph))
				break ;
			usleep(100);
		}
	}
	else if (flag == 1)
	{
		while ((get_time(ph) - start) < ph->t_sleep * 1000)
		{
			if (die(ph))
				break ;
			usleep(100);
		}
	}
}
