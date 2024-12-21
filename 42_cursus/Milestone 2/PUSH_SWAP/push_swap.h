/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:04:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/21 14:45:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putendl_fd_0(const char *str, int fd);
int		ft_putendl_fd_1(const char *str, int fd);
char	**ft_putendl_fd_n(const char *str, int fd);
int		ft_atoi(const char *nptr, int *error);
int		ft_isdigit(char c);
int	count_all_numbers(int argc, char **argv);

#endif /* PUSH_SWAP_H */
