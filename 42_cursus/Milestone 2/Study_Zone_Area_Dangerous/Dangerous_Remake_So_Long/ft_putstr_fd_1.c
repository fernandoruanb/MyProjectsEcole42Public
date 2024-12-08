/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:13:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 13:17:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr_fd_1(const char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (1);
}
