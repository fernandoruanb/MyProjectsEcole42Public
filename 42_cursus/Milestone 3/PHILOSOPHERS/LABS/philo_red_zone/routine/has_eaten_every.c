/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_eaten_every.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	has_eaten_every(t_philo *ph)
{
	return (ph->m_eaten == ph->me_time);
}
