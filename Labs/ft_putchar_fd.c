/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:12:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 10:32:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../42_cursus/Libft/libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
		return (1);
	file_descriptor = open(argv[1], O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (1);
	ft_putchar_fd(argv[2][0], file_descriptor);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}
