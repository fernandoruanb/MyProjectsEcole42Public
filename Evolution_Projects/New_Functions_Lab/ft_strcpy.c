/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:45:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 09:52:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Next_Generation_Libft/libft.h"

char	*ft_strcpy(char *s1, char *s2);

int	main(int argc, char **argv)
{
	char	dest[50];
	char	*src;

	(void)argc;
	src = argv[1];
	ft_strcpy(dest, src);
	ft_printf("%s\n", dest);
	return (0);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
