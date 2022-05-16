/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:24:43 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/16 11:07:07 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_child(t_child *child, t_cmd *cmd)
{
	child->i = 0;
	child->len = ft_cmdlen(cmd);
	child->current = 0;
	child->pipe[0][0] = -1;
	child->pipe[0][1] = -1;
	child->pipe[1][0] = -1;
	child->pipe[1][1] = -1;
}

void	child_process(t_child *child, t_cmd *cmd, int len)
{
	if (!cmd->infd && child->i > 0)
	{
		dup2(child->pipe[1 - child->current][0], STDIN_FILENO);
		close (child->pipe[1 - child->current][0]);
	}
	if (!cmd->outfd && child->i < len - 1)
	{
		dup2(child->pipe[child->current][1], STDOUT_FILENO);
		close (child->pipe[child->current][0]);
		close (child->pipe[child->current][1]);
	}
	redirect_in(cmd);	//есть ошибки при несуществующем файле
	redirect_out(cmd);	//есть ошибки
	if (cmd->args[0])
		ft_execute(cmd); //!!
	collect_variables();
	if (cmd->tmpfile)
		unlink(cmd->name);
}

void	wait_children(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		waitpid(-1, 0, 0);
		i++;
	}
}