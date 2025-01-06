/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:41:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:02:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_putendl_fd_0(const char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(fd, &str[index], 1);
		index++;
	}
	write(fd, "\n", 1);
	return (0);
}
