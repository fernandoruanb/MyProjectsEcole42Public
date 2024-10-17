/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/14 13:06:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);

/*int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (1);
	}
	if (argc > 3)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (1);
	ft_putnbr_fd(atoi(argv[2]), file_descriptor);
	close(file_descriptor);
	return (0);
}*/

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}
