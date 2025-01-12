/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:11:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 13:18:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	show_philo_struct(t_philo *philo)
{
	printf("Philosophers: %ld\n", philo->philosophers);
	printf("Time to die: %ld\n", philo->time_to_die);
	printf("Time to eat: %ld\n", philo->time_to_eat);
	printf("Time to sleep: %ld\n", philo->time_to_sleep);
	printf("Must eat times: %ld\n", philo->must_eat_time);
	printf("Meals eaten: %ld\n", philo->meals_eaten);
	printf("Time last meal: %ld\n", philo->time_last_meal);
}
