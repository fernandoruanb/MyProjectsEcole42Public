/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:21:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
char	*dynamic_str(char *buffer, size_t len);
void	free_memory(char **ptr);
char	*ft_strjoin(char *s1, char *s2, size_t len);
ssize_t	find_newline(char *buffer);
char	*append_line(char *line, char *buffer);
void	process_buffer(char *buffer, ssize_t newline_pos);
ssize_t	read_into_buffer(int fd, char *buffer);

#endif /* GET_NEXT_LINE_H */
