/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:30:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 09:08:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_to_buffer(int fd, char *buffer);
char	*extract_line(char **buffer);
size_t	ft_strlen_v2(const char *s);
char	*ft_strchr_v2(const char *s, int c);
char	*ft_strdup_v2(const char *s1);
char	*ft_strjoin_v2(const char *s1, const char *s2);
char	*ft_substr_v2(const char *s, unsigned int start, size_t len);
char	*free_buffer(char **buffer, char **read_buf);
void	*ft_calloc_v2(size_t nmemb, size_t size);

#endif /* GET_NEXT_LINE_H */
