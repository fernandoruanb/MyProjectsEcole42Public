/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:34:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/16 18:43:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	ft_printf("Funciona %s, %c%c%c!!!\n", "Fernando", 'e', 'b', 'a');
	rev_print("hello");
	first_word(argc, argv);
	fd = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		free(line);
	}
	return (0);
}
