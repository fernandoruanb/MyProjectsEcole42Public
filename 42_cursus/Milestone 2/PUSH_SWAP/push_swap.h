/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:45:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/19 15:30:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	count_operations;
	int	position;
}	t_stack;

char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t len);

#endif /* PUSH_SWAP_H */
