/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:42:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 11:44:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->is_cheapest == true)
			return (a);
		a = a->next;
	}
	return (NULL);
}
