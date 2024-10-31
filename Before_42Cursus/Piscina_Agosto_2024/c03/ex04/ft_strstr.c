/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:58:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/02 14:58:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>*/

char	*ft_strstr(char *str, char *to_find);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*s1;
	char	*s2;
	char	*result;
	char	*result2;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	result = ft_strstr(s1, s2);
	printf("O resultado em minha função ficou: %s\n", result);
	result2 = strstr(s1, s2);
	printf("O resultado na função original ficou: %s\n", result2);
	return (0);
}
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	detect;
	int	f_d;
	int	t_d;

	if (*to_find == '\0')
		return (str);
	detect = 0;
	while (str[detect] != '\0')
	{
		f_d = 0;
		if (str[detect] == to_find[f_d])
		{
			t_d = detect;
			while ((str[t_d + f_d] == to_find[f_d]) && (str[t_d + f_d] != '\0'
					&& to_find[f_d] != '\0'))
				f_d++;
			if (to_find[f_d] == '\0')
				return (&str[detect]);
		}
		detect++;
	}
	return (0);
}
