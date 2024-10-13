/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:06:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/13 13:06:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	detect;
	size_t	f_detect;

	detect = 0;
	if (little[detect] == '\0')
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	while (big[index] != '\0' && detect < len)
	{
		f_detect = 0;
		while (big[detect + f_detect] == little[f_detect])
	}
}
