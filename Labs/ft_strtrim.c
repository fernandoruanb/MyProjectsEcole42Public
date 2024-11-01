/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:49:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 09:58:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

char	*ft_strtrim(char const *s1, char const *set);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 3)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	char	*verificate_valid_answer;

	if (!s1 || !set)
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	verificate_valid_answer = ft_substr(s1, start, end - start);
	if (!verificate_valid_answer)
		return (ft_calloc(1, sizeof(char)));
	return (verificate_valid_answer);
}
