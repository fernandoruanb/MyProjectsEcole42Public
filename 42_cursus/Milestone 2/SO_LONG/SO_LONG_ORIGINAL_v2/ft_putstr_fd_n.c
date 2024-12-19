/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 18:57:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*char	*ft_putstr_fd_n(const char *s, int fd);

int	main(int argc, char **argv)
{
	ft_putstr_fd_n(argv[1], 1);
	return (0);
}*/

char	**ft_putstr_fd_n(const char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, (char *)&s[index], 1);
		index++;
	}
	return (NULL);
}
