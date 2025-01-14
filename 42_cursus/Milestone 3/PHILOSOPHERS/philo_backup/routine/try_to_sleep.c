/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 12:27:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	try_to_sleep(t_philo *ph)
{
	printf("%ld Philo %ld is sleeping\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_sleep * 1000);
}
