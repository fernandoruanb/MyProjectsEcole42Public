/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:47:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:02:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_putendl_fd_1(const char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(fd, &str[index], 1);
		index++;
	}
	write(fd, "\n", 1);
	return (1);
}
