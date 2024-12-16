/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:05:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/16 16:44:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static void	send_bits(pid_t pid, unsigned char character, char *s)
{
	int	index;
	int	length;
	int	time;

	length = ft_strlen(s);
	if (length <= 100)
		time = 900;
	if (length > 100)
		time = 5000;
	index = 7;
	while (index >= 0)
	{
		if (((character >> index) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((character >> index) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(time);
		index--;
	}
}

static int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\v' || nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			signal *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += (nptr[index] - '0');
		index++;
	}
	return (result * signal);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int	index;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	index = 0;
	while (argv[2][index] != '\0')
	{
		send_bits(pid, (unsigned char)argv[2][index], argv[2]);
		index++;
	}
	send_bits(pid, (unsigned char)argv[2][index], argv[2]);
	return (0);
}
