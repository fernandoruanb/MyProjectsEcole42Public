/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:51:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/02 15:58:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 3)
		return (1);
	file_descriptor = open(argv[1], O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (1);
	ft_putstr_fd(argv[2], file_descriptor);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s || fd == -1)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}
