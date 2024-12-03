/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/03 15:16:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>

int		ft_putstr_fd(const char *s, int fd);
int		ft_putstr_fd_0(const char *s, int fd);
int		init_game(t_game *game, char *map_file);
size_t	ft_strlen(const char *s);

#endif /* SO_LONG_H */
