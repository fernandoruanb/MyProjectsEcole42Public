/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/24 15:38:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *s);

void	free_memory(char ***str_list, int allocated);

void	fill_arr(int size, const char *str, char ***str_list);

int	count_words(const char *str);

char	**ft_split(char *str);

int	main(int argc, char **argv)
{
	int	index;
	char	**result;

	result = ft_split(argv[1]);
	index = 0;
	while (result[index] != NULL)
	{
		printf("Array [%d]: %s\n", index, result[index]);
		index++;
	}
	free(result);
	return (0);
}

char	**ft_split(char *str)
{
	int	size;
	char	**str_list;

	if (!str)
		return (ft_calloc(1, sizeof(char *)));
	size = count_words(str);
	if (size == 0)
		return (ft_calloc(1, sizeof(char *)));
	str_list = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!str_list)
		return (NULL);
	fill_arr(size, str, &str_list);
	return (str_list);
}

int	count_words(const char *str)
{
	int	index;
	int	count;
	size_t	length;

	length = ft_strlen(str);
	if (length == 0)
		return (0);
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] && str[index] != ' ' && str[index] != '\t' 
			&& str[index] != '\n')
		{
			while (str[index] && str[index] != ' ' && str[index] != '\t'
				&& str[index] != '\n')
				index++;
			count++;
		}
		if (str[index] != '\0')
			index++;
	}
	return (count);
}

void	fill_arr(int size, const char *str, char ***str_list)
{
	int	counter;
	int	index;
	int	pass;
	char	*test;

	counter = 0;
	index = 0;
	while (str[index] != '\0' && counter < size)
	{
		pass = 0;
		while ((str[index]) && (str[index] == ' ' ||
			str[index] == '\t' || str[index] == '\n'))
			index++;
		while ((str[index + pass]) && str[index + pass] != ' '
			&& str[index + pass] != '\t' && str[index + pass] != '\n')
			pass++;
		test = ft_substr((char *)&str[index], 0, pass);
		if (!test)
		{
			free_memory(str_list, counter);
			return ;
		}
		(*str_list)[counter] = test;
		counter++;
		index += pass;
	}
	(*str_list)[size] = 0;
}

void	free_memory(char ***str_list, int allocated)
{
	int	index;

	if (!str_list || !*str_list)
		return ;
	index = 0;
	while (index < allocated)
	{
		free((*str_list)[index]);
		index++;
	}
	*str_list = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	index;
	unsigned char	*ptr;
	void	*buffer;
	int	length;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	length = nmemb * size;
	buffer = malloc(length);
	ptr = (unsigned char *)buffer;
	index = 0;
	while (index < length)
	{
		ptr[index] = 0;
		index++;
	}
	return (buffer);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	length = ft_strlen(s);
	if (start >= length)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > length)
		len = length - start;
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (index < len)
	{
		buffer[index] = s[start];
		index++;
		start++;
	}
	buffer[index] = '\0';
	return (buffer);
}
