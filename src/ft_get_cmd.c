/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 18:47:28 by pleoma           ###   ########.fr       */
=======
/*   Updated: 2022/05/05 19:19:45 by spzona           ###   ########.fr       */
>>>>>>> 5d9e337a3838d06ca2efd07967618f9df678685a
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* filling args */

void	fill_args(void *content)
{
	t_cmd	*tmp;

	tmp = ft_cmd_last(g_shell.cmd);
	if (tmp->args[0])
		tmp->args = export_envp(tmp->args, content, 0);
	else 
	{
		tmp->args[0] = ft_strdup(content);
		tmp->args[1] = NULL;
	}
}

/* counting cmds while avoiding pipes */
	
void	count_cmd(t_list *list)
{
	t_cmd	*tmp_cmd;
	t_list	*tmp;

	tmp = list;
	while (tmp && ft_strncmp("|", tmp->content, 1))
	{
		if (!ft_strncmp(">", tmp->content, 1) || !ft_strncmp("<", tmp->content, 1))
			tmp = tmp = tmp->next;
		else
			ft_cmd_last(g_shell.cmd)->count++;
		tmp = tmp->next;
	}
	tmp_cmd = ft_cmd_last(g_shell.cmd);
	tmp_cmd->args = ft_calloc(tmp_cmd->count, sizeof(char *));
	if (!tmp_cmd->args)
		ft_error("count_cmd", ENOMEM);
}

/*	func fills t_cmd with needed commands and 
	makes dict from special symbols	*/

void	ft_get_cmd(void)
{
	t_list	*tmp_list;
	t_cmd	*cmd;
	
	cmd = g_shell.cmd;
	tmp_list = g_shell.list;
	while (tmp_list)
	{
		if (is_pipe(tmp_list) == false)
		{
			ft_cmdadd_back(&g_shell.cmd, ft_cmdnew());
			count_cmd(tmp_list);
		}
		while (tmp_list && (is_pipe(tmp_list) == false))
		{
			if (is_redir(tmp_list) == true)
			{
				fill_redirect(tmp_list->content, tmp_list->next->content);
				tmp_list = tmp_list->next;
			}
			else
				//fill_argument(); //2
			tmp_list = tmp_list->next;
		}
		if (tmp_list)
			tmp_list = tmp_list->next;
	}
	enum_cmd();
}
