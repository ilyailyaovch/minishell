/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 18:40:31 by spzona           ###   ########.fr       */
=======
/*   Updated: 2022/05/05 18:22:44 by pleoma           ###   ########.fr       */
>>>>>>> a949e982e1781284adcf5f3a7fc9106423d2c52f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* counting cmds while avoiding pipes*/
	
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
				//fill_redirect(); //1
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
