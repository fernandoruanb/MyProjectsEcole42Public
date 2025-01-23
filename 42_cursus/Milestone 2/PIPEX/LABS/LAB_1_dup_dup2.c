/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_1_dup_dup2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:31:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 13:10:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	file_input;
	int	file_output;
	char	buffer[4096];
	int	bytes_read;

	if (argc != 3)
		return (1);
	file_input = open(argv[1], O_RDONLY);
	if (file_input == -1)
		return (1);
	file_output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_output == -1)
	{
		close(file_input);
		return (1);
	}
	dup2(file_input, STDIN_FILENO);
	dup2(file_output, STDOUT_FILENO);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (bytes_read == -1)
			break ;
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(file_input);
	close(file_output);
	return (0);
}
