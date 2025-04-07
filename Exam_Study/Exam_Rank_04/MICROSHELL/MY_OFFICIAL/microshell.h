/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:05:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/02 09:06:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <wait.h>

typedef struct s_shell
{
	int	isPipe;
	char	*cmd;
	char	**cmds;
	char	**envp;
	int	pipefd[2];
}	t_shell;

#endif /* MICROSHELL_H */
