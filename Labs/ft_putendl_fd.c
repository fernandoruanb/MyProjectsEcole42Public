/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:02:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/02 16:06:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 3)
		return (1);
	file_descriptor = open(argv[1], O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (1);
	ft_putendl_fd(argv[2], file_descriptor);
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}
