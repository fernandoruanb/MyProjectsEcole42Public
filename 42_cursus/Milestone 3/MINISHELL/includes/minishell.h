/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:07:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H 

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int	file_stdin;
	int	file_stdout;
	int	file_stderr;
	int	pipes;
	int	status;
	int	redirect_in;
	int	redirect_out;
	int	redirect_out_append;
	int	redirect_in_heredoc;
	int	redirect_in_triple;
	int	redirect_out_triple;
}	t_data;

void	execute(char *line, t_data *data, char **envp);

#endif /* MINISHELL_H */
