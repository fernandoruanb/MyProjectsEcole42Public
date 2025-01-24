/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:50:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	transfer_information(char **argv)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (!bytes_read)
			return ;
		write(STDOUT_FILENO, buffer, bytes_read);
	}
}

int	main(int argc, char **argv)
{
	int	file_input;
	int	file_output;

	file_input = open(argv[1], O_RDONLY);
	if (file_input == -1)
		return (1);
	file_output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_output == -1)
	{
		close(file_input);
		return (1);
	}
	if (dup2(file_input, STDIN_FILENO) == -1)
		return (1);
	if (dup2(file_output, STDOUT_FILENO) == -1)
		return (1);
	transfer_information(argv);
	close(file_input);
	close(file_output);
	return (0);
}
