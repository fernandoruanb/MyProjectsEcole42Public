/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:28:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 20:41:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_on_struct(int index, int captured_number, t_philo *philo)
{
	if (index == 1)
		philo->philosophers = captured_number;
	else if (index == 2)
		philo->time_to_die = captured_number;
	else if (index == 3)
		philo->time_to_eat = captured_number;
	else if (index == 4)
		philo->time_to_sleep = captured_number;
	else if (index == 5)
		philo->must_eat_time = captured_number;
	if (philo->args < 5)
		philo->must_eat_time = -1;
	philo->time_last_meal = 0;
}
