/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:27:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/24 15:38:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int argc, char **argv)
{
	char	**tokens;

	if (argc != 2)
		return (1);
	tokens = ft_split(argv[1], ' ');
	if (!tokens)
		return (ft_putendl_fd_1("Failed to init tokens.", 2));
	handle_tokens(tokens);
	return (0);
}
