/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:24:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/31 11:24:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	char	buffer[1024];
	int	file_descriptor;
	ssize_t	bytes_read;

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (1);
	}
	file_descriptor = atoi(argv[1]);
	bytes_read = read(file_descriptor, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		write(1, &buffer, sizeof(buffer)));
		bytes_read = read(file_descriptor, buffer, sizeof(buffer)-1);
	}
	close (file_descriptor);
	return (0);
}

char	*get_next_line(int fd)
{
	int	count;
	int	bytes_read;
	char	buffer[1024];
	int	index;
	char	*temp[1024];

	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, sizeof(buffer));
	index = 0;
	while (index < bytes_read)
	{
		if (buffer[index] == '\n')
			break;
		else if (buffer[index] == '\0')
			break;
		index++
	}
	temp = read(fd, buffer, sizeof(index));
	write(1, buffer, sizeof(temp));
}
