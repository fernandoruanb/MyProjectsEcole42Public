/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anyone_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 14:58:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	anyone_death(t_philo *ph)
{
	if (ph->tl_meal == 0 && ph->flag->died != 1)
	{
		if ((get_time(ph) - ph->clock) >= ph->t_die * 1000)
		{
			printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
			ph->flag->died = 1;
			return (1);
		}
	}
	else if (ph->flag->died != 1)
	{
		if ((get_time(ph) - ph->tl_meal) >= ph->t_die * 1000)
		{
			printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
			ph->flag->died = 1;
			return (1);
		}
	}
	if (ph->flag->died == 1)
		return (1);
	return (0);
}
