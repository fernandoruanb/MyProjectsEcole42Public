/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 21:41:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//ft_printf("%d\n", ft_printf("%c %c\n", 'a', 'b'));
	ft_printf("%c %c %s 100%%\n", 'a', 'b', "Fernando");
	return (0);
}
