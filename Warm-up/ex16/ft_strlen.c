/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:21:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/20 10:21:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strlen(char *str);

/*int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 2)
		return (1);
	result = ft_strlen(argv[1]);
	result2 = strlen(argv[1]);
	printf("(MY FUNCTION) %i.\n", result);
	printf("(ORIGINAL) %i.\n", result2);
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
