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

size_t	ft_strlen(const char *s);

char	**ft_split(const char *s, char c);

char	*ft_split(const char *s, char c)
{
	size_t	len_s;
	char	*buffer;

	len_s = ft_strlen(s);
	if (s[0] == '\0')
	{
		buffer = malloc

}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
