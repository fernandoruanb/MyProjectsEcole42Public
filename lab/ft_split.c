/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:44:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/18 13:44:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s);

char	**ft_split(const char *s, char c);

int	help_me_god(const char *s);

int	main(int argc, char **argv)
{
	return (0);
}
char	*ft_split(const char *s, char c)
{
	size_t	len_s;
	int	let_go;
	int	let_stop;
	char	*buffer;
	int	words;

	if (s[0] == '\0')
	{
		buffer = (char *)malloc(1);
		buffer = '\0';
		return (buffer);
	}
	while (s[index] != '\0')
	{
		index = let_stop;
		while (s1[index] == (unsigned char)c)
			index++;
		let_go = index;
		while (s1[index] != (unsigned char)c)
			index++;
		let_stop = index;
		while (let_start < let_stop)

}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*help_me_god(const char *s, )
{
	int	let_go;
	int	let_stop;


}
