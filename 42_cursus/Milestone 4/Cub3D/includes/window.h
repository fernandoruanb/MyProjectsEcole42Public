/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:01:59 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/21 13:57:56 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"

int		drawstr(char *str, int fd, int _return);
int		set_window(t_game *game);
void	run_window(t_game *game);
void	render(t_game *game);

#endif
