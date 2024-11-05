/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:15:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 09:38:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <unistd.h>
# include <stdlib.h>

char	*dynamic_str(const char *buffer, size_t len);
int		print_line(const char *buffer, size_t *start, ssize_t bytes_read);
void	free_memory(char **ptr);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
