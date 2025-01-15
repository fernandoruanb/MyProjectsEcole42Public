/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anyone_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 14:55:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	anyone_death(t_philo *ph)
{
	if (ph->tl_meal == 0)
	{
		if ((get_time(ph) - ph->clock) > ph->t_die * 1000)
		{
			printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
			ph->flag->died = 1;
			return (1);
		}
	}
	else
	{
		if ((get_time(ph) - ph->tl_meal) > ph->t_die * 1000)
		{
			printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
			ph->flag->died = 1;
			return (1);
		}
	}
	return (0);
}
