/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:36:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 21:36:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
