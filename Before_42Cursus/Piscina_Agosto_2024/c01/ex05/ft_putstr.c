/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:14:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 15:14:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	while (str[index] != '\0' )
	{
		len++;
		index++;
	}
	write(1, str, len);
}
//int	main(void)
//{
//	char message[13] = "Hello, World!";
//
//	printf("A mensagem inicial é 'Hello, World!'\n");
//	printf("A mensagem final é: \n");
//	ft_putstr(message);
//	return (0);
//}
