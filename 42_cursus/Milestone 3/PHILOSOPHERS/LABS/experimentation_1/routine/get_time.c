/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:40:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(t_philo *ph)
{
	gettimeofday(&ph->time, NULL);
	return (ph->time.tv_sec * 1000000 + ph->time.tv_usec);
}
