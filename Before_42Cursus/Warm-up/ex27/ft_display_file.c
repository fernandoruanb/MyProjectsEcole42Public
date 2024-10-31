/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:11:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/04 17:11:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	ssize_t	bytes_read;
	char	buffer[4096];

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
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
	write(1, buffer, bytes_read);
	close(file_descriptor);
	return (0);
}
