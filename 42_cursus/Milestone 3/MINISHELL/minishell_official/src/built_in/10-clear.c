/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:41:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/16 09:56:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_clear(void)
{
	write(1, "\033[H\033[J", 7);
	write(1, "\033c", 2);
	return (1);
}
