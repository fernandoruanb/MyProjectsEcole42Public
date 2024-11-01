/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:37:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 16:09:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_final_line(char *buffer);

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	static	buffer[BUFFER_SIZE + 1];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read == -1)
		return (NULL);
	return (buffer);
}

int	find_final_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}
