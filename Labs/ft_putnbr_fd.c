/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:13:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 11:20:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

void	ft_putnbr_fd(int n, int fd);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
		return (1);
	file_descriptor = open(argv[1], O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (1);
	ft_putnbr_fd(ft_atoi(argv[2]), file_descriptor);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	digit;

	if (fd == -1)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num++;
	}
	if (num >= 10)
		ft_putnbr_fd((int)num / 10, fd);
	digit = (num % 10) + '0';
	write(fd, &digit, 1);
}
