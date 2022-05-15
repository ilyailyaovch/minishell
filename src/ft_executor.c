/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:24:39 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/15 15:48:58 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* makes pipes and executes cmds */

void	ft_executor(t_cmd *cmd)
{
	t_child child;

	ft_init_child(&child, cmd);
	ft_init_heredoc_instd(cmd);
	while(child.i < child.len) //цикл не готов лучше запускать без него
	{
		check_exit(cmd);
		//check_cd();
		if (pipe(child.pipe[child.current]) == -1)
			ft_error("minishell: pipe: ", EPIPE);
		child.pid = fork();
		if (child.pid < 0)
			ft_error("minishell: fork: ", errno);
		if (child.pid)
			ft_pipe_signals();
		if (child.pid == 0)
			//child_process(&child, cmd, child.len);
		close(child.pipe[1 - child.current][0]);
		close(child.pipe[child.current][1]);
		child.current = 1 - child.current;
		cmd = cmd->next;
		child.i++;
		//get_variables();
	}
	close(child.pipe[1 - child.current][0]);
	wait_children(child.len);
}