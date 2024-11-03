/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:39:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/03 10:44:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char	*buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
}

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

