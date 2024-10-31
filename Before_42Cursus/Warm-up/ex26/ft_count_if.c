/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/02 16:02:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count_if(char **tab, int (*f)(char *));

//int	count_a(char *str);

/*int	main(void)
{
	char	**tab;
	int	result;
	int	digit;

	tab = (char *[]){"apple", "banana", "zebra", 0};
	result = ft_count_if(tab, count_a);
	digit = result + '0';
	write(1, &digit, 1);
	write(1, "\n", 1);
	return (0);
}*/

/*int	count_a(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == 'a')
			return (1);
		index++;
	}
	return (0);
}*/

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]))
			count++;
		index++;
	}
	return (count);
}
