/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:11:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/11 21:18:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	show_philo_struct(t_philo *philo)
{
	printf("Philosophers: %d\n", philo->philosophers);
	printf("Time to die: %d\n", philo->time_to_die);
	printf("Time to eat: %d\n", philo->time_to_eat);
	printf("Time to sleep: %d\n", philo->time_to_sleep);
	printf("Must eat times: %d\n", philo->must_eat_time);
	printf("Forks: %d\n", philo->forks);
}
