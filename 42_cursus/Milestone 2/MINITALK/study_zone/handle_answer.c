/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_answer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:43:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 11:44:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	handle_answer(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		printf("Server answer received successfully.\n");
}
