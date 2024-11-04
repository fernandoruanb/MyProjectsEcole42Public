/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_Simple_read_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:53:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/04 11:31:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	ssize_t	bytes_read;
	char	buffer[1024];

	if (argc < 2)
	{
		write (1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (1);
	bytes_read = read(file_descriptor, buffer, sizeof(buffer));
	if (bytes_read == -1)
		return (1);
	buffer[bytes_read] = '\0';
	write(1, buffer, bytes_read);
	close(file_descriptor);
	return (0);
}
