/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_Manipulate_strings_n.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:43:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/04 12:52:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char	*dynamic_str(const char *buffer, ssize_t len);

static int	read_and_write(int fd);

static int	print_line(const char *buffer, ssize_t *start, ssize_t bytes_read);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error opening file!\n", 20);
		return (1);
	}
	if (read_and_write(file_descriptor) == 1)
		return (1);
	close(file_descriptor);
}

static char	*dynamic_str(const char *buffer, ssize_t len)
{
	int		index;
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = buffer[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

static int	read_and_write(int fd)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	ssize_t	start;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		start = 0;
		while (start < bytes_read)
		{
			if (print_line(buffer, &start, bytes_read) == 1)
				return (1);
		}
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	return (0);
}

static int	print_line(const char *buffer, ssize_t *start, ssize_t bytes_read)
{
	ssize_t	len;
	char	*dynamic_str_here;

	len = 0;
	while ((*start + len) < bytes_read && buffer[*start + len] != '\n')
		len++;
	dynamic_str_here = dynamic_str(&buffer[*start], len);
	if (!dynamic_str_here)
		return (1);
	write(1, dynamic_str_here, len);
	free(dynamic_str_here);
	if (buffer[*start + len] == '\n')
	{
		write(1, "\n", 1);
		(*start) += len + 1;
	}
	else
		(*start) += len;
	return (0);
}
